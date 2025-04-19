
// Core headers
#include <QTest>
#include <QtTest>
#include <QtWidgets/QApplication>
#include <memory>
#include <prac/QTimer>

#include "field_elements.h"
#include "game.h"
#include "mainwindow.h"
#include "player.h"
#include "utility/painter.h"
#include "utility/timer.h"

class TestYourApp : public QObject {
    Q_OBJECT
public:
    TestYourApp() = default;
    ~TestYourApp() = default;

private slots:

    void init();
    void cleanup();

    void TestCharacter();
    void TestPlayer();
    void TestController();

private:
    MainWindow* window;
    std::shared_ptr<Game> game;
    std::shared_ptr<Controller> controller;
    prac::QTimer* timer;
};

bool operator==(const CoordinateF a, const CoordinateF b) {
    constexpr double epsilon = 1e-6;
    const bool result = std::abs(a.x_pos - b.x_pos) > epsilon ? false
        : std::abs(a.y_pos - b.y_pos) > epsilon               ? false
                                                : std::abs(a.z_pos - b.z_pos) <= epsilon;
    return result;
}

void TestYourApp::init() {
    game.reset();
    controller.reset();

    game = std::make_shared<Game>(10, 12);
    controller = std::make_shared<Controller>(*game);
    const auto player
        = std::make_shared<Player>(game->GetContext(), Coordinate{5, 5, 0}, Direction::kRight);
    game->SetPlayer(player);
    game->AddFloor(0);

    window = new MainWindow(*game, *controller);

    QVERIFY2(window != nullptr, "Главное окно не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Главное окно не активируется");
    timer = prac::QTimer::getLastCreated();
    QVERIFY2(timer != nullptr, "Необходимо использовать ");
}

void TestYourApp::TestCharacter() {
    Character character{game->GetContext(), Coordinate{10, 2, 34}, Direction::kRight};
    constexpr Coordinate expected_coordinate{10, 2, 34};
    QVERIFY(character.GetPosition() == expected_coordinate);
    constexpr CoordinateF expected_coordinate_f{10, 2, 34};
    QVERIFY(character.GetExactPos() == expected_coordinate_f);
    QVERIFY(!character.NowComing());

    bool finished = false;
    character.DoTransition(Direction::kLeft, [&]() {
        finished = true;
    });

    QVERIFY(character.NowComing());
    QVERIFY(!finished);
    const CoordinateF expected_exact_pos = expected_coordinate + CoordinateF{-0.5, 0, 0};
    const auto step_duration = character.GetStepDuration();
    Clock::SetElapsedTime(step_duration / 2);
    timer->emitTimeout();
    QVERIFY(character.GetExactPos() == expected_exact_pos);
    QVERIFY(!finished);
    QVERIFY(character.NowComing());
    Clock::SetElapsedTime(step_duration);
    timer->emitTimeout();
    QVERIFY(character.GetPosition() == Coordinate(9, 2, 34));
    QVERIFY(finished);
    QVERIFY(!character.NowComing());

    finished = false;
    character.DoTransition(Direction::kRight, [&]() {
        finished = true;
    });
    QVERIFY(!finished);
    character.DoTransition(Direction::kLeft, [&]() {});
    QVERIFY(finished);
}

void TestYourApp::TestPlayer() {
    auto& player = game->GetPlayer();
    QCOMPARE(player.GetStepDuration(), 200);
    const CoordinateF initial_position = player.GetPosition();

    bool finished = false;
    player.GoCommand(Direction::kRight, [&]() {
        finished = true;
    });

    QVERIFY(player.NowComing());
    QVERIFY(!finished);

    QVERIFY(player.GetPosition() == initial_position);
    QVERIFY(player.GetExactPos() == initial_position);

    Clock::IncreaseTime(125);
    timer->emitTimeout();
    QVERIFY(player.GetPosition() == initial_position);
    CoordinateF expected_position = initial_position + CoordinateF{0.625, 0, 0};
    QVERIFY(player.GetExactPos() == expected_position);
    QVERIFY(player.NowComing());
    QVERIFY(!finished);
    window->paintEvent({});
    const CoordinateF paint_position = Painter::GetPlayerPos();
    QVERIFY(paint_position == player.GetExactPos());
    Clock::IncreaseTime(75);
    timer->emitTimeout();
    expected_position = initial_position + CoordinateF{1, 0, 0};
    QVERIFY(player.GetPosition() == expected_position);
    QVERIFY(player.GetExactPos() == expected_position);
    QVERIFY(!player.NowComing());
    QVERIFY(finished);
}

void TestYourApp::TestController() {
    auto& player = game->GetPlayer();
    const CoordinateF initial_position = player.GetPosition();
    QVERIFY(!player.NowComing());
    player.SetDirection(Direction::kUp);

    player.DoTransition(Direction::kUp, {});

    Clock::IncreaseTime(100);
    timer->emitTimeout();

    QVERIFY(player.NowComing());
    QCOMPARE(player.GetDirection(), Direction::kUp);

    // Already in move, should do nothing
    controller->OnMoveKey(Direction::kLeft);

    QCOMPARE(player.GetDirection(), Direction::kUp);
    CoordinateF expected_position
        = initial_position + CoordinateF(Coordinate::FromDirection(Direction::kUp));
    Clock::IncreaseTime(100);
    timer->emitTimeout();
    QVERIFY(!player.NowComing());
    QVERIFY(player.GetExactPos() == expected_position);

    // Should only turn right, without moving
    controller->OnMoveKey(Direction::kRight);
    QCOMPARE(player.GetDirection(), Direction::kRight);
    QVERIFY(!player.NowComing());

    // Now - go
    controller->OnMoveKey(Direction::kRight);
    QVERIFY(player.NowComing());

    expected_position
        = player.GetPosition() + CoordinateF(Coordinate::FromDirection(Direction::kRight));
    Clock::IncreaseTime(200);
    timer->emitTimeout();
    QVERIFY(player.GetPosition() == expected_position);
    QVERIFY(player.NowComing());

    expected_position
        = player.GetPosition() + CoordinateF(Coordinate::FromDirection(Direction::kRight));
    Clock::IncreaseTime(200);
    timer->emitTimeout();
    QVERIFY(player.GetPosition() == expected_position);
    QVERIFY(player.NowComing());

    expected_position
        = player.GetPosition() + CoordinateF(Coordinate::FromDirection(Direction::kRight));
    Clock::IncreaseTime(100);
    timer->emitTimeout();

    // Should stop at the end of the movement
    controller->OnReleaseMoveKey(Direction::kRight);
    Clock::IncreaseTime(100);
    timer->emitTimeout();

    QVERIFY(player.GetPosition() == expected_position);
    QVERIFY(!player.NowComing());
}

void TestYourApp::cleanup() {
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"


// Core headers
#include <QTest>
#include <QtTest>
#include <QtWidgets/QApplication>
#include <memory>
#include <prac/QTimer>

#include "characters.h"
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

    void TestPlayer();
    void TestFollowSteps();
    void TestBrownianSteps();
    void TestBrownianStops();
    void TestLostFollowing();

private:
    void TickTimer(const int delta) const {
        Clock::IncreaseTime(delta);
        timer->emitTimeout();
    }
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

    game = std::make_shared<Game>(250, 250);
    controller = std::make_shared<Controller>(*game);
    const auto player
        = std::make_shared<Player>(game->GetContext(), Coordinate{5, 5, 0}, Direction::kRight);
    game->SetPlayer(player);
    Floor& floor0 = game->AddFloor(0);

    auto make_edge_wall = [&] {
        return std::make_shared<EdgeWall>(game->GetContext());
    };

    floor0.SetWall({30, 25}, Direction::kUp, make_edge_wall());
    floor0.SetWall({30, 25}, Direction::kDown, make_edge_wall());
    floor0.SetWall({30, 25}, Direction::kRight, make_edge_wall());
    floor0.SetWall({30, 25}, Direction::kLeft, make_edge_wall());

    window = new MainWindow(*game, *controller);

    QVERIFY2(window != nullptr, "Главное окно не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Главное окно не активируется");
    timer = prac::QTimer::getLastCreated();
    QVERIFY2(timer != nullptr, "Необходимо использовать ");
}

void TestYourApp::TestPlayer() {
    auto& player = game->GetPlayer();
    const Coordinate player_old_pos = player.GetPosition();
    const Coordinate player_new_pos = player.GetPosition() + Coordinate{5, 5, 0};
    player.SetPosition(player_new_pos);
    QCOMPARE(player_old_pos, player.GetPrevPosition());
    QCOMPARE(player_new_pos, player.GetPosition());
}

Coordinate getNextPos(Coordinate current, Direction direction) {
    return current + Coordinate::FromDirection(direction);
}

void TestYourApp::TestFollowSteps() {
    auto& player = game->GetPlayer();
    const Coordinate player_old_pos = player.GetPosition();
    Coordinate victim_pos = player_old_pos + Coordinate{2, 2, 0};
    Victim victim(game->GetContext(), victim_pos, Direction::kUp);
    const auto victim_step_duration = victim.GetStepDuration();

    player.SetPosition(player_old_pos + Coordinate{-1, 0, 0});

    // Initial movement from brownian phase
    Coordinate expected_victim_pos = getNextPos(victim_pos, victim.GetDirection());
    victim.Interact(player, {});
    TickTimer(victim_step_duration);
    QVERIFY(victim.GetPosition() == expected_victim_pos);

    // Next step - towards the player
    auto expected_direction = GetDirectionToward(victim_pos, player_old_pos);
    expected_victim_pos
        = expected_victim_pos + Coordinate::FromDirection(expected_direction.value());
    TickTimer(victim_step_duration);

    QVERIFY(victim.GetPosition() == expected_victim_pos);

    expected_direction = GetDirectionToward(victim_pos, player.GetPosition());
    player.SetPosition(player_old_pos + Coordinate{0, 1, 0});
    expected_victim_pos
        = expected_victim_pos + Coordinate::FromDirection(expected_direction.value());
    TickTimer(victim_step_duration);
    QVERIFY(victim.GetPosition() == expected_victim_pos);
}

void TestYourApp::TestBrownianSteps() {
    const auto& player = game->GetPlayer();
    const Coordinate player_pos = player.GetPosition();
    RandomGen::SetInRange(3);
    const Coordinate victim_pos = player_pos + Coordinate{100, 100, 0};
    const Victim victim(game->GetContext(), victim_pos, Direction::kLeft);
    const auto victim_step_duration = victim.GetStepDuration();
    QVERIFY(RandomGen::GetLastFrom() == 2);
    QVERIFY(RandomGen::GetLastTo() == 8);

    // Should do three steps in the current direction (from random gen), seven after that
    RandomGen::SetInRange(7);

    const Direction initial_direction = victim.GetDirection();
    for (auto i = 0; i < 3; ++i) {
        Coordinate expected_victim_pos = getNextPos(victim.GetPosition(), initial_direction);
        QVERIFY(victim.GetDirection() == initial_direction);
        TickTimer(victim_step_duration);
        QVERIFY(victim.GetPosition() == expected_victim_pos);
    }
    // Now should switch direction and wait for 200ms after that - go
    QVERIFY(!victim.NowComing());
    const Direction second_direction = victim.GetDirection();
    QVERIFY(second_direction != initial_direction);
    TickTimer(200);
    QVERIFY(victim.NowComing());

    for (auto i = 0; i < 7; ++i) {
        Coordinate expected_victim_pos = getNextPos(victim.GetPosition(), second_direction);
        QVERIFY(victim.GetDirection() == second_direction);
        TickTimer(victim_step_duration);
        QVERIFY(victim.GetPosition() == expected_victim_pos);
    }
    QVERIFY(victim.GetDirection() != second_direction);
    while (!victim.NowComing()) {
        TickTimer(200);
    }
}

void TestYourApp::TestBrownianStops() {
    // Victim in the closed cage - shouldn't go anywhere, but should turn around every 200ms
    constexpr Coordinate victim_pos{30, 25, 0};
    const Victim victim(game->GetContext(), victim_pos, Direction::kLeft);

    QVERIFY(RandomGen::GetLastFrom() == 2);
    QVERIFY(RandomGen::GetLastTo() == 8);
    QVERIFY(!victim.NowComing());
    const Direction initial_direction = victim.GetDirection();
    TickTimer(200);
    QVERIFY(!victim.NowComing());
    QVERIFY(victim.GetDirection() != initial_direction);
}
void TestYourApp::TestLostFollowing() {
    // Start as in the TestFollowingSteps
    RandomGen::SetInRange(7);

    auto& player = game->GetPlayer();
    const Coordinate player_old_pos = player.GetPosition();
    Coordinate victim_pos = player_old_pos + Coordinate{2, 2, 0};
    Victim victim(game->GetContext(), victim_pos, Direction::kUp);
    const auto victim_step_duration = victim.GetStepDuration();

    // Initial movement from brownian phase
    Coordinate expected_victim_pos = getNextPos(victim_pos, victim.GetDirection());
    victim.Interact(player, {});
    TickTimer(victim_step_duration);
    QVERIFY(victim.GetPosition() == expected_victim_pos);

    // Next step - towards the player
    auto expected_direction = GetDirectionToward(victim_pos, player_old_pos);
    expected_victim_pos
        = expected_victim_pos + Coordinate::FromDirection(expected_direction.value());
    // But player goes away
    player.SetPosition(player_old_pos + Coordinate{50, 50, 0});

    TickTimer(victim_step_duration);

    QVERIFY(victim.GetPosition() == expected_victim_pos);

    // Now - player is too far away, so victim should go brown around
    // First step of seven was used on the initial movement, so six to go
    const Direction initial_direction = victim.GetDirection();
    for (auto i = 0; i < 6; ++i) {
        Coordinate expected_victim_pos = getNextPos(victim.GetPosition(), initial_direction);
        QVERIFY(victim.GetDirection() == initial_direction);
        TickTimer(victim_step_duration);
        QVERIFY(victim.GetPosition() == expected_victim_pos);
    }
    QVERIFY(victim.GetDirection() != initial_direction);
    QVERIFY(!victim.NowComing());
    TickTimer(200);
    QVERIFY(victim.NowComing());
}


void TestYourApp::cleanup() {
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"

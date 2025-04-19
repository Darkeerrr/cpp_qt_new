
// Core headers
#include <QtTest>
#include <QtWidgets/QApplication>
#include <memory>
#include <prac/QTimer>

#include "field_elements.h"
#include "game.h"
#include "mainwindow.h"
#include "player.h"
#include "utility/timer.h"

// Тестовый класс - проект не скомпилируется, не выполнить условия задания
class TestPlayer : public Character {
public:
    TestPlayer(GameContext& context, Coordinate pos, Direction dir) : Character(context, pos, dir) {
        SetWalkSprites(context.asset_loader.LoadAnimatedWithDirection("characters", "robot-walk", 19));
    }
};


class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:

    void init();
    void cleanup();

    void TestTimer();
    void TestDummyPlayer();

private:
    MainWindow* window;
    std::shared_ptr<Game> game;
    std::shared_ptr<Controller> controller;
};

void TestYourApp::init()
{
    game.reset();
    controller.reset();
    game = std::make_shared<Game>(10, 12);
    controller = std::make_shared<Controller>(*game);
    const auto player = std::make_shared<Player>(game->GetContext(), Coordinate{5, 5, 0}, Direction::kRight);
    game->SetPlayer(player);

    window = new MainWindow(*game, *controller);

    QVERIFY2(window != nullptr, "Главное окно не создано");
    window->show();
    QVERIFY2(window->isVisible(), "Главное окно не активируется");

}

void TestYourApp::TestTimer() {
    const auto timer =  prac::QTimer::getLastCreated();
    QVERIFY2(timer != nullptr, "Необходимо использовать prac::QTimer");
    const auto interval = timer->getInterval();
    QCOMPARE(interval, 40);

    Clock::SetElapsedTime(200);
    timer->emitTimeout();

    QCOMPARE(Timer::GetCurrentTime(), 200);

    // No redrawing event happens
    // const int expected_frame = 5;
    // const auto last_frame_requested = AnimatedAsset::last_frame_requested;
    // QCOMPARE(last_frame_requested, expected_frame);
}

void TestYourApp::TestDummyPlayer(){
    [[maybe_unused]] volatile TestPlayer player{game->GetContext(), {1, 2}, Direction::kRight};
}

void TestYourApp::cleanup()
{
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"

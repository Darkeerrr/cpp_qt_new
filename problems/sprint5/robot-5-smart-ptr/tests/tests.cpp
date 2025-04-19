
// Core headers
#include <QtWidgets/QApplication>

#include <QtTest>

#include "game.h"
#include "player.h"
#include "field_elements.h"
#include "characters.h"
#include <memory>

class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:

    void init();
    void cleanup();

    void TestPlayer();
    void TestVictim();
    void TestFloor();
    void TestCell();


private:
    std::shared_ptr<Game> game;


};

void TestYourApp::init()
{
    game.reset();
    game = std::make_shared<Game>(10, 12);

}

void TestYourApp::TestPlayer() {
    auto player = std::make_shared<Player>(game->GetContext(), Coordinate{5, 5, 0}, Direction::kRight);
    game->SetPlayer(player);
    QVERIFY(player.use_count() == 2);
}

void TestYourApp::TestVictim() {
    auto victim = std::make_shared<Victim>(game->GetContext(), Coordinate{7, 12, 0}, Direction::kLeft);
    game->AddObject(victim);
    QVERIFY(victim.use_count() == 2);
}

void TestYourApp::TestFloor() {
    auto& floor = game->AddFloor(0);

    auto check_wall = [&](const Coordinate2D& where) {
        auto wall = std::make_shared<EdgeWall>(game->GetContext());
        floor.SetWall(where, Direction::kUp, wall);
        QVERIFY(wall.use_count() == 2);
    };
    auto check_empty_wall = [&](const Coordinate2D& where) {
        auto wall = std::make_shared<EmptyWall>();
        floor.SetWall(where, Direction::kUp, wall);
        QVERIFY(wall.use_count() == 2);
    };
    auto check_door = [&](const Coordinate2D& where) {
        auto door = std::make_shared<Door>();
        floor.SetWall(where, Direction::kUp, door);
        QVERIFY(door.use_count() == 2);
    };
    auto check_tile = [&](const Coordinate2D& where) {
        const auto tile = std::make_shared<FloorTile>(game->GetContext(), "floor4");
        floor.SetTile(where, tile);
        QVERIFY(tile.use_count() == 2);
    };

    check_wall({4,  4});
    check_door({5,  4});
    check_wall({6,  4});
    check_wall({4, 3});
    check_door({5, 3});
    check_wall({6, 3});
    check_empty_wall({6,  6});
    check_empty_wall({7,  8});

    check_tile({4, 4});
    check_tile({5, 4});
    check_tile({6, 4});
}

void TestYourApp::TestCell() {
    const auto floor = std::make_shared<FloorTile>(game->GetContext(), "floor4");
    const auto left_wall = std::make_shared<EmptyWall>();
    const auto right_wall = std::make_shared<EmptyWall>();
    Cell cell(floor, left_wall, right_wall);
    QVERIFY(floor.use_count() == 2);
    QVERIFY(left_wall.use_count() == 2);
    QVERIFY(right_wall.use_count() == 2);
}


void TestYourApp::cleanup()
{
}

QTEST_MAIN(TestYourApp)

#include "tests.moc"

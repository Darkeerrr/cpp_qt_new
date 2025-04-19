#include <QtWidgets/QApplication>

#include <QtTest>

#include <string>

#include "level_loader.h"


class TestYourApp : public QObject
{
    Q_OBJECT
public:
    TestYourApp()=default;
    ~TestYourApp()=default;

private slots:
    void init();
    void cleanup();

    void Test1();
    void Test2();
    void Test3();
    void Test4();
    void Test5();
    void Test6();
    void Test7();
    void Test8();
    void Test9();
    void Test10();

};


void TestYourApp::init()
{

}

void TestYourApp::Test1() {
    QJsonObject json_obj;
    json_obj["x"] = 10;
    json_obj["y"] = 20;
    json_obj["z"] = 200;
    QJsonValue json_value(json_obj);

    Coordinate coord = LoadData<Coordinate>(json_value);
    QVERIFY(coord.x_pos == 10);
    QVERIFY(coord.y_pos == 20);
    QVERIFY(coord.z_pos == 200);
}

void TestYourApp::Test2() {
    QJsonArray json_array;
    json_array.append(10);
    json_array.append(20);
    json_array.append(30);
    QJsonValue json_value(json_array);

    Coordinate coord = LoadData<Coordinate>(json_value);
    QVERIFY(coord.x_pos == 10);
    QVERIFY(coord.y_pos == 20);
    QVERIFY(coord.z_pos == 30);
}

void TestYourApp::Test3() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        QJsonArray json_array;
        json_array.append(10);

        QJsonValue json_value(json_array);
        LoadData<Coordinate>(json_value);

    } catch (const std::exception &e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Wrong array length for Coordinate");
}

void TestYourApp::Test4() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        QJsonValue json_value("InvalidType");
        LoadData<Coordinate>(json_value);

    } catch (const std::exception &e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Expected array or object for Coordinate");
}

void TestYourApp::Test5() {
    QJsonObject json_obj;
    json_obj["w"] = 5;
    json_obj["h"] = 6;
    QJsonValue json_value(json_obj);

    Size size = LoadData<Size>(json_value);
    QVERIFY(size.width == 5);
    QVERIFY(size.height == 6);
}

void TestYourApp::Test6() {
    QJsonArray json_array;
    json_array.append(10);
    json_array.append(999);
    QJsonValue json_value(json_array);

    Size size = LoadData<Size>(json_value);
    QVERIFY(size.width == 10);
    QVERIFY(size.height == 999);
}

void TestYourApp::Test7() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        QJsonValue json_value("VeryInvalidType");
        LoadData<Size>(json_value);

    } catch (const std::exception &e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Expected array or object for size");
}

void TestYourApp::Test8() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        QJsonArray json_array;
        json_array.append(10);

        QJsonValue json_value(json_array);
        LoadData<Size>(json_value);

    } catch (const std::exception &e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Wrong array length for size");
}

void TestYourApp::Test9() {
    QJsonObject json_obj;
    json_obj["pos"] = "l";
    auto direction = LoadData<Direction>(json_obj["pos"]);
    QVERIFY(direction == Direction::kLeft);
    
    json_obj["pos"] = "u";
    direction = LoadData<Direction>(json_obj["pos"]);
    QVERIFY(direction == Direction::kUp);
}

void TestYourApp::Test10() {
    bool exception_flag = false;
    std::string exception_msg = "";
    
    QJsonObject json_obj;
    json_obj["pos"] = "77";
    try {
        auto direction = LoadData<Direction>(json_obj["pos"]);
    } catch (const std::exception& e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Unknown directon 77");
}

void TestYourApp::cleanup()
{

}

QTEST_MAIN(TestYourApp)

#include "tests.moc"

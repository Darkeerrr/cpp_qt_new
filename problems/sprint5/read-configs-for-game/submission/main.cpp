#include <cassert>
#include "level_loader.h"

void Test1() {
    QJsonObject json_obj;
    json_obj["x"] = 10;
    json_obj["y"] = 20;
    json_obj["z"] = 200;
    QJsonValue json_value(json_obj);

    Coordinate coord = LoadData<Coordinate>(json_value);
    assert(coord.x_pos == 10);
    assert(coord.y_pos == 20);
    assert(coord.z_pos == 200);
}

void Test2() {
    QJsonArray json_array;
    json_array.append(10);
    json_array.append(20);
    json_array.append(30);
    QJsonValue json_value(json_array);

    Coordinate coord = LoadData<Coordinate>(json_value);
    assert(coord.x_pos == 10);
    assert(coord.y_pos == 20);
    assert(coord.z_pos == 30);
}

void Test3() {
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
    assert(exception_flag);
    assert(exception_msg == "Wrong array length for Coordinate");
}

void Test4() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        QJsonValue json_value("InvalidType");
        LoadData<Coordinate>(json_value);

    } catch (const std::exception &e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    assert(exception_flag);
    assert(exception_msg == "Expected array or object for Coordinate");
}

void Test5() {
    QJsonObject json_obj;
    json_obj["w"] = 5;
    json_obj["h"] = 6;
    QJsonValue json_value(json_obj);

    Size size = LoadData<Size>(json_value);
    assert(size.width == 5);
    assert(size.height == 6);
}

void Test6() {
    QJsonArray json_array;
    json_array.append(10);
    json_array.append(999);
    QJsonValue json_value(json_array);

    Size size = LoadData<Size>(json_value);
    assert(size.width == 10);
    assert(size.height == 999);
}

void Test7() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        QJsonValue json_value("VeryInvalidType");
        LoadData<Size>(json_value);

    } catch (const std::exception &e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    assert(exception_flag);
    assert(exception_msg == "Expected array or object for size");
}

void Test8() {
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
    assert(exception_flag);
    assert(exception_msg == "Wrong array length for size");
}

void Test9() {
    QJsonObject json_obj;
    json_obj["pos"] = "l";
    auto direction = LoadData<Direction>(json_obj["pos"]);
    assert(direction == Direction::kLeft);
    
    json_obj["pos"] = "u";
    direction = LoadData<Direction>(json_obj["pos"]);
    assert(direction == Direction::kUp);
}

void Test10() {
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
    assert(exception_flag);
    assert(exception_msg == "Unknown directon 77");
}

int main(int argc, char *argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
}
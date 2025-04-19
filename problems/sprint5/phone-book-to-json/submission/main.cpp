#include <cassert>
#include "phone_book.h"

void WriteToFile(const QString& filename, const QString& text) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
}

void Test1() {
    QMap<QString, uint64_t> initial_phones;
    PhoneBook phone_book(initial_phones);

    QString filename = "phonebook_1.json";
    phone_book.WriteToJsonFile(filename);

    QFile file(filename);

    assert(file.exists());
    assert(file.open(QIODevice::ReadOnly | QIODevice::Text));

    QTextStream in(&file);
    QString file_content = file.readAll();
    file.close();

    assert(file_content == "{\"PhoneBook\":[]}");
}

void Test2() {
    QMap<QString, uint64_t> initial_phones;
    initial_phones["Ivan"] = 111111;
    initial_phones["Anna"] = 2222;
    initial_phones["Elsa"] = 333333;

    PhoneBook phone_book(initial_phones);

    QString filename = "phonebook_2.json";
    phone_book.WriteToJsonFile(filename);

    QFile file(filename);

    assert(file.exists());
    assert(file.open(QIODevice::ReadOnly | QIODevice::Text));

    QTextStream in(&file);
    QString file_content = file.readAll();
    file.close();

    assert(file_content == "{\"PhoneBook\":[{\"name\":\"Anna\",\"phone\":\"2222\"},{\"name\":\"Elsa\",\"phone\":\"333333\"},{\"name\":\"Ivan\",\"phone\":\"111111\"}]}");
}

void Test3() {
    PhoneBook phone_book(QMap<QString, uint64_t>{});

    QString filename = "phonebook_3.json";
    QString file_content = "{\"PhoneBook\":[]}";
    WriteToFile(filename, file_content);

    phone_book.ReadFromJsonFile(filename);

    QMap<QString, uint64_t> expected_phones;

    assert(phone_book.GetPhones() == expected_phones);
}

void Test4() {
    PhoneBook phone_book(QMap<QString, uint64_t>{});

    QString filename = "phonebook_4.json";
    QString file_content = "{\"PhoneBook\":[{\"name\":\"Dad\",\"phone\":\"2222\"},{\"name\":\"Mom\",\"phone\":\"111111\"}]}";
    WriteToFile(filename, file_content);

    phone_book.ReadFromJsonFile(filename);

    QMap<QString, uint64_t> expected_phones;
    expected_phones["Mom"] = 111111;
    expected_phones["Dad"] = 2222;

    assert(phone_book.GetPhones() == expected_phones);
}

void Test5() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        PhoneBook phone_book(QMap<QString, uint64_t>{});
        QString filename = "0.json";
        phone_book.ReadFromJsonFile(filename);

    } catch (const std::exception& e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    assert(exception_flag);
    assert(exception_msg == "Cannot open file for reading: 0.json");
}

void Test6() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        PhoneBook phone_book(QMap<QString, uint64_t>{});
        QString filename = "phonebook_err_1.json";
        QString file_content = "345:234<<<,,,";
        WriteToFile(filename, file_content);

        phone_book.ReadFromJsonFile(filename);

    } catch (const std::exception& e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    assert(exception_flag);
    assert(exception_msg == "Invalid JSON format");
}

void Test7() {
    bool exception_flag = false;
    std::string exception_msg = "";

    try {
        PhoneBook phone_book(QMap<QString, uint64_t>{});
        QString filename = "phonebook_err_2.json";
        QString file_content = "{\"PhoneBook\":{\"name\":\"Dad\",\"phone\":\"2222\"}}";
        WriteToFile(filename, file_content);

        phone_book.ReadFromJsonFile(filename);

    } catch (const std::exception& e) {
        exception_flag = true;
        exception_msg = e.what();
    }
    assert(exception_flag);
    assert(exception_msg == "Invalid JSON structure");
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
}

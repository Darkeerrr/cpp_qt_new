#include <QtWidgets/QApplication>

#include <QtTest>

#include <string>

#include "phone_book.h"


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

private:
    void WriteToFile(const QString& filename, const QString& text);
};


void TestYourApp::init()
{

}

void TestYourApp::WriteToFile(const QString& filename, const QString& text) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
}

void TestYourApp::Test1() {
    QMap<QString, uint64_t> initial_phones;
    PhoneBook phone_book(initial_phones);

    QString filename = "phonebook_1.json";
    phone_book.WriteToJsonFile(filename);

    QFile file(filename);

    QVERIFY(file.exists());
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));

    QTextStream in(&file);
    QString file_content = file.readAll();
    file.close();

    QVERIFY(file_content == "{\"PhoneBook\":[]}");
}

void TestYourApp::Test2() {
    QMap<QString, uint64_t> initial_phones;
    initial_phones["Ivan"] = 111111;
    initial_phones["Anna"] = 2222;
    initial_phones["Elsa"] = 333333;

    PhoneBook phone_book(initial_phones);

    QString filename = "phonebook_2.json";
    phone_book.WriteToJsonFile(filename);

    QFile file(filename);

    QVERIFY(file.exists());
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));

    QTextStream in(&file);
    QString file_content = file.readAll();
    file.close();

    QVERIFY(file_content == "{\"PhoneBook\":[{\"name\":\"Anna\",\"phone\":\"2222\"},{\"name\":\"Elsa\",\"phone\":\"333333\"},{\"name\":\"Ivan\",\"phone\":\"111111\"}]}");
}

void TestYourApp::Test3() {
    PhoneBook phone_book(QMap<QString, uint64_t>{});

    QString filename = "phonebook_3.json";
    QString file_content = "{\"PhoneBook\":[]}";
    WriteToFile(filename, file_content);

    phone_book.ReadFromJsonFile(filename);

    QMap<QString, uint64_t> expected_phones;

    QVERIFY(phone_book.GetPhones() == expected_phones);
}

void TestYourApp::Test4() {
    PhoneBook phone_book(QMap<QString, uint64_t>{});

    QString filename = "phonebook_4.json";
    QString file_content = "{\"PhoneBook\":[{\"name\":\"Dad\",\"phone\":\"2222\"},{\"name\":\"Mom\",\"phone\":\"111111\"}]}";
    WriteToFile(filename, file_content);

    phone_book.ReadFromJsonFile(filename);

    QMap<QString, uint64_t> expected_phones;
    expected_phones["Mom"] = 111111;
    expected_phones["Dad"] = 2222;

    QVERIFY(phone_book.GetPhones() == expected_phones);
}

void TestYourApp::Test5() {
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
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Cannot open file for reading: 0.json");
}

void TestYourApp::Test6() {
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
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Invalid JSON format");
}

void TestYourApp::Test7() {
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
    QVERIFY(exception_flag);
    QVERIFY(exception_msg == "Invalid JSON structure");
}

void TestYourApp::cleanup()
{

}

QTEST_MAIN(TestYourApp)

#include "tests.moc"

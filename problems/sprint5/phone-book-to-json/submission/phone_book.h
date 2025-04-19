#pragma once

#include <QMap>
#include <QString>

class PhoneBook {
public:
    PhoneBook(QMap<QString, uint64_t> phones) : phones_(phones) {}

    // Допишите методы WriteToJsonFile и ReadFromJsonFile.
    
    QMap<QString, uint64_t> GetPhones() const {
        return phones_;
    }

private:
    QMap<QString, uint64_t> phones_;
};

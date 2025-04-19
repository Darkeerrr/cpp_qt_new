#pragma once

#include "geometry.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

template<class T>
T LoadData(const QJsonValue &);

template<>
inline Coordinate LoadData<Coordinate>(const QJsonValue &json) {
    // Напишите функцию.
}

template<>
inline Size LoadData<Size>(const QJsonValue &json) {
    // Напишите функцию.
}

template<>
inline Direction LoadData<Direction>(const QJsonValue &json) {
    // Напишите функцию.
}
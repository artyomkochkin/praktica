#pragma once

// библиотеки для ввода/вывода и строк
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// класс маршрута
class Marsh {

public:

    // начальный пункт
    char name1[20] = "";

    // конечный пункт
    char name2[20] = "";

    // номер маршрута
    int number = 0;

    // конструктор по умолчанию
    Marsh() {}

    // конструктор с параметрами
    Marsh(const char* n,
        const char* a,
        int p) {

        strncpy_s(name1, n, 19);
        strncpy_s(name2, a, 19);

        number = p;
    }

    // конструктор копирования
    Marsh(const Marsh& m) {

        strncpy_s(name1, m.name1, 19);
        strncpy_s(name2, m.name2, 19);

        number = m.number;
    }

    // перегрузка оператора =
    Marsh& operator=(const Marsh& m) {

        // защита от самоприсваивания
        if (this != &m) {

            strncpy_s(name1, m.name1, 19);
            strncpy_s(name2, m.name2, 19);

            number = m.number;
        }

        return *this;
    }

    // перегрузка <
    bool operator<(const Marsh& m) {

        return number < m.number;
    }

    // перегрузка >
    bool operator>(const Marsh& m) {

        return number > m.number;
    }

    // перегрузка вывода
    friend ostream& operator<<(
        ostream& os,
        const Marsh& m) {

        os << m.name1 << " "
            << m.name2 << " "
            << m.number;

        return os;
    }

    // перегрузка ввода
    friend istream& operator>>(
        istream& is,
        Marsh& m) {

        is >> m.name1
            >> m.name2
            >> m.number;

        return is;
    }

    // функция сравнения для сортировки
    static bool compNumber(
        Marsh& m1,
        Marsh& m2) {

        return m1.number < m2.number;
    }

    // функция сравнения для qsort
    static int compNumberQsort(
        const void* a,
        const void* b) {

        Marsh* m1 = (Marsh*)a;
        Marsh* m2 = (Marsh*)b;

        return m1->number - m2->number;
    }

    // получение name1
    const char* getname1();
};

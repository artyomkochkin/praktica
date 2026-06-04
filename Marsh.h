#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Marsh {

public:

    char name1[20] = "";
    char name2[20] = "";
    int number = 0;

    Marsh() {}

    Marsh(const char* n,
        const char* a,
        int p) {

        strncpy_s(name1, n, 19);
        strncpy_s(name2, a, 19);

        number = p;
    }

    Marsh(const Marsh& m) {

        strncpy_s(name1, m.name1, 19);
        strncpy_s(name2, m.name2, 19);

        number = m.number;
    }

    Marsh& operator=(const Marsh& m) {

        if (this != &m) {

            strncpy_s(name1, m.name1, 19);
            strncpy_s(name2, m.name2, 19);

            number = m.number;
        }

        return *this;
    }

    bool operator<(const Marsh& m) {

        return number < m.number;
    }

    bool operator>(const Marsh& m) {

        return number > m.number;
    }

    friend ostream& operator<<(
        ostream& os,
        const Marsh& m) {

        os << m.name1 << " "
            << m.name2 << " "
            << m.number;

        return os;
    }

    friend istream& operator>>(
        istream& is,
        Marsh& m) {

        is >> m.name1
            >> m.name2
            >> m.number;

        return is;
    }

    static bool compNumber(
        Marsh& m1,
        Marsh& m2) {

        return m1.number < m2.number;
    }

    static int compNumberQsort(
        const void* a,
        const void* b) {

        Marsh* m1 = (Marsh*)a;
        Marsh* m2 = (Marsh*)b;

        return m1->number - m2->number;
    }

    const char* getname1();
};

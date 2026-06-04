#pragma once

#include "Marsh.h"

// размер хеш таблицы
const int m = 10;

// создание хеш таблицы
void create_hashTable(
    int hash[m][2],
    Marsh* arr,
    int n) {

    // заполнение таблицы -1
    for (int i = 0; i < m; i++) {

        hash[i][0] = -1;
        hash[i][1] = -1;
    }

    // добавление элементов
    for (int i = 0; i < n; i++) {

        int j;

        // переменная для квадратичного пробирования
        int i1 = 0;

        // ключ = номер маршрута
        int key = arr[i].number;

        while (1) {

            // вычисление ячейки
            j = (key + i1 * i1) % m;

            // если ячейка свободна
            if (hash[j][1] == -1)
                break;

            // иначе идём дальше
            i1++;
        }

        // записываем ключ
        hash[j][0] = key;

        // записываем индекс массива
        hash[j][1] = i;
    }
}

// поиск в хеш таблице
int search_hash(
    int key,
    int hash[m][2]) {

    int i1 = 0;
    int j;

    while (1) {

        // вычисление позиции
        j = (key + i1 * i1) % m;

        // если нашли ключ
        if (hash[j][0] == key)
            break;

        i1++;
    }

    // вернуть индекс массива
    return hash[j][1];
}

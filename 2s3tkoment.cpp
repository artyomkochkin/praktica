#include <fstream>
#include <iostream>

#include "Marsh.h"
#include "sort.h"
#include "List.h"
#include "Hash.h"

using namespace std;

int main() {

    // массив маршрутов
    Marsh gr[8];

    // количество элементов
    int n = 0;

    // открыть текстовый файл
    ifstream file("text.txt");

    // проверка открытия файла
    if (!file.is_open()) {

        cout << "error\n";

        return 1;
    }

    // чтение массива из файла
    while (
        n < 8 &&
        file >> gr[n]) {

        n++;
    }

    // закрыть файл
    file.close();

    cout << "--------Before--------\n";

    // вывод массива до сортировки
    for (int i = 0; i < n; i++) {

        cout << gr[i] << endl;
    }

    // сортировка вставками
    insert(
        gr,
        n,
        Marsh::compNumber);

    // другие сортировки
    //select(gr, n, Marsh::compNumber);
    //bubbleSort(gr, n, Marsh::compNumber);
    //shell(gr, n, Marsh::compNumber);
    //qs(gr, 0, n - 1, Marsh::compNumber);

    cout << "\n--------After--------\n";

    // вывод после сортировки
    for (int i = 0; i < n; i++) {

        cout << gr[i] << endl;
    }

    /*
    // работа со списком

    List lst;

    for (int i = 0; i < n; i++) {

        lst.insert_sorted(gr[i]);
    }

    cout << "\n------LIST------\n";

    cout << lst;
    */

    // открыть бинарный файл
    ofstream out(
        "marsh.bin",
        ios::binary);

    // запись массива в бинарный файл
    out.write(
        (char*)gr,
        n * sizeof(Marsh));

    // закрыть файл
    out.close();

    // хеш таблица
    int hash[m][2];

    // создание таблицы
    create_hashTable(
        hash,
        gr,
        n);

    cout << "\n------HASH TABLE------\n";

    // вывод таблицы
    for (int i = 0; i < m; i++) {

        cout
            << hash[i][0]
            << " "
            << hash[i][1]
            << endl;
    }

    int key;

    // ввод номера маршрута
    cout << "\nEnter route number: ";

    cin >> key;

    // поиск индекса через хеш
    int record =
        search_hash(
            key,
            hash);

    cout
        << "\nIndex in array: "
        << record
        << endl;

    cout
        << "Found record:\n";

    // вывод найденной записи
    cout
        << gr[record]
        << endl;

    // открыть бинарный файл
    ifstream fin(
        "marsh.bin",
        ios::binary);

    // переход к нужной записи
    fin.seekg(
        record *
        sizeof(Marsh),
        ios::beg);

    Marsh temp;

    // чтение одной записи
    fin.read(
        (char*)&temp,
        sizeof(Marsh));

    cout
        << "\nFROM BINARY FILE:\n";

    // вывод записи из бинарного файла
    cout
        << temp
        << endl;

    fin.close();

    return 0;
}

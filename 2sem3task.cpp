#include <fstream>
#include <iostream>

#include "Marsh.h"
#include "sort.h"
#include "List.h"
#include "Hash.h"

using namespace std;

int main() {

    Marsh gr[8];

    int n = 0;

    ifstream file("text.txt");

    if (!file.is_open()) {

        cout << "error\n";

        return 1;
    }

    while (
        n < 8 &&
        file >> gr[n]) {

        n++;
    }

    file.close();

    cout << "--------Before--------\n";

    for (int i = 0; i < n; i++) {

        cout << gr[i] << endl;
    }

    insert(
        gr,
        n,
        Marsh::compNumber);

    //select(gr, n, Marsh::compNumber);
    //bubbleSort(gr, n, Marsh::compNumber);
    //shell(gr, n, Marsh::compNumber);
    //qs(gr, 0, n - 1, Marsh::compNumber);

    cout << "\n--------After--------\n";

    for (int i = 0; i < n; i++) {

        cout << gr[i] << endl;
    }

    List lst;

    for (int i = 0; i < n; i++) {

        lst.insert_sorted(gr[i]);
    }

    cout << "\n------LIST------\n";

    cout << lst;

    cout << "\nPUSH FRONT\n";

    lst.push_front(
        Marsh(
            "Paris",
            "Berlin",
            100));

    cout << lst;

    cout << "\nPUSH BACK\n";

    lst.push_back(
        Marsh(
            "Rome",
            "Madrid",
            200));

    cout << lst;

    cout << "\nREMOVE Moscow\n";

    lst.remove("Moscow");

    cout << lst;

    Node* f =
        lst.find("Sochi");

    if (f)

        cout << "\nFOUND: "
        << f->data << endl;

    else

        cout << "\nNOT FOUND\n";

    ofstream out(
        "marsh.bin",
        ios::binary);

    out.write(
        (char*)gr,
        n * sizeof(Marsh));

    out.close();

    int hash[m][2];

    create_hashTable(
        hash,
        gr,
        n);

    cout << "\n------HASH TABLE------\n";

    for (int i = 0; i < m; i++) {

        cout
            << hash[i][0]
            << " "
            << hash[i][1]
            << endl;
    }

    int key;

    cout << "\nEnter route number: ";

    cin >> key;

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

    cout
        << gr[record]
        << endl;

    ifstream fin(
        "marsh.bin",
        ios::binary);

    fin.seekg(
        record *
        sizeof(Marsh),
        ios::beg);

    Marsh temp;

    fin.read(
        (char*)&temp,
        sizeof(Marsh));

    cout
        << "\nFROM BINARY FILE:\n";

    cout
        << temp
        << endl;

    fin.close();

    return 0;
}

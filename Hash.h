#pragma once
#include "Marsh.h"

const int m = 10;

void create_hashTable(
    int hash[m][2],
    Marsh* arr,
    int n) {

    for (int i = 0; i < m; i++) {

        hash[i][0] = -1;
        hash[i][1] = -1;
    }

    for (int i = 0; i < n; i++) {

        int j;
        int i1 = 0;

        int key = arr[i].number;

        while (1) {

            j = (key + i1 * i1) % m;

            if (hash[j][1] == -1)
                break;

            i1++;
        }

        hash[j][0] = key;
        hash[j][1] = i;
    }
}

int search_hash(
    int key,
    int hash[m][2]) {

    int i1 = 0;
    int j;

    while (1) {

        j = (key + i1 * i1) % m;

        if (hash[j][0] == key)
            break;

        i1++;
    }

    return hash[j][1];
}

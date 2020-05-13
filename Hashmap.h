//
// Created by prasl on 4/26/2020.
/*
 * Ziyan Prasla (zzp64)
 *
 * Hashmap class, function prototypes. Class is intended for use with hash table and hash values
 */
//

#ifndef CHEATERS_HASHMAP_H
#define CHEATERS_HASHMAP_H

#include <vector>
#include <string>
using namespace std;

class Hashmap {

public:
    Hashmap();
    ~Hashmap();
    void insert(int x, string str);
    int hash1(string str);
   // int hash(string str);

    struct hashNode
    {
        int index;
        hashNode *next;
    };

   // void printnodes(); for debugging
    void getCollisions(int* counts[]);




private:
    static const int SIZE = 166693;
    hashNode *table[SIZE];



};


#endif //CHEATERS_HASHMAP_H

//
// Created by prasl on 4/26/2020.
/*
 * Ziyan Prasla (zzp64)
 * EE312
 * Function definitions for Hashmap class
 */
//

#include "Hashmap.h"
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#include <iostream>
using namespace std;
#include <cmath>

Hashmap::Hashmap() {


}
//probably not the move. gets pretty large
int Hashmap::hash1(string str) {
    long sum = 0;
    for(int i =0; i < 8 ; i++){
        sum += int(str[str.length()*i/8])*pow(33,i);
    }

    sum %= SIZE;
    int val = abs((int)sum);


    return val;

}


void Hashmap::insert(int x, string str) {
    int hashval = hash1(str);
    hashNode *temp = new hashNode();
    temp->index = x;
    hashNode *node = table[hashval];
    if(node == NULL){    //if linked list empty
        table[hashval] = temp;
    }
    else {
        while (node->next != NULL) {
            node = node->next;  //insert at end of linked list
        }
        node->next = temp;
    }
}

/*  DEBUGGING
void Hashmap::printnodes() {        //want to use this to check the collision of the has function
    hashNode *ptr;
    for (int i = 0; i < SIZE; i++) {
        ptr = table[i];
        if (ptr != NULL) {
            int count = 0;
            while (ptr != NULL) {
                count += 1;
                //cout << ptr->index << endl;
                ptr = ptr->next;
            }
            if (count > 1) {
                cout << count << endl;
            }
        }
    }
}
 */

Hashmap::~Hashmap() {
    delete [] table[SIZE];
}


void Hashmap::getCollisions(int* counts[]){
    //iterate through each part of hashtable

    for(int i =0; i < SIZE ;i++) {     //iterate through those with at least two
        if (table[i] != NULL && table[i]->next != NULL) {
            hashNode *temp = table[i];
            while (temp->next != NULL) {
                hashNode *temp2 = temp->next;
                while (temp2 != NULL) {
                    if (temp2->index != temp->index) {
                        int a = temp->index;
                        int b = temp2->index;
                        counts[max(a,b)][min(a,b)]++;

                    }
                    temp2= temp2->next;
                }
                temp = temp->next;
            }
        }
    }
    }







//
// Created by prasl on 4/26/2020.
/*
 * Ziyan Prasla (zzp64)
 * EE312
 * Main file
 */
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <fstream>
#include "Hashmap.h"
#include <stdlib.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}


struct matchedPairs
{
    int numMatches;
    string file1;
    string file2;

};

void sortMatches(vector<matchedPairs>& matches)   //selection sort based on the numMatches for each matched pair
{


    for(int i = 0; i<matches.size()-1; i++)
    {
        int maxInd = i;
        for(int j=i+1; j<matches.size(); j++)
        {

            if( matches[j].numMatches > matches[maxInd].numMatches)
            {
                maxInd = j;
            }

        }

        struct matchedPairs temp = matches[i];
        matches[i] = matches[maxInd];
        matches[maxInd] = temp;
    }

}

void outputmatches(int * check[], int tol, vector<string> files){
    int count = 0;
    vector<matchedPairs> matches;
    for(int i = 0; i < files.size(); i++){
        for(int j=0; j <i; j++){
            if( check[i][j]>= tol){
                count++;
                struct matchedPairs match;
                match.numMatches = check[i][j];     //creates new match struct to add to vector so we can sort it
                match.file1 = files[i];
                match.file2 = files[j];
                matches.push_back(match);
                //cout << check[i][j] << ": "<< files[i] << " and "<< files[j] << endl;
            }
        }

    }
    //sort by numMatches in descending order
    sortMatches(matches);
    for(int i = 0; i<matches.size(); i++)
    {
        cout << matches[i].numMatches <<": "<< matches[i].file1 << " and " << matches[i].file2<<endl;
    }

    cout << "Total pairs: " << count <<endl;
}


int main(int argc, char* argv[])
{
    string dir = string(argv[1]);
    int n = atoi(argv[2]);
    int tolerance = atoi(argv[3]);



    // FOR WINDOWS TESTING
    /*
   string small = string("C:\\Users\\prasl\\Documents\\EE312\\cheaters\\sm_doc_set"); ///cheaters/sm_doc_set
   string medium = string("C:\\Users\\);
   string large = string("C:\\Users\\);
   string dir;
    cout<< "Enter 0 (small set), 1(medium set), or 2(large set) to test: "<<endl;
    int set;
    cin >> set;
    if (set == 0){
        dir = small;
    }
   else if(set ==1){
       dir = medium;
   }
   else if(set ==2){
       dir = large;
   }
     */


    vector<string> files = vector<string>();

    getdir(dir,files);




    files.erase(files.begin(), files.begin()+2);        //removes the first two useless elements




    ifstream inFile;
    deque<string> m1;
    Hashmap hash =  Hashmap();

    for(int i = 0; i < files.size(); i++) {
        string fname = dir + "/" + files[i]; // \\


        inFile.open(fname.c_str());

        string word;



            while (inFile >> word) {
                if (m1.size() < n) {
                    m1.push_back(word);
                }

                if (m1.size() == n) {
                    m1.pop_front();
                    m1.push_back(word);


                    string h = "";

                    for (int j = 0; j < n; j++) {
                        h += m1[j];
                    }

                    //cout<<h<<endl;
                    hash.insert(i, h);        //STORES SEQUENCES OF SIZE N

                }

            }

            inFile.close();
            m1.clear();

    }


    int*check[1400];
    //make the triangular array
    for(int i =0; i < files.size();i++){
        check[i] = new int[i];

        for(int j = 0; j < i ; j++){        //sets 2x2 Array to all zeroes to count matches
            check[i][j]=0;
        }
    }
    //iterate through everything and get values


    hash.getCollisions(check);

   outputmatches(check, tolerance, files);

    return 0;
}

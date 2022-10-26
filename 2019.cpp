//
// Created by Noémie on 03/12/2020.
//

#include "2019.h"
using namespace std;
#include "2020.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include <cstring>
#include "Fonctions_auxiliaires.h"


//2019 Exercice 1 (2 stars)

void Ex1_2019(){
    ifstream file("day1_2019.txt");
    string str;
    int x = 0;
    int tab[200]={0};
    int size=0;
    int totalResult = 0;
    while(getline(file,str)){
        stringstream ss(str);
        ss>>x;
        //tab[size]=x;
        //size++;
        totalResult+=calculateFurtherFuel(x);
    }

    cout<<"Result is "<<totalResult<<endl;
}
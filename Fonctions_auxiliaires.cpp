//
// Created by Noémie on 03/12/2020.
//

#include "Fonctions_auxiliaires.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include <cstring>


using namespace std;


int calculateFurtherFuel(int fuel){
    int totalResult;
    int furtherFuel;
    fuel /= 3;
    fuel = floor(fuel);
    fuel -= 2;
    furtherFuel = fuel;
    while(furtherFuel >= 0) {
// just result where all operations could be conducted considered
        totalResult +=furtherFuel;
        furtherFuel /= 3;
        furtherFuel = floor(furtherFuel);
        furtherFuel -= 2;
    }

    return totalResult;
}

void Tri_Selection(int table[10000], int taille){
    int c;
    for(int i=0;i<taille-1;i++){
        for(int j=i+1;j<taille;j++){
            if(table[i]>table[j]){
                c=table[i];
                table[i]=table[j];
                table[j]=c;
            }
        }
    }
}

void ecrireFichier(char* nom_fichier,bool tab[641]) {
    ofstream myfile;
    myfile.open(nom_fichier);
    myfile<<'FALSE';
    for(int i=0;i<641;i++){
        if (tab[i]==false) {
            myfile << i;
            myfile<<'\n';
        }
    }
    myfile<<'\n';
    myfile<<'TRUE';
    myfile<<'\n';
    myfile<<'\n';
    for(int i=0;i<641;i++){
        if (tab[i]==true) {
            myfile << i;
            myfile<<'\n';
        }
    }
}

void ecrireFichier2(char* nom_fichier,int tab[641]) {
    ofstream myfile;
    myfile.open(nom_fichier);
    for(int i=0;i<641;i++){
            myfile << tab[i];
            myfile<<'\n';
    }
}

void nombreToBinaire(double n,int tab[36]){
    double binary=68719476736/2;
    for (int i=0; i<35; i++){
        if(n-binary>=0){
            tab[i]=1;
            n=n-binary;
        }
        else{
            tab[i]=0;
        }
        binary=binary/2;
    }
    if(n==1){
        tab[35]=1;
    }
}

double binaireToNombre(int tab[36]){
    double n=0;
    double binary=68719476736/2;
    for (int i=0; i<36; i++){
        if(tab[i]==1){
            n=n+binary;
        }
        binary=binary/2;
    }
    return n;
}
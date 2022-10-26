//
// Created by Noémie on 03/12/2020.
//
using namespace std;
#include "2020.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include <cstring>
#include "Fonctions_auxiliaires.h"
#include "day4_2020.h"


//2020 Exercice 1 (2 stars)

void Ex1_2020(){
    ifstream file("day1_2020");
    string str;
    int x = 0;
    int totalResult = 0;
    int tab[200]={0};
    int size=0;
    while(getline(file,str)){
        stringstream ss(str);
        ss>>tab[size];

        size++;
    }

    int a=0;
    int b=0;

    int c=0;

    for(int i=0;i<200;i++){
        for(int j=i+1;j<200;j++){
            for(int k=0;k<200;k++) {
                if (tab[i] + tab[j]+tab[k] == 2020) {
                    a = tab[i];
                    b = tab[j];
                    c=tab[k];
                }
            }
        }
    }
    totalResult=a*b*c;
    cout<<"Result is "<<totalResult<<endl;
}



//2020 Exercice 2 (2 stars)

void Ex2_2020(){
    ifstream file("day2_2020");
    string str;
    int totalResult = 0;
    char letter;
    int num1;
    int num2;
    char tab[1000][1000];
    int size=0;
    while(size<1000){
        //stringstream ss(str);
        //ss>>tab[size];
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        //getline(file,tab[size]);
        size++;
    }

    for(int i=0;i<size;i++){
        int j=0;
        if(tab[i][1]!='-'){
            int a=tab[i][0]-48;
            int b=tab[i][1]-48;
            num1=a*10+b;
            if(tab[i][4]!=' '){
                int c=tab[i][3]-48;
                int d=tab[i][4]-48;
                num2=c*10+d;
                j=6;
            }
            else{
                num2=tab[i][3]-48;
                j=5;
            }
        }
        else{
            num1=tab[i][0]-48;
            if(tab[i][3]!=' '){
                int c=tab[i][2]-48;
                int d=tab[i][3]-48;
                num2=c*10+d;
                j=5;
            }
            else{
                num2=tab[i][2]-48;
                j=4;
            }
        }
        letter=tab[i][j];
        j=j+3;
        /*int occurence=0;
        while(tab[i][j]!='!'){
            if(tab[i][j]==letter){
                occurence++;
            }
            j++;
        }
        if(occurence>=num1&&occurence<=num2){
            totalResult++;
        }*/
        if(tab[i][num1+j-1]==letter&&tab[i][num2+j-1]!=letter){
            totalResult++;
        }
        if(tab[i][num2+j-1]==letter&&tab[i][num1+j-1]!=letter){
            totalResult++;
        }

    }

    cout<<"Result is "<<totalResult<<endl;
}


//2020 Exercice 3 (2 stars)

void Ex3_2020(){
    ifstream file("day3_2020");
    string str;
    double totalResult = 0;
    int totalResult1 = 0;
    int totalResult2 = 0;
    int totalResult3 = 0;
    int totalResult4 = 0;
    int totalResult5 = 0;
    char tab[323][31]={0};
    int size=0;
    int x=0;
    int y=0;
    while(getline(file,str)){
        stringstream ss(str);
        ss>>(tab[size]);
        size++;
    }
    for(int i=0;i<size;i++){
        x=x%31;
        if(tab[y][x]=='#'){
            totalResult1++;
        }
        y=y+1;
        x=x+3;
    }
    x=0;
    y=0;
    for(int i=0;i<size;i++){
        x=x%31;
        if(tab[y][x]=='#'){
            totalResult2++;
        }
        y=y+1;
        x=x+1;
    }
    x=0;
    y=0;
    for(int i=0;i<size;i++){
        x=x%31;
        if(tab[y][x]=='#'){
            totalResult5++;
        }
        y=y+1;
        x=x+5;
    }
    x=0;
    y=0;
    for(int i=0;i<size;i++){
        x=x%31;
        if(y<size) {
            if (tab[y][x] == '#') {
                totalResult3++;
            }
            y = y + 2;
            x = x + 1;
        }
    }
    x=0;
    y=0;
    for(int i=0;i<size;i++){
        x=x%31;
        if(tab[y][x]=='#'){
            totalResult4++;
        }
        y=y+1;
        x=x+7;
    }
    totalResult=totalResult1*totalResult2*totalResult3*totalResult4*totalResult5;
    cout<<"Result is "<<totalResult<<endl;
}


//2020 Exercice 5 (2 stars)

void Ex5_2020() {
    ifstream file("day5_2020");
    string str;
    int x = 0;
    int totalResult = 0;
    char tab[1000][10] = {" "};
    int size = 0;
    bool s[1000] = {false};
    while (getline(file, str)) {
        stringstream ss(str);
        ss >> tab;

        size++;
    }
    int max_Id = 0;
    for (int i = 0; i < size; i++) {
        int a = 0;
        int b = 127;
        int range = 0;
        int siege = 0;
        int Id = 0;
        for (int j = 0; j < 7; j++) {
            if (tab[i][j] == 'F') {
                b = (a + b) / 2;
            }
            if (tab[i][j] == 'B') {
                a = (a + b) / 2;
            }
        }
        range = b;
        a = 0;
        b = 7;
        for (int j = 7; j < 10; j++) {
            if (tab[i][j] == 'L') {
                b = (a + b) / 2;
            }
            if (tab[i][j] == 'R') {
                a = (a + b) / 2;
            }
        }
        siege = b;
        Id = range * 8 + siege;
        s[Id] = true;
        if (Id > max_Id) {
            max_Id = Id;
        }
    }

    for (int i = 1; i < size - 1; i++) {
        if (s[i] == false) {
            if ((s[i - 1] == true) && (s[i + 1] == true)) {
                cout << "Result is " << i << endl;
            }
        }
    }

    totalResult = max_Id;
    cout << "Result is " << totalResult << endl;
}


//2020 Exercice 6 (2 stars)

void Ex6_2020() {
    ifstream file("day6_2020");
    string str;
    int totalResult = 0;
    char letter;
    int num1;
    int num2;
    char tab[2191][1000];
    int size = 0;
    while (size < 2191) {
//stringstream ss(str);
//ss>>tab[size];
        file.getline(tab[size], sizeof(tab[size]));
        tab[size][strlen(tab[size])] = '!';
//getline(file,tab[size]);
        size++;
    }
/*
bool a[26]={false};
int totalResult2[1000]={0};
int size2=0;
for(int i=0;i<size;i++){
    if(tab[i][0]=='!'){
        for(int j=0;j<26;j++){
            if(a[j]){
                totalResult2[size2]++;
                a[j]=false;
            }
        }
        totalResult=totalResult+totalResult2[size2];
        size2++;
    }
    else{
        int j=0;
        while(tab[i][j]!='!'){
            a[tab[i][j] - 97]=true;
            j++;
        }
    }
}

for(int j=0;j<26;j++){
    if(a[j]){
        totalResult2[size2]++;
        a[j]=false;
    }
}
totalResult=totalResult+totalResult2[size2];
*/

    int a[26] = {0};
    int totalResult2[1000] = {0};
    int size2 = 0;
    int nb = 0;

    for (int i = 0; i < size; i++) {
        bool b[26] = {false};
        if (tab[i][0] == '!') {
            for (int j = 0; j < 26; j++) {
                if (a[j] == nb) {
                    totalResult2[size2]++;
                }
                a[j] = 0;
            }
            nb = 0;
            totalResult = totalResult + totalResult2[size2];
            size2++;
        } else {
            nb++;
            int j = 0;
            while (tab[i][j] != '!') {
                if (b[tab[i][j] - 97] == false) {
                    a[tab[i][j] - 97]++;
                    b[tab[i][j] - 97] = true;
                }
                j++;
            }
        }
    }
    cout << "Result is " << totalResult << endl;
}


//2020 Exercice 9 (2 stars)

void Ex9_2020() {
    int totalResult = 0;

    ifstream file("day9_2020");
    string str;
    int x = 0;
    int tab[1000] = {0};
    int size = 0;
    while (getline(file, str)) {
        stringstream ss(str);
        ss >> tab[size];

        size++;
    }
    for (int i = 26; i < size; i++) {
        bool res = false;
        for (int j = 0; j < i; j++) {
            for (int k = j; k < i; k++) {
                if (tab[i] == tab[j] + tab[k]) {
                    res = true;
                }
            }
        }
        if (res == false) {
            double a = tab[i];
            for (int j = 0; j < i; j++) {
                double b = 0;
                int t = 0;
                while (b < a) {
                    b = b + tab[j + t];
                    t++;
                }
                if (b == a) {
                    int min = tab[j];
                    int max = tab[j];
                    for (int k = 0; k < t; k++) {
                        if (min > tab[k]) {
                            min = tab[k];
                        }
                        if (max < tab[k]) {
                            max = tab[k];
                        }
                    }
                    totalResult = min + max;
                    cout << "Result is " << totalResult << endl;
                    return;
                }
            }

        }
    }
}


//2020 Exercice 11 (2 stars)

void Ex11_2020() {
    ifstream file("day11_2020");

    string str;
    double totalResult = 0;
    char tab[97][98] = {0};
    int size = 0;
    int hauteur = 97;
    int largeur = 98;
    while (getline(file, str)) {
        stringstream ss(str);
        ss >> (tab[size]);
        size++;
    }
    char tab2[97][98][800] = {0};
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            tab2[i][j][0] = tab[i][j];
        }
    }
    bool change = true;
    int nchangement = 0;
    while (change == true) {
        cout << endl;
        cout << endl;
        cout << endl;
        change = false;
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                tab2[i][j][nchangement + 1] = tab2[i][j][nchangement];
                if (tab2[i][j][nchangement] == '#') {
                    int num = 0;
/*for(int k=i-1;k<i+2;k++){
    for(int m=j-1;m<j+2;m++){
        if(k>-1&&m>-1&&k<hauteur&&m<largeur&&tab2[k][m][nchangement]=='#'){
            num++;
        }
    }
}
if(num>=5){
    tab2[i][j][nchangement+1]='L';
    change=true;
}*/
                    int k = i - 1;
                    int m = j - 1;
                    while (tab2[k][m][nchangement] == '.' && k > -1 && m > -1) {
                        k--;
                        m--;
                    }
                    if (k > -1 && m > -1 && tab2[k][m][nchangement] == '#') {
                        num++;
                    }
                    k = i - 1;
                    m = j;
                    while (tab2[k][m][nchangement] == '.' && k > -1) {
                        k--;
                    }
                    if (k > -1 && tab2[k][m][nchangement] == '#') {
                        num++;
                    }
                    k = i - 1;
                    m = j + 1;
                    while (tab2[k][m][nchangement] == '.' && k > -1 && m < largeur) {
                        k--;
                        m++;
                    }
                    if (k > -1 && m < largeur && tab2[k][m][nchangement] == '#') {
                        num++;
                    }
                    k = i;
                    m = j - 1;
                    while (tab2[k][m][nchangement] == '.' && m > -1) {
                        m--;
                    }
                    if (m > -1 && tab2[k][m][nchangement] == '#') {
                        num++;
                    }

                    k = i;
                    m = j + 1;
                    while (tab2[k][m][nchangement] == '.' && m < largeur) {
                        m++;
                    }
                    if (m < largeur && tab2[k][m][nchangement] == '#') {
                        num++;
                    }
                    k = i + 1;
                    m = j - 1;
                    while (m > -1 && k < hauteur && tab2[k][m][nchangement] == '.') {
                        k++;
                        m--;
                    }
                    if (k < hauteur && m > -1 && tab2[k][m][nchangement] == '#') {
                        num++;
                    }

                    k = i + 1;
                    m = j + 1;
                    while (m < largeur && k < hauteur && tab2[k][m][nchangement] == '.') {
                        k++;
                        m++;
                    }
                    if (m < largeur && k < hauteur && tab2[k][m][nchangement] == '#') {
                        num++;
                    }
                    k = i + 1;
                    m = j;
                    while (k < hauteur && tab2[k][m][nchangement] == '.') {
                        k++;
                    }
                    if (k < hauteur && tab2[k][m][nchangement] == '#') {
                        num++;
                    }
                    if (num >= 5) {
                        tab2[i][j][nchangement + 1] = 'L';
                        change = true;
                    }
                }
                if (tab2[i][j][nchangement] == 'L') {
                    bool num = true;
/*for(int k=i-1;k<i+2;k++){
    for(int m=j-1;m<j+2;m++){
        if(k>-1&&m>-1&&k<hauteur&&m<largeur&&tab2[k][m][nchangement]=='#'){
            num=false;
        }
    }
}*/

                    int k = i - 1;
                    int m = j - 1;
                    while (tab2[k][m][nchangement] == '.' && k > -1 && m > -1) {
                        k--;
                        m--;
                    }
                    if (k > -1 && m > -1 && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }
                    k = i - 1;
                    m = j;
                    while (k > -1 && tab2[k][m][nchangement] == '.') {
                        k--;
                    }
                    if (k > -1 && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }
                    k = i - 1;
                    m = j + 1;
                    while (k > -1 && m < largeur && tab2[k][m][nchangement] == '.') {
                        k--;
                        m++;
                    }
                    if (k > -1 && m < largeur && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }
                    k = i;
                    m = j - 1;
                    while (m > -1 && tab2[k][m][nchangement] == '.') {
                        m--;
                    }
                    if (m > -1 && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }

                    k = i;
                    m = j + 1;
                    while (m < largeur && tab2[k][m][nchangement] == '.') {
                        m++;
                    }
                    if (m < largeur && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }
                    k = i + 1;
                    m = j - 1;
                    while (m > -1 && k < hauteur && tab2[k][m][nchangement] == '.') {
                        k++;
                        m--;
                    }
                    if (k < hauteur && m > -1 && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }

                    k = i + 1;
                    m = j + 1;
                    while (m < largeur && k < hauteur && tab2[k][m][nchangement] == '.') {
                        k++;
                        m++;
                    }
                    if (m < largeur && k < hauteur && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }
                    k = i + 1;
                    m = j;
                    while (k < hauteur && tab2[k][m][nchangement] == '.') {
                        k++;
                    }
                    if (k < hauteur && tab2[k][m][nchangement] == '#') {
                        num = false;
                    }


                    if (num == true) {
                        tab2[i][j][nchangement + 1] = '#';
                        change = true;
                    }
                }
            }
        }
        nchangement++;
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                cout << tab2[i][j][nchangement] << "   ";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (tab2[i][j][nchangement - 1] == '#') {
                totalResult++;
            }
        }
    }
    cout << "Result is " << totalResult << endl;
}


//2020 Exercice 15 (2 stars)

void Ex15_2020() {
    int size_dep = 6;//6
    int size = 7;//7
//int tab[2020]={0};
    int *tab = new int[99999999];
    for (int i = 0; i < 99999999; i++) {
        tab[i] = 0;
    }
    int totalResult = 0;
    tab[0] = 1;
    tab[13] = 2;
    tab[16] = 3;
    tab[17] = 4;
    tab[1] = 5;
    tab[10] = 6;

    int a = 6;
    for (int i = size_dep; i < 29999999; i++) {
        if (tab[a] != 0) {
            int b = tab[a];
            tab[a] = size;
            a = size - b;
        } else {
            tab[a] = size;
            a = 0;
        }
        size++;
    }
    totalResult = a;
    delete[] tab;
/*
int a;
for(int i=size_dep;i<2020;i++){
    a=0;
    bool unique=true;
    for(int j=0;j<i;j++){
        if(tab[j]==tab[i]){
            unique=false;
            a=j;
        }
    }
    if(unique==true){
        tab[size]=0;
    }
    else{
        tab[size]=i-a;
    }
    size++;
}
totalResult=tab[2019];
*/
}


//2020 Exercice 4 (2 stars)

void Ex4_2020(){
    ifstream file("day4_2020");
    string str;
    int totalResult = 0;
    char tab[1133][1000];
    int size = 0;
    while (size < 1133) {
        file.getline(tab[size], sizeof(tab[size]));
        tab[size][strlen(tab[size])] = '!';
        size++;
    }
    /*
    day4_2020 Passeport;
    for(int i=0;i<size;i++){
        if(tab[i][0]=='!'){
            if(Passeport.valid1()){
                totalResult++;
            }
            Passeport.reset();
        }
        else{
            int j=0;
            while(tab[i][j]!='!'){
                if(tab[i][j]=='e'){
                    if((tab[i][j+1]=='y')&&(tab[i][j+2]=='r')){
                        Passeport.eyr=1;
                    }
                    if((tab[i][j+1]=='c')&&(tab[i][j+2]=='l')){
                        Passeport.ecl=1;
                    }
                }
                if((tab[i][j]=='p')&&(tab[i][j+1]=='i')&&(tab[i][j+2]=='d')) {
                    Passeport.pid=1;
                }
                if(tab[i][j]=='h') {
                    if((tab[i][j+1]=='c')&&(tab[i][j+2]=='l')){
                        Passeport.hcl=1;
                    }
                    if((tab[i][j+1]=='g')&&(tab[i][j+2]=='t')){
                        Passeport.hgt=1;
                    }
                }
                if((tab[i][j]=='i')&&(tab[i][j+1]=='y')&&(tab[i][j+2]=='r')) {
                    Passeport.iyr=1;
                }
                if((tab[i][j]=='b')&&(tab[i][j+1]=='y')&&(tab[i][j+2]=='r')) {
                    Passeport.byr=1;
                }
                j++;
            }
        }
    }
    if(Passeport.valid1()){
        totalResult++;
    }*/
    int passvalid[200] = {0};
    int valid = 0;
    int pass = 0;

    day4_2020 tabpasseportval[200];

    day4_2020 Passeport;
    Passeport.reset2();
    for (int i = 0; i < size; i++) {
        if (tab[i][0] == '!') {
            pass++;
            if (Passeport.valid2()) {
                passvalid[valid] = pass;
                tabpasseportval[valid] = Passeport;
                valid++;
                totalResult++;
            }
            Passeport.reset2();
        } else {
            int j = 0;
            while (tab[i][j] != '!' && tab[i][j - 1] != '!') {
                if (tab[i][j] == 'e') {
                    if ((tab[i][j + 1] == 'y') && (tab[i][j + 2] == 'r')) {
                        j = j + 4;
                        while (tab[i][j] != ' ' && tab[i][j] != '!') {
                            Passeport.eyr = Passeport.eyr * 10 + tab[i][j] - 48;
                            j++;
                        }
                    }
                    if ((tab[i][j + 1] == 'c') && (tab[i][j + 2] == 'l')) {
                        j = j + 4;
                        while (tab[i][j] != ' ' && tab[i][j] != '!') {
                            Passeport.ecl2[Passeport.nbecl2] = tab[i][j];
                            Passeport.nbecl2++;
                            j++;
                        }
                        Passeport.ecl2[Passeport.nbecl2] = '!';
                    }
                }
                if ((tab[i][j] == 'p') && (tab[i][j + 1] == 'i') && (tab[i][j + 2] == 'd')) {
                    j = j + 4;
                    while (tab[i][j] != ' ' && tab[i][j] != '!') {
                        Passeport.pid2[Passeport.nbpid2] = tab[i][j];
                        Passeport.nbpid2++;
                        j++;
                    }
                    Passeport.pid2[Passeport.nbpid2] = '!';
                }
                if (tab[i][j] == 'h') {
                    if ((tab[i][j + 1] == 'c') && (tab[i][j + 2] == 'l')) {
                        j = j + 4;
                        while (tab[i][j] != ' ' && tab[i][j] != '!') {
                            Passeport.hcl2[Passeport.nbhcl2] = tab[i][j];
                            Passeport.nbhcl2++;
                            j++;
                        }
                        Passeport.hcl2[Passeport.nbhcl2] = '!';
                    }
                    if ((tab[i][j + 1] == 'g') && (tab[i][j + 2] == 't')) {
                        j = j + 4;
                        while (tab[i][j] != ' ' && tab[i][j] != '!' && tab[i][j] != 'i' && tab[i][j] != 'c') {
                            Passeport.hgt = Passeport.hgt * 10 + tab[i][j] - 48;
                            j++;
                        }
                        while (tab[i][j] != ' ' && tab[i][j] != '!') {
                            Passeport.hgt_unite[Passeport.hgt_unites] = tab[i][j];
                            Passeport.hgt_unites++;
                            j++;
                        }
                        Passeport.hgt_unite[Passeport.hgt_unites] = '!';
                    }
                }
                if ((tab[i][j] == 'i') && (tab[i][j + 1] == 'y') && (tab[i][j + 2] == 'r')) {
                    j = j + 4;
                    while (tab[i][j] != ' ' && tab[i][j] != '!') {
                        Passeport.iyr = Passeport.iyr * 10 + tab[i][j] - 48;
                        j++;
                    }
                }
                if ((tab[i][j] == 'b') && (tab[i][j + 1] == 'y') && (tab[i][j + 2] == 'r')) {
                    j = j + 4;
                    while (tab[i][j] != ' ' && tab[i][j] != '!') {
                        Passeport.byr = Passeport.byr * 10 + tab[i][j] - 48;
                        j++;
                    }
                }
                j++;
            }
        }
    }
    if (Passeport.valid2()) {
        totalResult++;
    }
}

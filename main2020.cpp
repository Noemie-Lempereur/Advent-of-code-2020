
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include <cstring>
#include <map>
#include "day4_2020.h"
#include "Fonctions_auxiliaires.h"

using namespace std;
int totalResult=0;

int main(){

 /*   ifstream file("day24_2020");
    string str;
    int totalResult=0;
    char tab[400][500]={0};
    int x_depart=500;   //500
    int y_depart=500;
    int x=x_depart;
    int y=y_depart;
    int s=1000;"
    bool tabrep[1000][1000]={false};    //1000
    int size=0;
    while(size<322){   //322 20
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        size++;
    }
    for(int i=0;i<size;i++){
        int j=0;
        while(tab[i][j]!='!'){
            if(tab[i][j]=='e'){
                x=x-2;
            }
            if(tab[i][j]=='w'){
                x=x+2;
            }
            if(tab[i][j]=='n'&&tab[i][j+1]=='e'){
                j=j+1;
                x=x-1;
                y=y+1;
            }
            if(tab[i][j]=='n'&&tab[i][j+1]=='w'){
                j=j+1;
                x=x+1;
                y=y+1;
            }
            if(tab[i][j]=='s'&&tab[i][j+1]=='e'){
                j=j+1;
                x=x-1;
                y=y-1;
            }
            if(tab[i][j]=='s'&&tab[i][j+1]=='w'){
                j=j+1;
                x=x+1;
                y=y-1;
            }
            j++;
        }
        if(tabrep[x][y]==false){
            tabrep[x][y]=true;
        }else{
            tabrep[x][y]=false;
        }
        x=x_depart;
        y=y_depart;
        if(tabrep[x][y]==false){
            tabrep[x][y]=true;
        }else{
            tabrep[x][y]=false;
        }
        x=x_depart;
        y=y_depart;
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(tabrep[i][j]==true){
                totalResult++;
            }
        }
    }
    bool tabrep2[1000][1000]={false};
    for(int i=0;i<100;i++) {
        totalResult = 0;
        for (int j = 0; j < s; j = j + 2) {
            for (int k = 0; k < s; k = k + 2) {
                if (tabrep[j][k] == false) {
                    int numblack = 0;
                    if (j > 0 && k > 0 && tabrep[j - 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j > 0 && k < s-1 && tabrep[j - 1][k + 1] == true) {
                        numblack++;
                    }
                    if (k < s-2 && tabrep[j][k + 2] == true) {
                        numblack++;
                    }
                    if (k > 1 && tabrep[j][k - 2] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k > 0 && tabrep[j + 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k < s-1 && tabrep[j + 1][k + 1] == true) {
                        numblack++;
                    }
                    if (numblack == 2) {
                        tabrep2[j][k] = true;
                    } else {
                        tabrep2[j][k] = false;
                    }
                } else {
                    int numblack = 0;
                    if (j > 0 && k > 0 && tabrep[j - 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j > 0 && k < s-1 && tabrep[j - 1][k + 1] == true) {
                        numblack++;
                    }
                    if (k < s-2 && tabrep[j][k + 2] == true) {
                        numblack++;
                    }
                    if (k > 1 && tabrep[j][k - 2] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k > 0 && tabrep[j + 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k < s-1 && tabrep[j + 1][k + 1] == true) {
                        numblack++;
                    }
                    if (numblack == 1||numblack==2) {
                        tabrep2[j][k] = false;
                    } else {
                        tabrep2[j][k] = true;
                    }
                }

            }

        }
        for (int j = 1; j < s; j = j + 2) {
            for (int k = 1; k < s; k = k + 2) {
                if (tabrep[j][k] == false) {
                    int numblack = 0;
                    if (j > 0 && k > 0 && tabrep[j - 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j > 0 && k < s-1 && tabrep[j - 1][k + 1] == true) {
                        numblack++;
                    }
                    if (k < s-2 && tabrep[j][k + 2] == true) {
                        numblack++;
                    }
                    if (k > 1 && tabrep[j][k - 2] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k > 0 && tabrep[j + 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k < s-1 && tabrep[j + 1][k + 1] == true) {
                        numblack++;
                    }
                    if (numblack == 2) {
                        tabrep2[j][k] = true;
                    } else {
                        tabrep2[j][k] = false;
                    }
                } else {
                    int numblack = 0;
                    if (j > 0 && k > 0 && tabrep[j - 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j > 0 && k < s-1 && tabrep[j - 1][k + 1] == true) {
                        numblack++;
                    }
                    if (k < s-2 && tabrep[j][k + 2] == true) {
                        numblack++;
                    }
                    if (k > 1 && tabrep[j][k - 2] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k > 0 && tabrep[j + 1][k - 1] == true) {
                        numblack++;
                    }
                    if (j < s-1 && k < s-1 && tabrep[j + 1][k + 1] == true) {
                        numblack++;
                    }
                    if (numblack == 1||numblack==2) {
                        tabrep2[j][k] = false;
                    } else {
                        tabrep2[j][k] = true;
                    }
                }
            }
        }
        for(int j=0;j<s;j++){
            for(int k=0;k<s;k++){
                tabrep[j][k]=tabrep2[j][k];
                tabrep2[j][k]=false;
            }
        }
        for(int m=0;m<s;m++) {
            for (int j = 0; j < s; j++) {
                if (tabrep[m][j] == true) {
                    totalResult++;
                }
            }
        }
    }
    totalResult=0;
    for(int i=0;i<s;i++) {
        for (int j = 0; j < s; j++) {
            if (tabrep[i][j] == true) {
                totalResult++;
            }
        }
    }       //4000 too high , 6947 too high
*/
    /*
    int player1[50]={0};
    int player2[50]={0};
    int size1=0;
    int size2=0;
    ifstream file("day22_2020");
    string str;
    int totalResult = 0;
    getline(file,str);
    for(int i=1;i<26;i++){
        getline(file,str);
        stringstream ss(str);
        ss>>player1[size1];
        size1++;
    }
    getline(file,str);
    getline(file,str);
    for(int i=1;i<26;i++){
        getline(file,str);
        stringstream ss(str);
        ss>>player2[size2];
        size2++;
    }
    while (size2!=0&&size1!=0){
        int min;
        int max;
        if(player1[0]<player2[0]){
            min=player1[0];
            max=player2[0];
            for(int i=1;i<size1;i++){
                player1[i-1]=player1[i];
            }
            size1--;
            for(int i=1;i<size2;i++){
                player2[i-1]=player2[i];
            }
            player2[size2-1]=max;
            player2[size2]=min;
            size2++;
        }else{
            min=player2[0];
            max=player1[0];
            for(int i=1;i<size2;i++){
                player2[i-1]=player2[i];
            }
            size2--;
            for(int i=1;i<size1;i++){
                player1[i-1]=player1[i];
            }
            player1[size1-1]=max;
            player1[size1]=min;
            size1++;
        }
    }
    if(size1==50){
        for(int i=0;i<50;i++){
            totalResult=totalResult+(player1[i]*(50-i));
        }
    }else {
        for (int i = 0; i < 50; i++) {
            totalResult = totalResult + (player2[i] * (50 - i));
        }
    }
*/



    /*
    ifstream file("day10_2020");
        string str;
        int x = 0;
        int totalResult = 0;
        int tab[100]={0};
        int size=0;
        int occurence[4]={0};
        while(getline(file,str)){
            stringstream ss(str);
            ss>>tab[size];

            size++;
        }
        Tri_Selection(tab,100);
        for(int i=0;i<100;i++){
            occurence[tab[i+1]-tab[i]]++;
        }
        occurence[3]++;
        totalResult=occurence[1]*occurence[3];
        cout<<"Result is "<<totalResult<<endl;  //2178 too low

*/

    /*
    ifstream file("day7_2020_300.txt");
    string str;
    int totalResult = 0;
    char tab[600][500]={0};
    int size=0;
    char bags[600][300]={0};
    strcpy(bags[0], "shiny gold!");
    int sizebags=1;
    char attente[600][300]={0};
    strcpy(attente[0], "shiny gold!");
    int sizeattente=2;
    while(size<594){    //594
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        size++;
    }
    while(sizeattente!=0) {
        bool trouve = false;
        int i = 0;
        int j=0;
        while (trouve == false&&i<size){
            if(attente[sizeattente-1][j]=='!'){
                trouve=true;
                sizeattente--;
            }
            if(attente[sizeattente-1][j]!=tab[i][j]&&trouve==false){
                i++;
                j=-1;
            }
            j++;
            if(i==size){
                sizeattente--;
            }
        }
        if(trouve==true){
            while (tab[i][j-6]!='c'||tab[i][j-5]!='o'||tab[i][j-4]!='n'||tab[i][j-3]!='t'||tab[i][j-2]!='a'||tab[i][j-1]!='i'||tab[i][j]!='n'){
                j++;
            }
            j=j+4;
            int h=0;
            bool vide =false;
            if (tab[i][j]==' '&&tab[i][j+1]=='o'&&tab[i][j+2]=='t'&&tab[i][j+3]=='h'&&tab[i][j+4]=='e'&&tab[i][j+5]=='r'){
                vide=true;
            }
            while (tab[i][j]!='.'&&vide==false){
                    if (tab[i][j] == ',') {
                        bool ident = false;
                        for (int m = 0; m < sizebags; m++) {
                            bool id=true;
                            int n=0;
                            while(attente[sizeattente][n]!=' '||attente[sizeattente][n+1]!='b'||attente[sizeattente][n+2]!='a'||attente[sizeattente][n+3]!='g'){
                                if (bags[m][n] != attente[sizeattente][n]) {
                                    id= false;
                                }
                                n++;
                            }
                            if(id==true){
                                ident=true;
                            }
                        }
                        attente[sizeattente][h] = '!';
                        j = j + 4;
                        h = 0;
                        if (ident == false) {
                            int r = 0;
                            while (attente[sizeattente][r] != ' ' || attente[sizeattente][r + 1] != 'b' ||
                                   attente[sizeattente][r + 2] != 'a' || attente[sizeattente][r + 3] != 'g') {
                                r++;
                            }
                            for (int z = 0; z < r; z++) {
                                bags[sizebags][z] = attente[sizeattente][z];
                            }
                            bags[sizebags][r] = '!';
                            sizebags++;
                            sizeattente++;
                        }
                    } else {
                        attente[sizeattente][h] = tab[i][j];
                        h++;
                        j++;
                    }
            }
            if(vide==false) {
                bool ident = false;
                for (int m = 0; m < sizebags; m++) {
                    bool id=true;
                    int n=0;
                    while(attente[sizeattente][n]!=' '||attente[sizeattente][n+1]!='b'||attente[sizeattente][n+2]!='a'||attente[sizeattente][n+3]!='g'){
                        if (bags[m][n] != attente[sizeattente][n]) {
                            id= false;
                        }
                        n++;
                    }
                    if(id==true){
                        ident=true;
                    }
                }
                attente[sizeattente][h] = '!';
                j = j + 4;
                h = 0;
                if (ident == false) {
                    int r = 0;
                    while (attente[sizeattente][r] != ' ' || attente[sizeattente][r + 1] != 'b' ||
                           attente[sizeattente][r + 2] != 'a' || attente[sizeattente][r + 3] != 'g') {
                        r++;
                    }
                    for (int z = 0; z < r; z++) {
                        bags[sizebags][z] = attente[sizeattente][z];
                    }
                    bags[sizebags][r] = '!';
                    sizebags++;
                    sizeattente++;
                }
            }
        }
    }
    totalResult=sizebags-1;
    for(int i=0;i<sizebags;i++){
        cout<<bags[i]<<endl;
    }

     */
    /*
    char bags2[600][300]={0};
    int sizebags2=0;
    char testbag[30]="";
    for(int i=0;i<sizebags;i++){
        int j=0;
        int v=0;
        while(bags[i][j]!=' '){
            j++;
        }
        j++;
        while(bags[i][j]!='!'){
            testbag[v]=bags[i][j];
            j++;
            v++;
        }
        testbag[v]='!';
        bool pareil =false;
        for(int h=0;h<sizebags2;h++){
            int r=0;
            while(bags[i][r]!=' '){
                r++;
            }
            r++;
            bool par=false;
            if(testbag[v]==)
        }

    }*/

    /*

    ifstream file("day16_2020");
    string str;
    int totalResult = 0;
    char tab[300][200]={0};
    bool tab2[1000]={false};
    int size=0;
    int ticket[100]={0};
    int newtab[300][100]={0};
    while(size<267){
        //stringstream ss(str);
        //ss>>tab[size];
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        //getline(file,tab[size]);
        size++;
    }
    bool tabmauvais[1000]={false};
    for(int i=0;i<20;i++){
        int j=0;
        int k=0;
        while(tab[i][j]!=':'){
            j++;
        }
        j=j+2;
        int a=0;
        int b=0;
        while(tab[i][j]!='-'){
            a=a*10+tab[i][j]-48;
            j++;
        }
        j=j+1;
        while(tab[i][j]!=' '){
            b=b*10+tab[i][j]-48;
            j++;
        }
        for(int m=a;m<=b;m++){
            tab2[m]=true;
        }
        j=j+4;
        a=0;
        b=0;
        while(tab[i][j]!='-'){
            a=a*10+tab[i][j]-48;
            j++;
        }
        j=j+1;
        while(tab[i][j]!='!'){
            b=b*10+tab[i][j]-48;
            j++;
        }
        for(int m=a;m<=b;m++){
            tab2[m]=true;
        }
    }
    for(int i=25;i<size;i++){
        int j=0;
        int a=0;
        while(tab[i][j]!='!'){
            if(tab[i][j]!=',') {
                a = a * 10 + tab[i][j] - 48;
            }else{
                if(tab2[a]==false){
                    totalResult=totalResult+a;
                    tabmauvais[i]=true;
                }
                a=0;
            }
            j++;
        }
        if(tab2[a]==false){
            totalResult=totalResult+a;
            tabmauvais[i]=true;
        }
        a=0;
    }

    totalResult=0;
    int sizebon=0;
    bool tabpart2[1000]={false};
    int j=0;
    int n=15;
    cout<<n<<endl;*/
    /*
     * 0->2,5,13                127
     * 1->8,15          NON
     * 2->14            NON
     * 3->2,5,13        ?   197
     * 4->2,5           OUI
     * 5->8,15          NON
     * 6->3,9,10,17,18          71
     * 7->3,9,18        ?   131
     * 8->16            NON
     * 9->9,18          NON
     * 10->7            NON
     * 11-> 1           OUI
     * 12->4            OUI
     * 13->20           NON
     * 14->3,9,10,11,17,18      53
     * 15->3,9,10,11,17,18      89
     * 16->6            OUI
     * 17->12           NON
     * 18->19           NON
     * 19->3,9,17,18            167
     * 4033640701273 too high
     *
     * 4797860895623
     *
     * 288384979
    *//*
    while(tab[n][j]!=':'){
        j++;
    }
    j=j+2;
    int a=0;
    int b=0;
    while(tab[n][j]!='-'){
        a=a*10+tab[n][j]-48;
        j++;
    }
    j=j+1;
    while(tab[n][j]!=' '){
        b=b*10+tab[n][j]-48;
        j++;
    }
    for(int m=a;m<=b;m++){
        tabpart2[m]=true;
    }
    j=j+4;
    a=0;
    b=0;
    while(tab[n][j]!='-'){
        a=a*10+tab[n][j]-48;
        j++;
    }
    j=j+1;
    while(tab[n][j]!='!'){
        b=b*10+tab[n][j]-48;
        j++;
    }
    for(int m=a;m<=b;m++){
        tabpart2[m]=true;
    }
    tabmauvais[23]=true;
    tabmauvais[24]=true;
    for(int i=22;i<size;i++) {
        if(tabmauvais[i]==false) {
            int h = 0;
            int r = 0;
            int c=0;
            while (tab[i][h] != '!') {
                if (tab[i][h] != ',') {
                    r = r *10+tab[i][h]-48;
                }
                else{
                    newtab[sizebon][c]=r;
                    c++;
                    r=0;
                }
                h++;
            }
            newtab[sizebon][c]=r;
            sizebon++;
        }
    }
    bool possi[20][20]={true};
    for(int y=0;y<20;y++) {
        cout <<y+1<<endl;
        for (int i = 0; i < sizebon-1; i++) {
            if (!tabpart2[newtab[i][y]]) {
                cout << i<<" NON     " << newtab[i][y]<<endl;
            }
        }
        cout<<"--------------"<<endl;
    }
    int g=0;
    return 0;

   /*
    ifstream file("day13_2020");
    string str;
    int totalResult = 0;
    char tab[2][200]={0};
    int tab2[200]={0};
    int size=0;
    int size2=0;
    while(size<2){
        //stringstream ss(str);
        //ss>>tab[size];
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        //getline(file,tab[size]);
        size++;
    }
    double time=0;
    int k=0;
    while (tab[0][k]!='!'){
        time=time*10+tab[0][k]-48;
        k++;
    }
    k=0;
    int num=0;
    while (tab[1][k]!='!'){
        if(tab[1][k]==','){
            if(num!=0) {
                tab2[size2] = num;
                size2++;
                num = 0;
            }
        }else {
            if (tab[1][k] != 'x') {
                num=num*10+tab[1][k]-48;
            }
        }
        k++;
    }
    if(num!=0) {
        tab2[size2] = num;
        size2++;
        num = 0;
    }
    int idmin=0;
    int wait=time;
    for(int i=0;i<size2;i++){
        int intermed=i;
        int j=0;
        int waiting=0;
        while(intermed<time){
            intermed=intermed+tab2[i];
            j++;
        }
        waiting=intermed-time;
        if(waiting<wait){
            wait=waiting;
            idmin=tab2[i];
        }
    }
    totalResult=wait*idmin;

   */

    /*
    ifstream file("day12_2020");
    string str;
    int totalResult=0;
    int east=0;
    int north=0;
    char tab[778][10]={0};
    int size=0;
    while(size<778){
        //stringstream ss(str);
        //ss>>tab[size];
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        //getline(file,tab[size]);
        size++;
    }*/


    /*
    int direction=1;   //0=north    1=east  2=south     3=west
    for(int i=0;i<778;i++){
        if(tab[i][0]=='N'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            north=north+a;
        }
        if(tab[i][0]=='S'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            north=north-a;
        }
        if(tab[i][0]=='E'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            east=east+a;
        }
        if(tab[i][0]=='W'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            east=east-a;
        }
        if(tab[i][0]=='L'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            a=a/90;
            for(int k=0;k<a;k++) {
                direction = (direction+3) % 4;
            }
        }
        if(tab[i][0]=='R'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            a=a/90;
            for(int k=0;k<a;k++) {
                direction = (direction + 1) % 4;
            }
        }
        if(tab[i][0]=='F'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            if(direction==0){
                north=north+a;
            }
            if(direction==1){
                east=east+a;
            }
            if(direction==2){
                north=north-a;
            }
            if(direction==3){
                east=east-a;
            }
        }
    }
    if(north<0){
        north=-north;
    }
    if(east<0){
        east=-east;
    }*/
/*
    int waypointNorth=1;
    int waypointEast=10;
    for(int i=0;i<778;i++){
        if(tab[i][0]=='N'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            waypointNorth=waypointNorth+a;
        }
        if(tab[i][0]=='S'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            waypointNorth=waypointNorth-a;
        }
        if(tab[i][0]=='E'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            waypointEast=waypointEast+a;
        }
        if(tab[i][0]=='W'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            waypointEast=waypointEast-a;
        }
        if(tab[i][0]=='L'){
            int j=1;
            int a=0;
            int n=waypointNorth;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            a=a/90;
            for(int k=0;k<a;k++) {
                waypointNorth=waypointEast;
                waypointEast=-n;
            }
        }
        if(tab[i][0]=='R'){
            int j=1;
            int a=0;
            int e=waypointEast;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            a=a/90;
            for(int k=0;k<a;k++) {
                waypointEast=waypointNorth;
                waypointNorth=-e;
            }
        }
        if(tab[i][0]=='F'){
            int j=1;
            int a=0;
            while (tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            for(int k=0;k<a;k++) {
                north=north+waypointNorth;
                east=east+waypointEast;
            }
        }
    }
    if(north<0){
        north=-north;
    }
    if(east<0){
        east=-east;
    }
    totalResult=north+east; //50000 too low  55000 too high
int a=0;

*/


    /*
    ifstream file("day14_2020");
    string str;
    double totalResult = 0;
    char tab[1000][1000];
    int size=0;
    char tab2[36]={'X'};
    int tab3[36];
    double tab4[100000]={0};
    while(size<565){
        //stringstream ss(str);
        //ss>>tab[size];
        file.getline (tab[size], sizeof (tab[size]));
        tab[size][strlen(tab[size])]='!';
        //getline(file,tab[size]);
        size++;
    }
    for(int i=0;i<565;i++){
        if(tab[i][1]=='a'){
            for(int j=0;j<36;j++){
                tab2[j]=tab[i][j+7];
            }
        }
        else{
            for(int k=0;k<36;k++){
                tab3[k]=0;
            }
            int j=0;
            int a=0;
            while(tab[i][j]!='='){
                j++;
            }
            j=j+2;
            while(tab[i][j]!='\r'&&tab[i][j]!='!'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            nombreToBinaire(a,tab3);
            for(int m=0;m<36;m++){
                if(tab2[m]-48==0){
                    tab3[m]=0;
                }
                if(tab2[m]-48==1){
                    tab3[m]=1;
                }
            }
            double b;
            b=binaireToNombre(tab3);
            j=0;
            a=0;
            while(tab[i][j]!='['){
                j++;
            }
            j=j+1;
            while(tab[i][j]!=']'){
                a=a*10+tab[i][j]-48;
                j++;
            }
            tab4[a]=b;
        }

    }
    for(int i=0;i<100000;i++){
        totalResult=totalResult+tab4[i];
    }
    */





/*
    ifstream file("day8_2020_test");
    string str;
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
    int jump=0;
    int parcours[642]={0};
    int size_p=0;
    bool tab2[641]={false};
    for(int i=0;i<642;i++){
        parcours[size_p]=i;
        size_p++;
        if(tab2[i]==false) {
            tab2[i] = true;
            if (tab[i][0] == 'a') {
                int j = 5;
                float a = 0;
                bool positif = true;
                if (tab[i][4] == '-') {
                    positif = false;
                }
                while (tab[i][j] != '\r'&&tab[i][j] != '!') {
                    if (positif == true) {
                        a = a * 10 + tab[i][j]-48;
                    } else {
                        a = a * 10 - tab[i][j]+48;
                    }
                    j++;
                }
                totalResult = totalResult + a;
            }
            if (tab[i][0] == 'j') {
                bool positif = true;
                if (tab[i][4] == '-') {
                    positif = false;
                }
                float a = 0;
                int j=5;
                while (tab[i][j] != '\r'&&tab[i][j] != '!') {
                    if (positif == true) {
                        a = a * 10 + tab[i][j]-48;
                    } else {
                        a = a * 10 - tab[i][j]+48;
                    }
                    j++;
                }
                i=i+a-1;
            }
        }
        else{
            cout<<"Result is "<<totalResult<<endl;
            return 0;
        }
    }
*/


    cout<<"Result is "<<totalResult<<endl;
    return 0;
}


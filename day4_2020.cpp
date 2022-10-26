
#include <cstring>
#include "day4_2020.h"

bool day4_2020::valid1() {
    if((eyr!=-1)&&(pid!=-1)&&(byr!=-1)&&(ecl!=-1)&&(hcl!=-1)&&(iyr!=-1)&&(hgt!=-1)){
        return true;
    }
    return false;
}

void day4_2020::reset2() {
    eyr=0;
    pid=0;
    byr=0;
    ecl=0;
    hcl=0;
    iyr=0;
    hgt=0;
    cid=0;
    hgt_unites=0;
    nbhcl2=0;
    nbecl2=0;
    nbpid2=0;
    for(int i=0;i<20;i++){
        hcl2[i]='?';
        ecl2[i]='?';
        hgt_unite[i]='?';
        pid2[i]='?';
    }
}

bool day4_2020::valid2() {
    int total=0;

    if(eyr>=2020&&eyr<=2030){
        total++;
    }

    bool pidok=true;
    for(int i=0;i<9;i++){
        if(pid2[i]-48<0&&pid2[i]-48>9){
            pidok= false;
        }
    }
    if(pid2[9]!='!'){
        pidok= false;
    }
    if(pidok== true){
        total++;
    }

    if(byr>=1920&&byr<=2002){
        total++;
    }

    if(ecl2[3]=='!'){
        if(ecl2[0]=='a'&&ecl2[1]=='m'&&ecl2[2]=='b'){
            total++;
        }
        if(ecl2[0]=='b'&&ecl2[1]=='l'&&ecl2[2]=='u'){
            total++;
        }
        if(ecl2[0]=='b'&&ecl2[1]=='r'&&ecl2[2]=='n'){
            total++;
        }
        if(ecl2[0]=='g'&&ecl2[1]=='r'&&ecl2[2]=='y'){
            total++;
        }
        if(ecl2[0]=='g'&&ecl2[1]=='r'&&ecl2[2]=='n'){
            total++;
        }
        if(ecl2[0]=='h'&&ecl2[1]=='z'&&ecl2[2]=='l'){
            total++;
        }
        if(ecl2[0]=='o'&&ecl2[1]=='t'&&ecl2[2]=='h'){
            total++;
        }
    }

    if(hgt_unite[0]=='c'&&hgt_unite[1]=='m'&&hgt_unite[2]=='!') {
        if (hgt >= 150 && hgt <= 193) {
            total++;
        }
    }
    if(hgt_unite[0]=='i'&&hgt_unite[1]=='n'&&hgt_unite[2]=='!') {
        if (hgt >= 59 && hgt <= 76) {
            total++;
        }
    }

    if(iyr>=2010&&iyr<=2020){
        total++;
    }
    if(hcl2[0]=='#'){
        bool hclok=true;
        for(int j=1;j<7;j++){
            bool ok=false;
            if(hcl2[j]-48>=0&&hcl2[j]-48<=9){
                ok= true;
            }
            if(hcl2[j]>=97&&hcl2[j]<=102){
                ok= true;
            }
            if(ok==false){
                hclok= false;
            }
        }
        if(hcl2[7]!='!'){
            hclok= false;
        }
        if(hclok== true){
            total++;
        }
    }
    if(total==7){
        return true;
    }
    return false;
}

void day4_2020::reset() {
    eyr=-1;
    pid=-1;
    byr=-1;
    ecl=-1;
    hcl=-1;
    iyr=-1;
    hgt=-1;
    cid=-1;
}

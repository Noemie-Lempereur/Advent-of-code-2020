//
// Created by Noémie on 05/12/2020.
//

#ifndef TEST_DAY4_2020_H
#define TEST_DAY4_2020_H

class day4_2020 {
public:
    double eyr=-1;
    double pid=-1;
    char pid2[20]="";
    int nbpid2=0;
    double byr=-1;
    double ecl=-1;
    char ecl2[20]="";
    int nbecl2=0;
    double hcl=-1;
    char hcl2[20]="";
    int nbhcl2=0;
    double iyr=-1;
    double hgt=-1;
    char hgt_unite[20]="";
    int hgt_unites=0;
    double cid=-1;
    bool valid1();
    bool valid2();
    void reset();
    void reset2();
};


#endif //TEST_DAY4_2020_H

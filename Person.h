//
// Created by its_not_ganesh on 31-05-2021.
//

#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include <conio.h>
#include "sha256.h"
#include "errorException.h"
#include "Date.h"
#include "Adhaar.h"



using namespace std;

#ifndef OOPS_COURSE_PROJECT_PERSON_H
#define OOPS_COURSE_PROJECT_PERSON_H


class Person {

private:

    Adhaar Adhaarcard;
    string PanNo;
    errorException e;

public:

    Person()
    {
        PanNo = "CGJKY4578E";
    }


    void getPersondata()
    {
        Adhaarcard.getAdhaardata();
        PanNo=e.checkPanNumber();
    }


    void getPersondata(string pno,string fname,string lname,long long int ano, long long int phno,string addr, int d, int m, int y)
    {
        PanNo=pno;
        Adhaarcard.getAdhaardata(fname,lname,ano, phno,addr,d,m,y);
    }



    void displayPersondata()
    {
        Adhaarcard.displayAdhaardata();
        cout<<"\nPan Number:"<<PanNo;
    }



    string PersondataforHash()
    {
        return (Adhaarcard.AdhaardataforHash() + PanNo);
    }



    void displayPersondata(int i)
    {
        Adhaarcard.displayAdhaardata(1);
    }


};


#endif //OOPS_COURSE_PROJECT_PERSON_H

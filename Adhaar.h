//
// Created by its_not_ganesh on 31-05-2021.
//

#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include <conio.h>

using namespace std;

#ifndef OOPS_COURSE_PROJECT_ADHAAR_H
#define OOPS_COURSE_PROJECT_ADHAAR_H


class Adhaar {

private:

    string FirstName;
    string LastName;
    long long int Adhaar_no;
    long long int PhoneNo;
    string Address;
    Date DOB;
    errorException error;


public:

    Adhaar()
    {
        FirstName = "FirstName";
        LastName = "LastName";
        Adhaar_no = 1234123412341234;
        PhoneNo = 1234567890;
        Address = "Hubli,Karnataka";
    }



    void getAdhaardata()
    {
        cout<<"\nEnter First name and Last name:";
        cin>>FirstName;
        cin>>LastName;
        Adhaar_no=error.checkAdhaarNumber();
        PhoneNo=error.checkPhoneNumber();
        cout<<"Enter Address without spaces:";
        cin>>Address;
        DOB.getDate();
    }


    void getAdhaardata(string fname,string lname,long long int ano, long long int phno,string addr, int d, int m, int y)
    {
        FirstName=fname;
        LastName=lname;
        Adhaar_no=ano;
        PhoneNo=phno;
        Address=addr;
        DOB.getDate(d,m,y);
    }



    void displayAdhaardata()
    {
        cout<<"\nName:"<<FirstName<<" "<<LastName;
        cout<<"\nAdhaar Number:"<<Adhaar_no;
        cout<<"\nPhone number:"<<PhoneNo;
        cout<<"\nAddress:"<<Address;
        cout<<"\nDate of Birth:"<<DOB.displayDate();
    }



    void displayAdhaardata(int i)
    {
        cout<<"\nName:"<<FirstName<<" "<<LastName;
    }



    string AdhaardataforHash()
    {
        return (FirstName + LastName + to_string(Adhaar_no) + to_string(PhoneNo) + Address + DOB.displayDate());
    }


};


#endif //OOPS_COURSE_PROJECT_ADHAAR_H

//
// Created by its_not_ganesh on 31-05-2021.
//
#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include <conio.h>

using namespace std;

#ifndef OOPS_COURSE_PROJECT_ERROREXCEPTION_H
#define OOPS_COURSE_PROJECT_ERROREXCEPTION_H


class errorException {

public:
    long long int errorNumber;
    string errorString;

    errorException()
    {
        errorNumber=0;
        errorString="none";
    }



    long long int checkAdhaarNumber()
    {
        try {
            cout<<"Enter Adhaar Number:";
            cin>>errorNumber;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw 1;
            }

            if(errorNumber/1000000000000>0||errorNumber/99999999999.0<=1)
                throw 1;

            return errorNumber;
        }

        catch (int i) {
            cout<<"\nInvalid Adhaar number!"<<endl;
        }

        checkAdhaarNumber();
        return errorNumber;
    }



    long long int checkPhoneNumber()
    {
        try {
            cout<<"Enter Phone Number:";
            cin>>errorNumber;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw 1;
            }

            if(errorNumber/10000000000>0||errorNumber/999999999.0<=1)
                throw 1;

            return errorNumber;
        }

        catch (int i) {
            cout<<"\nInvalid Phone number!"<<endl;
        }

        checkPhoneNumber();
        return errorNumber;
    }


    bool negativeError(int i)
    {
        try {
            if(i<0)
                throw 1;
            return true;
        }
        catch (int q) {
            cout<<"\nInvalid input!"<<endl;
            return false;
        }
    }

    bool negativeError(float i)
    {
        try {
            if(i<0)
                throw 1;
            return true;
        }
        catch (int q) {
            cout<<"\nInvalid input!"<<endl;
            return false;
        }
    }

    bool negativeError(int i,int j)
    {
        try {
            if(i<0||i>j)
                throw 1;
            return true;
        }
        catch (int q) {
            cout<<"\nInvalid input!"<<endl;
            return false;
        }
    }

    string checkPanNumber()
    {
        try {
            cout<<"\nEnter Pan Number:";
            cin>>errorString;

            if(errorString.length()!=10)
                throw 1;

            return errorString;
        }
        catch (int i) {

            cout<<"\nInvalid Pan Number!"<<endl;

        }
        checkPanNumber();
        return errorString;

    }




};


#endif //OOPS_COURSE_PROJECT_ERROREXCEPTION_H

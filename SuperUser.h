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

#ifndef OOPS_COURSE_PROJECT_SUPERUSER_H
#define OOPS_COURSE_PROJECT_SUPERUSER_H


class SuperUser {

private:

    string username;
    string password;

public:

    SuperUser()
    {
        username = "Government";
        password = "G123!";
    }

    //function to authenticate a modification in the database

    bool verify()
    {
        char pass[20];
        string user;

        cout<<"\nEnter Username:";
        cin>>user;
        cout<<"Enter Password:";


        int i=0;
        while((pass[i]=getch())!='\r')
        {
            cout<<"*";
            i++;
        }
        pass[i]='\0';


        return user == username && pass == password;
    }

    void changeusername()
    {


        if(verify())
        {
            cout<<"\nEnter new username:";
            cin>>username;
        }

        else
        {
            cout<<"\nWrong Password!";
        }
    }

    void changepassword()
    {



        if(verify())
        {

            cout<<"\nEnter new password:";

            char pass[20];

            int i=0;
            while((pass[i]=getch())!='\r')
            {
                cout<<"*";
                i++;
            }
            pass[i]='\0';

            password=pass;

        }

        else
        {
            cout<<"\nWorng Password!";
        }
    }

};


#endif //OOPS_COURSE_PROJECT_SUPERUSER_H

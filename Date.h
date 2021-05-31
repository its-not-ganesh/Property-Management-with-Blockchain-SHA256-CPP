//
// Created by its_not_ganesh on 31-05-2021.
//

#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include <conio.h>

using namespace std;

#ifndef OOPS_COURSE_PROJECT_DATE_H
#define OOPS_COURSE_PROJECT_DATE_H


class Date {

private:

    int dd;
    int mm;
    int yy;
    string date;
    errorException e;

public:

    Date()
    {
        dd=1;
        mm=1;
        yy=2000;
        date = "1/1/2000";
    }



    void getDate()
    {

        while (!e.negativeError(dd)||!e.negativeError(mm)||!e.negativeError(yy))
        {
            cout<<"\nEnter Date of birth (DD MM YYYY with spaces):";
            cin>>dd;
            cin>>mm;
            cin>>yy;
        }

        date = to_string(dd) + "/" + to_string(mm) + "/" + to_string(yy);
    }

    void getDate(int d, int m, int y)
    {
        dd=d;
        mm=m;
        yy=y;
    }



    string displayDate()
    {
        return date;
    }


};


#endif //OOPS_COURSE_PROJECT_DATE_H

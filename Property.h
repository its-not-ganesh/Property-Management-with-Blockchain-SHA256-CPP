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

#ifndef OOPS_COURSE_PROJECT_PROPERTY_H
#define OOPS_COURSE_PROJECT_PROPERTY_H


class Property {

private:

    string state;
    string district;
    string town;
    string area;
    string SurveyNo;
    float arsqft;
    errorException e;

public:

    Property()
    {
        state = "Karnataka";
        district = "Dharwad";
        town = "Hubli";
        area = "Unkal";
        SurveyNo = "12A/3";
        arsqft = -0.0;
    }



    void getPropertydata(string st, string dst, string twn, string ar, string srn, float arsq)
    {
        state=st;
        district=dst;
        town=twn;
        area=ar;
        SurveyNo=srn;
        arsqft=arsq;
    }



    void getPropertydata()
    {
        cout<<"\nEnter Property Details:";
        cout<<"\nEnter State:";
        cin>>state;
        cout<<"Enter district:";
        cin>>district;
        cout<<"Enter Town:";
        cin>>town;
        cout<<"Enter Colony/Area:";
        cin>>area;
        cout<<"Enter Surver Number of the property:";
        cin>>SurveyNo;
        cout<<"Enter Area in sq feet:";
        cin>>arsqft;
        while (!e.negativeError(arsqft))
        {
            cout<<"Enter Area in sq feet:";
            cin>>arsqft;
        }

    }



    void displayPropertydata()
    {
        cout<<"\nState:"<<state;
        cout<<"\nDistrict:"<<district;
        cout<<"\nTown:"<<town;
        cout<<"\nArea/Colony:"<<area;
        cout<<"\nSurvey Number:"<<SurveyNo;
        cout<<"\nArea in sq ft:"<<arsqft<<endl;

    }



    string PropertydataforHash()
    {
        return (state + district + town + area + SurveyNo +to_string(arsqft));
    }


};


#endif //OOPS_COURSE_PROJECT_PROPERTY_H

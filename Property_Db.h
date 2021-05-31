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

#ifndef OOPS_COURSE_PROJECT_PROPERTY_DB_H
#define OOPS_COURSE_PROJECT_PROPERTY_DB_H


class Property_Db {

private:

    BlockChain Database[100];

public:

    Property_Db()
    = default;


    void addBlock(TransactionData d, int i)
    {
        Database[i].addBlock(d);
    }



    bool isChainValid(int i)
    {
        return Database[i].isChainValid();
    }



    Block getLatestBlock(int i)
    {
        return Database[i].getLatestBlock();
    }



    Person getcurrentowner(int i)
    {
        return Database[i].getcurrentowner();
    }



    Property getlanddetails(int i)
    {
        return Database[i].landdata();
    }

    //Checks if the property is available for sale

    bool checkavailability(int i)
    {
        return Database[i].checkavailability();
    }

    //Makes a property available for sale

    void makeavailable(int  i)
    {
        Database[i].makeavailable();
        cout<<"\nLand is available for sale\n";
    }

    //Makes a property not available for sale

    void makeunavailable(int i)
    {
        Database[i].makeunavailable();
    }

    //Displays details of the lands that are available for sale

    bool displaylandsavailableforsale(int i)
    {
        if(Database[i].checkavailability())
        {
            cout<<"\n\nLand Code: "<<i;
            getLatestBlock(i).displayavailableland();
            return true;
        }
        return false;
    }

    //Displays details of the lands that are not available for sale

    bool displaylandnotavailableforsale(int i)
    {
        if(!Database[i].checkavailability())
        {
            cout<<"\n\nLand Code: "<<i;
            getLatestBlock(i).displayavailableland();
            return true;
        }
        return false;
    }

    //Displays details of land

    void displaylands(int i)
    {

        cout<<"\n\nLand Code: "<<i;
        getLatestBlock(i).displayavailableland();

    }



};


#endif //OOPS_COURSE_PROJECT_PROPERTY_DB_H

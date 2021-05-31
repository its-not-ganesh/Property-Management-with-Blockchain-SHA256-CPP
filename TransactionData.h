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

#ifndef OOPS_COURSE_PROJECT_TRANSACTIONDATA_H
#define OOPS_COURSE_PROJECT_TRANSACTIONDATA_H


class TransactionData {

private:

    Person buyer;
    Property landdetails;
    Person seller;

public:

    TransactionData()
    {

    }



    void getTransactiondata(Person byr, Property landonsale, Person slr)
    {
        buyer = byr;
        landdetails = landonsale;
        seller = slr;
        cout<<"\nLand Successfully Sold!!";
    }



    void displayTransactiondata()
    {
        cout<<"\nBuyer Details:";
        buyer.displayPersondata();
        cout<<"\n\nLand Details:";
        landdetails.displayPropertydata();
        cout<<"\n\nSeller Details:";
        seller.displayPersondata();
    }



    string TransactiondataforHash()
    {
        return (buyer.PersondataforHash() + landdetails.PropertydataforHash() + seller.PersondataforHash());
    }



    Person currentownerdata()
    {
        return buyer;
    }



    Property landdata()
    {
        return landdetails;
    }



    void displayTransactiondata(int i)
    {
        cout<<"\n\nCurrent owner";
        buyer.displayPersondata(1);
        cout<<"\n\nLand Details";
        landdetails.displayPropertydata();
    }

};


#endif //OOPS_COURSE_PROJECT_TRANSACTIONDATA_H

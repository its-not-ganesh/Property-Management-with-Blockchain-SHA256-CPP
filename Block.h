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

#ifndef OOPS_COURSE_PROJECT_BLOCK_H
#define OOPS_COURSE_PROJECT_BLOCK_H


class Block {

private:

    TransactionData data;
    string blockHash;
    string previousHash;

    string generateHash()
    {
        string toHash;
        toHash = data.TransactiondataforHash();

        return sha256(toHash);
    };

public:

    //Constructor
    Block(TransactionData d, string prevHash)
    {
        data=d;
        previousHash=prevHash;
        blockHash=generateHash();
    }



    //Get Original Hash
    string getHash()
    {
        return blockHash;
    }



    //Get previous hash
    string getPreviousHash()
    {
        return previousHash;
    }



    //validate hash
    bool isHashValid()
    {
        return generateHash()==blockHash;
    }



    void displayBlockdata()
    {
        cout<<"\nBlock Hash:\n"<<getHash();

        cout<<"\nPrevious Hash:\n"<<getPreviousHash();

        cout<<"\nTransaction data:\n";
        data.displayTransactiondata();
    }



    Person currentowner()
    {
        return data.currentownerdata();
    }


    Property landdetails()
    {
        return data.landdata();
    }



    void displayavailableland()
    {
        data.displayTransactiondata(1);
    }


};


#endif //OOPS_COURSE_PROJECT_BLOCK_H

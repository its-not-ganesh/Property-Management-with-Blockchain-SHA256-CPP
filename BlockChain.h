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

#ifndef OOPS_COURSE_PROJECT_BLOCKCHAIN_H
#define OOPS_COURSE_PROJECT_BLOCKCHAIN_H


class BlockChain {

private:

    bool availability;

    Block createGenesisBlock()
    {
        TransactionData d;
        Block genesis(d, sha256("Nothing"));
        return genesis;
    }

public:
    //public chain
    vector<Block> chain;

    //Constructor
    BlockChain()
    {
        availability = false;
        Block genesis = createGenesisBlock();
        chain.push_back((genesis));
    }



    //Public functions
    void addBlock(TransactionData d)
    {

        Block newBlock(d,getLatestBlock().getHash());
        chain.push_back(newBlock);

    }



    bool isChainValid()
    {

        vector<Block>::iterator it;
        int chainLen=(int)chain.size();

        for(it=chain.begin()+1;it!=chain.end();it++)
        {
            Block currentBlock = *it;
            if(!currentBlock.isHashValid())
            {
                return false;
            }


            if(chainLen>1)
            {

                Block previousHash = *(it-1);
                if(currentBlock.getPreviousHash()!=previousHash.getHash())
                {
                    return false;
                }

            }
        }

        return true;
    }



    Block getLatestBlock()
    {
        return chain.back();
    }



    Person getcurrentowner()
    {
        return getLatestBlock().currentowner();
    }



    Property landdata()
    {
        return getLatestBlock().landdetails();
    }

    bool checkavailability()
    {
        return availability;
    }



    void makeavailable()
    {
        availability = true;
    }



    void makeunavailable()
    {
        availability = false;
    }


};


#endif //OOPS_COURSE_PROJECT_BLOCKCHAIN_H

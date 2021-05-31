#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include <conio.h>
#include "sha256.h"
#include "errorException.h"
#include "Date.h"
#include "Adhaar.h"
#include "Person.h"
#include "Property.h"
#include "TransactionData.h"
#include "Block.h"
#include "BlockChain.h"
#include "Property_Db.h"
#include "SuperUser.h"


using namespace std;


//Initilization function

Property_Db init(Property_Db GovernmentDatabase)
{
    Person buyer;
    Person seller;
    Property land;

    TransactionData d;

    //add 1st property to Database

    buyer.getPersondata ("12CDGF123R","Ramesh","S",789123912371,9868754215,"Akshay Park,Hubli",1,1,1998);
    seller.getPersondata("98GF123R56","Suresh","R",986454887654,8655465465,"Akshay Park,Hubli",4,2,1998);
    land.getPropertydata("Karnataka","Dharwad","Hubli","Srinagar","61/A",400.2);

    d.getTransactiondata(buyer,land,seller);

    GovernmentDatabase.addBlock(d,0);


    //add 2nd property to Database


    buyer.getPersondata ("65PGE345GE","Anil","Matt",459678238541,9876543211,"Unkal,Hubli",25,3,1978);
    seller.getPersondata("352TMR98RW","Bob","M",782654813325,7894561231,"Vidyanagar,Hubli",30,6,1993);
    land.getPropertydata("Karnataka","Dharwad","Hubli","Unkal","72/B/1",1200.0);

    d.getTransactiondata(buyer,land,seller);

    GovernmentDatabase.addBlock(d,1);


    //add 3rd property to Database


    buyer.getPersondata ("WEIU789WE0","Mahesh","B",356348951235,7686953414,"Deshpande Nagar,Hubli",25,3,1978);
    seller.getPersondata("CPZPG45KLL","Ram","C",489512359879,9865754312,"Vidyanagar,Hubli",30,6,1993);
    land.getPropertydata("Karnataka","Dharwad","Hubli","Deshpande Nagar","72/B/1",560.2);

    d.getTransactiondata(buyer,land,seller);

    GovernmentDatabase.addBlock(d,2);


    return GovernmentDatabase;



}

//


//Main Function!!!!!!!!!      !!!!!!!!!!!!!!      !!!!


//

int main()
{
    //Government database - holds all the property data

    Property_Db GovernmentDatabase;
    SuperUser Government;

    //Initialize

    GovernmentDatabase=init(GovernmentDatabase);

    //Temporary objects used to add data into the database

    TransactionData temptransaction;
    Person purchaser;
    Person owner;
    Property land;

    //Variables used in the application

    int propertyCount=3;
    int ch;
    int q=1;
    bool check;
    int landcode;

    //Exception object

    errorException e;


    while (q)
    {
        cout<<"\n\nEnter Your Choice:";
        cout<<"\n1.Add New Property to the Database";
        cout<<"\n2.Display the lands available for sale";
        cout<<"\n3.Make a property available for sale";
        cout<<"\n4.Buy a property";
        cout<<"\n5.Verify the Integrity and security of the database(Blockchain)";
        cout<<"\n6.Change Validation Username";
        cout<<"\n7.Change Validation Password";
        cout<<"\n8.Display Overview of the Government Database\n";
        cin>>ch;

        switch (ch) {

            case 1://Add New Property to the Database

                if (Government.verify()){

                    //Get the property data
                    land.getPropertydata();

                    //Assign default values as no one currently owns the land as it is the genesis block
                    temptransaction.getTransactiondata(purchaser,land,owner);
                    GovernmentDatabase.addBlock(temptransaction,propertyCount);

                    //Increment the property count
                    propertyCount++;

                    cout<<"\nProperty successfully added to the Government database!";
                }
                else{
                        cout<<"\nAuthentication Failed!!";

                }

                break;

            case 2://Display the lands available for sale

                for (int (i) = 0; (i) < propertyCount; i++) {

                    if(GovernmentDatabase.displaylandsavailableforsale(i))
                    {
                        check= true;
                    }

                }

                if (!check)
                {
                    cout<<"\nNo lands are available for sale";
                }
                break;

            case 3://Make a property available for sale

            //Display the lands unavailable for sale

                for (int (i) = 0; (i) < propertyCount; i++) {

                    if(GovernmentDatabase.displaylandnotavailableforsale(i))
                    {
                        check= true;
                    }

                }
                if (!check)
                {
                    cout<<"\nAll lands are available for sale";
                }
                else if(Government.verify()){

                    cout<<"\nEnter the land code to make it available for sale:";
                    cin>>landcode;
                    while (!e.negativeError(landcode,propertyCount))
                    {
                        cout<<"\nEnter the land code to make it available for sale:";
                        cin>>landcode;
                    }


                    GovernmentDatabase.makeavailable(landcode);
                }
                else
                {
                    cout<<"\nAuthentication Failed!!";
                }
                break;

            case 4://Buy a property

            //Display the lands available for sale for the user to choose

                for (int (i) = 0; (i) < propertyCount; i++) {

                    if(GovernmentDatabase.displaylandsavailableforsale(i))
                    {
                        check= true;
                    }

                }
                if (check)
                {
                    if(Government.verify())
                    {
                        cout<<"\nEnter Land code of the land you need to purchase:";
                        cin>>landcode;
                        while (!e.negativeError(landcode,propertyCount))
                        {
                            cout<<"\nEnter Land code of the land you need to purchase:";
                            cin>>landcode;
                        }
                        cout<<"\nEnter Buyer details:";
                        purchaser.getPersondata();

                        //Get the previous owner
                        owner=GovernmentDatabase.getcurrentowner(landcode);

                        //Get the land Details
                        land=GovernmentDatabase.getlanddetails(landcode);

                        //Assign the transaction data
                        temptransaction.getTransactiondata(purchaser,land,owner);

                        //Add block to the blockchain
                        GovernmentDatabase.addBlock(temptransaction,landcode);

                        //Make the newly added property unavailable for sale(default)
                        GovernmentDatabase.makeunavailable(landcode);

                        cout<<"\nProperty successfully added to the Government database!\n";
                    }
                    else
                    {
                        cout<<"\nAuthentication Failed!!!";
                    }
                }
                else
                {
                    cout<<"\nNo lands are available for sale";
                }

                break;

            case 5://Verify the Integrity and security of the database(Blockchain)

                check = true;
                if(propertyCount==0)
                {
                    cout<<"\nNo data in the Database";
                }
                else
                {
                    //Iterating the whole database to check the integrity using the isChainValid function

                    for(landcode=0;landcode<propertyCount;landcode++)
                    {
                        if (GovernmentDatabase.isChainValid(landcode));
                        else
                        {
                            check=false;
                            break;
                        }

                    }
                    if (check)
                        cout<<"\nThe Database is secure and valid!";
                    else
                        cout<<"\nThe Database has been tampered with and is not secure!!!!";
                }

                break;

            case 6://Change Validation Username

                Government.changeusername();
                break;


            case 7://Change Validation Password

                Government.changepassword();
                break;


            case 8://Display Overview of the Government Database

                cout<<"\nThere are "<<propertyCount<<" different property records currently in the Governmnet Database";
                cout<<"\nBrief Land details and current owners:";

                //loop iterating to display details of all lands in the database

                for (landcode = 0; landcode < propertyCount; landcode++) {

                    GovernmentDatabase.displaylands(landcode);

                }

                break;


        }
    }

}

# Property Management with Blockchain(Sha256)CPP
 Implementation of Property management with Blockchain technology using SHA256 algorithm for hashing in C++
 
<h2>Description</h2>
In this project there are 11 class which are "sha256", "errorException", "Date", "Adhaar", "Person", "Property", "TransactionData", "Block", "BlockChain", "Property_Db", "SuperUser" which all have custom exceptions for the user input. The sha256 class converts a string data into a 64 character long hash which is unique to that data. The Blockchain class has all the Blocks with all the transaction data with the hash. This project aims to improve the security of the Database and the transactions with the Blockchain technology whose architecture helps us achieve that goal.

<h2>How to Run?</h2>
 
 Preferably use any IDE with Cmake where the project can be run directly, if using any other ide configure the files and run th main.cpp file.
 
 <h3>Terminal interface with choices</h3>

![Capture](https://user-images.githubusercontent.com/44310129/120598351-cb817f00-c463-11eb-992b-c143bec5565e.JPG)

<h3>Adding new property</h3>
For all authentications use the Username:Government and Password:G123!
Add the specified details to add the property


![AddnewProp](https://user-images.githubusercontent.com/44310129/120602354-91ff4280-c468-11eb-884e-8f49bb2b86ab.JPG)

<h3>First make the property available for sale so that a user can buy the property</h3>
The following properties are shown which are available in the Database, select the land to make it available for sale by entering the land code.

![Landindb](https://user-images.githubusercontent.com/44310129/120603858-12727300-c46a-11eb-8c21-8d1d1df532e6.JPG)

![landavforsale](https://user-images.githubusercontent.com/44310129/120604202-6c733880-c46a-11eb-8765-bcc1a75ab240.JPG)

<h3>You can now buy a property that is already made available for sale</h3>

![buyaprop](https://user-images.githubusercontent.com/44310129/120604453-b52af180-c46a-11eb-944d-43f2218ef3d3.JPG)

<h3>Check the integrity of the Database</h3>
This function checks every block in the Blockchain by recalculating the hash and comparing with the previous present ant next block's hash ensuring that the Blockchain has not been tampered with.

![checkblkchn](https://user-images.githubusercontent.com/44310129/120605181-67fb4f80-c46b-11eb-8f6d-ebdddde9c880.JPG)

<h3>Other Functionalities</h3>
The overview of the Database shows the brief overview of the data in the database, the other functions enable you to change the default username and password.

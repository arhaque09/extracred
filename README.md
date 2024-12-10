# README for Extra Credit Assignment
## Table of Contents
1. [Description](#description)
2. [How to Use/Test the Project](#how-to-usetest-the-project)
3. [Recommendations for Modifications](#recommendations-for-modifications)


---
## Description
This project is written in C++ and is a database that keeps track of transactions done to accounts. The main data structure that is used is a <map> called "accounts" which stores the keys as strings and the values as integers. In addition, there is a temporary vector<map<string, int>> called "pre" that keeps track of non-committed changes to accounts. If the user writes commit, then the coordinates in "pre" are put into the "accounts" data structure. Furthermore, there is a bool called "transactions" that states true if the "begin_transaction()" function is called. This bool determines if certain functions can proceed or through errors based on if a transaction is taking place. 

---
## How to Use/Test the Project
1. First clone the repository into your account.
2. Then in the main function after the cout statement "TESTS FOR EXTRA CREDIT", you can write your tests such as the ones in Figure 2 of the assignment.
3. I would first create a instance of the InMemoryDB object like below:
   ```
   InMemoryDB object;
   ```
4. Then, if you want to write specific tests you would write object.<name_of_function> like below:
   ```
   object.put("A", 25);
   ```
   Here is an example given by the ESEP Extra Credit Assignment that you can use to test this code: 
   ```
   InMemoryDB inmemoryDB;

    // should return null, because A doesn’t exist in the DB yet
    inmemoryDB.get("A");

    // should throw an error because a transaction is not in progress
    inmemoryDB.put("A", 5);

    // starts a new transaction
    inmemoryDB.begin_transaction();

    // set’s value of A to 5, but its not committed yet
    inmemoryDB.put("A", 5);

    // should return null, because updates to A are not committed yet
    inmemoryDB.get("A");

    // update A’s value to 6 within the transaction
    inmemoryDB.put("A", 6);

    // commits the open transaction
    inmemoryDB.commit();
    // should return 6, that was the last value of A to be committed
    inmemoryDB.get("A");

    // throws an error, because there is no open transaction
    inmemoryDB.commit();

    // throws an error because there is no ongoing transaction
    inmemoryDB.rollback();

    // should return null because B does not exist in the database
    inmemoryDB.get("B");

    // starts a new transaction
    inmemoryDB.begin_transaction();

    // Set key B’s value to 10 within the transaction
    inmemoryDB.put("B", 10);

    // Rollback the transaction - revert any changes made to B
    inmemoryDB.rollback();

    // Should return null because changes to B were rolled back
    inmemoryDB.get("B");
   ```
   Expected output:
   ```bash
   TESTS FOR EXTRA CREDIT
   Account A not found!
   Exception: Transaction has not taken place for A
   Transaction started
   Account A not found!
   Transactions committed
   Account A: 6
   Exception: Transaction has not taken place
   Exception: Transaction has not taken place
   Account B not found!
   Transaction started
   Transactions roll backed
   Account B not found!
   ```


6. After writing your tests, save the file and in the terminal make sure you are in the path that contains this file. Then, run the below command. Make sure you have the g++ compiler, if you dont you may need to install g++ compiler:
   ```bash
   g++ -o output db.cpp
   ./output
   ```
## Recommendations for Modifications
This assignment has several things to improve upon. First, there should be clear instructions on what the code should output given a couple of examples. I made my own output like “Exception: Transaction has not taken place for A” and “Account A not found!”. Furthermore, for the get(key) function, it should not return null or the key, as languages like c++ require a type to be stated for output. My function was int get(key), thus I am not able to return null as it is not of type int (again specifying what the output for each function should be including the variable type or if its a print statement is crucial for this assignment).


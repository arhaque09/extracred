# README for Extra Credit Assignment
## Table of Contents
1. [Description](#description)
2. [How to Use/Test the Project](#how-to-usetest-the-project)


---
## Description
This project is written in C++ and is a database that keeps track of transactions done to accounts. The main data structure that is used is a <map> called "accounts" which stores the keys as strings and the values as integers. In addition, there is a temporary vector<map<string, int>> called "pre" that keeps track of non-committed changes to accounts. If the user writes commit, then the coordinates in "pre" are put into the "accounts" data structure. Furthermore, there is a bool called "transactions" that states true if the "begin_transaction()" function is called. This bool determines if certain functions can proceed or through errors based on if a transaction is taking place. 

---
## How to Use/Test the Project
1. First clone the repository into your account.
2. Then in the main functionw where it says "write your tests here", you can write your tests such as the ones in Figure 2 of the assignment.
3. I would first create a instance of the InMemoryDB object like below:
   ```
   InMemoryDB object;
   ```
4. Then, if you want to write specific tests you would write object.<name_of_function> like below:
   ```
   object.put("A", 25);
   ```
5. After writing your tests, save the file and in the terminal make sure you are in the path that contains this file. Then, run the below command. Make sure you have the g++ compiler, if you dont you may need to install g++ compiler:
   ```bash
   g++ -o output db.cpp
   ./output
   ```

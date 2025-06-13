#include "../include/MiniDBMS.hpp"
#include <iostream>
#include<sstream>
#include <fstream>

using namespace std;

// Create a new table with the given name
void MiniDBMS::createtable(string tablename) {
    if (tables.find(tablename) != tables.end()) {
        cout << "Table " << tablename << " already exists.\n";
        return;
    }
    tables[tablename] = new DeleteRecord(0," ");
    cout << "Table " << tablename << " created.\n";
}

// Insert a record into specified table
void MiniDBMS::insertinto(string tablename, int id, string name) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->insertdata(id, name);
}

// Find a record by id in specified table
void MiniDBMS::findfrom(string tablename, int id) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->finddata(id);
}

// Update the name of a record by id in specified table
void MiniDBMS::updatein(string tablename, int id, string newname) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->updatedata(id, newname);
}

// Delete a record by id from specified table
void MiniDBMS::deletefrom(string tablename, int id) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->deleterecord(0," ");
}

// Show all records of specified table
void MiniDBMS::showtable(string tablename) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->showallRecord();
}

// Dump table data to file
void MiniDBMS::dumptable(string tablename, string filename) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->dumpToFile(filename);
}

// Load table data from file
void MiniDBMS::loadtable(string tablename, string filename) {
    auto it = tables.find(tablename);
    if (it == tables.end()) {
        cout << "Table " << tablename << " not found.\n";
        return;
    }
    it->second->loadFromFile(filename);
}

// Destructor to free dynamically allocated DeleteRecord objects


    // Assuming your table class has dumpToFile method
 

void MiniDBMS::query(const string& sql)
{
    string command=getcommandType(sql);
    if(command=="INSERT")
    {
        handleInsert(sql);
    }
   else if(command=="CREATE")
    {
        handleCreate(sql);
    }
   else if(command=="UPDATE")
    {
             handleUpdate(sql);
    }
    else if(command=="DELETE")
    {
        handleDelete(sql);
    }
    else if(command=="SELECT")
    {
          handleSelect(sql);
    }
    else
    {
        cout<<"INVALID QUERY \n";
    }
}

void MiniDBMS::handleInsert(const string& sql) {
    string command, intoKeyword, table, valuesKeyword, name;
    int id;
    stringstream ss(sql);
    ss >> command >> intoKeyword >> table >> valuesKeyword >> id >> name;
    
    if (command == "INSERT" && intoKeyword == "INTO" && valuesKeyword == "VALUES") {
        insertinto(table, id, name);
    } else {
        cout << "Invalid INSERT query format.\n";
    }
}

void MiniDBMS::handleCreate(const string& sql)
{
    string command,tableKeyword,tablename;
    stringstream ss(sql);
    ss>>command>>tableKeyword>>tablename;
    if(command=="CREATE"&& tableKeyword=="TABLE")
    {
        createtable(tablename);
    }
    else{
        cout<<"invalid CREATE TABLE query format.\n";
    }
}
void MiniDBMS::handleUpdate(const string& sql)
{
    string command,tableKeyword,tablename,newname;
    int id;
    stringstream ss(sql);
    ss>>command>>tableKeyword>>tablename>>id>>newname;
    if(command=="UPDATE"&& tableKeyword=="TABLE")
    {
        updatein(tablename,id,newname);
    }
    else{
        cout<<"Invalid UPDATE query format.\n";
    }
}
void MiniDBMS::handleDelete(const string& sql)
{
    string command,tableKeyword,tablename;
    int id;
    stringstream ss(sql);
    ss>>command>>tableKeyword>>tablename>>id;
    if(command=="DELETE"&& tableKeyword=="TABLE")
    {
        deletefrom(tablename,id);
    } 
}
void MiniDBMS::handleSelect(const string& sql)
{
    string command,tableKeyword,tablename;
    stringstream ss(sql);
    ss>>command>>tableKeyword>>tablename;
    if(command=="SELECT" && tableKeyword=="TABLE")
    {
        showtable(tablename);

    }
}
std::string MiniDBMS::getcommandType(const std::string& sql) {
    std::stringstream ss(sql);
    std::string command;
    ss >> command;
    return command;
}

MiniDBMS::~MiniDBMS() {
    for (auto& pair : tables) {
        delete pair.second;
    }
}



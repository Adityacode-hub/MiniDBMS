#include "MiniDBMS.hpp"
#include <iostream>
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
MiniDBMS::~MiniDBMS() {
    for (auto& pair : tables) {
        delete pair.second;
    }
    tables.clear();
}

#ifndef MINIDBMS_HPP
#define MINIDBMS_HPP

#include "Deleterecord.hpp"
#include <unordered_map>
#include <string>
using namespace std;

class MiniDBMS
{
    unordered_map<string, DeleteRecord*> tables;  // map of table name to pointer to Deleterecord object

public:
    // Create a new table with given name
    void createtable(string tablename);

    // Insert a record into specified table
    void insertinto(string tablename, int id, string name);

    // Find a record by id in specified table
    void findfrom(string tablename, int id);

    // Update the name of a record by id in specified table
    void updatein(string tablename, int id, string newname);

    // Delete a record by id from specified table
    void deletefrom(string tablename, int id);

    // Show all records of specified table
    void showtable(string tablename);

    // Dump table data to file (not implemented fully)
    void dumptable(string tablename, string filename);

    // Load table data from file (not implemented fully)
    void loadtable(string tablename, string filename);

    // Destructor to free dynamically allocated Deleterecord objects
    void query(const string& sql);
    string getcommandType(const string& sql);
    void handleInsert(const string& sql);
    void handleCreate(const string& sql);
    void handleUpdate(const string& sql);
    void handleDelete(const string& sql);
    void handleSelect(const string& sql);
    ~MiniDBMS();
};

#endif

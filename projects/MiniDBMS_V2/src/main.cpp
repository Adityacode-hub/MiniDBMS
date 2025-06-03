#include "../include/MiniDBMS.hpp"

int main() {
    MiniDBMS dbms;

    // Step 1: Create table
    dbms.createtable("students");

    // Step 2: Insert some records
    dbms.insertinto("students", 1, "Vinay");
    dbms.insertinto("students", 2, "Aditya");

    // Step 3: Show records before saving
    cout << "Initial data:\n";
    dbms.showtable("students");

    // Step 4: Dump table to file
    dbms.dumptable("students", "students.txt");

    // Step 5: Create a new table and load data from file
    dbms.createtable("loaded_students");
    dbms.loadtable("loaded_students", "students.txt");

    // Step 6: Show loaded data
    cout << "\nData loaded from file:\n";
    dbms.showtable("loaded_students");

    return 0;
}



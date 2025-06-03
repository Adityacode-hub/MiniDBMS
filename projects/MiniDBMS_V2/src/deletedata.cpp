#include "Deleterecord.hpp"
#include<fstream>
#include <iostream>
using namespace std;

DeleteRecord::DeleteRecord(int id, string name) : Database(id, name) {
    if(id!=0&&!name.empty())
    {

    records.push_back({id, name});
    }
}

void DeleteRecord::save(string data) {
    cout << "Logging delete: " << data << endl;
}

void DeleteRecord::deleterecord(int id, string name) {
    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->first == id && it->second == name) {
            records.erase(it);
            cout << "Deleted: " << id << endl;
            save("Deleted: " + to_string(id));
            return;
        }
    }
    cout << "Record not found.\n";
}
void DeleteRecord::dumpToFile(string filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Error writing to file.\n";
        return;
    }
    for (auto& record : records) {
        out << record.first << " " << record.second << "\n";
    }
    out.close();
    cout << "Data dumped to file: " << filename << endl;
}

// Load all records from a file
void DeleteRecord::loadFromFile(string filename) {
    ifstream in(filename);
    if (!in) {
        cout << "File not found.\n";
        return;
    }
    records.clear();  // Clear current records before loading
    int id;
    string name;
    while (in >> id >> name) {
        records.push_back({id, name});
    }
    in.close();
    cout << "Data loaded from file: " << filename << endl;
}

void DeleteRecord::insertdata(int id, string name) {
    records.push_back({id, name});
    cout << "Record inserted: " << id << " " << name << endl;
}

void DeleteRecord::showallRecord() {
    cout << "All Records:" << endl;
    for (auto& record : records) {
        cout << "ID: " << record.first << ", Name: " << record.second << endl;
    }
}
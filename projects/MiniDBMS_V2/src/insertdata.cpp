#include "../include/insertdata.hpp"
#include <iostream>
using namespace std;

InsertData::InsertData(int id, string name) : Database(id, name) {
    records.push_back({id, name});
}

void InsertData::save(string data) {
    // Example save logic (could be file or DB)
    cout << "Saving data: " << data << endl;
}

void InsertData::insertdata(int id, string name) {
    records.push_back({id, name});
    save("Inserted: " + to_string(id) + ", " + name);
}

void InsertData::updatedata(int id, string name) {
    for (auto &record : records) {
        if (record.first == id) {
            record.second = name;
            save("Updated: " + to_string(id) + ", " + name);
            return;
        }
    }
    cout << "Record not found to update.\n";
}

void InsertData::finddata(int id) {
    for (auto &record : records) {
        if (record.first == id) {
            cout << "Found: " << id << " - " << record.second << endl;
            return;
        }
    }
    cout << "Record not found.\n";
}

void InsertData::deleterecord(int id, string name) {
    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->first == id && it->second == name) {
            records.erase(it);
            save("Deleted: " + to_string(id) + ", " + name);
            return;
        }
    }
    cout << "Record not found to delete.\n";
}

void InsertData::showallRecord() {
    cout << "All Records:\n";
    for (auto &record : records) {
        cout << record.first << " - " << record.second << endl;
    }
}

InsertData::~InsertData() {}

   
   
   
   

 
#include "finddata.hpp"
#include <iostream>
using namespace std;

FindData::FindData(int id, string name) : Database(id, name) {
    records.push_back({id, name});
}

void FindData::save(string data) {
    cout << "Logging: " << data << endl;
}

void FindData::finddata(int id) {
    for (auto &r : records) {
        if (r.first == id) {
            cout << "Found: " << id << " -> " << r.second << endl;
            save("Found: " + to_string(id));
            return;
        }
    }
    cout << "Not Found: " << id << endl;
}

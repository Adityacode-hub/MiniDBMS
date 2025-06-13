#include "../include/Updatedata.hpp"
#include <iostream>
using namespace std;

UpdateData::UpdateData(int id, string name) : Database(id, name) {
    records.push_back({id, name});
}

void UpdateData::save(string data) {
    cout << "Update Log: " << data << endl;
}

void UpdateData::updatedata(int id, string name) {
    for (auto &r : records) {
        if (r.first == id) {
            r.second = name;
            cout << "Updated: " << id << " to " << name << endl;
            save("Updated: " + to_string(id));
            return;
        }
    }
    cout << "ID not found.\n";
}

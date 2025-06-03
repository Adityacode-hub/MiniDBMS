#ifndef DELETERECORD_HPP
#define DELETERECORD_HPP

#include "Database.hpp"
#include <vector>
#include <string>
using namespace std;

class DeleteRecord : public Database {
private:
    vector<pair<int, string>> records;

protected:
    void save(string data) override;

public:
    DeleteRecord(int id, string name);
    void deleterecord(int id, string name) override;
    void insertdata(int id, string name) override ;
    void updatedata(int id, string name) override {}
    void finddata(int id) override {}
    void showallRecord() override ;
    void dumpToFile(string filename);
    void loadFromFile(string filename);


    ~DeleteRecord() {}
};

#endif

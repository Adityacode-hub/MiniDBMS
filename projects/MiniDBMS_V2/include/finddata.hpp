#ifndef FINDDATA_HPP
#define FINDDATA_HPP

#include "Database.hpp"

class FindData : public Database {
private:
    vector<pair<int, string>> records;

protected:
    void save(string data) override;

public:
    FindData(int id, string name);
    void finddata(int id) override;
    void insertdata(int id, string name) override {}
    void updatedata(int id, string name) override {}
    void deleterecord(int id, string name) override {}
    void showallRecord() override {}

    ~FindData() {}
};

#endif
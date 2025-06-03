#ifndef UPDATEDATA_HPP
#define UPDATEDATA_HPP

#include "Database.hpp"

class UpdateData : public Database {
private:
    vector<pair<int, string>> records;

protected:
    void save(string data) override;

public:
    UpdateData(int id, string name);
    void updatedata(int id, string name) override;
    void insertdata(int id, string name) override {}
    void finddata(int id) override {}
    void deleterecord(int id, string name) override {}
    void showallRecord() override {}

    ~UpdateData() {}
};

#endif

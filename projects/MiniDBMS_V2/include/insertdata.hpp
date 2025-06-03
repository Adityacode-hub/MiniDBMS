#ifndef INSERTDATA_HPP
#define INSERTDATA_HPP

#include "Database.hpp"
#include <vector>

class InsertData : public Database {
private:
    vector<pair<int, string>> records;

protected:
    void save(string data) override;

public:
    InsertData(int id, string name);
    void insertdata(int id, string name) override;
    void updatedata(int id, string name) override;
    void finddata(int id) override;
    void deleterecord(int id, string name) override;
    void showallRecord() override;
    ~InsertData();
};

#endif
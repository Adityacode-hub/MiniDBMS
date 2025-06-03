#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <iostream>
#include <vector>
#include<string>
using namespace std;
class Database
{
    protected:
    virtual void save(string data)=0;
    int id;
    string name;
    public:
    Database(int id,string name):id(id),name(name){}
    virtual void insertdata(int id,string name)=0;
    virtual void updatedata(int id,string name)=0;
    virtual void finddata(int id)=0;
    virtual void  deleterecord(int id,string name)=0;
    virtual void showallRecord()=0;
    virtual ~Database()
    {

    }
};
#endif
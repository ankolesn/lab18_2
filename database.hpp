//
// Created by ankolesn on 23.07.22.
//

#ifndef LAB18_2_DATABASE_HPP
#define LAB18_2_DATABASE_HPP

#include "person.hpp"
#include <vector>
#include <fstream>
#include <iomanip>

class database
{
private:
    vector<person> persons;

public:
    void add(const person& p);
    void erase(const person& p);
    void load(const string& filename);
    void save(const string& filename);
    int size() const;
    person get(int index);

    friend ostream& operator<<(ostream& out, const database& db);
};


#endif //LAB18_2_DATABASE_HPP

//
// Created by ankolesn on 23.07.22.
//

#ifndef LAB18_2_PERSON_HPP
#define LAB18_2_PERSON_HPP

#include <iostream>
using namespace std;

class person
{
private:
    string m_name;
    string m_surname;
    int m_year;
    string m_pol;
    string m_passport;

public:
    person(string name, string surname, int year, string pol, string passport);

    string get_name() const;
    string get_surname() const;
    int get_year() const;
    string get_pol() const;
    string get_passport() const;

    bool operator==(const person& p);
};



#endif //LAB18_2_PERSON_HPP

//
// Created by ankolesn on 23.07.22.
//

#include "person.hpp"

person::person(string name, string surname, int year, string pol, string passport)
{
    m_name = name;
    m_surname = surname;
    m_year = year;
    m_pol = pol;
    m_passport = passport;
}

string person::get_name() const
{
    return m_name;
}

string person::get_surname() const
{
    return m_surname;
}

int person::get_year() const
{
    return m_year;
}

string person::get_pol() const
{
    return m_pol;
}

string person::get_passport() const
{
    return m_passport;
}

bool person::operator==(const person& p)
{
    if (m_name == p.m_name && m_surname == p.m_surname && m_year == p.m_year && m_pol == p.m_pol && m_passport == p.m_passport)
        return true;
    else
        return false;
}

//
// Created by ankolesn on 23.07.22.
//

#include "database.hpp"

void database::add(const person& p)
{
    persons.push_back(p);
}

void database::erase(const person& p)
{
    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i] == p) {
            persons.erase(persons.begin() + i);
            break;
        }
    }
}

void database::load(const string& filename)
{
    /*persons.clear();*/
    ifstream file(filename);
    string name, surname, pol, passport;
    int year;

    while (file >> name >> surname >> year >> pol >> passport)
    {
        person p(name, surname, year, pol, passport);
        add(p);
    }
    file.close();
}

void database::save(const string& filename)
{
    ofstream file(filename);
    for (person& p : persons) {
        file << p.get_name() << " " << p.get_surname() << " " << p.get_year() << " " << p.get_pol() << " " << p.get_passport() << endl;
    }
    file.close();
}

int database::size() const
{
    return persons.size();
}

person database::get(int index)
{
    return persons[index];
}

ostream& operator<<(ostream& out, const database& db)
{
    for (const person& p : db.persons) {
        out << setw(15) << p.get_name() << setw(15) << p.get_surname() << setw(10) << p.get_year() <<
            setw(10) << p.get_pol() << setw(15) << p.get_passport() << endl;
    }
    return out;
}
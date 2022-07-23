#include <iostream>
#include "database.hpp"
#include "person.hpp"
using namespace std;

person create_person() {
    string name;
    string surname;
    int year;
    string pol;
    string passport;
    int p;

    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter surname: " << endl;
    cin >> surname;
    cout << "Enter year: " << endl;
    cin >> year;
    cout << "Enter gender: 1 - male, 2 - female " << endl;
    cin >> p;
    if (p == 1)
        pol = "Male";
    else if (p == 2)
        pol = "Female";
    cout << "Enter passport: ";
    cin >> passport;
    person person1(name, surname, year, pol, passport);
    return person1;
}

int main()
{

    database db;

    int choice;
    do
    {
        cout << "1. Create person" << endl;
        cout << "2. Erase person" << endl;
        cout << "3. Load" << endl;
        cout << "4. Save" << endl;
        cout << "5. Output database" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
            case 1: {
                person p = create_person();
                db.add(p);
                break;
            }
            case 2: {
                string name, surname;
                cout << "Enter name: " << endl;
                cin >> name;
                cout << "Enter surname: " << endl;
                cin >> surname;
                bool check = false;
                for (int i = 0; i < db.size(); i++)
                {
                    if (db.get(i).get_name() == name && db.get(i).get_surname() == surname) {
                        db.erase(db.get(i));
                        check = true;
                        break;
                    }
                }
                if (check == true) {
                    cout << "Person is erase" << endl;
                }
                else {
                    cout << "Person isn't exist" << endl;
                }
                break;
            }
            case 3: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                db.load(filename);
                break;
            }
            case 4: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                db.save(filename);
                break;
            }
            case 5: {
                cout << db;
                break;
            }
            case 0:
                break;
        }
    }
    while (choice != 0);
}

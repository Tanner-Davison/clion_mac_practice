#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    vector<Person*> people;
    people.emplace_back(new Person("tanner", 28));
    for(auto it = people.begin(); it < people.end(); ++it)
    {

        //better syntax when derefencing a member from an iterator pointer (*it)->mem;
        cout << (*it)->name << " is " << (*it)->age << " years old." << endl;
    }

    for(auto& p: people)
    {
        delete p;
    }

    return 0;
}
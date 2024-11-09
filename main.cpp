#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <array>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int nums[]={1,2,3,4,5};
    vector<int> mynums(begin(nums), end(nums));
    vector<int> subVec(nums, nums+5);

    size_t sz = mynums.size();
    cout << sz << " sz here!" << endl;

    int iarr[sz];
    ranges::copy(mynums.begin(),mynums.end(), iarr);

    for(const auto& i: iarr)
    {
        cout << i << endl;
    }
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
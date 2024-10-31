#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Home
{
    int x;
    std::string street;
    std::string home_name;
    Home():x(0){};
    Home(const int xP, std::string yP, std::string home_nameP):
    x(xP),
    street(std::move(yP)),
    home_name(std::move(home_nameP))
    {
        std::cout<< "Home constructed" << std::endl;
    }
    Home& operator=(const Home& rhs)
    {
        this->x = rhs.x;
        this->street = rhs.street;
        this->home_name = rhs.home_name;
        return *this;
    }
    friend std::ostream& operator <<(std::ostream& output, const Home& homeP)
    {
       output << "Street: " << homeP.x << " " << homeP.street
        << " \n" << "Type: " << homeP.home_name;
        return output;
    }
};

class Family
{
public:
    std::string name;
    std::vector<Home> homes;
    Home* home;

    Family(std::string nameP, Home& homeP):
    name(std::move(nameP)),
    home(&homeP)
    {
        homes.push_back(homeP);
    }

    friend std::ostream& operator <<(std::ostream& output, const Family& family)
    {
        output << family.name << "\n Family \n"
               << "Created the "
               << family.home->home_name
               << "\nLocated on street "
               << family.home->x
               << " "
               << family.home->street << "\n"
               << "\n # of homes: " << family.homes.size();  // Use size() instead of count

        // Print all homes in the vector
        for(size_t i = 0; i < family.homes.size(); i++)
        {
            output << "\nHome " << (i + 1) << ":\n" << family.homes[i];
        }

        return output;
    }

    ~Family(){ home = nullptr; }

    void add_home(Home& addHomeP)
    {
        this->homes.push_back(addHomeP);
    }
};

Home createHome()
{
    Home temp;
    std::cout << "Enter street number: "<<std::endl;
    std::cin >> temp.x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Street name: " << std::endl;
    getline(std::cin, temp.street);

    std::cout << "Enter Home Type ex) 'Vacation Home': " <<std::endl;
    getline(std::cin, temp.home_name);

    return temp;
}

int main() {
    auto address = new Home;

    std::cout << "Enter street number: "<<std::endl;
    std::cin >> address->x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Street name: " << std::endl;
    getline(std::cin, address->street);

    std::cout << "Enter Home Type ex) 'Vacation Home': " <<std::endl;
    getline(std::cin, address->home_name);  // Changed to getline

    Family tanner{"Davison", *address};

    char addMore = 'y';
    while(addMore == 'y' || addMore == 'Y')
    {
        Home home_addition = createHome();
        tanner.add_home(home_addition);
        std::cout << "\nAdd another home? (y/n): ";
        std::cin >> addMore;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nFinal Family Information:\n" << tanner << std::endl;

    delete address;
    return 0;
}

/*
 //const int* const ptr = &x;
//  ^      ^
//  |      |
//  |      const pointer (CAN'T reassign)
//  const int (CAN'T modify value)

// This has BOTH:
// 1. Low-level const (const int) - can't modify value
// 2. High-level const (const ptr) - can't reassign pointer*/
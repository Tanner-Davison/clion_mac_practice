#include <iostream>
using std::cout,std::endl, std::cin;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <cctype>
using std::isspace, std::empty;


int main() {
    string input_string;
    vector<string> result_vector;
    int index = 0;
    while(getline(cin, input_string) && !input_string.empty())
    {
       if(!input_string.empty())
       {
           string temp_word;
                for(const auto& c : input_string)
                    {
                    if(!isspace(c))
                        temp_word += static_cast<char>(toupper(c));
                    else if(!temp_word.empty())
                    {
                        result_vector.emplace_back(temp_word);
                        temp_word.clear();
                    }
           }
           if(!temp_word.empty())
                result_vector.emplace_back(temp_word);
       }
    }

    for(const auto& word: result_vector)
    {
        if(index > 0 && index % 9 ==0)
            cout << "\n";
        cout << word << " ";
        ++index;
    }
    cout << '\n';
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
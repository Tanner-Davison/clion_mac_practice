#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <array>
using namespace std;

int main()
{
constexpr int row=10, col=5;

    int matrix[row][col];
    for(size_t i = 0; i != row; ++i)
    {
        for(size_t j = 0; j != col; ++j)
        {
            matrix[i][j] = i * col +j;
        }
    }

    size_t count = 0;

    //using library begin and end pointer functions;
    // for(auto p = begin(matrix); p != end(matrix); ++p)
    // {
    //     cout << ++count << "\n";
    //     for(auto q = begin(*p); q != end(*p);++q)
    //     {
    //         cout << "\t" <<  *q << " ";
    //     }
    //     cout << endl;
    // }

    //using the exact same as the one below just using keyword auto
    for(auto p = matrix; p != matrix+row; ++p)
    {
        cout <<"# "<< ++count << "\n";
        for(auto q = *p; q != *p + col; ++q)
        {
            cout <<"\t"<< *q << " ";
        }
        cout << endl;
    }
    // USING POINTERS TO ARRAY INDICES TO DERIVE VALUE AND SET THE ITERATORS;
    // for(int(*p)[5] = matrix; p != matrix+row; ++p)
    // {
    //     cout <<"# "<< ++count << "\n";
    //     for(int*q = *p; q != *p + col; ++q)
    //     {
    //         cout <<"\t"<< *q << " ";
    //     }
    //     cout << endl;
    // }


    //USES THE RANGE BASE FOR LOOP (MAKE SURE TO USE '&' REFERENCE;
    //
    // int count = 0;
    // for(auto & rowval : matrix)
    // {
    //     cout << "\n# " << ++count << endl;;
    //     for(const int column : rowval)
    //     {
    //         cout <<"\t" << column << " ";
    //     }
    //     cout <<endl;
    // }
    //

    return 0;
}
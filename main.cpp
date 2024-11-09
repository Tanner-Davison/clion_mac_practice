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
    int count = 0;
    for(auto & rowval : matrix)
    {
        cout << "\n# " << ++count << endl;;
        for(const int column : rowval)
        {
            cout <<"\t" << column << " ";
        }
        cout <<endl;
    }

    return 0;
}
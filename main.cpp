#include <iostream>
#include <string>

using namespace std;

int main() {

    char ca[]={'c','h','a','r','\0'};
    char ca2[]={'a','r','r','a','y','\0'};

    size_t csize = (strlen(ca)+1) + (strlen(ca2)+1);
    char combined[csize];


    if(sizeof(combined) >= csize)
    {
        strcpy(combined, ca);
        strcat(combined, " ");
        strcat(combined, ca2);
    }
    char *p = combined;
    while(*p)
    {
        cout << *p;
        ++p;
    }
    cout << endl;
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
#include <iostream>
#include <print>


int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    auto a = r; // OK a is int;
    auto b = ci;// OK b is int;
    auto c = cr;// OK c is int;
    auto d = &i;// OK d is int pointer;
    auto e = &ci;// OK e is a const int *;
    const auto f = ci;// OK f is const int;
    auto &g = ci; //OK &g is a const int&;
    // auto &h = 42; error cant bind non-const literal to h;
    const auto&j = 42;
    a = 42;
    b = 42;
    c =42;
    //d = 42; // d is a pointer this is an error;
    //e = 42; // this is a constant reference binding and will error;
    *d = 42;
    i =10;
    //g = 42;// g throws an error because you cannot redeclare a constant int
    int y = 42;
    const auto &p = y + 2;
    y = 10;
    int z = 100;
    auto *ptr = &z;
    auto &ref = *ptr;
    ref =50;
    std::cout << z;
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
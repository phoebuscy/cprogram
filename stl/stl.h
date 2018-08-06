//
// Created by phoeb on 2018/8/6.
//

#ifndef CPROGRAM_STL_H
#define CPROGRAM_STL_H



#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


template<typename T>
class Print
{
public:
    void operator()(T a)
    {
        cout << a << " ";
    }
};

int test_remove();

int test_remove_if();
int test_remove_copy_if();
bool IsOdd (int i);



#endif //CPROGRAM_STL_H

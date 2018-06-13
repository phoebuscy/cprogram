//
// Created by phoeb on 2018/6/10.
//

#include "maintest.h"

#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>


using namespace std;

int main()
{
    map<int , list<string>> intLstMap;
    intLstMap[1].push_back("aaa");
    intLstMap[1].push_back("bbb");

    intLstMap[2].push_back("ccc");
    intLstMap[2].push_back("ddd");

    list<string> tmplst = intLstMap.at(3);


    int a = 1;
}


//
// Created by phoeb on 2018/8/6.
//
/**
 * ÖÇÄÜÖ¸ÕëÀý×Ó
 */

#ifndef CPROGRAM_SMARTPTR_H
#define CPROGRAM_SMARTPTR_H

#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

class Song
{
public:
    Song(string artist, string title);

    ~Song();

public:
    string artist;
    string title;

};


#endif //CPROGRAM_SMARTPTR_H

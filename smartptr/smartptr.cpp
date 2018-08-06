//
// Created by phoeb on 2018/8/6.
//
#include "smartptr.h"
#include <iostream>
#include <esent.h>
#include <list>

using namespace std;


int main_smartptr()
{
    vector<shared_ptr<Song>> v;

    v.push_back(make_shared<Song>("111","111aaaa"));
    v.push_back(make_shared<Song>("222","222aaa"));
    v.push_back(make_shared<Song>("333", "333aaa"));

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
    {
        return s->artist.compare("222") == 0;
    });

    for (const auto& s : v2)
    {
        cout << s->artist << ":" << s->title << endl;
    }





    return (0);
}






Song::Song(string artist, string title)
{
    this->artist = artist;
    this->title = title;
}

Song::~Song()
{

}

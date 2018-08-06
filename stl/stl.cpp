//
// Created by phoeb on 2018/8/6.
//

#include "stl.h"


#include "smartptr.h"
#include <iostream>
#include <esent.h>
#include <list>

using namespace std;


int main()
{
    // int a = test_remove();
    // int b = test_remove_if();
    int c = test_remove_copy_if();

    return 0;
}


int test_remove()
{
    list<int> s = {1, 9, 5, 4, 2, 6, 5, 7, 8, 5, 10};
    //remove算法，除去使第三个参数的值为true的元素.
    //注意，不管是什么算法，是不可能对原容器的元素的数量进行改变的，换句话说，
    // 就是算法不可能对容器进行增加元素或者删除元素的操作，所以remove算法只是把原容器的元素进行了筛选重组了而已，元素的数量还是原来的数量.
    list<int>::iterator pos = remove(s.begin(), s.end(), 5);
    for_each(s.begin(), s.end(), Print<int>());    //1 9 4 2 6 7 5 7
    cout << endl;

    //容器内元素的增减只能通过容器自身所带的函数，比如:erase()或insert(),addpend()等等.
    s.erase(pos, s.end());
    for_each(s.begin(), s.end(), Print<int>());    //1 9 4 2 6 7
    cout << endl;

    // system("pause");

    return 0;
}

int test_remove_if()
{
    list<int> s = {1, 9, 5, 4, 2, 6, 5, 7};

    //第三个参数可以看成是:如果元素>5,则返回true,否则返回false,这是个仿函数和配接器的配套使用.只能用于简单的操作，
    // 一些比较复杂的东西还是要自己去定制一个模板类，去重载()操作符滴...
    list<int>::iterator pos = remove_if(s.begin(), s.end(), bind2nd(greater<int>(), 5));
    for_each(s.begin(), s.end(), Print<int>());     // 1 5 4 2 5 6 5 7
    cout << endl;

    s.erase(pos, s.end());
    for_each(s.begin(), s.end(), Print<int>());      // 1 5 4 2 5
    cout << endl;

    return 0;
}

bool IsOdd(int i)
{
    return ((i % 2) == 1);
}

int test_remove_copy_if()
{
    int myints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> myvector;

   // std::remove_copy_if(myints, myints + 9, myvector.begin(), IsOdd);
    std::remove_copy_if(myints, myints + 9, back_inserter(myvector), IsOdd);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << endl;

    cout << "print by for: ";
    for(int a: myvector)
    {
        cout << ' ' << a;
    }
    cout << endl;

    cout << "print by for_each : ";
    for_each(myvector.begin(), myvector.end(), Print<int>());
    cout << endl;

    return 0;
}

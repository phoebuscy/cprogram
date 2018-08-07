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
    // int c = test_remove_copy_if();
    // int d = test_replace_copy_if();
    int e = test_replace_copy();

    return 0;
}


int test_remove()
{
    list<int> s = {1, 9, 5, 4, 2, 6, 5, 7, 8, 5, 10};
    //remove�㷨����ȥʹ������������ֵΪtrue��Ԫ��.
    //ע�⣬������ʲô�㷨���ǲ����ܶ�ԭ������Ԫ�ص��������иı�ģ����仰˵��
    // �����㷨�����ܶ�������������Ԫ�ػ���ɾ��Ԫ�صĲ���������remove�㷨ֻ�ǰ�ԭ������Ԫ�ؽ�����ɸѡ�����˶��ѣ�Ԫ�ص���������ԭ��������.
    list<int>::iterator pos = remove(s.begin(), s.end(), 5);
    for_each(s.begin(), s.end(), Print<int>());    //1 9 4 2 6 7 5 7
    cout << endl;

    //������Ԫ�ص�����ֻ��ͨ���������������ĺ���������:erase()��insert(),addpend()�ȵ�.
    s.erase(pos, s.end());
    for_each(s.begin(), s.end(), Print<int>());    //1 9 4 2 6 7
    cout << endl;

    // system("pause");

    return 0;
}

int test_remove_if()
{
    list<int> s = {1, 9, 5, 4, 2, 6, 5, 7};

    //�������������Կ�����:���Ԫ��>5,�򷵻�true,���򷵻�false,���Ǹ��º����������������ʹ��.ֻ�����ڼ򵥵Ĳ�����
    // һЩ�Ƚϸ��ӵĶ�������Ҫ�Լ�ȥ����һ��ģ���࣬ȥ����()��������...
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
    for (int a: myvector)
    {
        cout << ' ' << a;
    }
    cout << endl;

    cout << "print by for_each : ";
    for_each(myvector.begin(), myvector.end(), Print<int>());
    cout << endl;

    return 0;
}

int test_replace_copy_if()
{
    std::vector<int> foo, bar;
    // set some values:
    for (int i = 1; i < 10; i++)
    { foo.push_back(i); }              // 1 2 3 4 5 6 7 8 9

    bar.resize(foo.size());            // allocate space
    std::replace_copy_if(foo.begin(), foo.end(), bar.begin(), IsOdd, 0);
    // 0 2 0 4 0 6 0 8 0

    std::cout << "bar contains:";
    for_each(bar.begin(), bar.end(), Print<int>());
    cout << endl;

    return 0;
}

int test_replace_copy()
{
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};

    std::vector<int> myvector(8);
    std::replace_copy(myints, myints + 8, myvector.begin(), 20, 99);

    std::cout << "myvector contains:";
    for_each(myvector.begin(), myvector.end(), Print<int>());
    std::cout << endl;

    return 0;
}

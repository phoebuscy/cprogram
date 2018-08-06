
#include "maintest.h"

#include <list>
#include <string>
#include <memory>
#include "../smartptr/smartptr.h"

using namespace std;

typedef unsigned long long U64;
typedef long long I64;

extern "C"
{
    void SmartPointerDemo2();
}




int main_main()
{

    int a = 9;
    int b = 8;

    int c = b / a;

    SmartPointerDemo2();
    return 0;
}


class LargeObject
{
public:
    LargeObject()
    {

    }
    void DoSomething()
    {}
};

void ProcessLargeObject(const LargeObject &lo)
{}

void SmartPointerDemo()
{
    // Create the object and pass it to a smart pointer
    unique_ptr<LargeObject> pLarge(new LargeObject());

    //Call a method on the object
    pLarge->DoSomething();

    // Pass a reference to a method.
    ProcessLargeObject(*pLarge);

} //pLarge is deleted automatically when function block goes out of scope.




void SmartPointerDemo2()
{
    // Create the object and pass it to a smart pointer
    std::unique_ptr<LargeObject> pLarge(new LargeObject());

    //Call a method on the object
    pLarge->DoSomething();

    // Free the memory before we exit function block.
    pLarge.reset();

    auto sp1 = make_shared<LargeObject>();
    shared_ptr<LargeObject> sp5(NULL);

    // Do some other work...

}




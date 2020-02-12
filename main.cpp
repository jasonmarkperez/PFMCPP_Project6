/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or const reference types ** WHERE POSSIBLE **
    hint: There is no reference equivalent to nullptr.  
    So don't try to convert nullptr, if nullptr is being returned anywhere
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>

struct T
{
    int value = 0;
    const char* name = nullptr;
    
    T(int valueIn, const char* nameIn) : value(valueIn), name(nameIn) {}
};

struct Comparer
{
    T* compare(T &a, T &b)
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float foo { 0 }, bar { 0 };
    float multiply(float &updatedValue)
    {
        std::cout << "U's foo value: " << foo << std::endl;
        foo = updatedValue;
        std::cout << "U's foo updated value: " << foo << std::endl;
        while( std::abs(bar - foo) > 0.001f )
        {   
            bar += 0.001f;
        }
        std::cout << "U's bar updated value: " << bar << std::endl;
        return bar * foo;
    }
};

struct staticStruct
{
    static float staticFunctionA(U &that, float &updatedValue)
    {
        std::cout << "U's foo value: " << that.foo << std::endl;
        that.foo = updatedValue;
        std::cout << "U's foo updated value: " << that.foo << std::endl;
        while( std::abs(that.bar - that.foo) > 0.001f )
        {
            that.bar += 0.001f;
        }
        std::cout << "U's bar updated value: " << that.bar << std::endl;
        return that.bar * that.foo;
    }
};


int main()
{
    T name1(40, "foo");
    T name2(60, "zbar");
    Comparer f;
    T* smaller = f.compare(name1, name2);
    std::cout << "the smaller one is << " << smaller->name << std::endl;
    
    U u;
    float updatedValue = 5.f;
    std::cout << " [static func] u's multiple values: " << staticStruct::staticFunctionA(u, updatedValue)
    << std::endl;

    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.multiply(updatedValue) << std::endl;
}

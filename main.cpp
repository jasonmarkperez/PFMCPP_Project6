/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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

struct U
{
    float foo { 0 }, bar { 0 };
    float multiply(float* updatedValue)
    {
        if(updatedValue != nullptr)
        {
            std::cout << "U's foo value: " << this->foo << std::endl;
            this->foo = *updatedValue;
            std::cout << "U's foo updated value: " << this->foo << std::endl;
            while( std::abs(this->bar - this->foo) > 0.001f )
            {   
                this->bar += 0.001f;
            }
            std::cout << "U's bar updated value: " << this->bar << std::endl;
            return this->bar * this->foo;
        }
        return 0;
    }
};

struct Struct2
{
    static float staticFunctionA(U* that, float* updatedValue)
    {
        if(that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's foo value: " << that->foo << std::endl;
            that->foo = *updatedValue;
            std::cout << "U's foo updated value: " << that->foo << std::endl;
            while( std::abs(that->bar - that->foo) > 0.001f )
            {
                that->bar += 0.001f;
            }
            std::cout << "U's bar updated value: " << that->bar << std::endl;
            return that->bar * that->foo;
        }
        return 0;
    }
};

struct Comparer                                //4
{
    T* compare(T* a, T* b) //5
    {   
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};


int main()
{
    T name1(40, "foo");
    T name2(60, "zbar");
    Comparer f;
    f.compare(&name1, &name2);
    auto* smaller = f.compare(&name1, &name2);
    std::cout << "the smaller one is << " << smaller->name << std::endl;
    
    U u;
    float updatedValue = 5.f;
    std::cout << " [static func] u's multiple values: " << Struct2::staticFunctionA(&u, &updatedValue)
    << std::endl;

    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.multiply( &updatedValue ) << std::endl;
}

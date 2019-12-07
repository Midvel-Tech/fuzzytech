#include <iostream>

#include <fuzzyset.h>

int main()
{
    std::cout << "Test1\n";

    fuzzy::FuzzySet fs1;
    fuzzy::FuzzySet fs2( "other_name" );

    std::cout << fs1.name() << "\n";

    std::string sName1 = fs2.name();
    sName1 += " modified";
    std::cout << sName1 << " " << fs2.name() << "\n";


    std::cout << "\nTest2\n";
    fuzzy::t_FZContainer ex1;
    ex1.insert( { 1, 0.0 } );
    ex1.insert( { 2, 0.5 } );
    ex1.insert( { 3, 1.0 } );
    fuzzy::FuzzySet fs3( ex1 );
    fuzzy::FuzzySet fs4( ex1, "new_name" );

    std::cout << fs3.name() << " " << fs4.name() << "\n";

    std::cout << "\nTest3\n";
    fuzzy::t_FZContainer ex2;
    ex2.insert( { 1, 1.5 } );

    try
    {
        fuzzy::FuzzySet fs5( ex2 );
    }
    catch ( const char* message )
    {
        std::cout << message << "\n";
    }

    std::cout << "\nTest4\n";
    fuzzy::FuzzySet fs5( fs2 );
    fuzzy::FuzzySet fs6;
    fs6 = fs4;

    std::cout << fs5.name() << " " << fs6.name() << "\n";


    std::cout << "Test file for fuzzy functionality\n"; 
    return 0;
}

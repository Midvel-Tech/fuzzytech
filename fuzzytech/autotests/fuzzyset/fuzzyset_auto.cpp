#include <iostream>

#include "gtest/gtest.h"

#include "fuzzyset/fuzzyset.h"

TEST( FuzzySetCreation, defaultName )
{
    fuzzy::FuzzySet fs;

    EXPECT_STREQ( fs.name().c_str(), "newfset" );
}

TEST( FuzzySetCreation, customName )
{
    const char* customName = "custom_name";
    fuzzy::FuzzySet fs( customName );

    EXPECT_STREQ( fs.name().c_str(), customName );
}

TEST( FuzzySetCreation, equalSets )
{
    //Uncomment for equality operator
    fuzzy::t_FZContainer numSet;
    numSet.insert( { 1, 0.0 } );
    numSet.insert( { 2, 0.5 } );
    numSet.insert( { 3, 1.0 } );

    fuzzy::FuzzySet fs1( numSet );
    fuzzy::FuzzySet fs2( numSet );
    fuzzy::FuzzySet fs3( numSet, "custom_name" );

    //    EXPECT_TRUE( fs1 == fs2 );
    //    EXPECT_TRUE( fs1 == fs3 );
    //    EXPECT_TRUE( fs3 == fs2 );
}

TEST( FuzzySetCreation, assignmentTest )
{
    const char* customName = "custom_name";
    fuzzy::FuzzySet fs1( customName );
    fuzzy::FuzzySet fs2( fs1 );
    fuzzy::FuzzySet fs3;
    fs3 = fs1;

    //Uncomment after equality implemented
    //    EXPECT_TRUE( fs1 == fs2 );
    //    EXPECT_TRUE( fs1 == fs3 );
    EXPECT_STREQ( fs2.name().c_str(), customName );
    EXPECT_STREQ( fs3.name().c_str(), customName );
}

//All tests for incorrect membership should be added for this testset
TEST( IncorrectMembership, setCreation )
{
    const char* expStr = "FuzzySet: not acceptable membership value.";
    fuzzy::t_FZContainer incorrectNumSet1;
    incorrectNumSet1.insert( { 1, 1.5 } );
    fuzzy::t_FZContainer incorrectNumSet2;
    incorrectNumSet2.insert( { 1, -0.5 } );

    try
    {
        fuzzy::FuzzySet fs( incorrectNumSet1 );
        FAIL() << "Exception was not thrown\n";
    }
    catch ( const char* expected )
    {
        EXPECT_STREQ( expStr, expected );
    }

    try
    {
        fuzzy::FuzzySet fs( incorrectNumSet2 );
        FAIL() << "Exception was not thrown\n";
    }
    catch ( const char* expected )
    {
        ASSERT_STREQ( expStr, expected );
    }
}

//All zero value tests should be added for this testset
TEST( ZeroValue, forCreation )
{
    fuzzy::t_FZContainer numSet;
    numSet.insert( { 1, 0.0 } );
    numSet.insert( { 2, 0.5 } );
    numSet.insert( { 3, 1.0 } );

    fuzzy::FuzzySet fs1( numSet );
    //Uncomment after size method or alpha level is added
    //Test for alpha level should contain Alpha(0) == Original set
}

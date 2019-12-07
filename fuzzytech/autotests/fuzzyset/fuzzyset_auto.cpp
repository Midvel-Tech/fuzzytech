#include <iostream>

#include "gtest/gtest.h"

#include "fuzzyset/fuzzyset.h"

TEST(FuzzySetCreation, defaultName)
{
    fuzzy::FuzzySet fs1;

    ASSERT_STREQ(fs1.name().c_str(), "newfset");
}
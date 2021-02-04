#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include "palindrome.hpp"

TEST_CASE("Check palindrome for empty String"){
    REQUIRE(palindrome("")==true);
}

TEST_CASE("Check case for single character input"){
    REQUIRE(palindrome("a") == true);
    REQUIRE(palindrome("2") == true);
}

TEST_CASE("Check for non palindrome input")
{
    REQUIRE(palindrome("nope") == false);
    REQUIRE(palindrome("helloWorld") == false);
}

TEST_CASE("Check for palindrome input")
{
    REQUIRE(palindrome("malayalam") == true);
    REQUIRE(palindrome("racecar") == true);
    REQUIRE(palindrome("12121") == true);
    REQUIRE(palindrome("aaa") == true);
}

TEST_CASE("Check for non palindrome because of differect case"){
    REQUIRE(palindrome("Malayalam") == false);
    REQUIRE(palindrome("Racecar") == false);
}
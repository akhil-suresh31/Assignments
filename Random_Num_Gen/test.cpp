#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"randNum.hpp"

TEST_CASE("passed 1 as parameter")
{
    REQUIRE(randNumGen(1) == 0);
}

TEST_CASE("Passing positive integer")
{
    REQUIRE(randNumGen(79) < 79);
}
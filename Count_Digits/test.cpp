#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"CountDigits.hpp"

SCENARIO("Counting digits of negetive number"){
    GIVEN("A negetive number"){
        WHEN("single digit -ve no. is passed"){
            THEN("only the digits are taken into count"){
                REQUIRE(countDigits(-0) ==  1);
            }
        }
    }
}
SCENARIO("Counding digits of positive no."){
    GIVEN("Positive no. is passed"){
        WHEN("Pass a number with n digits"){
            THEN("Returns n as count "){
                REQUIRE(countDigits(4512) == 4);
            }
        }
    }
}

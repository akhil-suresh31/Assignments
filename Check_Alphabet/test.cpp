#define CATCH_CONFIG_MAIN

#include"../catch.hpp"
#include"CheckAlpha.hpp"

TEST_CASE("empty character passed"){
    SECTION("Passing space as input"){
        REQUIRE(checkAlpha(' ') == false);
    }

    SECTION("Passing tab space char"){
        
        REQUIRE(checkAlpha('\t') == false);
    }

    SECTION("Passing nect line character"){
        REQUIRE(checkAlpha('\n') == false);
    }
}

TEST_CASE("Passing non Alphabets"){
    SECTION("Passing digits"){
        REQUIRE(checkAlpha('0') == false);
        REQUIRE(checkAlpha('8') == false);
    }

    SECTION("Passing symbols "){
        REQUIRE(checkAlpha('[') == false);
        REQUIRE(checkAlpha('$') == false);
    }
}

TEST_CASE("Passing alphabets"){
    SECTION("passing lowercase alphabet"){
        REQUIRE(checkAlpha('a') == true);
        REQUIRE(checkAlpha('j') == true);
    }

    SECTION("Passing uppercase alphabet"){
        REQUIRE(checkAlpha('A') == true);
        REQUIRE(checkAlpha('J') == true);
    }
}

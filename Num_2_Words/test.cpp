#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"Num2Words.hpp"

SCENARIO("Invalid input is rejected or handled"){
    GIVEN("An invalid input to the program"){
        string num;
        WHEN("The input has no number after -(negetive sign)"){
            num="-";
            THEN("The function returns invalid input"){
                REQUIRE(num2word(num) == "Invalid input");
            }
        }
        WHEN("The input has alphabets after -(negetive sign)"){
            num="-asd";
            THEN("The function returns invalid input"){
                REQUIRE(num2word(num) == "Invalid input");
            }
        }
        WHEN("The input's negetive sign does not preceed other numbers"){
            num =" 98-" ;
            THEN("The function returns invalid input"){
                REQUIRE(num2word(num) == "Invalid input");
                num = "9-8";
                REQUIRE(num2word(num) == "Invalid input");
            }
        }

        WHEN("The input has only alphabets"){
            num="asdfa";
            THEN("THE function returns invalid input"){
                REQUIRE(num2word(num) == "Invalid input");
            }
        }
        WHEN("The input has atleast 1 character which is not a digit"){
            num="12378o9";
            THEN("The function returns invalid input"){
                REQUIRE(num2word(num) == "Invalid input");
            }
        }
        WHEN("The input has more than 21 characters"){
            num="7182749372638472615231";
            THEN("The function returns invalid input"){
                REQUIRE(num2word(num) == "Invalid input");
            }
        }
    }
}

SCENARIO("Numbers with preeceding zero"){
    GIVEN("Number input with preceeding zeros"){
        string num;
        WHEN("positive number is preceeded with some zeros"){
            num = "0000200";
            THEN("function ignores preeceding zeros and prints word of remaining number"){
                REQUIRE(num2word(num) == "two hundred");
            }
        }
        WHEN("negetive number is preeceded with some zero"){
            num = "-000200";
            THEN("function ignores preeceding zeros and prints word of remaining number"){
                REQUIRE(num2word(num) == "minus two hundred");
            }
        }
    }
}

SCENARIO("Negetive numbers can be converted to words"){
    GIVEN("Valid negetive number input"){
        string num;
        WHEN("The number is -0"){
            num="-0";
            THEN("Fucntion corrects it to zero"){
                REQUIRE(num2word(num) == "zero");
            }
        }
        WHEN("The number is negetive"){
            THEN("Fucntion adds minus in front of the number"){
                num = "-1";
                REQUIRE(num2word(num) == "minus one");
                num = "-4862";
                REQUIRE(num2word(num) == "minus four thousand eight hundred sixty two");
            }
        }
    }
}

SCENARIO("Positive numbers can be converted to words"){
    GIVEN("Valid Positive number input"){
        string num;
        WHEN("The number is 0"){
            num="0";
            THEN("function returns zero"){
                REQUIRE(num2word(num) == "zero");
            }
        }
        WHEN("the number is single digit"){
            THEN("function return appropriate words"){
                REQUIRE(num2word("1") == "one");
                REQUIRE(num2word("6") == "six");
            }
        }
        WHEN("The number is two digit"){
            THEN("function returns appropriate words"){
                REQUIRE(num2word("15") == "fifteen");
                REQUIRE(num2word("65") == "sixty five");
                REQUIRE(num2word("99") == "ninety nine");
            }
        }
        WHEN("The number is more than less than 6 digits"){
            REQUIRE(num2word("402") == "four hundred two");
            REQUIRE(num2word("1002") == "one thousand two");
            REQUIRE(num2word("1202") == "one thousand two hundred two");
            REQUIRE(num2word("10002") == "ten thousand two");
        }
        WHEN("The number is more than 6 digits"){
            REQUIRE(num2word("4000000") == "fourty lakh");
            REQUIRE(num2word("6700015000") == "six arab seventy crore fifteen thousand");
        }
    }
}
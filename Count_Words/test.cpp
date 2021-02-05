#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include<map>
#include"WordFreq.hpp"

TEST_CASE("Function Retrieves all words"){
    map<string,int> words;
    SECTION("Input file has 22 words"){
        words=getWords();
       REQUIRE(words.size() == 23);
    }
}

TEST_CASE("Return correct count of words"){
    map<string,int> words = getWords();
    string word;
    SECTION("The word does not exist, count=0"){
        REQUIRE(getWordCount(words,"home") == 0);
    }
    SECTION("The word Exists"){
        REQUIRE(getWordCount(words,"Help") == 2);
    }
}
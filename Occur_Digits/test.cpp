#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"OccurDigits.hpp"

TEST_CASE("Passed a single digit charcter to function")
{
    std::string num;
    int *arr=(int *)calloc(10,sizeof(int));
    SECTION("Passing 1 as input")
    {   num="1";
        REQUIRE(countDig(num,arr)[1]==1);
    }
    SECTION("passing one digit and rest alphabet ")
    {
        num="asd6asd";
        REQUIRE(countDig(num,arr)[6]==1);
    }
}

TEST_CASE("Passing multiple digits, multiple times")
{
    std::string num;
    int *arr=(int *)calloc(10,sizeof(int));
    SECTION("Passing 222 as input")
    {
        num="222";
        REQUIRE(countDig(num,arr)[2]==3);
    }
    SECTION("passing 222444 as input")
    {
        num="222444";
        arr=countDig(num,arr);
        REQUIRE(arr[2]==3);
        REQUIRE(arr[4]==3);
    }
}

TEST_CASE("PAssing no digits")
{
    std::string num;
    int *arr=(int *)calloc(10,sizeof(int));
    SECTION("Passing asd as input")
    {
        num="asd";
        int count=0;
        arr=countDig(num,arr);
        for(int i=0;i<10;i++)
            count+=arr[i];
        REQUIRE(count == 0);
    }
}
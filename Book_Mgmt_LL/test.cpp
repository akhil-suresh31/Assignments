#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"BookMgmtLL.hpp"


TEST_CASE("inserting a book"){
    struct list *head = NULL;
    struct Book b={12,"book","auth",321};
    struct Book b2={13,"a Book","famous",400};
    struct Book b3={15,"a  bad Book","unfamous",400};
    REQUIRE(book_count(head) == 0);
    head = insertBook(head,b2);
    REQUIRE(book_count(head) == 1);
    head = insertBook(head,b);
    REQUIRE(book_count(head) == 2);
    head = insertBook(head,b3);
    REQUIRE(book_count(head) == 3);
    head = insertBook(head,b);
    REQUIRE(book_count(head) == 3);
}

TEST_CASE("Removing book"){
    struct list *head = NULL;
    struct Book b={12,"book","auth",321};
    struct Book b2={13,"a Book","famous",400};
    head= removeBook(head,12);
    REQUIRE(book_count(head) == 0);
    head = insertBook(head,b);
    head = insertBook(head,b2);
    REQUIRE(book_count(head) == 2);
    head = removeBook(head,12);
    REQUIRE(book_count(head) == 1);
    head = removeBook(head,12);
    REQUIRE(book_count(head) == 1);
    head = removeBook(head,13);
    REQUIRE(book_count(head) == 0);
}

TEST_CASE("Searching for a book"){
    struct list *head = NULL;
    struct Book b={12,"book","auth",321};
    struct Book b2={13,"a Book","famous",400};
    struct Book b3={15,"a  bad Book","unfamous",400};
    REQUIRE(search(head,0) == false);
    head = insertBook(head,b2);
    head = insertBook(head,b);
    head = insertBook(head,b3);
    REQUIRE(search(head,13) == true);
    REQUIRE(search(head,14) == false);
}
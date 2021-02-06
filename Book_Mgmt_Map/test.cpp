#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"BookMgmtMap.hpp"

SCENARIO("Inserting a book")
{   map<int,struct Book> Books;
    GIVEN("A empty Map with no book"){
        WHEN("A new book is added to it"){
            struct Book b = {12,"Book1","Author2",457};
            THEN("Book is added successfully"){
                REQUIRE(insertBook(Books,b) == true);
            }
        }
    }
    GIVEN("A map with some books already present"){
        struct Book b1={12,"Book1","Author2",457},b2={13,"Book2","Author1",600},b3={11,"Book3","Author3",200};
        insertBook(Books,b1);
        insertBook(Books,b2);
        insertBook(Books,b3);
        WHEN("A new book is inserted"){
            struct Book b = {15,"New Book","Old Author",1200};
            THEN("Book is added successfully"){
                REQUIRE(insertBook(Books,b) == true);
            }
        }
    }
    GIVEN("A map with some books already present"){
        struct Book b1={12,"Book1","Author2",457},b2={13,"Book2","Author1",600},b3={11,"Book3","Author3",200};
        insertBook(Books,b1);
        insertBook(Books,b2);
        insertBook(Books,b3);
        WHEN("A old book is inserted(book already exists)"){
            struct Book b = {12,"New Book","Old Author",1200};
            THEN("Book is not added beacause book with same id already exists"){
                REQUIRE(insertBook(Books,b) == false);
            }
        }
    }
}

SCENARIO("Removing a book")
{
    map<int,struct Book> Books;
    GIVEN("an empty list of books"){
        WHEN("Try to remove a book"){
            THEN("No book is removed, list is empty is printed"){
                REQUIRE(removeBook(Books,12) == false);
            }
        }
    }
    GIVEN("a list of books"){
        struct Book b1={12,"Book1","Author2",457},b2={13,"Book2","Author1",600},b3={11,"Book3","Author3",200};
        insertBook(Books,b1);
        insertBook(Books,b2);
        insertBook(Books,b3);
        WHEN("Try to remove a book"){
            THEN("The book is removed"){
                REQUIRE(removeBook(Books,12) == true);
            }
        }
    }
    GIVEN("a list of books"){
        struct Book b1={12,"Book1","Author2",457},b2={13,"Book2","Author1",600},b3={11,"Book3","Author3",200};
        insertBook(Books,b1);
        insertBook(Books,b2);
        insertBook(Books,b3);
        WHEN("Try to remove a book which doesnt exist"){
            THEN("No book is removed,shows book doesnt exist"){
                REQUIRE(removeBook(Books,15) == false);
            }
        }
    }
    GIVEN("a Map with only 1 book"){
        struct Book b = {12,"Book1","Author2",457};
        insertBook(Books,b);
        WHEN("Try to remove the book"){
            THEN("the book is removed, list is empty"){
                REQUIRE(removeBook(Books,12) == true);
                REQUIRE(Books.size() == 0);
            }
        }
    }
}

SCENARIO("Searching for a book")
{
    map<int,struct Book> Books;
    GIVEN("A empty list of books"){
        WHEN("Try to search for a book"){
            THEN("Prints Map is empty"){
                REQUIRE(search(Books,12) == false);
            }
        }
    }
    GIVEN("A list of books"){
        struct Book b1={12,"Book1","Author2",457},b2={13,"Book2","Author1",600},b3={11,"Book3","Author3",200};
        insertBook(Books,b1);
        insertBook(Books,b2);
        insertBook(Books,b3);
        WHEN("Try to search for a book which exists"){
            THEN("return true to indicate book exists"){
                REQUIRE(search(Books,12) == true);
            }
        }
    }
    GIVEN("A list of books"){
        struct Book b1={12,"Book1","Author2",457},b2={13,"Book2","Author1",600},b3={11,"Book3","Author3",200};
        insertBook(Books,b1);
        insertBook(Books,b2);
        insertBook(Books,b3);
        WHEN("Try to search for a book which doesnt exists"){
            THEN("Prints no such book exists"){
                REQUIRE(search(Books,15) == false);
            }
        }
    }
}
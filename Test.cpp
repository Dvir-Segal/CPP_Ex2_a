#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <iostream>

TEST_CASE("Without overriding"){
    Board board;
    board.post(0, 1, Direction::Horizontal, "node.js");
    board.post(0 ,0 ,Direction::Vertical, "angular");
    board.post(1, 4, Direction::Horizontal, "java");
    board.post(3, 10, Direction::Horizontal, "python");
    board.post(4, 7, Direction::Vertical, "cpp");

    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "anode");
    CHECK(board.read(0, 0, Direction::Horizontal, 8) == "anode.js");
    CHECK(board.read(0, 3, Direction::Horizontal, 7) == "de.js__");
    CHECK(board.read(0, 7, Direction::Vertical, 6) == "sa__c_");
    CHECK(board.read(0, 0, Direction::Vertical, 10) == "angular___");
    CHECK(board.read(4, 0, Direction::Horizontal, 10) == "l______cpp");
    CHECK(board.read(1, 0, Direction::Horizontal, 6) == "n___ja");
    CHECK(board.read(5, 0, Direction::Vertical, 5) == ".a___");
    CHECK(board.read(2, 0, Direction::Vertical, 7) == "gular__");
    CHECK(board.read(20, 30, Direction::Vertical, 4) == "____");
}

TEST_CASE("Overriding"){
    Board board;
    board.post(0, 1, Direction::Horizontal, "node.js");
    board.post(0 ,0 ,Direction::Vertical, "angular");
    board.post(1, 4, Direction::Horizontal, "java");
    board.post(3, 10, Direction::Horizontal, "python");
    board.post(4, 7, Direction::Vertical, "cpp");
    board.post(0, 7, Direction::Vertical, "script");
    board.post(2, 0, Direction::Vertical, "sharp");
    board.post(3, 8, Direction::Horizontal, "html");
    board.post(0, 2, Direction::Horizontal, "oop");

    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "anoop");
    CHECK(board.read(0, 0, Direction::Horizontal, 8) == "anoop.js");
    CHECK(board.read(0, 3, Direction::Horizontal, 7) == "op.js__");
    CHECK(board.read(0, 7, Direction::Vertical, 6) == "script");
    CHECK(board.read(0, 0, Direction::Vertical, 10) == "ansharp___");
    CHECK(board.read(4, 0, Direction::Horizontal, 10) == "l______ppp");
    CHECK(board.read(1, 0, Direction::Horizontal, 9) == "n___javc_");
    CHECK(board.read(3, 7, Direction::Vertical, 9) == "ihtmlthon");
    CHECK(board.read(1, 0, Direction::Vertical, 7) == "nsharp_");
    CHECK(board.read(1, 8, Direction::Vertical, 4) == "__hp");

}
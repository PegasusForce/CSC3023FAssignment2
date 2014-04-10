/* 
 * File:   main.cpp
 * Author: khagendra
 *
 * Created on 10 April 2014, 5:56 PM
 */

#include <cstdlib>
#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework
using namespace std;

/*
 * 
 
int main(int argc, char** argv) {

    return 0;
}
*/
TEST_CASE("TEST", "")
{
    INFO("Fuck you");
    SECTION("Section1"){
        REQUIRE(5==5);
    }
}


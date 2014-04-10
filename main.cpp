/* 
 * File:   main.cpp
 * Author: khagendra
 *
 * Created on 10 April 2014, 5:56 PM
 */

#include <cstdlib>
#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework
#include "Node.h"
#include "ParseTree.h"
#include "Iterator.h"
using namespace std;

/*
 * 
 
int main(int argc, char** argv) {

    return 0;
}
*/
TEST_CASE("TEST", "")
{
    
    SECTION("Section1"){
        Node root = Node(3,"root");
        ParseTree testTree = ParseTree(&root);
        Iterator it = testTree.begin(); 
        Node one = Node(0,"1");
        Node two = Node(0,"2");
        Node three = Node(0,"3");
        testTree.insert(it,one);
        testTree.insert(it,two);
        testTree.insert(it,three);
        REQUIRE(0==0);
       // cout<<it;
        
}
}

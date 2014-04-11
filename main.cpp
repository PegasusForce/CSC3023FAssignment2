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
   /* SECTION("Section1"){
        Node* array[3];
        Node** children = array;
        children[0]=nullptr;
        children[1]=nullptr;
        children[2]=nullptr;
        Node one = Node(0,"1");
        Node two = Node(0,"2");
        Node three = Node(0,"3");
        children[0]=&one;
        children[1]=&two;
        children[2]=&three;
        REQUIRE(children[0]->getValue()=="1");
        REQUIRE(children[1]->getValue()=="2");
        REQUIRE(children[2]->getValue()=="3");
    }*/
    SECTION("Section2"){
        {
            Node root = Node(4,"root");
        ParseTree testTree = ParseTree();
        
           Iterator it = testTree.insert(testTree.begin(),root);
     
        Node one = Node(0,"The ");
        Node two = Node(2,"<parent>");
        Node two1= Node(0,"dog ");
        Node two2= Node(0,"ran ");
        Node three = Node(0,"away ");
        Node four = Node(0,"again ");
        testTree.insert(it,one);
       Iterator parent1 = testTree.insert(it,two);
       testTree.insert(parent1,two1);
       testTree.insert(parent1,two2);
       testTree.insert(it,three);
       testTree.insert(it,four);
       std::cout<<testTree.print()<<"."<<std::endl;
    /*    REQUIRE((*it)->getValue()=="root");
        REQUIRE((*it)->getChild(0)->getValue()=="The ");
        REQUIRE((*it)->getChild(1)->getValue()=="<parent>");
        REQUIRE((*it)->getChild(1)->getChild(0)->getValue()=="dog ");
        REQUIRE((*it)->getChild(1)->getChild(1)->getValue()=="ran ");
        REQUIRE((*it)->getChild(2)->getValue()=="away ");
        REQUIRE((*it)->getChild(3)->getValue()=="again ");*/
        }
             Node::print_counts(std::cout, "Node");
           
          
       
       // cout<<it;
        
}
}

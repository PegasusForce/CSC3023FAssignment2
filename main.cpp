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
   
    SECTION("Simple Sentence"){
        {
            Compound root = Compound(4);
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
       std::cout<<testTree<<std::endl;
       
    /*    REQUIRE((*it)->getValue()=="root");
        REQUIRE((*it)->getChild(0)->getValue()=="The ");
        REQUIRE((*it)->getChild(1)->getValue()=="<parent>");
        REQUIRE((*it)->getChild(1)->getChild(0)->getValue()=="dog ");
        REQUIRE((*it)->getChild(1)->getChild(1)->getValue()=="ran ");
        REQUIRE((*it)->getChild(2)->getValue()=="away ");
        REQUIRE((*it)->getChild(3)->getValue()=="again ");*/
       
        }
        
        SECTION("Special Nodes"){
            Expression lhs = Expression("a","%","2");
            Expression parent1 = Expression(lhs,"==","0");
            
            Expression parent2 = Expression(parent1,0);
            
            Compound tru = Compound(1);
            FunctionCall f1 = FunctionCall("print",1);
            Node f1n = Node(0,"\"even\"");
            f1.addChild(f1n);
            tru.addChild(f1);
            
            Compound fals = Compound(1);
            FunctionCall f2 = FunctionCall("print",1);
            Node f2n = Node(0,"\"odd\"");
            f2.addChild(f2n);
            fals.addChild(f2);
            
            
            If parent3 = If(parent2,tru,fals);
            
            
            Node root = parent3;
            ParseTree testTree = ParseTree();
            Iterator it = testTree.insert(testTree.begin(),root);
            std::cout<<testTree<<std::endl;
            
        }
             Node::print_counts(std::cout, "Node");
           
          
       
        
        
}
}

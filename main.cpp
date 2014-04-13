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
   
  /*  SECTION("Simple Sentence"){
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
        REQUIRE((*it)->getChild(3)->getValue()=="again ");
       
        }*/
        
        SECTION("Special Nodes"){
            {
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
           
           Compound parent4 = Compound(2);
           Expression p4n21 = Expression("1");
           Statement p4n2 = Statement("a","+=",p4n21);
           parent4.addChild(parent3);
           parent4.addChild(p4n2);
           
           Expression p5n11 = Expression("a","<","10");
           Expression p5n1=Expression(p5n11,0);
           While parent5 = While(p5n1,parent4);
           
           Compound parent6 = Compound(2);
           
           Expression p6n11=Expression("0");
           Statement p6n1=Statement("a","=",p6n11);
           
           parent6.addChild(p6n1);
           parent6.addChild(parent5);
                    
            
            Node root = parent6;
            ParseTree testTree = ParseTree();
            Iterator it = testTree.insert(testTree.begin(),root);
            std::cout<<testTree<<std::endl;
       REQUIRE(0==0);
            
        }
        Node::print_counts(std::cout, "Node");
        }
             
           
          
       
        
        
}


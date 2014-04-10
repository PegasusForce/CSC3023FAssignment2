/* 
 * File:   ParseTree.h
 * Author: khagendra
 *
 * Created on 10 April 2014, 11:30 AM
 */

#ifndef PARSETREE_H
#define	PARSETREE_H
#include "Iterator.h"
#include "Node.h"
class ParseTree {
  
public:
    //Default constructor
    ParseTree();
    //Standard constructor
    ParseTree(Node* r):root(r){};
    //Copy constructor
    ParseTree(const ParseTree& orig):root(orig.root){};
    //Move constructor
    ParseTree(ParseTree&& orig):root(std::move(orig.root)){orig.root=nullptr;};
    //Copy assignment operator
    ParseTree& operator=(const ParseTree& rhs);
    //Move assignment operator
    ParseTree& operator=(ParseTree&& rhs);
    //Destructor
    virtual ~ParseTree(){clear();}
    
   Iterator begin(){return Iterator(root);}
   Iterator end(){return Iterator(nullptr);}
   void clear(){delete root;}
   std::size_t size(){return begin()-end();}
   void erase(Iterator i){delete *i;}
   
   Iterator insert(Iterator& parent, const Node & child);
   std::ostream& operator<<(std::ostream &lhs);
    
private:
    Node* root=nullptr;
};

#endif	/* PARSETREE_H */


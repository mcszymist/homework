// huffcode.cpp
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
// Now solves problem

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::move;
#include <queue>
using std::priority_queue;

bool operator<(const shared_ptr<Node> &x, const shared_ptr<Node> &y)
{
    return x->_weight > y->_weight;
}

void HuffCode::setWeights(const unordered_map<char, int> & theweights)
{
    if (theweights.empty())
        return;
   if (theweights.size() == 1) {
      _codewords[theweights.begin()->first]='0';
      return;
   }
    priority_queue<shared_ptr<Node>> trees;

    for(auto p:theweights)
        trees.push(make_shared<Node>(Node{p.first,p.second}));
    
    while (trees.size()>1) {
        auto l = trees.top();
        trees.pop();
        auto r = trees.top();
        trees.pop();
        trees.push(make_shared<Node>(Node{0,l->_weight+r->_weight,l,r}));
    }
    _tree = trees.top();
    findCodeWords(_tree,"");
}

void HuffCode::findCodeWords(shared_ptr<Node> node, const string &word)
{
    if(node->_c) {
        _codewords[node->_c] = word;
        return;
    }
    findCodeWords(node->_left,word+"0");
    findCodeWords(node->_right,word+"1");
}

string HuffCode::encode(const string & text) const
{
    string retval;
    for(char c:text)
        retval += _codewords.find(c)->second;
    return retval;
}

string HuffCode::decode(const string & codestr) const
{
    string retval;
    auto node = _tree;
    for(auto bit:codestr){
        if (bit=='0')
            node = node->_left;
        else
            node = node->_right;
        if(node->_c) {
            retval += node->_c;
            node = _tree;
        }
    }
    return retval;
}


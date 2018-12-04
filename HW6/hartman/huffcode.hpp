// huffcode.hpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <memory>

struct Node {
    char _c=0;
    int _weight=0;
    std::shared_ptr<Node> _left=nullptr;
    std::shared_ptr<Node> _right=nullptr;
};

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const std::unordered_map<char, int> & theweights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;
// ***** HuffCode: data members *****
private:
    std::shared_ptr<Node> _tree;
    std::unordered_map<char,std::string> _codewords;
    // ***** HuffCode: private member functions *****
    void findCodeWords(std::shared_ptr<Node> node, const std::string &word);
};  // End class HuffCode

#endif //#ifndef FILE_HUFFCODE_H_INCLUDED


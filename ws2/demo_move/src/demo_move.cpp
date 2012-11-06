//============================================================================
// Name        : demo_move.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

struct MoveOnly
{
   MoveOnly() = default;
   MoveOnly(MoveOnly&&)
   {
       std::cout << "Move constructor called\n";
   }
   MoveOnly(const MoveOnly&) = delete;
};

void f(MoveOnly) { std::cout << "f(MoveOnly) called\n"; }

void g(MoveOnly&&) { std::cout << "g(MoveOnly&&) called\n"; }

void g(MoveOnly const &){ std::cout << "g(MoveOnly const&) called\n"; }

int main()
{
   f( MoveOnly{} ); // rvalue temporary
   g( MoveOnly{} ); // rvalue temporary
   std::cout << "moving lvalues:\n";
   MoveOnly mv{}; // lvalue
   //f(mv); // doens't compile, because lvalue cannot be passed (would require copy-ctor)
   f(std::move(mv)); // make an rvalue from lvalue
   g(mv); // binds to const-ref
   g(std::move(mv)); // binds to rvalue-ref

}

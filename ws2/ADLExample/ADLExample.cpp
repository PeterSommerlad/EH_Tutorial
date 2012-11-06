#include <iostream>
using std::cout;
namespace one{
struct type_one{}; // empty type
void f(type_one) {cout << "one::f\n";}
}
namespace two{
struct type_two{};
void f(type_two)     {cout << "two::f\n";}
void g(one::type_one){cout << "two::g\n";}
void h(one::type_one){cout << "two::h\n";}
}
void g(two::type_two){cout << "::g\n";}

int main(){
    one::type_one a{};
    f(a);//one::f
    two::type_two b{};
    f(b);//two::f
    //h(a); // can not see h
    //g(a); // try ::g(), but can not convert
    g(b);//::g
    two::g(a); // needs two::
    void works_with_inheriting_ctors();
    works_with_inheriting_ctors();
}



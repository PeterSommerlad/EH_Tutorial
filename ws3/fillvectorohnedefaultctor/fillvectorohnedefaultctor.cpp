#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
struct X{
	X(int i):x(i){}
	int x;
};
std::ostream &operator<<(std::ostream &out,X const &x){
	return out << x.x;
}
struct Initializer{
	int j;
	Initializer(int start=0):j(start){}
	X operator()(){ return X(j++);}
};

int main(){
	std::vector<X> v; // geht nicht: v(10) -> braucht X::X()
	generate_n(std::back_inserter(v),10,Initializer(100));
	copy(v.begin(),v.end(),std::ostream_iterator<X>(std::cout,", "));
}

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>

int main(){
	using namespace boost;
	std::cout << std::boolalpha;
	function<bool(int)> odd=bind(std::modulus<int>(),_1,2);
	std::cout << "bind()(42) = "<< bind(std::modulus<int>(),_1,2)(42);
	std::cout << "\n odd(42) = "<< odd(42);
}

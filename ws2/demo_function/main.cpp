#include <functional>
#include <iostream>
#include <type_traits>
int main(){
	static_assert(sizeof(int) == 4,"int is 32 bit");
	static_assert(std::is_unsigned<char>::value,"char is signed");
	using std::cout;
	using std::endl;
	std::function<bool(int)> odd;
	if (not odd) cout <<"odd is empty"<< endl;
	odd = [](int i)->bool{ return i%2;};
	if (odd) cout << "odd is defined" << endl;
	if (odd(2)) cout << "2 is odd"<< endl;
	if (odd(3)) cout << "3 is odd"<< endl;
}

#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main(){
	using namespace std;
	using placeholders::_1;
	vector<int> numbers(10);
	iota(numbers.begin(),numbers.end(),1);
	ostream_iterator<int> out(cout,", ");
	copy(numbers.begin(),numbers.end(),out); cout << endl;
	transform(numbers.begin(),numbers.end(),out,
		  bind(plus<int>(),_1,10));
	cout << endl;
	transform(numbers.begin(),numbers.end(),out,
		  bind(multiplies<int>(),_1,_1));
	cout << endl;
}

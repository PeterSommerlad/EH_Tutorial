#include "Sack.h"
#include <iostream>
int main() {
	Sack<int> s;
	s.putInto(42);
	std::cout << s.getOut() << std::endl;
}

#include <iostream>

enum unscoped {
	one, two, three
};

enum class scoped {
	one, two, three
};

enum class one_char : unsigned char {
	has, size, of , one
};
enum class really_big : unsigned long long {
	has/*=0xabcdef0123456789ULL*/, size, of , eight
};


int main() {
	int i = one;
	int j1=static_cast<int>(scoped::one); // doesn't compile!
	scoped j = scoped::two;
	// scoped k = one; // doesn't compile
	std::cout << "sizeof scoped = " << sizeof(scoped) << std::endl;
	std::cout << "sizeof one_char = " << sizeof(one_char) << std::endl;
	std::cout << "sizeof really_big = " << sizeof(really_big) << std::endl;
}

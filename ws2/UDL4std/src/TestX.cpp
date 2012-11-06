#include "suffixes_parse_integers.h"
#include "chrono_suffix.h"
#include "string_suffix.h"
#include "binary.h"

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "TestComplex.h"
#include <typeinfo>

constexpr int operator"" _10(unsigned long long i){return i;}
auto x=10_10;
#if 1
using namespace std::suffixes::binary;
void testBinaryInt() {
	// compile error:
	//2b;
	ASSERT_EQUAL(10b,2);
	ASSERT(typeid(int) == typeid(10b));
	// all suffixes
	ASSERT_EQUAL(10bu,2);
	ASSERT(typeid(unsigned) == typeid(10bu));
	ASSERT_EQUAL(10bl,2);
	ASSERT(typeid(long) == typeid(10bl));
	ASSERT_EQUAL(10bul,2);
	ASSERT(typeid(unsigned long) == typeid(10bul));
	ASSERT_EQUAL(10bll,2);
	ASSERT(typeid(long long) == typeid(10bll));
	ASSERT_EQUAL(10bull,2);
	ASSERT(typeid(unsigned long long) == typeid(10bull));

}
#if 1
void testWithblSuffix() {
	ASSERT_EQUAL(100bl, 4l);
}
void testWithbuSuffix() {
	ASSERT_EQUAL(100bu, 4u);
	ASSERT_EQUAL(typeid(unsigned).name(),
			typeid(1bu).name());
	ASSERT_EQUAL(typeid(unsigned long).name(),
			typeid(
1000000000000000000000000000000000bu).name());
}

template <unsigned sz_long> struct select_ull;
template <>
struct select_ull<4>{
	typedef long long LLTYPE;
	typedef unsigned long long ULLTYPE;
};
template <>
struct select_ull<8>{
	typedef long LLTYPE;
	typedef unsigned long ULLTYPE;
};

void testTypeSelector() {
	ASSERT_EQUAL(100b, 4l);
	ASSERT(typeid(int) == typeid(0b));
	ASSERT_EQUAL(4, sizeof(int));
	ASSERT_EQUAL(typeid(int).name(),
			typeid(
01111111111111111111111111111111b).name());
	ASSERT_EQUAL(typeid(unsigned).name(),
			typeid(
10000000000000000000000000000000b).name());
	typedef select_ull<sizeof(long)>::LLTYPE LLTYPE;
	typedef select_ull<sizeof(long)>::ULLTYPE ULLTYPE;
	ASSERT_EQUAL(typeid(LLTYPE).name(),
			typeid(
0111111111111111111111111111111111111111111111111111111111111111b).name());
	ASSERT_EQUAL(typeid(ULLTYPE).name(),
			typeid(
1000000000000000000000000000000000000000000000000000000000000000b).name());
}

static_assert(std::is_same<decltype(1b),int>{},"default type for binary is int");
static_assert(10000100bU == 0x84U,"did not convert 0x84 from binary");
static_assert(std::is_same<decltype(
1000000000000000000000000000000000000000000000000000000000000000b),
		select_ull<sizeof(long)>::ULLTYPE>{},"large binaries are ull");
static_assert(std::is_same<decltype(
10000000000000000000000000000000b),
		unsigned>{},"larger binaries are unsigned");
static_assert(std::is_same<decltype(
01111111111111111111111111111111b),
		int>{},"larger binaries are unsigned");
static_assert(std::is_same<decltype(
01111111111111111111111111111111bu),
		unsigned>{},"larger binaries are unsigned");
static_assert(std::is_same<decltype(
0111111111111111111111111111111111111111111111111111111111111111bu),
		decltype(0x7fffffffffffffffu)>{},"same rules as with u and hex values");
static_assert(std::is_same<decltype(
1000000000000000000000000000000000bu),
		decltype(0x100000000u)>{},"same rules as with u and hex values");
static_assert(std::is_same<decltype(
1000000000000000000000000000000000b),
		decltype(0x100000000)>{},"same rules as with u and hex values");
static_assert(15==1b+1bu+1bU+1bl+1bL+1bul+1bUl+1buL+1bUL+1bll+1bLL+1bull+1bUll+1buLL+1bULL,
		"15 variants of binary literal suffixes defined");
#endif
//-------------- string UDL
using namespace std::string_literals;
static_assert(std::is_same<decltype("hallo"s),std::string>{},"s means std::string");
static_assert(std::is_same<decltype(u8"hallo"s),std::string>{},"u8 s means std::string");
static_assert(std::is_same<decltype(L"hallo"s),std::wstring>{},"L s means std::wstring");
static_assert(std::is_same<decltype(u"hallo"s),std::u16string>{},"u s means std::u16string");
static_assert(std::is_same<decltype(U"hallo"s),std::u32string>{},"U s means std::u32string");

void testStringSuffix(){
	ASSERT_EQUAL(typeid("hi"s).name(),typeid(std::string).name());
	ASSERT_EQUAL(std::string{"hello"},"hello"s);
}
template <char... Digits>
constexpr  unsigned long long
operator"" _testit(){
	return std::parse_int::base_dispatch<Digits...>::value;
}
template <char... Digits>
constexpr  unsigned long long
operator"" _ternary(){
    return std::parse_int::parse_int<3,Digits...>::value;
}

constexpr auto large=std::parse_int::pow(16,40);
using std::select_int_type::select_int_type;
template <unsigned long long val>
constexpr
typename select_int_type<val,
short, int, long long>::value_type
foo() {
    return  select_int_type<val,
            short, int, long long>::value;
}
static_assert(std::is_same<decltype(foo<100>()), short>::value,"foo<100>() is short");
static_assert(std::is_same<decltype(foo<0x10000>()), int>::value,"foo<0x10000>() is int");
static_assert(std::is_same<decltype(foo<0x100000000000>()), long long>::value,"foo<0x100000000000>() is long long");
void testDigitParsinFromUDLOperatorTemplate() {
	//constexpr auto overflowh= 0x80000000h; // compile error!
constexpr auto atest = 123_testit;
constexpr auto a = 0123_testit;
constexpr auto b = 0x123_testit;
constexpr auto c = 0X123_testit;
constexpr auto zero = 0_testit;
constexpr auto five= 012_ternary;
static_assert(five==5, "_ternary should be three-based");
//constexpr auto invalid=3_ternary;
//constexpr auto invalid = 0x_testit;
ASSERT_EQUAL(123ULL, atest);
ASSERT_EQUAL(0123, a);
ASSERT_EQUAL(0x123, b);
ASSERT_EQUAL(01234567, 01234567_testit);
ASSERT_EQUAL(0x1234567890abcdef, 0x1234567890ABCDEF_testit);
ASSERT_EQUAL(0x1234567890abcdef, 0x1234567890abcdef_testit);
}

using namespace std::chrono_literals;

void testChronoLiterals(){
	static_assert(std::is_same<std::chrono::hours::rep, int>::value,
	              "hours are too long to check");
	//constexpr auto overflowh= 0x80000000h; // compile error!
	constexpr auto xh=5h;
	ASSERT_EQUAL(std::chrono::hours{5}.count(),xh.count());
	static_assert(std::chrono::hours{5}==xh,"chrono suffix hours");
	constexpr auto xmin=0x5min;
	static_assert(std::chrono::duration<unsigned long long,
	              std::ratio<60,1>>{5}==xmin,"chrono suffix min");
	constexpr auto x=05s;
	static_assert(std::chrono::duration<unsigned long long,
	              std::ratio<1,1>>{5}==x,"chrono suffix s");
	constexpr auto xms=5ms;
	static_assert(std::chrono::duration<unsigned long long,
	              std::ratio<1,1000>>{5}==xms,"chrono suffix ms");
	constexpr auto xus=5us;
	static_assert(std::chrono::duration<unsigned long long,
	              std::ratio<1,1000000>>{5}==xus,"chrono suffix ms");
	constexpr auto xns=5ns;
	static_assert(std::chrono::duration<unsigned long long,
	              std::ratio<1,1000000000>>{5}==xns,"chrono suffix ms");

	constexpr auto dh=0.5h;
	constexpr auto dmin=0.5min;
	constexpr auto ds=0.5s;
	constexpr auto dms=0.5ms;
	constexpr auto dus=0.5us;
	constexpr auto dns=0.5ns;
}
void aTestForDuration(){
	auto  x=5h;
	auto y=18000s;
	ASSERT_EQUAL(x,y);
}


void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testBinaryInt));
	s.push_back(CUTE(testWithblSuffix));
	s.push_back(CUTE(testWithbuSuffix));
	s.push_back(CUTE(testTypeSelector));
	s.push_back(CUTE(testStringSuffix));
	s.push_back(CUTE(testChronoLiterals));
	s.push_back(CUTE(aTestForDuration));
	s.push_back(CUTE(testDigitParsinFromUDLOperatorTemplate));
	s += make_suite_TestComplex();
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}

#else
int main(){}
#endif


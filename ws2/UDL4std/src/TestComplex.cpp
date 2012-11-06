#include "complex_suffix.h"
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "TestComplex.h"
using namespace std::complex_literals;
//static_assert(std::is_same<decltype(1i_f),std::complex<float>>{},"default it complex<double>");
//static_assert(std::is_same<decltype(1.0i_f),std::complex<float>>{},"default it complex<double>");

void testComplexDouble(){
	ASSERT_EQUALM("fails on g++ due to extensions that can not be turned off",
	        typeid(1.0il).name(),typeid(std::complex<long double>).name());
}

cute::suite make_suite_TestComplex(){
	cute::suite s;
	s.push_back(CUTE(testComplexDouble));
	return s;
}




#ifndef COMPLEX_SUFFIX_H_
#define COMPLEX_SUFFIX_H_
#include <complex>
namespace std{
inline namespace literals{
inline namespace complex_literals{
constexpr
std::complex<long double> operator"" il(long double d){
	return std::complex<long double>{0.0L,static_cast<long double>(d)};
}
constexpr
std::complex<long double> operator"" il(unsigned long long d){
	return std::complex<long double>{0.0L,static_cast<long double>(d)};
}
constexpr
std::complex<double> operator"" i(long double d){
	return std::complex<double>{0,static_cast<double>(d)};
}
constexpr
std::complex<double> operator"" i(unsigned long long d){
	return std::complex<double>{0,static_cast<double>(d)};
}
constexpr
std::complex<float> operator"" i_f(long double d){
	return std::complex<float>{0,static_cast<float>(d)};
}
constexpr
std::complex<float> operator"" i_f(unsigned long long d){
	return std::complex<float>{0,static_cast<float>(d)};
}
}}}
#endif /* COMPLEX_SUFFIX_H_ */

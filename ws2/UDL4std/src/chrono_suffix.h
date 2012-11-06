#ifndef CHRONO_SUFFIX_H_
#define CHRONO_SUFFIX_H_
#include <chrono>
#include <limits>
#include "suffixes_parse_integers.h"
namespace std {
inline namespace literals {
inline namespace chrono_literals{

namespace __impl {
using namespace std::parse_int;

template <unsigned long long val, typename DUR>
struct select_type:conditional<
    (val <=static_cast<unsigned long long>(
            std::numeric_limits<typename DUR::rep>::max()))
	, DUR , void > {
		static constexpr typename select_type::type
			value{ static_cast<typename select_type::type>(val) };
};
template <unsigned long long val, typename DUR>
constexpr typename select_type<val,DUR>::type select_type<val,DUR>::value;
}

template <char... Digits>
constexpr typename
__impl::select_type<__impl::base_dispatch<Digits...>::value,
std::chrono::hours>::type
operator"" h(){
	return  __impl::select_type<__impl::base_dispatch<Digits...>::value,
	        std::chrono::hours>::value;
}
constexpr std::chrono::duration<long double, ratio<3600,1>>
operator"" h(long double hours){
	return std::chrono::duration<long double,ratio<3600,1>>{hours};
}
template <char... Digits>
constexpr typename
__impl::select_type<__impl::base_dispatch<Digits...>::value,
std::chrono::minutes>::type
operator"" min(){
	return __impl::select_type<__impl::base_dispatch<Digits...>::value,
	       std::chrono::minutes>::value;
}
constexpr std::chrono::duration<long double, ratio<60,1>>
operator"" min(long double min){
	return std::chrono::duration<long double,ratio<60,1>>{min};
}

template <char... Digits>
constexpr typename
__impl::select_type<__impl::base_dispatch<Digits...>::value,
std::chrono::seconds>::type
operator"" s(){
	return __impl::select_type<__impl::base_dispatch<Digits...>::value,
	       std::chrono::seconds>::value;
}
constexpr std::chrono::duration<long double>
operator"" s(long double sec){
	return std::chrono::duration<long double>{sec};
}

template <char... Digits>
constexpr typename
__impl::select_type<__impl::base_dispatch<Digits...>::value,
std::chrono::milliseconds>::type
operator"" ms(){
	return __impl::select_type<__impl::base_dispatch<Digits...>::value,
	       std::chrono::milliseconds>::value;
}
constexpr std::chrono::duration<long double, milli>
operator"" ms(long double msec){
	return std::chrono::duration<long double,milli>{msec};
}

template <char... Digits>
constexpr typename
__impl::select_type<__impl::base_dispatch<Digits...>::value,
std::chrono::microseconds>::type
operator"" us(){
	return __impl::select_type<__impl::base_dispatch<Digits...>::value,
	       std::chrono::microseconds>::value;
}
constexpr std::chrono::duration<long double, micro>
operator"" us(long double usec){
	return std::chrono::duration<long double, micro>{usec};
}

template <char... Digits>
constexpr typename
__impl::select_type<__impl::base_dispatch<Digits...>::value,
std::chrono::nanoseconds>::type
operator"" ns(){
	return __impl::select_type<__impl::base_dispatch<Digits...>::value,
	       std::chrono::nanoseconds>::value;
}
constexpr std::chrono::duration<long double, nano>
operator"" ns(long double nsec){
	return std::chrono::duration<long double, nano>{nsec};
}

}}}
#endif /* CHRONO_SUFFIX_H_ */

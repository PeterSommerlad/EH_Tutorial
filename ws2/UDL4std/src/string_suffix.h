#ifndef STRING_SUFFIX_H_
#define STRING_SUFFIX_H_
#include <string>
namespace std{
inline namespace literals{
inline namespace string_literals{
#if 0
#define __MAKE_SUFFIX_S(CHAR) \
	basic_string<CHAR>\
operator "" s(CHAR const *str, size_t len){\
	return basic_string<CHAR>(str,len);\
}

__MAKE_SUFFIX_S(char)
__MAKE_SUFFIX_S(wchar_t)
__MAKE_SUFFIX_S(char16_t)
__MAKE_SUFFIX_S(char32_t)
#undef __MAKE_SUFFIX
#else // copy-paste version for proposal

basic_string<char>
operator "" s(char const *str, size_t len){
return basic_string<char>(str,len);
}
basic_string<wchar_t>
operator "" s(wchar_t const *str, size_t len){
return basic_string<wchar_t>(str,len);
}
basic_string<char16_t>
operator "" s(char16_t const *str, size_t len){
return basic_string<char16_t>(str,len);
}
basic_string<char32_t>
operator "" s(char32_t const *str, size_t len){
return basic_string<char32_t>(str,len);
}

#endif
}
}
}



#endif /* STRING_SUFFIX_H_ */

#if 0
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
namespace X {
using std::vector;
struct vec:vector<int>{
    using vector::vector;
};
using std::ostream;
using out=std::ostream_iterator<int>;
ostream& operator<<(ostream &os, vec const &v){
    copy(v.begin(),v.end(),out{os,","});
    return os;
}
}
void works_with_inheriting_ctors(){
    std::vector<X::vec> vv{{1,2,3},{4,5,6}};
    using outv=std::ostream_iterator<X::vec>;
    copy(vv.begin(),vv.end(),outv{std::cout,"\n"});
}
#endif

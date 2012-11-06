#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::vector;
using vec=vector<int>;
using std::ostream;
using out=std::ostream_iterator<int>;
namespace std {
ostream& operator<<(ostream &os, vec const &v){
    copy(v.begin(),v.end(),out{os,","});
    return os;
}
}
void work_only_with_shift_in_ns_std(){
    std::vector<vec> vv{{1,2,3},{4,5,6}};
    using outv=std::ostream_iterator<vec>;
    copy(vv.begin(),vv.end(),outv{std::cout,"\n"});
}

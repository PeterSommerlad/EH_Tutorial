#include <memory>
#include <iostream>
std::unique_ptr<int> afactory(int i){
    return std::unique_ptr<int>{new int{i}};
}
int main(){
    auto pi=afactory(42);

    std::cout << "*pi =" << *pi << "\n";
    std::cout << "pi.valid? "<< std::boolalpha
              << static_cast<bool>(pi) << std::endl;
    auto pj=std::move(pi);
    std::cout << "*pj =" << *pj << "\n";
    std::cout << "pi.valid? "<< std::boolalpha
              << static_cast<bool>(pi) << std::endl;

}

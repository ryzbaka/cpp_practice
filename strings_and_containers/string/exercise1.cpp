#include <iostream>
#include <string>

int main(){
    std::string s1,s2;
    std::cin>>s1>>s2;
    int l1 = s1.length();
    int l2 = s2.length();
    if(l2>l1){
        std::cout<<s1<<"\n";
    }else{
        std::cout<<s2<<"\n";
    }
    return 0;
}
#include <iostream>
using namespace std;
class ClassOne{
    private:
        int x;
    public:
        ClassOne(int a):x(a){};
        friend class ClassTwo;
        int getX() const{
            return this->x;
        }
        friend void display(ClassOne obj);
};

void display(ClassOne obj){
    cout<< obj.x<<"\n";
}

class ClassTwo{
    private:
        int x;
    public:
        ClassTwo(int a):x(a){};
        int getClassOneX(ClassOne obj){
            return obj.x;
        }
};

int main(){
    ClassOne obj(23);
    ClassTwo obj2(46);
    cout<<obj2.getClassOneX(obj)<<"\n";
    display(obj);
    return 0;
}


// https://stackoverflow.com/questions/39212027/how-to-make-two-classes-friend-of-each-other -> saving link for future reference.
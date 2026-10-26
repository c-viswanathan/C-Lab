
#include<iostream>
using namespace std;
class animal {
    public:
    virtual void speak() const = 0;
    virtual ~animal() { cout<<"~animal\n";} // virtual -> full cleanup
};
class dog : public animal {
    public:
    void speak() const override { cout<<"woof\n";}
    ~dog() { cout<<"~dog\n";}
};
int main()
{
    animal *a = new dog();  //upcasting(implicit,safe)
    if(dog *d  = dynamic_cast<dog*>(a)) {//downcasting(base-> derived,checked  ,unsafe)
        cout<<"downcast ok ->";  //downcasting (bse -> derived, checked,)
        d->speak();//woof

    }
    delete a;//~dog then ~animal (virtual dtor )
    return 0;
}

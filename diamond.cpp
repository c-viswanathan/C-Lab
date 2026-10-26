#include<iostream>
using namespace std;
class Stream{
    Public:
    Stream(){cout<<"Stram/tor\n";}
void open(){cout<<"Streamopend\n";}
};
class instream:virtual public stream();
class outstream:virtual public stream();
class iostream:public instream public outstream{};
int main(){
    iostream i0;
    io.open();
    return 0;
}
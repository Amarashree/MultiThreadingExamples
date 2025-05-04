#include<iostream>

void display(const std::shared_ptr<int> t, const char& ch){
    if(t == nullptr){
        std::cout<<"\nthe "<<ch<<" is nullptr";
        return;
    }
    std::cout<<"\nAddress of "<<ch<<" is "<<t;
    std::cout<<"\nValue of "<<ch<<" is "<<*t;
}


void display(const int* t, const char&& ch){
    if(t == nullptr){
        std::cout<<"\nthe "<<ch<<" is nullptr";
        return;
    }
    std::cout<<"\nAddress of "<<ch<<" is "<<t;
    std::cout<<"\nValue of "<<ch<<" is "<<*t;
}




int main(){

    int *c = new int;
    *c = 1000;

    display(c, 'c');

    std::unique_ptr<int> z = (std::unique_ptr<int>)new int;
    *z = 200;
    display(z,'z');

    
    std::shared_ptr<int> a,b;

    a = (std::shared_ptr<int>)new int;
    *a = 999;
    display(a, 'a');
    b = a;
    display(b,'b');
    *b = 888;
    display(a,'a');
    display(b,'b'); 

   
    








    std::cout<<"\n\n\n\n";
    return 0;
}
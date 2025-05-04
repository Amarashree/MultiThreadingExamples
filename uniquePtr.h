#include<iostream>

void display(const std::unique_ptr<int>& t, const char& ch){
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
    
    std::unique_ptr<int> a,b;

    a = (std::unique_ptr<int>)new int;
    display(a, 'a');
    

    a = (std::unique_ptr<int>)c;
    std::cout<<"\nptr c is assigned to unique pointer a";
    std::cout<<"\nValue of a is "<<*a;
    std::cout<<"\nAddress of a is "<<a;

    b = std::move(a);
    display(b,'b');

    display(a,'a');


    //a = new int;
    
    

   
    








    std::cout<<"\n\n\n\n";
    return 0;
}
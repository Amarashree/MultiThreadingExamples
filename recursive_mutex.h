#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<shared_mutex>
#include<memory>

std::recursive_mutex m;

void foo1(){
    std::lock_guard<std::recursive_mutex> lk(m);
    std::cout<<"\nI AM IN FOO1!";
}

void foo2(){
    std::lock_guard<std::recursive_mutex> lk(m);
    std::cout<<"\nI AM IN FOO 2";
    foo1();
}


int main()
{

    std::thread t1(foo2);
    


    // auto ptr = std::make_unique<int>(10);
    // std::cout<<"\n contents of pointer is "<<*ptr;

    std::cout<<"\n\n\n";

    t1.join();
    
   
    return 0;
}
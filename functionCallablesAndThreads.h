#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<vector>


typedef void(method_func)(void);
void exampleTypedef(method_func func){
    func();
}

void display(){
    std::cout<<"\nHello from nested";
}

// Function which takes 2 inputs
void product(int a, int b){
    std::cout<<"\nProduct of a and b is "<<a*b<<"\n";
}

// function which accepts callable inputs using std::function
void method1(std::function<void(int,int)> func){
    func(1,2);
}

//function which accepts callable values using function pointers and templates

template <typename Func>
void method2(Func func){
    func(4,100);
}

template <typename Func>
void method3(Func func){
    func();
}

int main(){

    std::thread t1(product, 2,3);

 
    //calling using lambdas
    auto method = ([](int a, int b){
        std::cout<<"\n Thread2: Sum of a and b is "<<a+b<<"\n";
    });

    std::thread t2(method, 3,4);


    //threads with functions, arguements as another function

    std::thread t3(exampleTypedef,display);

    std::thread t4(method1,product);









    t1.join();
    t2.join();
    t3.join();
    t4.join();








    std::cout<<"\n\n\n";
}

    


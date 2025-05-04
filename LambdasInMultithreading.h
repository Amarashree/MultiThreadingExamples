#include<iostream>
#include<thread>
#include<chrono>
#include<vector>



void product(int a, int b){
    std::cout<<"\nProduct of a and b is "<<a*b<<"\n";
}



int main(){

    std::thread t1(product, 2,3);

    t1.join();

    std::thread t2([](int n){
        std::cout<<"\n Lambda thread function n = "<<n<<"\n";
    }, 1000);

    t2.join();










    std::cout<<"\n\n\n";
}

    


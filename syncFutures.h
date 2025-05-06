#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<future>

int display(){
    
    int c = 1000;
    
    std::cout<<"\nHello from ASYNC";
    
    return c;
}


int factorial(int N)
{
    int res = 1;
    for (int i = N; i > 1; i--) {
        res *= i;
    }

    std::cout << res << "\n";
    return res;
}




int main(){

    //create a future with std::launch::deferred
    // defferred = function call is deferred until future invoked via wait() or get()
    std::future<int> f1 = std::async(std::launch::deferred, display);

    //create a future with std::launch::async
    // async = function is run on its own thread
    std::future<int> f1 = std::async(std::launch::deferred, display);

    std::future<int> a1 = std::async(std::launch::deferred, factorial, 5);
    std::cout<<"\nFactorial Value using deferred future with args is  "<<a1.get();
 
    
    















    std::cout<<"\n\n\n";
}

    


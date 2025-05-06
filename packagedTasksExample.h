#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<deque>
#include<chrono>
#include<future>
#include<experimental/iterator>



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
 
    //creating packaged tasks instead of using std::futures
    std::packaged_task<int()> t1(std::bind(factorial,6));
    std::cout<<"\nFactorial value from packaged task is ";

    // invoking the packaged task
    t1();

   

    std::packaged_task<int(int)> t2(factorial);
    std::cout<<"\nFactorial value from packaged task with passing arg into task invokation is ";t2(5);


   
   

 















    std::cout<<"\n\n\n";
}

    


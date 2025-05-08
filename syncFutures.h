#include<iostream>
#include<thread>
#include<future>

int factorial(int N)
{
    int res = 1;
    for (int i = N; i > 1; i--) {
        res *= i;
    }

    std::cout << "\nFactroial of "<<N<<" is "<<res << "\n";
    return res;
}




int main(){
 
    //creating Packaged tasks as below 
    // a package will tie a future to a function 

    std::packaged_task<int(void)> p(std::bind(factorial, 6));

    // invoke the future in the package as below

    p();
    
    // obtain the future associated with the task
    // a call to get_future() from task will wait until the task is invoked as above

    std::cout<<"\n Obtaining future from packaged task";
    auto f = p.get_future();
    std::cout<<"\n Future retrieved from task";

    // get the associated return data from the future as below
    
    std::cout<<"\nOutput of Fatorial of 6, from future = "<<f.get();


   



    

    

    std::cout<<"\n\n\n";
}

    


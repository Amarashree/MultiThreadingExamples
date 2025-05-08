#include<iostream>
#include<thread>
#include<future>
#include<deque>

std::deque<std::packaged_task<int(void)>> task_q;
std::mutex mux;
std::condition_variable cond;

// sample function that is packaged in the task
int factorial(int N)
{
    int res = 1;
    for (int i = N; i > 1; i--) {
        res *= i;
    }

   // std::cout << "\nFactroial of "<<N<<" is "<<res << "\n";
    return res;
}

// this function is run by a thread to add a task
// below functions are synchronized using condition variables
void addTask(int n){
    std::cout<<"\nEXECUTING ADD TASK";
    std::packaged_task<int(void)> tAdd(std::bind(factorial,n));
    {
        std::unique_lock<std::mutex> lk(mux);
        task_q.push_back(std::move(tAdd));
    }
    cond.notify_one();
}

// this function is run by a thread to execute a task
void runTask(){
    std::cout<<"\nEXECUTING RUN TASK";
    std::packaged_task<int(void)> tRun;
    
    {
        std::unique_lock<std::mutex> lk(mux);
        cond.wait(lk, []() { return !task_q.empty(); });
        tRun = std::move(task_q.front());
    }
    tRun();
    std::cout << "\nFactroial of value fed is "<< tRun.get_future().get();
}

int main(){
 
    //creating Packaged tasks as below 
    // a package will tie a future to a function 

    std::thread t2(runTask);
    std::thread t1(addTask, 7);
    

    

    
    t1.join();
    t2.join();
    std::cout<<"\n\n\n";
}

    


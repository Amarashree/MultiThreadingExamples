#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<memory>



std::vector<int> vec;
std::mutex m;
std::condition_variable vec_cond;

void init_vector(int a[], int size){
    {
        std::cout<<"\nVECTOR INIT FUNCTION STARTED";
        std::lock_guard<std::mutex> lk(m);
        for(int i=0; i<size;i++){
            vec.push_back(a[i]);
        }

         std::cout<<"\nVector elements are\n";
        for(int i=0;i<vec.size();i++)
            std::cout<<vec[i]<<"\t";
    }

        vec_cond.notify_one();
}

void sum_vector(){
    std::cout<<"\nSUM FUNCTION STARTED";
    std::unique_lock<std::mutex> lk(m);
    vec_cond.wait(lk,[]{ return !vec.empty(); });
    int sum = 0;
    for(int i=0;i<vec.size();i++)
        sum = sum + vec[i];
    std::cout<<"\nValue of vector sum is "<<sum;
    lk.unlock();
}

int main(){

    int a[] = {1,1,1,1,1,1,1};

    
    std::thread t2(sum_vector);
    std::thread t1(init_vector, a , 7);




    t1.join();
    t2.join();
    std::cout<<"\n\n\n";
   
    return 0;
}
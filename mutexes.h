#include <iostream>
#include<vector>
#include<thread>
#include<mutex>

std::mutex mx1; // mark code with same mutext to tell compiler they are mutuallu exclusive
std::mutex mx2;


class test1{
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10, 000, 001, 002, 003, 004, 005, 006, 007};
    public:
    void displayN(){
        std::lock_guard<std::mutex> guard(mx1);
            for(int i=0;i<10;i++)
                std::cout<<"\n"<<v[i];
    }

    void displayA(){
        std::lock_guard<std::mutex> guard(mx1);
        for(int i=10;i<18;i++)
            std::cout<<"\n"<<i;

    }
};



int main(){
    test1 x;
    //test2 y;
    std::thread t1(&test1::displayN,&x);
    std::thread t2(&test1::displayA,&x);
    
    

    

   

    t1.join();
    t2.join();
    std::cout<<"\n\n\n\n"; 
    return 0;
}
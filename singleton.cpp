#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Counter {
    public:
        int count = 0;
        static Counter* get_instance(){
            //if(instance == nullptr){
            std::lock_guard<std::mutex> lock(flag);
            if(instance == nullptr){
                instance = new Counter();
            }
            //}
            return instance;
        }
        void add_one(){
            count++;
        }
    private:
        
        Counter(){};
        static Counter* instance;
        static std::mutex flag;
};

Counter *Counter::instance = nullptr;
std::mutex Counter::flag;

void thread1(){
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Counter* c1 = Counter::get_instance();
    c1->add_one();
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    cout<<c1<<endl;
    cout<<c1->count<<"\n";
} 

void thread2(){
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Counter* c2 = Counter::get_instance();
    c2->add_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout<<c2<<endl;
    cout<<c2->count<<"\n";
}

int main(){
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
}
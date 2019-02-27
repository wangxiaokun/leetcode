// g++ -std=c++11 test_pthread_cond.c  -lpthread

#include <iostream>
#include <thread>
#include <chrono>

#include <pthread.h>


pthread_mutex_t mutex_;
pthread_cond_t pcond_;
int count_ = 1;



void wait()
{
    pthread_mutex_lock(&mutex_);
    while (count_ > 0) {
        std::cout<<"wait begin"<<std::endl;
        pthread_cond_wait(&pcond_, &mutex_);
        std::cout<<"wait end"<<std::endl;
    }
    pthread_mutex_unlock(&mutex_);
}

void notify()
{
    pthread_mutex_lock(&mutex_);
    --count_;
    if (count_ == 0) {
        std::cout<<"notify all"<<std::endl;
        pthread_cond_broadcast(&pcond_);
    }
    pthread_mutex_unlock(&mutex_);
}


int main()
{
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&pcond_, NULL);

    std::thread t1(wait);
    std::thread t2(wait);
    std::thread t3(wait);

    std::this_thread::sleep_for(std::chrono::seconds(1));


    notify();

    t1.join();
    t2.join();
    t3.join();

    pthread_mutex_destroy(&mutex_);
    pthread_cond_destroy(&pcond_);

    return 0;
}


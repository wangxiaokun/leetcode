#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

using namespace std;




void Log(const char* format, ...)
{
    static unsigned int MAX_LOG_LENGTH=1024;

    struct timeval tv;
    gettimeofday(&tv, NULL);

    tm ptm = {0};
    localtime_r((const time_t*)&tv.tv_sec, &ptm);

    ////////////////////////////////////////////////////////////////////////////////////

    char strLog[MAX_LOG_LENGTH + 1] = {0};

    snprintf(strLog, MAX_LOG_LENGTH, "%04d-%02d-%02d %02d:%02d:%02d.%03lu ",
        ptm.tm_year + 1900,
        ptm.tm_mon + 1,
        ptm.tm_mday,
        ptm.tm_hour,
        ptm.tm_min,
        ptm.tm_sec,
        tv.tv_usec/1000);

    va_list argp;
    va_start(argp, format);
    vsnprintf(strLog + strlen(strLog), MAX_LOG_LENGTH - strlen(strLog), format, argp);
    va_end(argp);


    printf("%s\n", strLog);
}


namespace wxk
{

template<class T>
struct __list_node {
    typedef __list_node<T>* void_pointer;
    void_pointer next;
    T data;
};


template<typename T>
class list {
protected:
    typedef __list_node<T> list_node;

public:
    typedef list_node* link_type;

protected:
    link_type head;
    link_type tail;


public:
    list():head(NULL),tail(NULL) {}

    // 节点插入到尾部
    void push_back(const T& x) {
        link_type p = new list_node();
//        Log("p:%x", p);
        p->data = x;
        if (tail) {
            tail->next = p;
            tail = p;
        }
        else {
            head = tail = p;
        }
    }

    // 获取第一个元素
    T& front() {
        return head->data;
    }

    // 从头部删除节点
    void pop_front() {
        if (head) {
            link_type tmp = head;
            head = tmp->next;
//            Log("tmp:%x", tmp);
            delete tmp;
            tmp = NULL;
        }
    }
};

}




const int LOOP_COUNT = 30;
const int _10M = 10*1024*1024;

int hhhhh()
{
    wxk::list<char*> queue;

    for (int i=0; i<LOOP_COUNT; ++i) {
        char* p = new char[_10M];
        queue.push_back(p);
        Log("--> i:%d, p:%x", i, p);
        sleep(1);
    }

    for (int i=0; i<LOOP_COUNT; ++i) {
        char* p = queue.front();
        queue.pop_front();
        if (p) {
            Log("--> i:%d, p:%x", i, p);
            delete p;
            p = NULL;
        }
        else {
            Log("error");
        }
        sleep(1);
    }

    return 0;
}


int main(int argc, char* argv[])
{
    sleep(3);

    hhhhh();
    hhhhh();

    pause();
    return 0;
}


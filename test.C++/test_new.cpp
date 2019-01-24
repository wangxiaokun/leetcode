#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

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

int main()
{
    vector<char*> vecMem;
    
    // 1s申请10M内存，申请100s,1000M
    for (int i=0; i<100; ++i)
    {
        static int _10M = 10*1024*1024;
        
        char* p = new char[_10M];
        vecMem.push_back(p);
        
        Log(" --> %d - %d, %x", i, i*_10M, p);
        sleep(1);
    }
    
    // 1s释放10M内存，释放100s,1000M
    for (char* p : vecMem)
    {
        delete p;
        Log(" --> delete %x", p);
        sleep(1);
    }
    
    return 0;
}


#include <iostream>
#include <string>
#include <queue>

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
    if (argc != 2)
    {
        Log("Incorrect arg num:%d, must be 7.", argc-1);
        return 0;
    }
    
    int loop_count = argv[1];
    
    
    
    
    queue<TMsg*> queueTmp;
    TMsg* pMsg = new TMsg();
    
    
    sleep(8);
    

    for (int i=0; i<loop_count; ++i)
    {
        for (int j=0; j<10000; ++j)
        {
            queueTmp.push(pMsg);
        }
        
        sleep(1);
    }
    
    
    for (int i=0; i<loop_count; ++i)
    {
        for (int j=0; j<10000; ++j)
        {
            queueTmp.pop(pMsg);
        }
        
        sleep(1);
    }


    return 0;
}


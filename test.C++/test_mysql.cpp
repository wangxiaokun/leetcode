#include <mysql.h>

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>

#include <string>

using namespace std;



unsigned int MAX_LOG_LENGTH=1024;

MYSQL* pDbConn = NULL;


string strDbHost;
string strDbUserName;
string strDbPassword;
string strDbName;
unsigned short usDbPort = 0;



void Log(const char* format, ...)
{
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


bool connectDb()
{
    MYSQL* conn = mysql_init(NULL);

    if (NULL == conn)
    {
        Log("mysql_init fail.");
        return false;
    }

    if (NULL == mysql_real_connect(conn,
                                    strDbHost.data(),
                                    strDbUserName.data(),
                                    strDbPassword.data(),
                                    strDbName.data(),
                                    usDbPort,
                                    NULL,
                                    0))
    {
        Log("connect to database fail error: %s", mysql_error(conn));
        mysql_close(conn);
        return false;
    }

    string strSql = "set names utf8";

    if (!mysql_real_query(conn, strSql.c_str(), (unsigned long) strSql.length()))
    {
        //mysql_affected_rows(conn);
    }
    else
    {
        Log("set names utf8 is failed.");
        return false;
    }

    pDbConn = conn;
    return true;
}

void excuteSql(const string& strSql, int& result, int& affected)
{
    result = -99;
    affected = -99;
    
    result = mysql_query(pDbConn, strSql.data());

    if (0 == result)
    {
        affected = (int)mysql_affected_rows(pDbConn);

        if (-1 == affected)
        {
            Log("Call mysql_affected_rows failed. strSql[%s].",
                strSql.data());
        }
    }
    else
    {
        Log("Call mysql_query failed. sql[%s], errno[%d], err[%s]",
            strSql.data(),
            mysql_errno(pDbConn), 
            mysql_error(pDbConn));
    }
}



int main(int argc, char* argv[])
{
    if (argc != 8)
    {
        Log("Incorrect arg num:%d, must be 7.", argc-1);
        return 0;
    }
    
    strDbHost = argv[1];
    strDbUserName = argv[2];
    strDbPassword = argv[3];
    strDbName = argv[4];
    usDbPort = atoi(argv[5]);
    
    int loop_count = atoi(argv[6]);
    string strSql = argv[7];
    
    // string str = "UPDATE t_sms_direct_client_give_pool SET remain_number=remain_number-1,update_time='2018-12-03 08:59:03' WHERE give_pool_id=106 AND remain_number>=1;";
    
    Log("loop_count:%d, sql:%s.", loop_count, strSql.data());
    
    if (!connectDb())
    {
        Log("connectDb failed");
        return 1;
    }
    else
    {
        Log("connectDb success");
    }
    
    int result; 
    int affected;
    
    for (int i=0; i < loop_count; ++i)
    {
        excuteSql(strSql, result, affected);
        Log(" --> %d  result:%d, affected:%d.", i, result, affected);
        
        if (0 != result)
        {
            Log("excuteSql failed.");
            return 2;
        }
    }

    return 0;
}


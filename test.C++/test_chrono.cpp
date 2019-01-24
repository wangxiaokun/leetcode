#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>


#include <sys/time.h>
#include <time.h>

using namespace std;

int main()
{
    auto t = chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    cout<< std::put_time(std::localtime(&t), "%Y-%m-%d %X")<<endl;
    cout<< std::put_time(std::localtime(&t), "%Y-%m-%d %H.%M.%S.%N")<<endl;



    struct timeval tv;
    gettimeofday(&tv, NULL);

//    return (UInt64)tv.tv_sec * ONE_SECOND_FOR_MICROSECOND + (UInt64)tv.tv_usec;

    tm ptm = {0};
    time_t now = time(NULL);
//    localtime_r((const time_t*) &now, &ptm);


	cout << tv.tv_sec << endl;
	cout << now << endl;


    return 0;
}

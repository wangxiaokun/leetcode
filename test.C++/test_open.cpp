#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#include <sys/types.h>
#include <unistd.h>

#include <string>
using namespace std;

string getFileMd5(const string& strPath, int i)
{
    unsigned char result[32];
    int file_descript = open(strPath.data(), O_RDONLY);

    if (file_descript < 0)
    {
        printf("%d open %s failed.\n", i, strPath.data());
        return "";
    }

    struct stat statbuf;

    if (fstat(file_descript, &statbuf) < 0)
    {
        printf("%d fstat %s failed.\n", i, strPath.data());
        close(file_descript);
        return "";
    }
 
    close(file_descript);
    return "";
}

string getSelfMd5A(int i)
{
    char link[128] = {0};
    char path[128] = {0};
    snprintf(link, 128, "/proc/%d/exe", getpid());

    if (-1 == readlink(link, path, sizeof(path)))
    {
        printf("readlink %s failed.\n", link);
        return "";
    }

    return getFileMd5(string(path), i);
}

string getSelfMd5B(int i)
{
    char link[128] = {0};
    char path[128] = {0};
    snprintf(link, 128, "/proc/%d/exe", getpid());

    if (-1 == readlink(link, path, sizeof(path)))
    {
        printf("readlink %s failed.\n", link);
        return "";
    }

    return getFileMd5(string(path)+".aa", i);
}

int main()
{
   // for (int i=0; i<20; ++i)
   // {
   //     getSelfMd5B(i);
   // }
    
    
    for (int i=0; i<50; ++i)
    {
        printf("---%d\n",i);
        getSelfMd5A(i);
        sleep(1);
    }
    
    
    return true;
}

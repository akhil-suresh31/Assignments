#include<sys/time.h>
using namespace std;

long long randNumGen(int max)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);

    unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
    
    return millisecondsSinceEpoch%max;
}
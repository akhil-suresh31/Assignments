/*
    Author : Akhil Suresh
    q: Custom random no. generator 
        features:
            generates a random no. between 0 - (max-1) , by taking the no. of milliseconds ellapsed till now and getting the reminder
            of it by dividing it by max
        shortcomings:
            if called on same value of max too quick will give the same value or with delta of 1 as current cpu's are so fast
            and doesnt work on nevegetive no's (for now )
*/
#include<iostream>
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

int main(int argc, char const *argv[])
{
    int max;
    do{
    cout<<"Enter the max value to generate random no.( Range :0-max) : ";
    cin>>max;
    }while(max<=0);
    cout<<"random no. of range(0-(max-1)) : "<<randNumGen(max);
    return 0;
}

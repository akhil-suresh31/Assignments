#include<string>

int* countDig(std::string no,int *arr)
{  
    
    for(int i=0;i<no.length();i++)
    {  int dig=no[i]-'0';
        arr[dig]++;
    }
    return arr;
}
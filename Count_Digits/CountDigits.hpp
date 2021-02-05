int countDigits(int num)
{
    int temp=num,count=0;
    if(num == 0)
        count=1;
    while(temp)
    {
        count++;
        temp/=10;
    }
    return count;
}
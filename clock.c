#include <stdio.h>
#include <time.h>
#include <unistd.h>//short cut of Unix standard library used for sleep() function

int main()
{
    int sec,min,hour;
    struct tm* current_time;
    time_t s;
    //returns time in seconds from 1 January 1970
    s=time(NULL);
    //getting current time
    current_time=localtime(&s);
    sec=current_time->tm_sec;
    min=current_time->tm_min;
    hour=current_time->tm_hour;
    //printf("%d Local time  ",asctime(current_time));

    while(1)
    {
        sec+=1;
        if(sec==60)
        {
            min+=1;
            sec=0;
        }
        if(min==60)
        {
            hour+=1;
            min=0;
        }
        if(hour==24)
        {
            hour=0;
            min=0;
            sec=0;
        }
        sleep(1);
        printf("%d:%d:%d\n",hour,min,sec);
    }
    return 0;
}

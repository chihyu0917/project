#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main()
{
  double ratio=0.0;
  int32_t idle_1=0,idle_2=0;
  int32_t total_cpu_time_1=0,total_cpu_time_2=0;
  while(1)
  {
    FILE *pfile=NULL;
    char inform[10000]={0};
    char first_row[500]={0};
    char cpu_time[12][20]={0};
    int32_t cpu_time_10[10]={0};

    pfile=fopen("/proc/stat","r");
    fread(&inform,1,10000,pfile);
    // printf("%s",inform);
    for(int i=0;i<strlen(inform);i++)
    {
      first_row[i]=inform[i];
      if(inform[i]=='\n') break;
    }
    // printf("%s\n",first_row);
    for(int i=0,j=0,k=0;i<strlen(first_row);i++)
    {
      if(first_row[i]==' ') j++,k=0;
      else if(first_row[i]=='\n') break;
      else
      {
        cpu_time[j][k]=first_row[i];
        k++;  
      }
    }
    // printf("%s\n",cpu_time[11]);
    for(int i=2;i<12;i++)
    {
      cpu_time_10[i-2]=atoi(cpu_time[i]);
    }
    //printf("%d\n",cpu_time_10[3]);
    for(int i=0;i<10;i++)
    {
      total_cpu_time_2+=cpu_time_10[i];
    }
    //printf("%d\n",total_cpu_time_2);
    idle_2=cpu_time_10[3];
    ratio=(double)((total_cpu_time_2-total_cpu_time_1)-(idle_2-idle_1))/(total_cpu_time_2-total_cpu_time_1);
    if(total_cpu_time_1!=0.0) printf("CPU usage: %0.02lf%\n",ratio*100);
    idle_1=idle_2;
    idle_2=0;
    total_cpu_time_1=total_cpu_time_2;
    total_cpu_time_2=0;
    sleep(1);
  }
  return 0;
}

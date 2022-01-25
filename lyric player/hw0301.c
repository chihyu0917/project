#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define _BSD_SOURCE

void color(int num)
{
  if(num==0) printf("\033[31m");
  if(num==1) printf("\033[32m");
  if(num==2) printf("\033[33m");
  if(num==3) printf("\033[34m");
  if(num==4) printf("\033[35m");
  if(num==5) printf("\033[36m");
  if(num==6) printf("\033[93m");
  if(num==7) printf("\033[94m");
  if(num==8) printf("\033[95m");
  if(num==9) printf("\033[96m");
}
int main()
{
  FILE *pfile=NULL;
  char file[100]={0};
  
  printf("Open a LRC file: ");
  fgets(file,100,stdin);

  if((file[strlen(file)-1]=='\n')&&(file[strlen(file)-2]=='c')&&(file[strlen(file)-3]=='r')&&(file[strlen(file)-4]=='l'))
  {
    file[strlen(file)-1]='\0';
  } 
  else 
  {
    printf("This is not a LRC File.\n");
    return 0;
  }
  if((pfile=fopen(file,"r"))==NULL)
  {
    printf( "File could not be opened!\n" );
    return 0;
  }
  //pfile=fopen("phantom.of.the.opera.lrc","r");
  char lyric[10000]={0},lyric1[10000];
  fread(lyric,1,10000,pfile);

  int32_t en=0;
  for(int i=0;i<strlen(lyric);i++)//換行個數en
  {
    if(lyric[i]=='\n') en++;
  }
  char lyric2[1000][1000]={0};//每行
  for(int i=0,j=0,k=0;i<strlen(lyric);i++)
  {
    if(lyric[i]!='\n')
    {
      lyric2[j][k]=lyric[i];
      k++;
    }
    else 
    {
      j++;
      k=0;
    }
  }


//---------名字
  char name[20][100]={0};
  char name_all[10][100]={0};
  int name_n=0,name_all_n=0; 
  for(int i=0,k=0;i<en;i++)
  {
  //  printf("%ld\n",strlen(lyric2[i]));
    if((lyric2[i][strlen(lyric2[i])-2]==':')&&(lyric2[i][0]>='A')&&(lyric2[i][0]<='Z'))
    {
      for(int j=0;j<(strlen(lyric2[i])-1);j++)
      {
        name[k][j]=lyric2[i][j];
      }
      k++;
      name_n=k;
    }
  }
  for(int i=0,l=0,m=0;i<name_n;i++)
  {
    l=0;
    for(int j=0;j<20;j++)
    {
      if(strcmp(name[i],name_all[j])==0) l++;
      else if((j==9)&&(l==0)) 
      {
        strcpy(name_all[m],name[i]);
        m++;
      }
      name_all_n=m;
    }
  }

  //for(int i=0;i<strlen(name_all[1]);i++)
 // {
  //  printf("%c",name_all[1][i]);
  //}
  //printf("\n");


//----------時間間隔
  int line[100]={0};
  double min1[5000]={0};
  double sec1[5000]={0};
  double interval[5000]={0};
  for(int i=0,j=0,k=0;i<en;i++)  
  {
    if((lyric2[i][1]>=48)&&(lyric2[i][1]<=57)&&(lyric2[i][2]>=48)&&(lyric2[i][2]<=57))
    {
      line[k]=i;
      min1[i]=(double)((lyric2[i][1]-48)*10+(lyric2[i][2]-48));
      sec1[i]=(double)((lyric2[i][4]-48)*10+(lyric2[i][5]-48)+(lyric2[i][7]-48)*0.1+(lyric2[i][8]-48)*0.01);
      if(i>=1) 
      {
        interval[j]=(min1[i]-min1[line[k-1]])*60+(sec1[i]-sec1[line[k-1]]);
      }
      j++;
      k++;
    }
  }


//---------時間跑出文字
  for(int i=0,k=0,m=0;i<en;i++)
  {
    if((lyric2[i][1]>=48)&&(lyric2[i][1]<=57)&&(lyric2[i][2]>=48)&&(lyric2[i][2]<=57))
    {
      usleep((int)(interval[k]*1000000.0));
      k++;
      for(int j=10;j<strlen(lyric2[i]);j++)
      {
        printf("%c",lyric2[i][j]);
      }
      printf("\n");
    }
    else if((lyric2[i][strlen(lyric2[i])-2]!=':')&&(lyric2[i][0]!='['))
    {
      for(int j=0;j<strlen(lyric2[i]);j++)
      {
        printf("%c",lyric2[i][j]);
      }
      printf("\n");
    }
    else if((lyric2[i][strlen(lyric2[i])-2]==':')&&(lyric2[i][0]>='A')&&(lyric2[i][0]<='Z'))
    {
      for(int j=0;j<10;j++)
      {
        if(strcmp(name[m],name_all[j])==0) 
        {
          color(j);
        }
      }
      m++;
    }
  }
}
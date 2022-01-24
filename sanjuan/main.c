#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <time.h>

#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define blue "\033[34m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define white "\033[37m"
#define b_yellow "\033[93m"
#define b_magenta "\033[95m"
#define b_cyan "\033[96m"

int  error(int c,int min,int max)
{
  if(c==-1) return 1;
  else if((c<min)||(c>max))
  {
    printf("\nWrong Input!!\n");
    return 2;
  }
  else return 3;
}

int role_ch()
{
  int c=0;
  c=-1;
  while(error(c,1,5)!=3)
  {
    printf(b_yellow" ___           "magenta"___            "green"___\n");
    printf(b_yellow"| 1 | BUILDER "magenta"| 2 | PRODUCER "green"| 3 | TRADER  \n");
    printf(b_yellow"|___|         "magenta"|___|          "green"|___|  \n\n");
    printf(blue" ___                 "b_cyan"___\n");
    printf(blue"| 4 | COUNCILOR     "b_cyan"| 5 | PROSPECTOR\n");
    printf(blue"|___|               "b_cyan"|___|\n\n");
    printf(white);
    printf("Please enter your choice.(1-5): ");
    scanf("%d",&c);
  }
  return c;
}

char * role(int c)
{
  if(c==1)
  {
    char *r="Builder";
    return r;
  }
  else if(c==2)
  {
    char *r="Producer";
    return r;
  }
  else if(c==3)
  {
    char *r="Trader";
    return r;
  }
  else if(c==4)
  {
    char *r="Councilor";
    return r;
  }
  else if(c==5)
  {
    char *r="Prospector";
    return r;
  }
}

void card_initial(int card[110],char card_name[29][30],int card_money[29])
{
  strcpy(card_name[0],"indigo plant"),strcpy(card_name[1],"sugar mill"),strcpy(card_name[2],"tobacco storage"),strcpy(card_name[3],"coffee roaster"),strcpy(card_name[4],"silver smelter");
  strcpy(card_name[5],"tower"),strcpy(card_name[6],"chapel"),strcpy(card_name[7],"smithy"),strcpy(card_name[8],"poor house"),strcpy(card_name[9],"black market"),strcpy(card_name[10],"crane"),strcpy(card_name[11],"carpenter"),strcpy(card_name[12],"quarry"),strcpy(card_name[13],"well"),strcpy(card_name[14],"aquaduct"),strcpy(card_name[15],"market stand"),strcpy(card_name[16],"market hall"),strcpy(card_name[17],"trading post"),strcpy(card_name[18],"archive"),strcpy(card_name[19],"prefecture"),strcpy(card_name[20],"gold mine"),strcpy(card_name[21],"library"),strcpy(card_name[22],"statue"),strcpy(card_name[23],"victory column"),strcpy(card_name[24],"hero"),strcpy(card_name[25],"guild hall"),strcpy(card_name[26],"city hall"),strcpy(card_name[27],"triumhal arch"),strcpy(card_name[28],"palace");
  card_money[0]=1,card_money[1]=2,card_money[2]=3,card_money[3]=4,card_money[4]=5;
  card_money[7]=card_money[18]=card_money[20]=1,card_money[8]=card_money[9]=card_money[10]=card_money[13]=card_money[15]=card_money[17]=2,card_money[5]=card_money[6]=card_money[11]=card_money[14]=card_money[19]=card_money[22]=3,card_money[12]=card_money[16]=card_money[23]=4,card_money[21]=card_money[24]=5,card_money[25]=card_money[26]=card_money[27]=card_money[28]=6;
  for(int i=0;i<10;i++) card[i]=0;
  for(int i=10;i<18;i++) card[i]=1;
  for(int i=18;i<26;i++) card[i]=2;
  for(int i=26;i<34;i++) card[i]=3;
  for(int i=34;i<42;i++) card[i]=4;
  for(int i=42;i<45;i++) card[i]=5;
  for(int i=45;i<48;i++) card[i]=6;
  for(int i=48;i<51;i++) card[i]=7;
  for(int i=51;i<54;i++) card[i]=8;
  for(int i=54;i<57;i++) card[i]=9;
  for(int i=57;i<60;i++) card[i]=10;
  for(int i=60;i<63;i++) card[i]=11;
  for(int i=63;i<66;i++) card[i]=12;
  for(int i=66;i<69;i++) card[i]=13;
  for(int i=69;i<72;i++) card[i]=14;
  for(int i=72;i<75;i++) card[i]=15;
  for(int i=75;i<78;i++) card[i]=16;
  for(int i=78;i<81;i++) card[i]=17;
  for(int i=81;i<84;i++) card[i]=18;
  for(int i=84;i<87;i++) card[i]=19;
  for(int i=87;i<90;i++) card[i]=20;
  for(int i=90;i<93;i++) card[i]=21;
  for(int i=93;i<96;i++) card[i]=22;
  for(int i=96;i<99;i++) card[i]=23;
  for(int i=99;i<102;i++) card[i]=24;
  for(int i=102;i<104;i++) card[i]=25;
  for(int i=104;i<106;i++) card[i]=26;
  for(int i=106;i<108;i++) card[i]=27;
  for(int i=108;i<110;i++) card[i]=28;
}

int take_a_card(int card_take_away[])
{
  int a_card=0,result=0;
  // char *a_card_name=NULL;
  srand(time(0));
  a_card=rand()%110;
  while(card_take_away[a_card]<=-1) 
  {
    a_card=0;
    srand(time(0));
    a_card=rand()%110;
  }
  // strcpy(a_card_name,card_name[card[a_card]]);
  return a_card;
  // return a_card_name;
}

void card_score(int score[29])
{
  score[0]=score[1]=score[7]=score[8]=score[9]=score[10]=score[13]=score[15]=score[17]=score[18]=score[20]=1;
  score[2]=score[3]=score[5]=score[6]=score[11]=score[12]=score[14]=score[16]=score[19]=2;
  score[4]=score[21]=score[22]=3;
  score[23]=score[27]=4,score[24]=5;//剩guide hall到palace
}

void win(int i)
{
  if(i==0) printf(b_cyan"\n\nYou win!!\n\n"white);
  else printf(green"\n\nYou lose!!\n\n"white);
}

// char *action(int role,int player_role[],int fee[29],int f_d_card[])

// {
//   size_t n=sizeof(&player_role)/sizeof(player_role[0]);
//   char *action_result=NULL;
//   if(role==1)
//   {
//     if(player_role[0]==1)
//     {
//       printf("\nEnter the face-down card number: ");
//       scanf("%c",&action_result[0]);
//       // action_result[0]=action_ch(1);
//       action_result[0]+=48;
//       printf("\ntest: %c\n",action_result[0]);
//       for(size_t i=1;i<n;i++)
//       {
//         srand(time(0));
//         action_result[i]=(char)(rand()%f_d_card[i]);
//         action_result[i]+=48;
//       }
//       return action_result;
//     }
//   }
//   else if(role==2)
//   {
//     for(size_t i=0;i<n;i++)
//     {
//       if(player_role[i]==2) action_result[i]=2;
//       else action_result[i]=1;
//     }
//     return action_result;
//   }  
// }



void player2(int card[110],char card_name[29][30],int fee[29],int score[29])
{
  int stop=0;
  int gov=0;
  int f_d_card_num[2]={0},f_u_card_num[2]={0},f_d_card_seq[2][12]={0},f_u_card_seq[2][12]={0};
  int goods[2][12]={0};
  int total[2]={0};
  srand(time(0));
  gov=rand()%2;
  // printf("%d\n",gov);
    int card_take_away[110]={0};
    printf("Your face-up cards : ");
    f_u_card_seq[0][0]=0,f_u_card_num[0]=1;
    card_take_away[0]=card_take_away[1]=-1;
    printf(red"%s"white,card_name[card[f_u_card_seq[0][0]]]);
    printf("\nYour face-down cards [fee] : ");
    for(int i=0;i<4;i++)
    {
      // int tmp=0;
      f_d_card_seq[0][i]=take_a_card(card_take_away);
      printf("(%d)"red"%s [%d]"white,i+1,card_name[card[f_d_card_seq[0][i]]],fee[card[f_d_card_seq[0][i]]]);
      card_take_away[f_d_card_seq[0][i]]=(-1);
      if(i!=3) printf(", ");
    }
    f_d_card_num[0]=4;
    printf("\nYour money : "red"%d"white,f_d_card_num[0]); 
    printf("\nComputer Agent 1's face-up cards : ");
    f_u_card_seq[1][0]=1,f_u_card_num[1]=1;
    printf("%s",card_name[card[f_u_card_seq[1][0]]]);
    // printf("\nComputer Agent 1's face-down cards [fee] : ");
    // for(int i=0;i<4;i++)
    // {
    //   // int tmp=0;
    //   f_d_card_seq[1][i]=take_a_card(card_take_away);
    //   printf("(%d)%s [%d]",i+1,card_name[card[f_d_card_seq[1][i]]],fee[card[f_d_card_seq[1][i]]]);
    //   card_take_away[f_d_card_seq[1][i]]=(-1);
    //   if(i!=3) printf(", ");
    // }
    f_d_card_num[1]=4;
    printf("\nComputer Agent 1's money : %d\n",f_d_card_num[1]);
  while(1)
  {
    int fir_tmp=0,sec_tmp=0;
    printf("\n\n"b_yellow"=====================================\n\n"white);
    int player_role[2]={0},role_seq[3]={0};
    printf("The Governor is ");
    if(gov==0) printf(red"you\n"white);
    else if(gov==1) printf(red"Computer Agent %d\n"white,gov);
    for(int k=0;k<110;k++) card_take_away[k]=0;
    for(int k=0;k<2;k++)
    {
      card_take_away[0]=card_take_away[1]=-1;
      if(f_d_card_num[k]>=7)
      {
        for(int m=7;m<f_d_card_num[k];m++) f_d_card_seq[k][m]=0;
        f_d_card_num[k]=7;
      }
      for(int m=0;m<f_u_card_num[k];m++) card_take_away[f_u_card_seq[k][m]]=-1;
      for(int m=0;m<f_d_card_num[k];m++) card_take_away[f_d_card_seq[k][m]]=-1;
    }
    
    if(gov==1)
    {
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[0]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));//
      fir_tmp=player_role[1];//
      player_role[0]=role_ch();
      while(player_role[0]==player_role[1])
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[1]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));//
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[2]=player_role[0];
      while((player_role[0]==player_role[1])||(fir_tmp==player_role[1]))
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[2]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
      sec_tmp=player_role[1];//
      player_role[1]=fir_tmp;//
    }
    else if(gov==0)
    {
      player_role[0]=role_ch();
      printf("\nYour Role is "red"%s"white,role(player_role[0]));//
      fir_tmp=player_role[0];//
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[0]=player_role[0];
      while(player_role[0]==player_role[1])
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[1]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
      player_role[0]=role_ch();
      while((player_role[0]==player_role[1])||(player_role[0]==fir_tmp))
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[2]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));//
      sec_tmp=player_role[0];//
      player_role[0]=fir_tmp;//
    }

    for(int ii=0;ii<3;ii++)
    {
      if(role_seq[ii]==1)//----------builder
      {
        int building[29]={0};
        for(int i=0;i<2;i++)
        {
          for(int j=0;j<f_u_card_num[i];j++) 
          {
            if(card[f_u_card_seq[i][j]]==7) building[7]=1;
            if(card[f_u_card_seq[i][j]]==8) building[8]=1;
            if(card[f_u_card_seq[i][j]]==9) building[9]=1;
            if(card[f_u_card_seq[i][j]]==10) building[10]=1;
            if(card[f_u_card_seq[i][j]]==11) building[11]=1;
            if(card[f_u_card_seq[i][j]]==12) building[12]=1;
          }
        }
        size_t n=2;
      // sizeof(&player_role)/sizeof(player_role[0]);
        int action_result[2]={0};
        
        // if(player_role[0]==1)
        // {
            printf("\nEnter the building number from face-down card number which you want to "b_yellow"build"white"(0 for No): ");
            scanf("%d",&action_result[0]);
            action_result[0]--;
        for(size_t i=1;i<n;i++)
        {
            srand(time(0));
            action_result[i]=rand()%f_d_card_num[i];
        }
        
        for(int i=0;i<2;i++)
        {
          if(action_result[i]==-1) i++;//改過
          f_u_card_num[i]++;
          // printf("\ntest:%d\n",f_u_card_num[i]);
          f_u_card_seq[i][f_u_card_num[i]-1]=f_d_card_seq[i][action_result[i]];
          // f_d_card_seq[i][action_result[i]]=0;
          int tmp=0,tmp2=0,tmp3=0;
          tmp=f_d_card_num[i];
          if(player_role[i]==role_seq[ii]) f_d_card_num[i]++;
          if(building[7]==1) f_d_card_num[i]++;
          f_d_card_num[i]-=fee[card[f_d_card_seq[i][action_result[i]]]];
          if((building[8]==1)&&(f_d_card_num[i]<=1)) f_d_card_num[i]++;
          if((building[11]==1)&&(card[f_d_card_seq[i][action_result[i]]]>=5)) 
          {
            tmp2=take_a_card(card_take_away);
            card_take_away[tmp2]=(-1);
            tmp3=f_d_card_num[i];
            f_d_card_num[i]++;
            f_d_card_seq[i][tmp3]=tmp2;
          }
          if((building[12]==1)&&(card[f_d_card_seq[i][action_result[i]]]>=5)) f_d_card_num[i]++;
          // printf("test:%d %d\n",action_result[i],fee[card[f_d_card_seq[i][action_result[i]]]]);
    //--------價格ok怪怪的fee[card[f_d_card_seq[i][j]]]
          for(int j=action_result[i];j<=tmp-1;j++)
          {
            f_d_card_seq[i][j]=f_d_card_seq[i][j+1];
          }
          if(i==0) printf("\nYour face-up cards : ");
          else printf("\n\nComputer Agent %d's face-up cards : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
            printf("(%d)"red"%s"white,j+1,card_name[card[f_u_card_seq[i][j]]]);
            if(j!=f_u_card_num[i]-1) printf(", ");
          }
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
          
          if (i==0) printf("\nYour money : %d\n",f_d_card_num[i]);
          else printf("\nComputer Agent %d's money : %d\n",i,f_d_card_num[i]);
        }
      }
      else if(role_seq[ii]==2)//----------producer
      {
        
        int action_result[2]={0};
            printf("\nEnter the "yellow"production building"white" number from face-up card number which you want to "magenta"produce: "white);
            scanf("%d",&action_result[0]);
            action_result[0]--;
        for(size_t i=1;i<2;i++)
        {
          srand(time(0));
          action_result[i]=rand()%f_u_card_num[i];
          if(card[f_u_card_seq[i][action_result[i]]]>=5) action_result[i]=-1;//改過

        }    
        for(int i=0;i<2;i++)
        {
          if(action_result[i]==-1) i++;//改過
          if(action_result[i]>f_u_card_num[i]) break;
          for(int j=0;j<2;j++)
          {
            // printf(red"test\n"white);
            int tmp=0;
            // printf(red"\ntest: %d\n"white,action_result[i]);
            goods[i][action_result[i]]++;
            // printf(red"\ntest: %d\n"white,goods[i][action_result[1]]);
            tmp=take_a_card(card_take_away);
            card_take_away[tmp]=(-1);
            if(player_role[i]!=role_seq[ii]) break;//改過
          }
        }
        for(int i=0;i<2;i++)
        {
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);//f_u_card_seq[i][j]
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
        }
      }
      else if(role_seq[ii]==3)//----------trader
      {
        int n=0;
        int tile[5][5]={0};
        tile[0][0]=tile[0][1]=tile[0][2]=tile[1][0]=tile[1][1]=tile[2][0]=tile[2][1]=tile[3][0]=tile[4][0]=1;
        tile[0][3]=tile[0][4]=tile[1][2]=tile[1][3]=tile[1][4]=tile[2][2]=tile[2][3]=tile[3][1]=tile[3][2]=tile[3][3]=tile[4][1]=tile[4][2]=2;
        tile[2][4]=tile[3][4]=tile[4][3]=tile[4][4]=3;
        srand(time(0));
        n=rand()%5;
        printf("\nProduction Building : (1) Indigo plant, (2) Sugar mill, (3) Tobacco storage, (4) Coffee roaster, (5) Silver smelter\n");
        printf("Price (Trading House Tile) : ");
        for(int i=0;i<5;i++)
        {
          printf("(%d) "green"%d"white,i+1,tile[n][i]);
          if(i!=4) printf(", ");
          else printf("\n");
        }
        // printf(red"IIIIItest\n"white);
        for(int i=0;i<2;i++)
        {
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
        }
        //
        for(int j=0;j<2;j++)
        {
          int action_result[2]={0};
        
          printf("\nEnter the "yellow"production building"white" number from face-up card number which you want to "green"trade "white"(0 for No): ");
          scanf("%d",&action_result[0]);
          action_result[0]--;
          if(action_result[0]==-1) break;
          // printf(red"test: \n"white);
          for(size_t i=1;i<2;i++)
          {
              srand(time(0));
              action_result[i]=rand()%f_u_card_num[i];
              if((card[f_d_card_seq[i][action_result[i]]]>=5)||goods[i][action_result[i]]<=0) action_result[i]=-1;//改過
          }
          for(int i=0;i<2;i++)
          {
            if(action_result[i]==-1) i++;//改過
            // if(card[f_d_card_seq[i][action_result[i]]]>=5) break;
            int tmp=0,tmp2=0;
            goods[i][action_result[i]]--;
            // printf(red"test: \n"white);
            tmp2=f_d_card_num[i];
            f_d_card_num[i]+=tile[n][card[f_u_card_seq[i][action_result[i]]]];//新加ok
            // printf(red"test: %d\n"white,card[f_u_card_seq[i][action_result[i]]]);
            // fee[card[f_d_card_seq[i][j]]]
            for(int j=0;j<tile[n][card[f_u_card_seq[i][action_result[i]]]];j++)//新加
            {
              tmp=take_a_card(card_take_away);
              card_take_away[tmp]=(-1);
              f_d_card_seq[i][tmp2]=tmp;//新加
              tmp2++;
            }
          }
          if(player_role[j]!=role_seq[ii]) break;//改過
        }
        
        for(int i=0;i<2;i++)
        {  
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
          if (i==0) printf("\nYour money : %d\n",f_d_card_num[i]);
          else printf("\nComputer Agent %d's money : %d\n",i,f_d_card_num[i]);
        } 
      }
      else if(role_seq[ii]==4)//----------councilor
      {
        int action_result[2]={0};
        int tmp[5]={0};
        for(int i=0;i<1;i++)
        {
          // printf(red"\ntest: %d %d\n"white,player_role[ii],role_seq[ii]);
          if(player_role[0]==role_seq[ii])
          {

            for(int i=0;i<5;i++)
            {
              tmp[i]=take_a_card(card_take_away);
              card_take_away[tmp[i]]=(-1);
            }
            printf("\n");
            for(int i=0;i<5;i++)
            {
              printf("(%d) "blue"%s"white,i+1,card_name[card[tmp[i]]]);
              if(i!=1) printf(", ");
            }
              printf("\nEnter the card which you want to keep : ");
              scanf("%d",&action_result[0]);
              action_result[0]--;
          }
          else
          {
            // int tmp[2]={0};
            for(int i=0;i<2;i++)
            {
              tmp[i]=take_a_card(card_take_away);
              card_take_away[tmp[i]]=(-1);
            }
            printf("\n");
            for(int i=0;i<2;i++)
            {
              printf("(%d) "blue"%s"white,i+1,card_name[card[tmp[i]]]);
              if(i!=1) printf(", ");
            }
              printf("\nEnter the card which you want to keep : ");
              scanf("%d",&action_result[0]);
              action_result[0]--;
          }
        }
        for(size_t i=1;i<2;i++)
        {
            srand(time(0));
            action_result[i]=rand()%2;
            // if(card[f_d_card_seq[i][action_result[i]]]>=5) i--;
        }
        for(int i=0;i<2;i++)
        {
          int tmp2=0;
          tmp2=f_d_card_num[i];
          f_d_card_num[i]++;
          // // fee[card[f_d_card_seq[i][j]]]
          // for(int j=0;j<tile[n][card[f_d_card_seq[i][action_result[i]]]];j++)//新加
          // {
          //   tmp=take_a_card(card_take_away);
          //   card_take_away[tmp]=(-1);
          f_d_card_seq[i][tmp2]=tmp[action_result[i]];
          // printf(red"\n%d\n"white,tmp[action_result[i]]);
          // card_name[card[tmp[i]]]
          // }
        
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
        }
      }
      else if(role_seq[ii]==5)//----------prospector
      {
        int tmp=0;
        for(int i=0;i<2;i++)
        {
          if(player_role[i]==role_seq[ii])//改過
          {
            tmp=take_a_card(card_take_away);
            card_take_away[tmp]=(-1);
            int tmp2=0;
            tmp2=f_d_card_num[i];
            f_d_card_num[i]++;
            f_d_card_seq[i][tmp2]=tmp;
            if(i==0) printf("\nYour face-down cards [fee] : ");
            // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
            if(i==0)
            {
              for(int j=0;j<f_d_card_num[i];j++)
              {
                  printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                  if(j!=(f_d_card_num[i]-1)) printf(", ");
              }
            }
          }
        }
      }
    }
    gov++;
    if(gov>=2) gov=0;
    for(int k=0;k<2;k++)
    {
      if(f_u_card_seq[k][11]!=0) 
      {
        stop=1;
        break;
      }
    }
    if(stop==1) break;
  }
  card_score(score);
  for(int n=0;n<2;n++)
  {
    for(int p=0,q=0;p<f_u_card_num[n];p++)
    {
      for(int q=0;q<29;q++)
      {
        if((card[f_d_card_seq[n][p]]==q)&&(q<25)) total[n]+=score[q];
        if((card[f_d_card_seq[n][p]]==q)&&(q==27)) total[n]+=score[q];
        if((card[f_d_card_seq[n][p]]==q)&&(q==28))
        {
          double tmp4=0.0;
          tmp4=total[n];
          tmp4*=1.25;
          total[n]=(int)tmp4;
        }
      }
    }
    if(n==0) printf("\n\nYour "yellow" total score"white": %d\n",total[n]);
    else printf("Computer Agent %d's"yellow" total score"white": %d\n",n,total[n]);
  }
  int max=0;
  for(int n=0;n<2;n++)
  {
    if(total[n]>=total[max]) max=n;
  }
  win(max);
}

void player3(int card[110],char card_name[29][30],int fee[29],int score[29])
{
  int stop=0;
  int gov=0;
  int f_d_card_num[3]={0},f_u_card_num[3]={0},f_d_card_seq[3][12]={0},f_u_card_seq[3][12]={0};
  int goods[3][12]={0};
  int total[3]={0};
  srand(time(0));
  gov=rand()%3;
  // printf("%d\n",gov);
    int card_take_away[110]={0};
    printf("Your face-up cards : ");
    f_u_card_seq[0][0]=0,f_u_card_num[0]=1;
    card_take_away[0]=card_take_away[1]=card_take_away[2]=-1;
    printf(red"%s"white,card_name[card[f_u_card_seq[0][0]]]);
    printf("\nYour face-down cards [fee] : ");
    for(int i=0;i<4;i++)
    {
      // int tmp=0;
      f_d_card_seq[0][i]=take_a_card(card_take_away);
      printf("(%d)"red"%s [%d]"white,i+1,card_name[card[f_d_card_seq[0][i]]],fee[card[f_d_card_seq[0][i]]]);
      card_take_away[f_d_card_seq[0][i]]=(-1);
      if(i!=3) printf(", ");
    }
    f_d_card_num[0]=4;
    printf("\nYour money : "red"%d"white,f_d_card_num[0]);// 
    printf("\nComputer Agent 1's face-up cards : ");
    f_u_card_seq[1][0]=1,f_u_card_num[1]=1;
    printf("%s",card_name[card[f_u_card_seq[1][0]]]);
    // printf("\nComputer Agent 1's face-down cards [fee] : ");
    // for(int i=0;i<4;i++)
    // {
    //   // int tmp=0;
    //   f_d_card_seq[1][i]=take_a_card(card_take_away);
    //   printf("(%d)%s [%d]",i+1,card_name[card[f_d_card_seq[1][i]]],fee[card[f_d_card_seq[1][i]]]);
    //   card_take_away[f_d_card_seq[1][i]]=(-1);
    //   if(i!=3) printf(", ");
    // }
    f_d_card_num[1]=4;
    printf("\nComputer Agent 1's money : %d\n",f_d_card_num[1]);//
    printf("\nComputer Agent 2's face-up cards : ");
    f_u_card_seq[2][0]=2,f_u_card_num[2]=1;
    printf("%s",card_name[card[f_u_card_seq[2][0]]]);
    // printf("\nComputer Agent 2's face-down cards [fee] : ");
    // for(int i=0;i<4;i++)
    // {
    //   // int tmp=0;
    //   f_d_card_seq[2][i]=take_a_card(card_take_away);
    //   printf("(%d)%s [%d]",i+1,card_name[card[f_d_card_seq[2][i]]],fee[card[f_d_card_seq[2][i]]]);
    //   card_take_away[f_d_card_seq[2][i]]=(-1);
    //   if(i!=3) printf(", ");
    // }
    f_d_card_num[2]=4;
    printf("\nComputer Agent 2's money : %d\n",f_d_card_num[2]);
  while(1)
  {
    printf("\n\n"b_yellow"=====================================\n\n"white);
    int player_role[3]={0},role_seq[3]={0};
    printf("The Governor is ");
    if(gov==0) printf(red"you\n"white);
    else if(gov==1) printf(red"Computer Agent %d\n"white,gov);
    else if(gov==2) printf(red"Computer Agent %d\n"white,gov);
    for(int k=0;k<110;k++) card_take_away[k]=0;
    for(int k=0;k<3;k++)
    {
      card_take_away[0]=card_take_away[1]=card_take_away[2]=-1;
      if(f_d_card_num[k]>=7)
      {
        for(int m=7;m<f_d_card_num[k];m++) f_d_card_seq[k][m]=0;
        f_d_card_num[k]=7;
      }
      for(int m=0;m<f_u_card_num[k];m++) card_take_away[f_u_card_seq[k][m]]=-1;
      for(int m=0;m<f_d_card_num[k];m++) card_take_away[f_d_card_seq[k][m]]=-1;
    }
    if(gov==1)
    {
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[0]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
      player_role[2]=rand()%5;
      player_role[2]++;
      while(player_role[1]==player_role[2])
      {
        player_role[2]=rand()%5;
        player_role[2]++;
      }
      role_seq[1]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));
      player_role[0]=role_ch();
      while((player_role[0]==player_role[1])||(player_role[0]==player_role[2]))
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[2]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));
    }
    else if(gov==2)
    {
      player_role[2]=rand()%5;
      player_role[2]++;
      role_seq[0]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));//
      player_role[0]=role_ch();
      while(player_role[0]==player_role[2])
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[1]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));//
      player_role[1]=rand()%5;
      player_role[1]++;
      while((player_role[1]==player_role[2])||(player_role[1]==player_role[0]))
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[2]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
      
    }
    else if(gov==0)
    {
      player_role[0]=role_ch();
      printf("\nYour Role is "red"%s"white,role(player_role[0]));
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[0]=player_role[0];
      while(player_role[0]==player_role[1])
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[1]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
      player_role[2]=rand()%5;
      player_role[2]++;
      while((player_role[1]==player_role[2])||(player_role[0]==player_role[2]))
      {
        player_role[2]=rand()%5;
        player_role[2]++;
      }
      role_seq[2]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));
    }

    for(int ii=0;ii<3;ii++)
    {
      if(role_seq[ii]==1)//----------builder
      {
        int building[29]={0};
        for(int i=0;i<3;i++)
        {
          for(int j=0;j<f_u_card_num[i];j++) 
          {
            if(card[f_u_card_seq[i][j]]==7) building[7]=1;
            if(card[f_u_card_seq[i][j]]==8) building[8]=1;
            if(card[f_u_card_seq[i][j]]==9) building[9]=1;
            if(card[f_u_card_seq[i][j]]==10) building[10]=1;
            if(card[f_u_card_seq[i][j]]==11) building[11]=1;
            if(card[f_u_card_seq[i][j]]==12) building[12]=1;
          }
        }
        size_t n=3;
      // sizeof(&player_role)/sizeof(player_role[0]);
        int action_result[3]={0};
        
       
        printf("\nEnter the building number from face-down card number which you want to "b_yellow"build"white"(0 for No): ");
        scanf("%d",&action_result[0]);
        action_result[0]--;
        for(size_t i=1;i<n;i++)
        {
            srand(time(0));
            action_result[i]=rand()%f_d_card_num[i];
        }
        
        for(int i=0;i<3;i++)
        {
          if(action_result[i]==-1) i++;
          f_u_card_num[i]++;
          // printf("\ntest:%d\n",f_u_card_num[i]);
          f_u_card_seq[i][f_u_card_num[i]-1]=f_d_card_seq[i][action_result[i]];
          // f_d_card_seq[i][action_result[i]]=0;
          int tmp=0,tmp2=0,tmp3=0;
          tmp=f_d_card_num[i];
          if(player_role[i]==role_seq[ii]) f_d_card_num[i]++;
          if(building[7]==1) f_d_card_num[i]++;
          f_d_card_num[i]-=fee[card[f_d_card_seq[i][action_result[i]]]];
          if((building[8]==1)&&(f_d_card_num[i]<=1)) f_d_card_num[i]++;
          if((building[11]==1)&&(card[f_d_card_seq[i][action_result[i]]]>=5)) 
          {
            tmp2=take_a_card(card_take_away);
            card_take_away[tmp2]=(-1);
            tmp3=f_d_card_num[i];
            f_d_card_num[i]++;
            f_d_card_seq[i][tmp3]=tmp2;
          }
          if((building[12]==1)&&(card[f_d_card_seq[i][action_result[i]]]>=5)) f_d_card_num[i]++;
          // printf("test:%d %d\n",action_result[i],fee[card[f_d_card_seq[i][action_result[i]]]]);
    //--------價格ok怪怪的fee[card[f_d_card_seq[i][j]]]
          for(int j=action_result[i];j<=tmp-1;j++)
          {
            f_d_card_seq[i][j]=f_d_card_seq[i][j+1];
          }
          if(i==0) printf("\nYour face-up cards : ");
          else printf("\n\nComputer Agent %d's face-up cards : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
            printf("(%d)"red"%s"white,j+1,card_name[card[f_u_card_seq[i][j]]]);
            if(j!=f_u_card_num[i]-1) printf(", ");
          }
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
          if (i==0) printf("\nYour money : %d\n",f_d_card_num[i]);
          else printf("\nComputer Agent %d's money : %d\n",i,f_d_card_num[i]);
        }
      }
      else if(role_seq[ii]==2)//----------producer
      {
        
        int action_result[3]={0};
            printf("\nEnter the "yellow"production building"white" number from face-up card number which you want to "magenta"produce: "white);
            scanf("%d",&action_result[0]);
            action_result[0]--;
        for(size_t i=1;i<3;i++)
        {
            srand(time(0));
            action_result[i]=rand()%f_u_card_num[i];
            if(card[f_u_card_seq[i][action_result[i]]]>=5) action_result[i]=-1;//改過
        }    
        for(int i=0;i<3;i++)
        {
          if(action_result[i]==-1) i++;
          if(action_result[i]>f_u_card_num[i]) break;
          for(int j=0;j<2;j++)
          {
            // printf(red"test\n"white);
            int tmp=0;
            // printf(red"\ntest: %d\n"white,action_result[i]);
            goods[i][action_result[i]]++;
            // printf(red"\ntest: %d\n"white,goods[i][action_result[1]]);
            tmp=take_a_card(card_take_away);
            card_take_away[tmp]=(-1);
            if(player_role[i]!=role_seq[ii]) break;//改過
          }
        }
        for(int i=0;i<3;i++)
        {
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);//f_u_card_seq[i][j]
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
        }
      }
      else if(role_seq[ii]==3)//----------trader
      {
        int n=0;
        int tile[5][5]={0};
        tile[0][0]=tile[0][1]=tile[0][2]=tile[1][0]=tile[1][1]=tile[2][0]=tile[2][1]=tile[3][0]=tile[4][0]=1;
        tile[0][3]=tile[0][4]=tile[1][2]=tile[1][3]=tile[1][4]=tile[2][2]=tile[2][3]=tile[3][1]=tile[3][2]=tile[3][3]=tile[4][1]=tile[4][2]=2;
        tile[2][4]=tile[3][4]=tile[4][3]=tile[4][4]=3;
        srand(time(0));
        n=rand()%5;
        printf("\nProduction Building : (1) Indigo plant, (2) Sugar mill, (3) Tobacco storage, (4) Coffee roaster, (5) Silver smelter\n");
        printf("Price (Trading House Tile) : ");
        for(int i=0;i<5;i++)
        {
          printf("(%d) "green"%d"white,i+1,tile[n][i]);
          if(i!=4) printf(", ");
          else printf("\n");
        }
        // printf(red"IIIIItest\n"white);
        for(int i=0;i<3;i++)
        {
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
        }
        //
        for(int j=0;j<2;j++)
        {
          int action_result[3]={0};
          printf("\nEnter the "yellow"production building"white" number from face-up card number which you want to "green"trade "white"(0 for No): ");
          scanf("%d",&action_result[0]);
          action_result[0]--;
          if(action_result[0]==-1) break;
          // printf(red"test: \n"white);
          for(size_t i=1;i<3;i++)
          {
              srand(time(0));
              action_result[i]=rand()%f_u_card_num[i];
              if((card[f_d_card_seq[i][action_result[i]]]>=5)||goods[i][action_result[i]]<=0) action_result[i]=-1;//改過
          }
          for(int i=0;i<3;i++)
          {
            if(action_result[0]==-1) i++;
            // if(card[f_d_card_seq[i][action_result[i]]]>=5) break;
            int tmp=0,tmp2=0;
            goods[i][action_result[i]]--;
            // printf(red"test: \n"white);
            tmp2=f_d_card_num[i];
            f_d_card_num[i]+=tile[n][card[f_u_card_seq[i][action_result[i]]]];//新加ok
            // printf(red"test: %d\n"white,card[f_u_card_seq[i][action_result[i]]]);
            // fee[card[f_d_card_seq[i][j]]]
            for(int j=0;j<tile[n][card[f_u_card_seq[i][action_result[i]]]];j++)//新加
            {
              tmp=take_a_card(card_take_away);
              card_take_away[tmp]=(-1);
              f_d_card_seq[i][tmp2]=tmp;//新加
              tmp2++;
            }
          }
          if(player_role[j]!=role_seq[ii]) break;//改過
        }
        
        for(int i=0;i<3;i++)
        {  
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
          if (i==0) printf("\nYour money : %d\n",f_d_card_num[i]);
          else printf("\nComputer Agent %d's money : %d\n",i,f_d_card_num[i]);

        } 
      }
      else if(role_seq[ii]==4)//----------councilor
      {
        int action_result[3]={0};
        int tmp[5]={0};
        for(int i=0;i<1;i++)
        {
          // printf(red"\ntest: %d %d\n"white,player_role[ii],role_seq[ii]);
          if(player_role[0]==role_seq[ii])
          {
            for(int i=0;i<5;i++)
            {
              tmp[i]=take_a_card(card_take_away);
              card_take_away[tmp[i]]=(-1);
            }
            printf("\n");
            for(int i=0;i<5;i++)
            {
              printf("(%d) "blue"%s"white,i+1,card_name[card[tmp[i]]]);
              if(i!=1) printf(", ");
            }
              printf("\nEnter the card which you want to keep : ");
              scanf("%d",&action_result[0]);
              action_result[0]--;
          }
          else
          {
            // int tmp[2]={0};
            for(int i=0;i<2;i++)
            {
              tmp[i]=take_a_card(card_take_away);
              card_take_away[tmp[i]]=(-1);
            }
            printf("\n");
            for(int i=0;i<2;i++)
            {
              printf("(%d) "blue"%s"white,i+1,card_name[card[tmp[i]]]);
              if(i!=1) printf(", ");
            }
              printf("\nEnter the card which you want to keep : ");
              scanf("%d",&action_result[0]);
              action_result[0]--;
          }
        }
        for(size_t i=1;i<3;i++)
        {
            srand(time(0));
            action_result[i]=rand()%2;
            // if(card[f_d_card_seq[i][action_result[i]]]>=5) i--;  
        }
        for(int i=0;i<3;i++)
        {
          int tmp2=0;
          tmp2=f_d_card_num[i];
          f_d_card_num[i]++;
          // // fee[card[f_d_card_seq[i][j]]]
          // for(int j=0;j<tile[n][card[f_d_card_seq[i][action_result[i]]]];j++)//新加
          // {
          //   tmp=take_a_card(card_take_away);
          //   card_take_away[tmp]=(-1);
          f_d_card_seq[i][tmp2]=tmp[action_result[i]];
          // printf(red"\n%d\n"white,tmp[action_result[i]]);
          // card_name[card[tmp[i]]]
          // }
        
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
        }
      }
      else if(role_seq[ii]==5)//----------prospector
      {
        int tmp=0;
        for(int i=0;i<3;i++)
        {
          if(player_role[i]==role_seq[ii])//改過
          {
            tmp=take_a_card(card_take_away);
            card_take_away[tmp]=(-1);
            int tmp2=0;
            tmp2=f_d_card_num[i];
            f_d_card_num[i]++;
            f_d_card_seq[i][tmp2]=tmp;
            if(i==0) printf("\nYour face-down cards [fee] : ");
            // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
            if(i==0)
            {
              for(int j=0;j<f_d_card_num[i];j++)
              {
                  printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                  if(j!=(f_d_card_num[i]-1)) printf(", ");
              }
            }
          }
        }
      }
    }
    gov++;
    if(gov>=3) gov=0;
    for(int k=0;k<3;k++)
    {
      if(f_u_card_seq[k][11]!=0) 
      {
        stop=1;
        break;
      }
    }
    if(stop==1) break;
  }
  card_score(score);
  for(int n=0;n<3;n++)
  {
    for(int p=0,q=0;p<f_u_card_num[n];p++)
    {
      for(int q=0;q<29;q++)
      {
        if((card[f_d_card_seq[n][p]]==q)&&(q<25)) total[n]+=score[q];
        if((card[f_d_card_seq[n][p]]==q)&&(q==27)) total[n]+=score[q];
        if((card[f_d_card_seq[n][p]]==q)&&(q==28))
        {
          double tmp4=0.0;
          tmp4=total[n];
          tmp4*=1.25;
          total[n]=(int)tmp4;
        }
      }
    }
    if(n==0) printf("\n\nYour "yellow" total score"white": %d\n",total[n]);
    else printf("Computer Agent %d's"yellow" total score"white": %d\n",n,total[n]);
  }
  int max=0;
  for(int n=0;n<3;n++)
  {
    if(total[n]>=total[max]) max=n;
  }
  win(max);
}

void player4(int card[110],char card_name[29][30],int fee[29],int score[29])
{
  int stop=0;
  int gov=0;
  int f_d_card_num[4]={0},f_u_card_num[4]={0},f_d_card_seq[4][12]={0},f_u_card_seq[4][12]={0};
  int goods[4][12]={0};
  int total[4]={0};
  srand(time(0));
  gov=rand()%4;
  // printf("%d\n",gov);
    int card_take_away[110]={0};
    printf("Your face-up cards : ");
    f_u_card_seq[0][0]=0,f_u_card_num[0]=1;
    card_take_away[0]=card_take_away[1]=card_take_away[2]=card_take_away[3]=-1;
    printf(red"%s"white,card_name[card[f_u_card_seq[0][0]]]);
    printf("\nYour face-down cards [fee] : ");
    for(int i=0;i<4;i++)
    {
      // int tmp=0;
      f_d_card_seq[0][i]=take_a_card(card_take_away);
      printf("(%d)"red"%s [%d]"white,i+1,card_name[card[f_d_card_seq[0][i]]],fee[card[f_d_card_seq[0][i]]]);
      card_take_away[f_d_card_seq[0][i]]=(-1);
      if(i!=3) printf(", ");
    }
    f_d_card_num[0]=4;
    printf("\nYour money : "red"%d"white,f_d_card_num[0]);// 
    printf("\nComputer Agent 1's face-up cards : ");
    f_u_card_seq[1][0]=1,f_u_card_num[1]=1;
    printf("%s",card_name[card[f_u_card_seq[1][0]]]);
    // printf("\nComputer Agent 1's face-down cards [fee] : ");
    // for(int i=0;i<4;i++)
    // {
    //   // int tmp=0;
    //   f_d_card_seq[1][i]=take_a_card(card_take_away);
    //   printf("(%d)%s [%d]",i+1,card_name[card[f_d_card_seq[1][i]]],fee[card[f_d_card_seq[1][i]]]);
    //   card_take_away[f_d_card_seq[1][i]]=(-1);
    //   if(i!=3) printf(", ");
    // }
    f_d_card_num[1]=4;
    printf("\nComputer Agent 1's money : %d\n",f_d_card_num[1]);//
    printf("\nComputer Agent 2's face-up cards : ");
    f_u_card_seq[2][0]=2,f_u_card_num[2]=1;
    printf("%s",card_name[card[f_u_card_seq[2][0]]]);
    // printf("\nComputer Agent 2's face-down cards [fee] : ");
    // for(int i=0;i<4;i++)
    // {
    //   // int tmp=0;
    //   f_d_card_seq[2][i]=take_a_card(card_take_away);
    //   printf("(%d)%s [%d]",i+1,card_name[card[f_d_card_seq[2][i]]],fee[card[f_d_card_seq[2][i]]]);
    //   card_take_away[f_d_card_seq[2][i]]=(-1);
    //   if(i!=3) printf(", ");
    // }
    f_d_card_num[2]=4;
    printf("\nComputer Agent 2's money : %d\n",f_d_card_num[2]);//
    printf("\nComputer Agent 3's face-up cards : ");
    f_u_card_seq[3][0]=3,f_u_card_num[3]=1;
    printf("%s",card_name[card[f_u_card_seq[3][0]]]);
    // printf("\nComputer Agent 3's face-down cards [fee] : ");
    // for(int i=0;i<4;i++)
    // {
    //   // int tmp=0;
    //   f_d_card_seq[3][i]=take_a_card(card_take_away);
    //   printf("(%d)%s [%d]",i+1,card_name[card[f_d_card_seq[3][i]]],fee[card[f_d_card_seq[3][i]]]);
    //   card_take_away[f_d_card_seq[3][i]]=(-1);
    //   if(i!=3) printf(", ");
    // }
    f_d_card_num[3]=4;
    printf("\nComputer Agent 3's money : %d\n",f_d_card_num[3]);
  while(1)
  {
    printf("\n\n"b_yellow"=====================================\n\n"white);
    int player_role[4]={0},role_seq[4]={0};
    printf("The Governor is ");
    if(gov==0) printf(red"you\n"white);
    else printf(red"Computer Agent %d\n"white,gov);
    for(int k=0;k<110;k++) card_take_away[k]=0;
    for(int k=0;k<4;k++)
    {
      card_take_away[0]=card_take_away[1]=card_take_away[2]=card_take_away[3]=-1;
      if(f_d_card_num[k]>=7)
      {
        for(int m=7;m<f_d_card_num[k];m++) f_d_card_seq[k][m]=0;
        f_d_card_num[k]=7;
      }
      for(int m=0;m<f_u_card_num[k];m++) card_take_away[f_u_card_seq[k][m]]=-1;
      for(int m=0;m<f_d_card_num[k];m++) card_take_away[f_d_card_seq[k][m]]=-1;
    }
    if(gov==1)
    {
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[0]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));//
      player_role[2]=rand()%5;
      player_role[2]++;
      while(player_role[1]==player_role[2])
      {
        player_role[2]=rand()%5;
        player_role[2]++;
      }
      role_seq[1]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));//
      player_role[3]=rand()%5;
      player_role[3]++;
      while((player_role[1]==player_role[3])||(player_role[2]==player_role[3]))
      {
        player_role[3]=rand()%5;
        player_role[3]++;
      }
      role_seq[2]=player_role[3];
      printf("\nComputer Agent 3's Role is %s\n",role(player_role[3]));//
      player_role[0]=role_ch();
      while((player_role[0]==player_role[1])||(player_role[0]==player_role[2])||(player_role[0]==player_role[3]))
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[3]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));
    }
    else if(gov==2)
    {
      player_role[2]=rand()%5;
      player_role[2]++;
      role_seq[0]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));//
      player_role[3]=rand()%5;
      player_role[3]++;
      while(player_role[2]==player_role[3])
      {
        player_role[3]=rand()%5;
        player_role[3]++;
      }
      role_seq[1]=player_role[3];
      printf("\nComputer Agent 3's Role is %s\n",role(player_role[3]));//
      player_role[0]=role_ch();
      while((player_role[0]==player_role[2])||(player_role[0]==player_role[3]))
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[2]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));//
      player_role[1]=rand()%5;
      player_role[1]++;
      while((player_role[1]==player_role[2])||(player_role[1]==player_role[0])||(player_role[1]==player_role[3]))
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[3]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
    }
    else if(gov==3)
    {
      player_role[3]=rand()%5;
      player_role[3]++;
      role_seq[0]=player_role[3];
      printf("\nComputer Agent 3's Role is %s\n",role(player_role[3]));//
      player_role[0]=role_ch();
      while(player_role[0]==player_role[3])
      {
        printf(red"Please choose another role.\n"white);
        player_role[0]=0;
        player_role[0]=role_ch();
      }
      role_seq[1]=player_role[0];
      printf("\nYour Role is "red"%s"white,role(player_role[0]));//
      player_role[1]=rand()%5;
      player_role[1]++;
      while((player_role[1]==player_role[3])||(player_role[1]==player_role[0]))
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[2]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));//
      player_role[2]=rand()%5;
      player_role[2]++;
      while((player_role[0]==player_role[2])||(player_role[1]==player_role[2])||(player_role[3]==player_role[2]))
      {
        player_role[2]=rand()%5;
        player_role[2]++;
      }
      role_seq[3]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));
    }
    else if(gov==0)
    {
      player_role[0]=role_ch();
      printf("\nYour Role is "red"%s"white,role(player_role[0]));
      player_role[1]=rand()%5;
      player_role[1]++;
      role_seq[0]=player_role[0];
      while(player_role[0]==player_role[1])
      {
        player_role[1]=rand()%5;
        player_role[1]++;
      }
      role_seq[1]=player_role[1];
      printf("\nComputer Agent 1's Role is %s\n",role(player_role[1]));
      player_role[2]=rand()%5;
      player_role[2]++;
      while((player_role[1]==player_role[2])||(player_role[0]==player_role[2]))
      {
        player_role[2]=rand()%5;
        player_role[2]++;
      }
      role_seq[2]=player_role[2];
      printf("\nComputer Agent 2's Role is %s\n",role(player_role[2]));//
      player_role[3]=rand()%5;
      player_role[3]++;
      while((player_role[0]==player_role[3])||(player_role[1]==player_role[3])||(player_role[2]==player_role[3]))
      {
        player_role[3]=rand()%5;
        player_role[3]++;
      }
      role_seq[3]=player_role[3];
      printf("\nComputer Agent 3's Role is %s\n",role(player_role[3]));
    }

    for(int ii=0;ii<4;ii++)
    {
      if(role_seq[ii]==1)//----------builder
      {
        int building[29]={0};
        for(int i=0;i<4;i++)
        {
          for(int j=0;j<f_u_card_num[i];j++) 
          {
            if(card[f_u_card_seq[i][j]]==7) building[7]=1;
            if(card[f_u_card_seq[i][j]]==8) building[8]=1;
            if(card[f_u_card_seq[i][j]]==9) building[9]=1;
            if(card[f_u_card_seq[i][j]]==10) building[10]=1;
            if(card[f_u_card_seq[i][j]]==11) building[11]=1;
            if(card[f_u_card_seq[i][j]]==12) building[12]=1;
          }
        }
        size_t n=4;
      // sizeof(&player_role)/sizeof(player_role[0]);
        int action_result[4]={0};
        
       
        printf("\nEnter the building number from face-down card number which you want to "b_yellow"build"white"(0 for No): ");
        scanf("%d",&action_result[0]);
        action_result[0]--;
        for(size_t i=1;i<n;i++)
        {
            srand(time(0));
            action_result[i]=rand()%f_d_card_num[i];
        }
        
        for(int i=0;i<4;i++)
        {
          if(action_result[i]==-1) i++;
          f_u_card_num[i]++;
          // printf("\ntest:%d\n",f_u_card_num[i]);
          f_u_card_seq[i][f_u_card_num[i]-1]=f_d_card_seq[i][action_result[i]];
          // f_d_card_seq[i][action_result[i]]=0;
          int tmp=0,tmp2=0,tmp3=0;
          tmp=f_d_card_num[i];
          if(player_role[i]==role_seq[ii]) f_d_card_num[i]++;
          if(building[7]==1) f_d_card_num[i]++;
          f_d_card_num[i]-=fee[card[f_d_card_seq[i][action_result[i]]]];
          if((building[8]==1)&&(f_d_card_num[i]<=1)) f_d_card_num[i]++;
          if((building[11]==1)&&(card[f_d_card_seq[i][action_result[i]]]>=5)) 
          {
            tmp2=take_a_card(card_take_away);
            card_take_away[tmp2]=(-1);
            tmp3=f_d_card_num[i];
            f_d_card_num[i]++;
            f_d_card_seq[i][tmp3]=tmp2;
          }
          if((building[12]==1)&&(card[f_d_card_seq[i][action_result[i]]]>=5)) f_d_card_num[i]++;
          // printf("test:%d %d\n",action_result[i],fee[card[f_d_card_seq[i][action_result[i]]]]);
    //--------價格ok怪怪的fee[card[f_d_card_seq[i][j]]]
          for(int j=action_result[i];j<=tmp-1;j++)
          {
            f_d_card_seq[i][j]=f_d_card_seq[i][j+1];
          }
          if(i==0) printf("\nYour face-up cards : ");
          else printf("\n\nComputer Agent %d's face-up cards : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
            printf("(%d)"red"%s"white,j+1,card_name[card[f_u_card_seq[i][j]]]);
            if(j!=f_u_card_num[i]-1) printf(", ");
          }
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
          if (i==0) printf("\nYour money : %d\n",f_d_card_num[i]);
          else printf("\nComputer Agent %d's money : %d\n",i,f_d_card_num[i]);
        }
      }
      else if(role_seq[ii]==2)//----------producer
      {
        
        int action_result[4]={0};
            printf("\nEnter the "yellow"production building"white" number from face-up card number which you want to "magenta"produce: "white);
            scanf("%d",&action_result[0]);
            action_result[0]--;
        for(size_t i=1;i<4;i++)
        {
            srand(time(0));
            action_result[i]=rand()%f_u_card_num[i];
            if(card[f_u_card_seq[i][action_result[i]]]>=5) action_result[i]=-1;//改過
        }    
        for(int i=0;i<4;i++)//注意
        {
          if(action_result[i]==-1) i++;
          if(action_result[i]>f_u_card_num[i]) break;
          for(int j=0;j<2;j++)
          {
            // printf(red"test\n"white);
            int tmp=0;
            // printf(red"\ntest: %d\n"white,action_result[i]);
            goods[i][action_result[i]]++;
            // printf(red"\ntest: %d\n"white,goods[i][action_result[1]]);
            tmp=take_a_card(card_take_away);
            card_take_away[tmp]=(-1);
            if(player_role[i]!=role_seq[ii]) break;//改過
          }
        }
        for(int i=0;i<4;i++)
        {
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);//f_u_card_seq[i][j]
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
        }
      }
      else if(role_seq[ii]==3)//----------trader
      {
        int n=0;
        int tile[5][5]={0};
        tile[0][0]=tile[0][1]=tile[0][2]=tile[1][0]=tile[1][1]=tile[2][0]=tile[2][1]=tile[3][0]=tile[4][0]=1;
        tile[0][3]=tile[0][4]=tile[1][2]=tile[1][3]=tile[1][4]=tile[2][2]=tile[2][3]=tile[3][1]=tile[3][2]=tile[3][3]=tile[4][1]=tile[4][2]=2;
        tile[2][4]=tile[3][4]=tile[4][3]=tile[4][4]=3;
        srand(time(0));
        n=rand()%5;
        printf("\nProduction Building : (1) Indigo plant, (2) Sugar mill, (3) Tobacco storage, (4) Coffee roaster, (5) Silver smelter\n");
        printf("Price (Trading House Tile) : ");
        for(int i=0;i<5;i++)
        {
          printf("(%d) "green"%d"white,i+1,tile[n][i]);
          if(i!=4) printf(", ");
          else printf("\n");
        }
        // printf(red"IIIIItest\n"white);
        for(int i=0;i<4;i++)
        {
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
        }
        //
        for(int j=0;j<2;j++)
        {
          int action_result[3]={0};
          printf("\nEnter the "yellow"production building"white" number from face-up card number which you want to "green"trade "white"(0 for No): ");
          scanf("%d",&action_result[0]);
          action_result[0]--;
          if(action_result[0]==-1) break;
          // printf(red"test: \n"white);
          for(size_t i=1;i<4;i++)
          {
              srand(time(0));
              action_result[i]=rand()%f_u_card_num[i];
              if((card[f_d_card_seq[i][action_result[i]]]>=5)||goods[i][action_result[i]]<=0) action_result[i]=-1;//改過
          }
          for(int i=0;i<4;i++)
          {
            if(action_result[0]==-1) i++;//改過
            // if(card[f_d_card_seq[i][action_result[i]]]>=5) break;
            int tmp=0,tmp2=0;
            goods[i][action_result[i]]--;
            // printf(red"test: \n"white);
            tmp2=f_d_card_num[i];
            f_d_card_num[i]+=tile[n][card[f_u_card_seq[i][action_result[i]]]];//新加ok
            // printf(red"test: %d\n"white,card[f_u_card_seq[i][action_result[i]]]);
            // fee[card[f_d_card_seq[i][j]]]
            for(int j=0;j<tile[n][card[f_u_card_seq[i][action_result[i]]]];j++)//新加
            {
              tmp=take_a_card(card_take_away);
              card_take_away[tmp]=(-1);
              f_d_card_seq[i][tmp2]=tmp;//新加
              tmp2++;
            }
          }
          if(player_role[j]!=role_seq[ii]) break;
        }
        
        for(int i=0;i<4;i++)
        {  
          if(i==0) printf("\nYour face-up cards [goods] : ");
          else printf("\n\nComputer Agent %d's face-up cards [goods] : ",i);
          for(int j=0;j<f_u_card_num[i];j++)
          {
              printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_u_card_seq[i][j]]],goods[i][j]);
              if(j!=(f_u_card_num[i]-1)) printf(", ");
          }
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
          if (i==0) printf("\nYour money : %d\n",f_d_card_num[i]);
          else printf("\nComputer Agent %d's money : %d\n",i,f_d_card_num[i]);

        } 
      }
      else if(role_seq[ii]==4)//----------councilor
      {
        int action_result[4]={0};
        int tmp[5]={0};
        for(int i=0;i<1;i++)
        {
          // printf(red"\ntest: %d %d\n"white,player_role[ii],role_seq[ii]);
          if(player_role[0]==role_seq[ii])
          {
            for(int i=0;i<5;i++)
            {
              tmp[i]=take_a_card(card_take_away);
              card_take_away[tmp[i]]=(-1);
            }
            printf("\n");
            for(int i=0;i<5;i++)
            {
              printf("(%d) "blue"%s"white,i+1,card_name[card[tmp[i]]]);
              if(i!=1) printf(", ");
            }
              printf("\nEnter the card which you want to keep : ");
              scanf("%d",&action_result[0]);
              action_result[0]--;
          }
          else
          {
            // int tmp[2]={0};
            for(int i=0;i<2;i++)
            {
              tmp[i]=take_a_card(card_take_away);
              card_take_away[tmp[i]]=(-1);
            }
            printf("\n");
            for(int i=0;i<2;i++)
            {
              printf("(%d) "blue"%s"white,i+1,card_name[card[tmp[i]]]);
              if(i!=1) printf(", ");
            }
              printf("\nEnter the card which you want to keep : ");
              scanf("%d",&action_result[0]);
              action_result[0]--;
          }
        }
        for(size_t i=1;i<4;i++)
        {
            srand(time(0));
            action_result[i]=rand()%2;
            // if(card[f_d_card_seq[i][action_result[i]]]>=5) i--;  
        }
        for(int i=0;i<4;i++)
        {
          int tmp2=0;
          tmp2=f_d_card_num[i];
          f_d_card_num[i]++;
          // // fee[card[f_d_card_seq[i][j]]]
          
          f_d_card_seq[i][tmp2]=tmp[action_result[i]];
          // printf(red"\n%d\n"white,tmp[action_result[i]]);
          // card_name[card[tmp[i]]]
          // }
        
          if(i==0) printf("\nYour face-down cards [fee] : ");
          // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
          if(i==0)
          {
            for(int j=0;j<f_d_card_num[i];j++)
            {
                printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                if(j!=(f_d_card_num[i]-1)) printf(", ");
            }
          }
        }
      }
      else if(role_seq[ii]==5)//----------prospector
      {
        int tmp=0;
        for(int i=0;i<4;i++)
        {
          if(player_role[i]==role_seq[ii])//改過
          {
            tmp=take_a_card(card_take_away);
            card_take_away[tmp]=(-1);
            int tmp2=0;
            tmp2=f_d_card_num[i];
            f_d_card_num[i]++;
            f_d_card_seq[i][tmp2]=tmp;
            if(i==0) printf("\nYour face-down cards [fee] : ");
            // else printf("\n\nComputer Agent %d's face-down cards [fee] : ",i);
            if(i==0)
            {
              for(int j=0;j<f_d_card_num[i];j++)
              {
                  printf("(%d)"red"%s [%d]"white,j+1,card_name[card[f_d_card_seq[i][j]]],fee[card[f_d_card_seq[i][j]]]);
                  if(j!=(f_d_card_num[i]-1)) printf(", ");
              }
            }
          }
        }
      }
    }
    gov++;
    if(gov>=4) gov=0;
    for(int k=0;k<4;k++)
    {
      if(f_u_card_seq[k][11]!=0) 
      {
        stop=1;
        break;
      }
    }
    if(stop==1) break;
  }
  card_score(score);
  for(int n=0;n<4;n++)
  {
    for(int p=0,q=0;p<f_u_card_num[n];p++)
    {
      for(int q=0;q<29;q++)
      {
        if((card[f_d_card_seq[n][p]]==q)&&(q<25)) total[n]+=score[q];
        if((card[f_d_card_seq[n][p]]==q)&&(q==27)) total[n]+=score[q];
        if((card[f_d_card_seq[n][p]]==q)&&(q==28))
        {
          double tmp4=0.0;
          tmp4=total[n];
          tmp4*=1.25;
          total[n]=(int)tmp4;
        }
      }
    }
    if(n==0) printf("\n\nYour "yellow" total score"white": %d\n",total[n]);
    else printf("Computer Agent %d's"yellow" total score"white": %d\n",n,total[n]);
  }
  int max=0;
  for(int n=0;n<4;n++)
  {
    if(total[n]>=total[max]) max=n;
  }
  win(max);
}

int main()
{
  printf("\n         SUANJUAN         \n\n");
  printf("Welcome to San Juan.\n");
  printf("Prospector or governor - councilor or builder?\n");
  printf("Which roles will you play in the new world?\n");
  printf("You have only one goal: acquire the most wealth and fame!\n");
  printf("Who will own the most fruitful production facilities?\n");
  printf("Who will build the most important buildings?\n");
  printf("Who earns the most victory points...is the winner!\n\n");
  
  int c1=0,c2=0,c3=0,c4=0;
  c1=-1,c2=-1,c4=-1;
  while(error(c1,1,2)!=3)
  {
    printf(red" ___           "blue"___\n");
    printf(red"| 1 | PLAY    "blue"| 2 | QUIT\n");
    printf(red"|___|         "blue"|___|\n\n");
    printf(white);
    printf("Please enter your choice.(1 or 2): ");
    scanf("%d",&c1);
  }
  if(c1==2)
  {
    printf(red"\nYou pressed the quit button!\n"white);
    printf("Are you sure you want to end this level?\n");
    printf("(1) Keep Playing    (2)Quit\n");
    scanf("%d",&c3);
    if(c3==2)
    {
      printf(cyan"\n\nBYE!\n"white);
      return 0;
    } 
    else c1=1;
  }
  printf("\n\n"b_yellow"==============PREPARATION==============\n\n"white);
  while(error(c2,2,4)!=3)
  {
    printf(cyan" ___     "magenta"___     "green"___\n");
    printf(cyan"| 2 |   "magenta"| 3 |   "green"| 4 |   \n");
    printf(cyan"|___|   "magenta"|___|   "green"|___|  \n\n");
    printf(white);
    printf("Players (2-4): ");
    scanf("%d",&c2);
  }
  // while(error(c4,1,3)!=3)
  // {
  //   printf(blue" ___        "red"___          "yellow"___\n");
  //   printf(blue"| 1 | EASY "red"| 2 | MEDIUM "yellow"| 3 | HARD\n");
  //   printf(blue"|___|      "red"|___|        "yellow"|___|\n\n");
  //   printf(white);
  //   printf("Level: ");
  //   scanf("%d",&c4);
  // }
  printf("\n\n"b_yellow"=====================================\n\n"white);
  printf(b_yellow"  ■■■■■ ■■■■■   ■■    ■■■■■ ■■■■■\n");
  printf(b_yellow"  ■       ■    ■  ■   ■   ■   ■  \n");
  printf(b_yellow"  ■■■■■   ■   ■■■■■■  ■■■■■   ■  \n");
  printf(b_yellow"      ■   ■   ■    ■  ■  ■    ■  \n");
  printf(b_yellow"  ■■■■■   ■   ■    ■  ■   ■   ■  \n"white);
  printf("\n\n"b_yellow"=====================================\n\n\n"white);
  int card[110]={0};
  char card_name[29][30]={0};
  int fee[29]={0},score[29]={0};
  card_initial(card,card_name,fee);//好像不能這麼用
  if(c2==2) player2(card,card_name,fee,score);
  else if(c2==3) player3(card,card_name,fee,score);
  else if(c2==4) player4(card,card_name,fee,score);
  return 0;
}
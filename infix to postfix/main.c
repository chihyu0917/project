#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

void error(){
  printf("錯誤!輸入格式錯誤\n");
}
int choose(){
  int c=0;
  printf("-------選單--------\n");
	printf("請選一個選項: \n");
  printf("(1) 輸入一個正整數n，隨機產生n張牌加到資料中，表示發給這個人n張牌\n");
  printf("(2) 選擇某一花色，依發牌拿到的順序一一列出\n");
  printf("(3) 選擇某一花色，依發牌拿到的相反順序一一列出\n");
  printf("(4) 選擇某一花色，依牌色大小由小而大一一列出\n");
  printf("(5) 刪除一張牌 (根據一個輸入牌的花色及大小，從該花色中找到比該牌大的牌中最小的一張牌輸出並刪除，若該花色不存在比該牌數字大的牌，就輸出該花色數字最小的牌。若不存在該花色的牌，則需輸出相關訊息。)\n");
  printf("(6) 輸入並記錄另一個人的牌 (輸入完請在下次選單輸入1到5來進行第二個人的功能)\n");
  printf("(7) 額外功能的遊戲 (必須發完兩人的牌才可啟用)\n");
  printf("(8) 結束程式\n");
  printf("你的選擇為");
	scanf("%d",&c);
  if(c<1||c>8) error();
  printf("------------------\n");
	return c;
}
int take_a_card(int take[]){
  int take_card=0;
  
  srand(time(NULL));
  take_card=rand()%52;
  while(take[take_card]==1){
    srand(time(NULL));
    take_card=rand()%52;
  }
  take[take_card]++;
  return take_card;
}
int deter_suit(int n){
  if(n/13==0) return 0;
  else if(n/13==1) return 1;
  else if(n/13==2) return 2;
  else if(n/13==3) return 3;
}
int deter_hand(int n){
  n++;
  return n%13;
}
int input_card_suit(char *s){
  char in_suit=0;
  in_suit=s[0];
  // printf("%c\n",in_suit);
  if(in_suit=='C') return 0;
  else if(in_suit=='D') return 1;
  else if(in_suit=='H') return 2;
  else if(in_suit=='S') return 3;
}
int input_card_hand(char *s){
  int in_hand=0;
  if(s[1]=='A') in_hand=1;
  else in_hand=atoi(&s[1]);
  // printf("%d\n",in_hand);
  return in_hand;
}
void print_card(int n){
  if(n/13==0) printf("C");
  else if(n/13==1) printf("D");
  else if(n/13==2) printf("H");
  else if(n/13==3) printf("S");
  n++;
  if(n%13>1) printf("%d\n",n%13);
  else if(n%13==1) printf("A\n");
  else if(n%13==0) printf("13\n");
}
void intro(){
  printf("花色 : ");
  printf("黑桃Spades，紅心Heart，方塊Diamond，梅花Club\n");
  printf("各花色有13張 : ");
  printf("A,2,3,4,5,6,7,8,9,10,11,12,13\n");
  printf("預設開始為第一個人，若要輸入第二人，請在選單中輸入1發完牌再輸入6切換到第二人\n");
  printf("\n");
}
void end(){
  printf("-----已終止程式-----\n");
}

int main(){
  intro();
  int c1=0,c2=0;
  int per=0;
  int take[52]={0};
  int seq[2][52]={0};
  int num[2]={0};
  // int S_num=0,H_num=0,D_num=0,C_num=0;
  int suit_nums[2][4]={0};
  char str[5]={0};
  struct node* card[2][4][14]={0};
  struct node* min_to_max[2][14]={0};
  for(int i=0;i<2;i++){
    for(int j=0;j<14;j++){
    min_to_max[i][j]=(struct node*)malloc(sizeof(struct node));
    }
  }
  struct node* temp=0;
  temp=(struct node*)malloc(sizeof(struct node));
  for(int i=0;i<2;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<14;k++){
        card[i][j][k]=(struct node*)malloc(sizeof(struct node));
      }
    }
  }
  int stop=0,stop2=0;
  while(stop!=1){
    int ch=choose();
    
    if(ch==1){
      c1=1;
      printf("(1) 請輸入一個正整數(1-52) : ");
      scanf("%d",&num[per]);
      if((num[per]<=0)||(num[per]>52)) error();
      else{
        for(int i=0;i<num[per];i++){
          seq[per][i]=take_a_card(take);
          // printf("%d\n",seq[per][i]);
        }
        for(int i=0,j1=0,j2=0,j3=0,j4=0;i<num[per];i++){
          if(deter_suit(seq[per][i])==0){
            card[per][0][j1]->data=seq[per][i];
            card[per][0][j1]->next=card[per][0][j1+1];
            j1++;
            suit_nums[per][0]=j1;
          }
          else if(deter_suit(seq[per][i])==1){
            card[per][1][j2]->data=seq[per][i];
            card[per][1][j2]->next=card[per][1][j2+1];
            j2++;
            suit_nums[per][1]=j2;
          }
          else if(deter_suit(seq[per][i])==2){
            card[per][2][j3]->data=seq[per][i];
            card[per][2][j3]->next=card[per][2][j3+1];
            j3++;
            suit_nums[per][2]=j3;
          }
          else if(deter_suit(seq[per][i])==3){
            card[per][3][j4]->data=seq[per][i];
            card[per][3][j4]->next=card[per][3][j4+1];
            j4++;
            suit_nums[per][3]=j4;
          }
        }
      }
    }
    else if((ch==2)&&(c1==1)){
      int suit=0;
      printf("(2) 請選擇一花色 (黑桃S=4，紅心H=3，方塊D=2，梅花C=1，請輸入數字) : ");
      scanf("%d",&suit);
      if((suit<1)||(suit>4)) error();
      else{
        printf("顯示依發牌拿到的順序 : \n");
        for(int i=0;i<num[per];i++){
          // print_card(seq[per][i]);
        }
        // printf("---\n");
        for(temp=card[per][suit-1][0];temp->next!=NULL;temp=temp->next){
          print_card(temp->data);
        }
      }
      
    }
    else if(ch==2) printf("錯誤!請先選擇1並輸入n張牌\n");
    else if((ch==3)&&(c1==1)){
      int suit=0;
      printf("(3) 請選擇一花色 (黑桃S=4，紅心H=3，方塊D=2，梅花C=1，請輸入數字) : ");
      scanf("%d",&suit);
      if((suit<1)||(suit>4)) error();
      else{
        printf("顯示依發牌拿到的相反順序 : \n");
        for(int i=num[per]-1;i>=0;i--){
          // print_card(seq[per][i]);
        }
        // printf("---\n");
        if(suit==1){
          for(int i=suit_nums[per][0]-1;i>=0;i--){
            print_card(card[per][suit-1][i]->data);
          }
        }
        else if(suit==2){
          for(int i=suit_nums[per][1]-1;i>=0;i--){
            print_card(card[per][suit-1][i]->data);
          }
        }
        else if(suit==3){
          for(int i=suit_nums[per][2]-1;i>=0;i--){
            print_card(card[per][suit-1][i]->data);
          }
        }
        else if(suit==4){
          for(int i=suit_nums[per][3]-1;i>=0;i--){
            print_card(card[per][suit-1][i]->data);
          }
        }
      }
    }
    else if(ch==3) printf("錯誤!請先選擇1並輸入n張牌\n");
    else if((ch==4)&&(c1==1)){
      int suit=0;
      printf("(4) 請選擇一花色 (黑桃S=4，紅心H=3，方塊D=2，梅花C=1，請輸入數字) : ");
      scanf("%d",&suit);
      if((suit<1)||(suit>4)) error();
      else{
        printf("顯示依牌色大小由小而大 : \n");
        for(int i=0;i<suit_nums[per][suit-1];i++){
          min_to_max[per][i]->data=card[per][suit-1][i]->data;
          min_to_max[per][i]->next=min_to_max[per][i+1];
          if(i==suit_nums[per][suit-1]-1) min_to_max[per][i]->next->next=NULL;
        }
        for(int i=0;i<suit_nums[per][suit-1];i++){
          for(int j=i;j<suit_nums[per][suit-1];j++){//
            int k=0,m=0,n=0;
            k=min_to_max[per][i]->data;
            m=min_to_max[per][j]->data;
            if(k%13==0) k+=13;
            if(m%13==0) m+=13;
            if(k>m){
              n=k;
              k=m;
              m=n;
            }
            if(k%13==0) k-=13;
            if(m%13==0) m-=13;
            min_to_max[per][i]->data=k;
            min_to_max[per][j]->data=m;
          }
        }
        for(int i=0;i<suit_nums[per][suit-1];i++){
          print_card(min_to_max[per][i]->data);
        }
      }
    }
    else if(ch==4) printf("錯誤!請先選擇1並輸入n張牌\n");
    else if((ch==5)&&(c1==1)){
      int del=0;
      printf("(5) 請輸入一張牌的花色及大小，例如: H5為紅心5，SA為黑桃A\n");
      while(getchar()!='\n') continue; //scanf和fgets連用
      fgets(str,5,stdin);
      int s=0,h=0;
      s=input_card_suit(str);
      h=input_card_hand(str)-1;
      if(suit_nums[per][s]<=0) printf("無該花色的牌\n");
      else{
        for(int i=0;i<suit_nums[per][s];i++){
          min_to_max[per][i]->data=card[per][s][i]->data;
          min_to_max[per][i]->next=min_to_max[per][i+1];
          if(i==suit_nums[per][s]-1) min_to_max[per][i]->next->next=NULL;
        }
        for(int i=0;i<suit_nums[per][s];i++){
          for(int j=i;j<suit_nums[per][s];j++){//
            int k=0,m=0,n=0;
            k=min_to_max[per][i]->data;
            m=min_to_max[per][j]->data;
            if(k%13==0) k+=13;
            if(m%13==0) m+=13;
            if(k>m){
              n=k;
              k=m;
              m=n;
            }
            if(k%13==0) k-=13;
            if(m%13==0) m-=13;
            min_to_max[per][i]->data=k;
            min_to_max[per][j]->data=m;
          }
        }
        printf("輸出的牌為");
        for(int i=0;i<suit_nums[per][s];i++){
          if(h==0) h+=13;
          if((min_to_max[per][i]->data>(s*13+h))&&(min_to_max[per][i]->data%13!=0)){
            print_card(min_to_max[per][i]->data);
            del=i;
            break;
          }
          else if(min_to_max[per][i]->data%13==0){
            print_card(min_to_max[per][i]->data);
            del=i;
            break;
          }
          if(i==suit_nums[per][s]-1){
            print_card(min_to_max[per][0]->data);
            del=0;
          } 
        }
        for(int i=0;i<suit_nums[per][s];i++){
          if(i>=del){
            min_to_max[per][i]->data=min_to_max[per][i+1]->data;
            min_to_max[per][i]->next=min_to_max[per][i+1];
          }
          // else if(i>del){
          //   min_to_max[i]->next=min_to_max[i+1];
          // }
        }
        suit_nums[per][s]--;
        // printf("%d\n",suit_nums[per][s]);
        for(int i=0;i<suit_nums[per][s];i++){
          // print_card(min_to_max[per][i]->data);
        }
        for(int i=0;i<suit_nums[per][s];i++){
          card[per][s][i]->data=min_to_max[per][i]->data;
        }
      }
    }
    else if(ch==5) printf("錯誤!請先選擇1並輸入n張牌\n");
    else if((ch==6)&&(c2!=6)&&(c1==1)){
      printf("\n第二個人\n");
      per++;
      c2=6;
      c1=0;
      //++
    }
    else if(ch==6) printf("錯誤!請先選擇1或是請勿重複選擇6\n");
    else if((ch==7)&&(c2==6)&&(c1==1)){
      while(getchar()!='\n') continue; //scanf和fgets連用
      int del=0;
      int p1=0,s1=0,sh1=0,h1=0;
      printf("啟用額外功能的遊戲\n");
      printf("規則 : \n");
      printf("輸入完兩個人的牌色後，由第一個人開始任意刪除一張牌(表示出牌)，接下來輪流根據該牌色，從所屬花色中找到比該牌大的牌中數字最小的一張牌輸出並刪除；若所屬花色中沒有比該牌大的牌，就取該花色中最小的一張牌輸出並刪除。若輪到者沒有該花色則必須抽一張牌(輸入一張新牌)，再由另一位重新出牌。最後先出完牌者為贏家，請顯示過程中兩者的牌面資料變化。\n");
      // srand(time(NULL));
      // s1=rand()%4;
      printf("---\n");
      for(per=0;per<2;per++){
          if(per==0) printf("第一人的所有牌 : \n");
          else if(per==1) printf("第二人的所有牌 : \n");
          for(int i=0;i<suit_nums[per][0];i++){
            print_card(card[per][0][i]->data);
          }
          for(int i=0;i<suit_nums[per][1];i++){
            print_card(card[per][1][i]->data);
          }
          for(int i=0;i<suit_nums[per][2];i++){
            print_card(card[per][2][i]->data);
          }
          for(int i=0;i<suit_nums[per][3];i++){
            print_card(card[per][3][i]->data);
          }
          printf("---\n");
      }
      per=1;
      p1=1;
      while(stop2!=1){
        if(per==1) per=0;
        else if(per==0) per=1;
        if(per==0) printf("第一人任意出牌 (刪除一張牌) : \n");
        else if(per==1) printf("第二人任意出牌 (刪除一張牌) : \n");
        if(p1==1){
          printf("請輸入一張牌的花色及大小，例如: H5為紅心5，SA為黑桃A\n");
          fgets(str,5,stdin);
          s1=input_card_suit(str);
          h1=input_card_hand(str)-1;
        }

        if((suit_nums[per][0]<=0)&&(suit_nums[per][1]<=0)&&(suit_nums[per][2]<=0)&&(suit_nums[per][3]<=0)){
          if(per==0) printf("第一人為");
          else if(per==1) printf("第二人為");
          printf("贏家\n");
          printf("\n遊戲結束 (請再按8結束程式)\n");
          stop2=1;
        }
        else if(suit_nums[per][s1]<=0){
          int new_card=0,s2=0;
          printf("無該花色的牌\n");
          new_card=take_a_card(take);
          printf("抽一張牌 : ");
          print_card(new_card);
          s2=deter_suit(new_card);
          card[per][s2][suit_nums[per][s2]]->data=new_card;
          card[per][s2][suit_nums[per][s2]]->next=card[per][s2][suit_nums[per][s2]+1];
          suit_nums[per][s2]++;
          // printf("---\n");
          printf("現有的牌 : \n");
          for(int i=0;i<suit_nums[per][0];i++){
            print_card(card[per][0][i]->data);
          }
          for(int i=0;i<suit_nums[per][1];i++){
            print_card(card[per][1][i]->data);
          }
          for(int i=0;i<suit_nums[per][2];i++){
            print_card(card[per][2][i]->data);
          }
          for(int i=0;i<suit_nums[per][3];i++){
            print_card(card[per][3][i]->data);
          }
          if(per==1) per=0;
          else if(per==0) per=1;
          if((suit_nums[per][0]<=0)&&(suit_nums[per][1]<=0)&&(suit_nums[per][2]<=0)&&(suit_nums[per][3]<=0)){
            p1=0;
          }
          else p1=1;
          if(per==1) per=0;
          else if(per==0) per=1;
          
          // srand(time(NULL));
          // s1=rand()%4;
        } 
        else{
        
        //   for(int l=suit_nums[per][s1]-1;l>=0;l--){
            // sh1=rand()%suit_nums[per][s1];
            // h1=deter_hand(card[per][s1][sh1]->data)-1;
          for(int i=0;i<suit_nums[per][s1];i++){
            min_to_max[per][i]->data=card[per][s1][i]->data;
            min_to_max[per][i]->next=min_to_max[per][i+1];
            if(i==suit_nums[per][s1]-1) min_to_max[per][i]->next->next=NULL;
          }
          for(int i=0;i<suit_nums[per][s1];i++){
            for(int j=i;j<suit_nums[per][s1];j++){//
                int k=0,m=0,n=0;
                k=min_to_max[per][i]->data;
                m=min_to_max[per][j]->data;
                if(k%13==0) k+=13;
                if(m%13==0) m+=13;
                if(k>m){
                  n=k;
                  k=m;
                  m=n;
                }
                if(k%13==0) k-=13;
                if(m%13==0) m-=13;
                min_to_max[per][i]->data=k;
                min_to_max[per][j]->data=m;
            }
          }
          printf("輸出的牌為");
          for(int i=0;i<suit_nums[per][s1];i++){
              if(h1==0) h1+=13;
              if((min_to_max[per][i]->data>(s1*13+h1))&&(min_to_max[per][i]->data%13!=0)){
                print_card(min_to_max[per][i]->data);
                del=i;
                break;
              }
              else if(min_to_max[per][i]->data%13==0){
                print_card(min_to_max[per][i]->data);
                del=i;
                break;
              }
              if(i==suit_nums[per][s1]-1){
                print_card(min_to_max[per][0]->data);
                del=0;
              } 
          }
          for(int i=0;i<suit_nums[per][s1];i++){
              if(i>=del){
                min_to_max[per][i]->data=min_to_max[per][i+1]->data;
                min_to_max[per][i]->next=min_to_max[per][i+1];
              }
          }
          suit_nums[per][s1]--;
          // printf("%d\n",suit_nums[per][s1]);
          for(int i=0;i<suit_nums[per][s1];i++){
            card[per][s1][i]->data=min_to_max[per][i]->data;
          }
          // printf("---\n");
          printf("現有的牌 : \n");
          for(int i=0;i<suit_nums[per][0];i++){
            print_card(card[per][0][i]->data);
          }
          for(int i=0;i<suit_nums[per][1];i++){
            print_card(card[per][1][i]->data);
          }
          for(int i=0;i<suit_nums[per][2];i++){
            print_card(card[per][2][i]->data);
          }
          for(int i=0;i<suit_nums[per][3];i++){
            print_card(card[per][3][i]->data);
          }
          p1=0;
        //     for(int i=0;i<suit_nums[per][s1];i++){
        //       print_card(min_to_max[per][i]->data);
        //     }
        //     for(int i=0;i<suit_nums[per][s1];i++){
        //       card[per][s1][i]->data=min_to_max[per][i]->data;
        //     }
        //   }
        //   if(suit_nums[per][s1]<=0){
        //     int new_card=0,s2=0;
        //     printf("無該花色的牌\n");
        //     new_card=take_a_card(take);
        //     s2=deter_suit(new_card);
        //     card[per][s2][suit_nums[per][s2]]->data=new_card;
        //     card[per][s2][suit_nums[per][s2]]->next=card[per][s2][suit_nums[per][s2]+1];
        //     suit_nums[per][s2]++;
        //   } 
          
        }
        // per++;
        // stop2=1;
        printf("---\n");
      }
    }
    else if(ch==7) printf("錯誤!請輸入完兩人的牌\n");
    else if(ch==8) stop=1,end();
  }
  return 0;
}

// This project is an experimental project developed by Vahid_Sheigani(Mr.)
// Dated is 2014.09.13

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int x[4][4];
bool b[4][4];

int main(int argc, const char *argv[])
{
  char a;
  int x1,y1;
  int sw,rr,cc,row,col,yy,z,j,i,m,n;
  struct timeval now1;
  struct timeval now2;

  for (m = 0; m < 4; m++) {
    for (n = 0; n < 4; n++) {
      x[m][n]=0;
    }
  }
  
  x[3][2]=2;
  x[1][2]=2;
  
    int random_1(){
        gettimeofday(&now1, NULL);
        //time = tp.tv_sec;
        //tm *t = localtime(&curtime);
        int randomnumber;
        // srand(now.tv_usec/1000);
        randomnumber = ((now1.tv_usec/1000)%4)+1;
        return randomnumber;
        }

   int random_2(){
         gettimeofday(&now2,NULL);
         int randomnumber_2;
         randomnumber_2= ((now2.tv_usec/100)%4)+1;
         return randomnumber_2;
   }

   system("clear");
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if(x[i][j] != 0){
      printf("|%-5d",x[i][j]);
      }
      else{
      printf("|");
      for (z = 0; z < 5; z++){
      printf(" ");
      }
      }
      }
    puts("");
  }

  int moveup(){
  int s2,s1,s3;
  for (s1 = 0; s1 < 4; s1++) {
    for (s2 = 3; s2 > 0; s2--) {
      for (s3 = 1; s3 < 4; s3++){
      if (x[s2][s1]==x[s2-s3][s1] && x[s2][s1] != 0 && x[s2-s3][s1]!=0) {
        x[s2-s3][s1]+=x[s2][s1];
        x[s2][s1]=0;
        b[s2-s3][s1]=true;
        b[s2][s1]=true;
      }
      }
    }
  }
  
  return 0;
  }


  int refresh(){ 
  int s2,s1;
  for (s1 = 0; s1 < 4; s1++) {
    for (s2 = 0; s2 <4 ; s2++) {
      if(x[s2][s1]!=0){
       if (b[s2][s1]==true) {
       y1=((s2));
       x1=((s1)*5);
       printf("\033[%d;%dH%-d",y1,x1,x[s2][s1]);
       b[s2][s1]=false;
      }
     }
    }
    }
    return 0;
  }

      while(1){
      a=getchar();
      
      switch(a){
      case 65:
      moveup();
      row=random_1();
      col=random_2();
      x[row][col]=2;
      b[row][col]=true;
      refresh();
      break;
    
      case 66:
      printf("DOWN");
      break;
      case 67:
      printf("RIGHT");
      break;
      case 68:
      printf("LEFT");
      break;
      
    }
    if (a==13)
    break;
  }
  
  return 0;

  }

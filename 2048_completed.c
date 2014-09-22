// This project is an experimental project developed by Vahid_Sheigani(Mr.)
// Dated is 2014.09.13

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

  // Array for storing numbers in it
  int nums[4][4];
  // Array for storing nums array changes
  bool changed[4][4];
  
  char getkey;
  int row,col,z,j,i,m,n;
  struct timeval now1;
  struct timeval now2;

  // Function for generating random row number
    int random_1(){
        gettimeofday(&now1, NULL);
        int randomnumber;
        srand(now1.tv_usec);
        randomnumber = (rand()%4);
        return randomnumber;
        }

  // Function for generating random column number
   int random_2(){
         gettimeofday(&now2,NULL);
         int randomnumber_2;
         srand(now2.tv_usec);
         randomnumber_2 = (rand()%4);
         return randomnumber_2;
   }
   
  // Function for inserting a number in specific row and column
  int random_insert(){
     int counter;
  for (counter = 1; counter < 1000; counter++) {
      row=random_1();
      col=random_2();
      if(nums[row][col]==0){
      nums[row][col]=2;
      changed[row][col]=true;
      break;
      }
    }
    return 0;
  }



  // Function for moving all numbers to up and summing nearby equal numbers
  int moveupandsum(){
  // this variable count full cells between two numbers
  int between=0;
  int isdeal=-1;
  int ss1,ss2,ss3;
  int s4,s5,s2,s1,s3;
  for (s1 = 0; s1 < 4; s1++) {
    for (s2 = 3; s2 > 0; s2--) {
      if (isdeal==s2) {
        s2--;
        isdeal=-1;
      }
      if (s2==0) {
        break;
      }
      for (s3 = 1; s3 <= s2; s3++){
      for (s4 = s2-1; s4 > s2-s3; s4--) {
      if (nums[s4][s1]!=0) {
      between++;
      }
    }

  // this will sum two non zero numbers that there is no full cells between them
      if (between==0 && nums[s2][s1] != 0 && nums[s2-s3][s1]!=0 && nums[s2][s1]==nums[s2-s3][s1]) { 
        nums[s2-s3][s1]+=nums[s2][s1];
        nums[s2][s1]=0;
        changed[s2-s3][s1]=true;
        changed[s2][s1]=true;     
        isdeal=s2-s3;
    }
    }
    between=0;
    }
  }
    
  // this will shift all numbers to the uppest avaliable empty cells
  for (ss1 = 0; ss1 < 4; ss1++) {
    for (ss2 = 0; ss2 <=3 ; ss2++) {
      if (nums[ss2][ss1]!=0) {
      for (ss3 = 0; ss3 <= ss2-1; ss3++) {
        if (nums[ss3][ss1]==0) {
        nums[ss3][ss1]=nums[ss2][ss1];
        nums[ss2][ss1]=0;
        changed[ss3][ss1]=true;
        changed[ss2][ss1]=true;
        }
      }
      }
  }
  }

  return 0;
  }



  // Function for moving all numbers to the down and summing nearby equal numbers
  int movedownandsum(){
  // this variable count full cells between two numbers
  int between=0;
  int isdeal=-1;
  int ss1,ss2,ss3;
  int s4,s5,s2,s1,s3;
  for (s1 = 0; s1 < 4; s1++) {
    for (s2 = 0; s2 < 4; s2++) {
      if (isdeal==s2) {
        s2++;
        isdeal=-1;
      }
      if (s2==3) {
        break;
      }
      for (s3 = 1; s3 <= 3-s2; s3++){
      for (s4 = s2+1; s4 < s2+s3; s4++) {
      if (nums[s4][s1]!=0) {
      between++;
      }
    }


  // this will sum two non zero numbers that there is no full cells between them
      if (between==0 && nums[s2][s1] != 0 && nums[s2+s3][s1]!=0 && nums[s2][s1]==nums[s2+s3][s1]) { 
        nums[s2+s3][s1]+=nums[s2][s1];
        nums[s2][s1]=0;
        changed[s2+s3][s1]=true;
        changed[s2][s1]=true;     
        isdeal=s2+s3;
        }
    }
    between=0;
    }
  }
    
  // this will shift all numbers to the downest avaliable empty cells
  for (ss1 = 0; ss1 < 4; ss1++) {
    for (ss2 = 3; ss2 >= 0 ; ss2--) {
      if (nums[ss2][ss1]!=0) {
      for (ss3 = 3 ; ss3 >= ss2+1 ; ss3--) {
        if (nums[ss3][ss1]==0) {
        nums[ss3][ss1]=nums[ss2][ss1];
        nums[ss2][ss1]=0;
        changed[ss3][ss1]=true;
        changed[ss2][ss1]=true;
        }
      }
      }
  }
  }

  return 0;
  }


  // Function for moving all numbers to the right and summing nearby equal numbers
  int moverightandsum(){
  // this variable count full cells between two numbers
  int between=0;
  int isdeal=-1;
  int ss1,ss2,ss3;
  int s4,s5,s2,s1,s3;
  for (s2 = 0; s2 < 4; s2++) {
    for (s1 = 0; s1 < 4; s1++) {
      if (isdeal==s1) {
        s1++;
        isdeal=-1;
      }
      if (s1==3) {
        break;
      }
      for (s3 = 1; s3 <= 3-s1; s3++){
      for (s4 = s1+1; s4 < s1+s3; s4++) {
      if (nums[s2][s4]!=0) {
      between++;
      }
    }


  // this will sum two non zero numbers that there is no full cells between them
      if (between==0 && nums[s2][s1] != 0 && nums[s2][s1+s3]!=0 && nums[s2][s1]==nums[s2][s1+s3]) { 
        nums[s2][s1+s3]+=nums[s2][s1];
        nums[s2][s1]=0;
        changed[s2][s1+s3]=true;
        changed[s2][s1]=true;     
        isdeal=s1+s3;
        
        }
    }
    between=0;
    }
  }
    
  // this will shift all numbers to the rightest avaliable empty cells
  for (ss2 = 0; ss2 < 4; ss2++) {
    for (ss1 = 3; ss1 >= 0 ; ss1--) {
      if (nums[ss2][ss1]!=0) {
      for (ss3 = 3 ; ss3 >= ss1+1 ; ss3--) {
        if (nums[ss2][ss3]==0) {
        nums[ss2][ss3]=nums[ss2][ss1];
        nums[ss2][ss1]=0;
        changed[ss2][ss3]=true;
        changed[ss2][ss1]=true;
        }
      }
      }
  }
  }

  return 0;
}


  // Function for moving all numbers to the left and summing nearby equal numbers
  int moveleftandsum(){
  // this variable count full cells between two numbers
  int between=0;
  int isdeal=-1;
  int ss1,ss2,ss3;
  int s4,s5,s2,s1,s3;
  for (s2 = 0; s2 < 4; s2++) {
    for (s1 = 3; s1 > 0; s1--) {
      if (isdeal==s1) {
        s1--;
        isdeal=-1;
      }
      if (s1==0) {
        break;
      }
      for (s3 = 1; s3 <= s1; s3++){
      for (s4 = s1-1; s4 > s1-s3; s4--) {
      if (nums[s2][s4]!=0) {
      between++;
      }
    }


  // this will sum two non zero numbers that there is no full cells between them
      if (between==0 && nums[s2][s1] != 0 && nums[s2][s1-s3]!=0 && nums[s2][s1]==nums[s2][s1-s3]) { 
        nums[s2][s1-s3]+=nums[s2][s1];
        nums[s2][s1]=0;
        changed[s2][s1-s3]=true;
        changed[s2][s1]=true;     
        isdeal=s1-s3;
      }
    }
    between=0;
    }
  }
    
  // this will shift all numbers to the leftest avaliable empty cells
  for (ss2 = 0; ss2 < 4; ss2++) {
    for (ss1 = 0; ss1 <=3 ; ss1++) {
      if (nums[ss2][ss1]!=0) {
      for (ss3 = 0; ss3 <= ss1-1; ss3++) {
        if (nums[ss2][ss3]==0) {
        nums[ss2][ss3]=nums[ss2][ss1];
        nums[ss2][ss1]=0;
        changed[ss2][ss3]=true;
        changed[ss2][ss1]=true;
        }
      }
      }
  }
  }

  return 0;
  }

  // this function change application state to recieve arrow keys without buffering them and hitting enter key  
  void setBufferedInput(bool enable) {
    static bool enabled = true;
    static struct termios old;
    struct termios new;
    if (enable && !enabled) {
      tcsetattr(STDIN_FILENO,TCSANOW,&old);
      enabled = true;
    } else if (!enable && enabled) {
    tcgetattr(STDIN_FILENO,&new);
    old = new;
    new.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new);
    enabled = false;
    }
  }
  // below function print any changed number in nums array in specified loction
  int printchanges(){ 
  int ss2,ss1,ss3;
  int xposition;
  for (ss1 = 0; ss1 < 4; ss1++) {
    for (ss2 = 3; ss2 >= 0 ; ss2--) {
       if (changed[ss2][ss1]==true) {
       if (nums[ss2][ss1] != 0){
       xposition=((ss1)*5)+2;
       printf("\033[%d;%dH%-s",ss2+1,xposition,"    ");
       printf("\033[%d;%dH%-d",ss2+1,xposition,nums[ss2][ss1]);
      }
      else{   
       xposition=((ss1)*5)+2;
       printf("\033[%d;%dH%-s",ss2+1,xposition,"    ");
      }
      changed[ss2][ss1]=false;
     }
  }
  }
    return 0;
  }
  

  

int main(int argc, const char *argv[])
{
int ff;

   // Clearing terminal screen using system function
   system("clear");
  
  // filling nums and changed arrays witn zero and false values in the application start
  for (m = 0; m < 4; m++) {
    for (n = 0; n < 4; n++) {
      nums[m][n]=0;
      changed[m][n]=false;
    }
  }
  
  nums[3][2]=2;
  nums[1][2]=2;

  // printing game table with nums array number in application start
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if(nums[i][j] != 0){
      printf("|%-4d",nums[i][j]);
      }
      else{
      printf("|");
      for (z = 0; z < 4; z++){
      printf(" ");
      }
      }
      }
    puts("");
  }
  
      setBufferedInput(false);
      while(1){
      // getting arrow keys from user repeatedly 
      getkey=getchar(); 

      // check which arrow keys are pressed
      switch(getkey){

      // calling required functions when up key is pressed
      case 65:
      moveupandsum();
      random_insert();
      printchanges();
      break;
      
      // calling required functions when down key is pressed
      case 66:
      movedownandsum();
      random_insert();
      printchanges();
      break;

      // calling required functions when right key is preesed
      case 67:
      moverightandsum();
      random_insert();
      printchanges();
      break;

      // calling required functions when left key is pressed
      case 68:
      moveleftandsum();
      random_insert();
      printchanges();
      break;
      
    }
  }
  
  return 0;

  }

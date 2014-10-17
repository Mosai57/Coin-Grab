#include <stdio.h>
#include <stdlib.h>
#include <time.h>  /* for time() */

int gen_random_num(int coins);
void print_coins(int coins, int i);

int main(){
 // Seed the RNG for computer randomized selections
 srand(time(NULL));
 
 // Initialization Block
 int coins                   =  30;  /* Total coins used in the game */
 int psel                    =   0;
 int csel                    =   0;
 int i                       =   0;

 printf("Welcome to Coin Grabber.\n");
 printf("To play, take either 1, 2, or 3 coins from the stack,\n");
 printf("and the computer will make its selection. The one who takes\n");
 printf("the last coin from the stack wins. To start, press enter");
 getchar();

 while(coins > 0){
  //print the amount of coins
  print_coins(coins, i);

  //get player input
  printf("Please choose 1, 2, or 3: ");
  scanf("\n%d", &psel);
  
  //check that player input is within the bounds
  do{
   if(psel < 1){
    printf("You have to take at least one coin. ");
    scanf("\n%d", &psel);
   } else if(psel > 3 || psel > coins){
    printf("Dont take that many coins, greedy! ");
    scanf("\n%d", &psel);
   }
  }while(psel < 1 || psel > 3 || psel > coins);
  
  coins -= psel;
  if(coins == 0){
   printf("You took the last coin! You Win!\n");
   break;
  } else{
   printf("You take %d coins, there are %d coins left.\n", psel, coins);
  }  

  csel = gen_random_num(coins);
  coins -= csel;
  if(coins == 0){
   printf("The computer took the last coin. You lose.\n");
   break;
  } else{
   printf("The computer takes %d coins, there are %d coins left.\n", csel, coins);
  }
  current_round++;
 }

 return 0;
}

int gen_random_num(int coins){
 int r = (rand() % 3) + 1; //r will be either 1, 2, or 3
 
 // prevent the computer from taking more coins than there are left 
 if(r > coins){
  r = coins;
 }

 return r;
}

void print_coins(int coins, int i){
 printf("\nRemaining coins (%d): ", coins);
 for(i = 0; i < coins; i++){
  printf("o");
 }
 printf("\n");
}

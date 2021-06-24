#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/* Caesar Decryption */
char* CaesarDecrypt(int, char*);
/* BruteForceAttack */
void BruteForceAttack(char*, char*); 

int main(){
 
  char ciphertext[1024];  
  char keyword[1024];

  /*
    Input ciphertext and keyword. 
    If keyword is not specified (no keyword), press ENTER
  */
  
  BruteForceAttack(ciphertext, keyword);
  return 0;

}

char* CaesarDecrypt(int key, char *ciphertext){
}

void BruteForceAttack(char *ciphertext, char *keyword){
}

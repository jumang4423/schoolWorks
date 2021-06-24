#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Encrypt Function like foo -> gpp with key = 1
char* *CaesarEncrypt(int key, char *plaintext)
{

  char *ciphertext = (char*)malloc(strlen(plaintext+1));
  // for (int i = 0; i < sizeof(&plaintext) / sizeof(char); i++)
  // {
  //   // A-Z
  //   if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
  //     plaintext[i] += key;
  //     if(plaintext[i] >= 'Z') {
  //       plaintext[i] -= 25;
  //     }
  //   }
  //   // a-z
  //   else if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {
  //     plaintext[i] += key;
  //     if(plaintext[i] >= 'z') {
  //       plaintext[i] -= 25;
  //     }
  //   }
    
    
  // }


}

// Encrypt Function like gpp -> foo with key = 1
void *CaesarDecrypt(int key, char *ciphertext)
{
  for (int i = 0; i < sizeof(&ciphertext) / sizeof(char); i++)
  {
    // A-Z
    if(ciphertext[i] >= 65 && ciphertext[i] <= 90) {
      ciphertext[i] -= key;
      if(ciphertext[i] <= 65) {
        ciphertext[i] += 25;
      }
    }
    // a-z
    else if(ciphertext[i] >= 97 && ciphertext[i] <= 122) {
      ciphertext[i] -= key;
      if(ciphertext[i] <= 97) {
        ciphertext[i] += 25;
      }
    }
  }
}

int main()
{
  char plaintext[1024];
  char ciphertext[1024];
  char decrypttext[1024];

  int key;
  printf("Input plaintext:");
  scanf("%[^\n]", plaintext);

  printf("Input key (0<=key=<25):");
  scanf("%d", &key);
  
  // key validation
  while (key < 0 || key > 25)
  {
    printf("Your input wrong key, please input again:");
    scanf("%d", &key);
  }

  // input plaintext:
  printf("Plaintext: %s \n\n", plaintext);

  // input ciphertext:
  strcpy(ciphertext, plaintext);
  CaesarEncrypt(key, ciphertext);
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypted plaintext
  strcpy(decrypttext, ciphertext);
  CaesarDecrypt(key, decrypttext);
  printf("Decrypted plaintext: %s", decrypttext);
}

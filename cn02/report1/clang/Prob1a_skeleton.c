#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Caesar Encryption */
char* CaesarEncrypt(int, char*);
/* Caesar Decryption */
char* CaesarDecrypt(int, char*);

int main(){
  char plaintext[1024];
  char ciphertext[1024];
  char decrypttext[1024];
  
  int key;

  printf("plain is:");
  scanf("%s", plaintext);
  printf("key is:");
  scanf("%d", &key);
  printf("plain: %s\n", plaintext);
  printf("key: %d\n", key);

  strcpy(ciphertext, plaintext);
  CaesarEncrypt(key, ciphertext);
  printf("en: %s\n", ciphertext);

  strcpy(decrypttext, ciphertext);
  CaesarDecrypt(key, decrypttext);
  printf("de: %s\n", decrypttext);
  
  /*
    Perform Caesar Decryption: CaesarDecrypt(key, ciphertext) and print out the decryted ciphertext (decrypttext)
  */
}

char* CaesarEncrypt(int key, char *plaintext){

  for (int i=0; i< strlen(plaintext); i++) {
    plaintext[i] += key;
    // overflow
    if (plaintext[i] > 'Z' && plaintext[i] < 'a' || plaintext[i] > 'z' ) {
      plaintext[i] -= 26;
    }
  }

  return plaintext;
}
char* CaesarDecrypt(int key, char *ciphertext){
    for (int i=0; i< strlen(ciphertext); i++) {
    ciphertext[i] -= key;
    // overflow
    if (ciphertext[i] < 'A' && ciphertext[i] > 'Z' || ciphertext[i] < 'a' ) {
      ciphertext[i] -= 26;
    }
  }

  return ciphertext;
}

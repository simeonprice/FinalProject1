#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void rotationCipherE(char* text, int key);
void rotationCipherD(char* text, int key);
void rotationEncryption(void);
void rotationDecryption(void);

int main(void) {
    //USER INTERFACE
    int chosenCipher;
    printf("THE FOLLOWING IS A LIST OF REQUIREMENTS TO USE THIS PROGRAM:\n");
	printf("   ONLY ENTER YOUR TEXT IN CAPITAL LETTERS FOR ROTATION\n");
	printf("   SPACES ARE RECOGNISED AS SYMBOLS\n");
	printf("   NO USE OF NUMBERS OR SYMBOLS\n");
	printf("\n");
    
    printf("CIPHER LIST:\n");
    printf("    1: Rotation Encryption\n");
    printf("    2: Rotation Decryption\n");
    printf("    3: Substitution Encryption\n");
    printf("    4: Substitution Decryption\n");
    printf("\n");
    printf("Which cipher do you want to perform: ");
    
    scanf("%d", &chosenCipher);
    
    switch(chosenCipher) {
        case 1: rotationEncryption(); break;
        case 2: rotationDecryption(); break;
        case 3: substitutionEncryption(); break;
        case 4: substitutionDecryption(); break;
    }
    
    
}

void rotationEncryption(void) {
    int key;
    char text[1024];
    printf("Enter the text you want encrypted: ");
    fgets(text, sizeof(text), stdin); // takes the text and the length of the text
    printf("Enter your rotation key: ");
    scanf("%d", &key); // takes the key
    printf("The encrypted text is: ");
    rotationCipherE(text, key); //performs function 
    return 0;
}

//rotation decryption fuction (same as encryption but with different subfuctions)
void rotationDecryption(void) {
    int key;
    char text[1024];
    printf("Enter the text you want decrypted: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter your rotation key: ");
    scanf("%d", &key);
    printf("The decrypted text is: ");
    rotationCipherD(text, key);
    return 0;
}
//This function takes the text and the key and peforms the actual rotation for each letter
void rotationCipherE(char* text, int key) {
    
    int index = 0;
    int cipherValue;
    char cipher;
    
    while (text[index] != "\0" && strlen(text) - 1 > index) { // whilst the letter is not the end of the string and the it is not the end of the string
        
        cipherValue = (((int)text[index] - 65 + key) % 26 + 65); //encryption equation
        cipher = (char)(cipherValue); //converts the letters
        
        printf("%c", cipher);
        index++; //increments the index
    }
    printf("\n");
    
}
// same as encryption but for decryption
void rotationCipherD(char* text, int key) {
    
    int index = 0;
    int cipherValue;
    char cipher;
    
    while (text[index] != "\0" && strlen(text) - 1 > index) {
        
        cipherValue = (((int)text[index] - 65 - key) % 26 + 65); //decryption equation
        cipher = (char)(cipherValue);
        
        printf("%c", cipher);
        index++;
    }
    printf("\n");
    
}
// looking for the index
int findIndex(char code[], char charToFind){
  for(int index = 0 ; index < 26; index ++){
    if(code[index] == charToFind){
      return index;
    }
  }
  return -1;
}
//substitution encryption subfunction
char* encrypt(char *message,char code[]) {
  int length = strlen(message);
  char *encryptedMessage = (char *) malloc(sizeof(char)*length); // the malloc function allocates the needed memory and returns a pointer

  for(int index = 0; index < length; index++){
    int encryptionIndex = tolower(message[index]) - 'a'; //tolower converts a letter to lowercase
    if (encryptionIndex >= 0 && encryptionIndex < 26) {
      encryptedMessage[index] = code[encryptionIndex];
    }
    else {
      encryptedMessage[index] = message[index];
    }
  }
  return encryptedMessage;
}
//decryption statement that holds the same principles as encryption but is slightly different
char *decrypt(char *message,char code[]){
  int length = strlen(message);
  char *decryptedMessage = (char *) malloc(sizeof(char)*length);
  
  for(int index = 0; index < length; index++){
    int decryptionIndex = tolower(message[index]) - 'a';
    if(decryptionIndex >= 0 && decryptionIndex < 26){
      int codeIndex = findIndex(code,tolower(message[index])); //here the findIndex function is used
      decryptedMessage[index] = 'a' + codeIndex;
    }
    else {
      decryptedMessage[index] = message[index];
    }
  }
  return decryptedMessage;
}
//this function calls the substitution encryption after collecting the user data
void substitutionEncryption(void) {
    
    char *message;
    char code[26];
    printf("Enter the text you want encrypted: ");
    scanf("%[^\n]s", *message);
    printf("Enter the arrangement of characters you want: ");
    scanf("%s", code);
    
    char *encryptedMessage = encrypt(message, code);
    printf("Your substitution encryption is: %s\n", encryptedMessage);
}
//this function is the same but it uses the decrpyt function instead 
void substitutionDecryption(void) {
    
    char *message;
    char code[26];
    printf("Enter the text you want decrypted: ");
    scanf("%[^\n]s", *message);
    printf("Enter the arrangement of characters you want: ");
    scanf("%s", code);
    
    char *decryptedMessage = decrypt(message, code);
    printf("Your substitution decryption is: %s\n", decryptedMessage);
}

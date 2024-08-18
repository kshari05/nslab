#include <stdio.h>
#include <string.h>
void encrypt(char plaintext[], char key[]) {
int i;
char ciphertext[strlen(plaintext) + 1];
for (i = 0; plaintext[i] != '\0'; i++) {
if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
ciphertext[i] = key[plaintext[i] - 'A'];
} else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
ciphertext[i] = key[plaintext[i] - 'a'];
} else {
ciphertext[i] = plaintext[i];
}
}
ciphertext[i] = '\0';
printf("Ciphertext: %s\n", ciphertext);
}
void decrypt(char ciphertext[], char key[]) {
int i, j;
char plaintext[strlen(ciphertext) + 1];
for (i = 0; ciphertext[i] != '\0'; i++) {
if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
for (j = 0; key[j] != '\0'; j++) {
if (ciphertext[i] == key[j]) {
plaintext[i] = 'A' + j;
break;
}
}
} else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
for (j = 0; key[j] != '\0'; j++) {
if (ciphertext[i] == key[j] + 'a' - 'A') {
plaintext[i] = 'a' + j;
break;
}
}
} else {
plaintext[i] = ciphertext[i];
}
}
plaintext[i] = '\0';
printf("Decrypted plaintext: %s\n", plaintext);
}
int main() {
char plaintext[100];
char key[27];
printf("Enter the plaintext: ");
fgets(plaintext, sizeof(plaintext), stdin);
plaintext[strcspn(plaintext, "\n")] = 0;
printf("Enter the key (26 uppercase letters): ");
scanf("%s", key);
printf("Plaintext: %s\n", plaintext);
encrypt(plaintext, key);
char ciphertext[100];
printf("Enter the ciphertext to decrypt: ");
scanf(" %[^\n]%*c", ciphertext);
decrypt(ciphertext, key);
return 0;
}

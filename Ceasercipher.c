#include <stdio.h>
void caesar(char text[], int shift) {
for (int i = 0; text[i] != '\0'; ++i) {
if (text[i] >= 'a' && text[i] <= 'z')
text[i] = 'a' + (text[i] - 'a' + shift) % 26;
else if (text[i] >= 'A' && text[i] <= 'Z')
text[i] = 'A' + (text[i] - 'A' + shift) % 26;
}}
int main() {
char message[100];
int key;
printf("Enter a message: ");
fgets(message, sizeof(message), stdin);
printf("Enter the shift key: ");
scanf("%d", &key);
printf("Original message: %s\n", message);
caesar(message, key);
printf("Encrypted message: %s\n", message);
caesar(message, -key);
printf("Decrypted message: %s\n", message);
return 0;
}

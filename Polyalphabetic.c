#include <stdio.h>
#include <ctype.h>
#include <string.h>
void transform(char *msg, const char *key, int mode) {
int key_len = strlen(key);
for (int i = 0, j = 0; msg[i]; i++) {
if (isalpha(msg[i]))
{
char offset = islower(msg[i]) ? 'a' : 'A';
int key_shift = (islower(msg[i]) ? tolower(key[j % key_len]) : toupper(key[j % key_len])) - offset;
if (!mode) key_shift = -key_shift;
msg[i] = (msg[i] - offset + key_shift + 26) % 26 + offset;
j++;
}
}
}
int main() {
char msg[256];
char key[256];
printf("Enter message: ");
fgets(msg, sizeof(msg), stdin);
msg[strcspn(msg, "\n")] = '\0';
printf("Enter key: ");
fgets(key, sizeof(key), stdin);
key[strcspn(key, "\n")] = '\0';
transform(msg, key, 1);
printf("Encrypted: %s\n", msg);
transform(msg, key, 0);
printf("Decrypted: %s\n", msg);
return 0;
}

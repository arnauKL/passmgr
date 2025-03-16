#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_BUF_SIZE 64	// Bcs why not
#define XOR_KEY 0x5A	// XOR_KEY

int main() {
    // For now, enter a password and encrypt it.

    char buffer[MAX_BUF_SIZE];
    printf("Enter a string to encrypt: ");

    //scanf("%63s", buffer);	// 63: MAX_BUF_SIZE - 1 for '\0'
    //scanf leaves behind in the stdin everything that it did not read. Should avoid doing that
    fgets(buffer, MAX_BUF_SIZE, stdin);

    // fgets also saves the '\n'. Let's replace it by '\0':
    buffer[strcspn(buffer, "\n")] = '\0';
    size_t length = strlen(buffer);


    for(int i = 0; i < length; i++) {
	//encrypt using xor operator
	buffer[i] ^= XOR_KEY;
    }

    printf("The encrypted string: ");
    for(int i = 0; i < length; i++) {
	printf("%02X ", buffer[i]);
    }
    printf("\n");

    //Decrypt: XOR works both ways
    for(int i = 0; i < length; i++) {
	buffer[i] ^= XOR_KEY;
    }

    printf("The decrypted string: %s\n", buffer);

    return 0;
}

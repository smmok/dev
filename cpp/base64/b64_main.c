//
// OpenSSL Base64 Encoding: Binary Safe and Portable
//
// https://gist.github.com/barrysteyn/7308212
//
// gcc -o base64 Main.c Base64Encode.c Base64Decode.c -lcrypto -lm -w
//  or
// gcc -o b64_main b64_main.c Base64Encode.c Base64Decode.c -I/usr/local/include -L/usr/local/lib -lcrypto
//

#include <stdio.h>
#include <string.h>

int Base64Encode(const unsigned char* buffer, size_t length, char** b64text);
int Base64Decode(char* b64message, unsigned char** buffer, size_t* length);
size_t calcDecodeLength(const char* b64input);

int main() {
  //Encode To Base64
  char* base64EncodeOutput, *text="Hello World";

  Base64Encode(text, strlen(text), &base64EncodeOutput);
  printf("Output (base64): %s\n", base64EncodeOutput);

  //Decode From Base64
  char* base64DecodeOutput;
  size_t test;
  Base64Decode("SGVsbG8gV29ybGQ=", &base64DecodeOutput, &test);
  printf("Output: %s %d\n", base64DecodeOutput, test);
  
  return(0);
}

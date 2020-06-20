//
// OpenSSL Base64 Encoding: Binary Safe and Portable
// https://gist.github.com/barrysteyn/7308212
//
// gcc -o Base64_EncodeDecode Base64_EncodeDecode.c
//     -I/usr/local/include -L/usr/local/lib -lcrypto
//

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include <openssl/buffer.h>
#include <stdint.h>
#include <assert.h>
#include <stdio.h>

int Base64Encode(const unsigned char*, size_t, char**);
size_t calcDecodeLength(const char* b64input);
int Base64Decode(char*, unsigned char**, size_t*);

int main(int argc, char** argv)
{
	char* b64text;	
	char message[] = "Hello World!";
	int  msglen = strlen(message);

	printf("Original text=%s\n", message);

	Base64Encode(message,msglen,&b64text);
	printf("Encoded text=%s\n",b64text);

	unsigned char* base64DecodeOutput;
	size_t test;
	Base64Decode(b64text, &base64DecodeOutput, &test);
	printf("Decoded Text=%s\n", base64DecodeOutput);
	printf("Decoded Text Length=%ld\n", test);

	return 0;
}
	
int Base64Encode(const unsigned char* buffer, size_t length, char** b64text)
{
	BIO *bio, *b64;
	BUF_MEM *bufferPtr;

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	BIO_write(bio, buffer, length);
	BIO_flush(bio);
	BIO_get_mem_ptr(bio, &bufferPtr);
	BIO_set_close(bio, BIO_NOCLOSE);
	BIO_free_all(bio);

	*b64text=(*bufferPtr).data;
}

size_t calcDecodeLength(const char* b64input)
{
	size_t len = strlen(b64input);
	size_t padding = 0;

	if (b64input[len-1] == '=' && b64input[len-2] == '=')
		padding = 2;
	else if (b64input[len-1] == '=')
		padding = 1;

	return (len*3)/4 - padding;
}

int Base64Decode(char* b64message, unsigned char** buffer, size_t* length) 
{
	BIO *bio, *b64;

	int decodeLen = calcDecodeLength(b64message);
	*buffer = (unsigned char*)malloc(decodeLen+1);
	(*buffer)[decodeLen] = '\0';

	bio = BIO_new_mem_buf(b64message, -1);
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	*length = BIO_read(bio, *buffer, strlen(b64message));
	assert(*length==decodeLen);
	BIO_free_all(bio);
}		

//
// https://eclipsesource.com/blogs/2017/01/17/tutorial-aes-encryption-and-decryption-with-openssl/
// https://gist.github.com/irbull/c76a8c60e049a9fcba1116aa81771253
//

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <openssl/evp.h>

using namespace std;

void handleOpenSSLErrors(void)
{
  ERR_print_errors_fp(stderr);
  abort();
}

string decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv ) {

  EVP_CIPHER_CTX *ctx;
  unsigned char *plaintexts;
  int len;
  int plaintext_len;
  unsigned char* plaintext = new unsigned char[ciphertext_len];
  bzero(plaintext,ciphertext_len);

  /* Create and initialise the context */
  if(!(ctx = EVP_CIPHER_CTX_new())) handleOpenSSLErrors();

  /* Initialise the decryption operation. IMPORTANT - ensure you use a key
   * and IV size appropriate for your cipher
   * In this example we are using 256 bit AES (i.e. a 256 bit key). The
   * IV size for *most* modes is the same as the block size. For AES this
   * is 128 bits */
  if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    handleOpenSSLErrors();

  EVP_CIPHER_CTX_set_key_length(ctx, EVP_MAX_KEY_LENGTH);

 /* Provide the message to be decrypted, and obtain the plaintext output.
   * EVP_DecryptUpdate can be called multiple times if necessary
   */
  if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    handleOpenSSLErrors();

  plaintext_len = len;

  /* Finalise the decryption. Further plaintext bytes may be written at
   * this stage.
   */
  if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleOpenSSLErrors();
  plaintext_len += len;


  /* Add the null terminator */
  plaintext[plaintext_len] = 0;

  /* Clean up */
  EVP_CIPHER_CTX_free(ctx);
  string ret = (char*)plaintext;
  delete [] plaintext;
  return ret;
}

void initAES(const string& pass, unsigned char* salt, unsigned char* key, unsigned char* iv )
{
  bzero(key,sizeof(key));
  bzero(iv,sizeof(iv));

  EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, (unsigned char*)pass.c_str(), pass.length(), 1, key, iv);
}

size_t calcDecodeLength(char* b64input) {
  size_t len = strlen(b64input), padding = 0;

  if (b64input[len-1] == '=' && b64input[len-2] == '=') //last two chars are =
    padding = 2;
  else if (b64input[len-1] == '=') //last char is =
    padding = 1;
  return (len*3)/4 - padding;
}

void Base64Decode( char* b64message, unsigned char** buffer, size_t* length) {
  BIO *bio, *b64;

  int decodeLen = calcDecodeLength(b64message);
  *buffer = (unsigned char*)malloc(decodeLen + 1);
  (*buffer)[decodeLen] = '\0';

  bio = BIO_new_mem_buf(b64message, -1);
  b64 = BIO_new(BIO_f_base64());
  bio = BIO_push(b64, bio);

  //BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer
  *length = BIO_read(bio, *buffer, strlen(b64message));
  BIO_free_all(bio);
}

int main (int argc, char** argv)
{
  // This is the string Hello, World! encrypted using aes-256-cbc with the
  // pasword 12345
  //char* ciphertext_base64 = (char*) "U2FsdGVkX1/E/yWBwY9nW96pYIv2nouyJIFF9BtVaKA=\n";
  //char* ciphertext_base64 = (char*) "U2FsdGVkX19ttge/RWJVbTutvH99nLXN9aepOEeSR6KVpWnJQdP/iDD2BRANKiYixoDytT4cSNPDapUy/BzItg==";

//  char* ciphertext_base64 = (char*) "U2FsdGVkX18u70L5+UEKL2O5mFOSKfrw6/+pYp9N4r4IbWEnjQazWVh3OEukfq5l\nODsKgIoaBzEJ2QEUF2GMbJQTl4x/ZIFhehRXYEL8WOCIN79UVx5i5Z2+eOaGP1Rd";

  if (argc!=3) 
  {
    std::cout << "Usage: program emessage.txt pw" << std::endl;
	exit(1);
  }

  char* filename = argv[1];
  char* pw = argv[2];
  std::cout << filename << " " << pw << std::endl;

  std::string line;
  std::string lines("");
  ifstream infile;
  infile.open(filename);
  if (infile.is_open())
  {
  	while (getline (infile,line) )
	{
	  lines = lines + "\n" + line;
	  //std::cout << lines << std::endl;
	}
	infile.close();
  }
  else
    std::cout << "Problem reading file.\n";

  std::cout << "\nInput file content:";
  std::cout << lines << std::endl;
  char* ciphertext_base64 = const_cast<char*>(lines.c_str());

  int decryptedtext_len, ciphertext_len;
  size_t cipher_len;
  unsigned char* ciphertext;
  unsigned char salt[8];
  ERR_load_crypto_strings();
  Base64Decode(ciphertext_base64, &ciphertext, &cipher_len);

  unsigned char key[32];
  unsigned char iv[32];
  if (strncmp((const char*)ciphertext,"Salted__",8) == 0) {
    memcpy(salt,&ciphertext[8],8);
    ciphertext += 16;
    cipher_len -= 16;
  }
  //initAES("12345", salt, key, iv);
  initAES(pw, salt, key, iv);

  string result = decrypt(ciphertext, cipher_len, key, iv);
  std::cout << "\nDecoded message:\n";
  std::cout << result << std::endl;

  // Clean up
  EVP_cleanup();
  ERR_free_strings();

  return 0;
}

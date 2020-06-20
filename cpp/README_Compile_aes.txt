g++ -o aes-decryption aes-decryption.cpp -I/usr/local/include -L/usr/local/lib -lssl -lcrypto

openssl enc -aes-256-cbc -in message.txt -out emessage.txt -base64 -md sha1

./aes-decrpytion emessage.txt password

iconv WebsiteNames.cpp -f UTF-16 -t UTF-8 > WebsiteNames1.cpp

g++ -o WebsiteNames WebsiteNames.cpp -Wall -static -static-libgcc -I/home/asm001/dev/boost/boost_1_72_0 -L/home/asm001/dev/boost/boost_1_72_0/stage/lib -lboost_ser
ialization -lpthread

g++ -o WebsiteNames WebsiteNames.cpp -Wall -static -static-libgcc
 -I/home/asm001/dev/boost/boost_1_72_0 -L/home/asm001/dev/boost/boost_1_72_0/stage/lib -lboost_ser
 ialization

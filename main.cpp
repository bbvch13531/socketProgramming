// https://www.joinc.co.kr/w/Site/Network_Programing/Documents/Socket_Sample
// https://github.com/openbsd/src/blob/master/sys/sys/socket.h
// http://pubs.opengroup.org/onlinepubs/7908799/xns/socket.html
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#define PORT 8080

using namespace std;

int main(void){
    int server_sock, client_sock;
    int state, client_len;

    /*
    // int socket(int domain, int type, int protocol);
    // 서버 소켓 생성
    // PF_INET : 인터넷 프로토콜 체계, # define AF_INET 2로 UDP, TCP 프로토콜 이용할 때 사용
    // SOCK_STREAM : 스트림 방식의 소켓 (TCP) 생성
    // 0 : 구체적인 프로토콜을 정의할 때 사용
    */
    server_sock = socket(PF_INET, SOCK_STREAM, 0); 
    
    /*
    // int connect(int socket, const struct sockaddr *address,
    // socklen_t address_len);
    // 
    */

    cout<<"hello socket" ;
    return 0;
}

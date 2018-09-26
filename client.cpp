#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>


using namespace std;

int main(void){
    int client_sock;
    socklen_t client_addr_size;
    
    /*
    // int socket(int domain, int type, int protocol);
    // 클라이언트 소켓을 생성한다.
    // PF_INET : 인터넷 프로토콜 체계, # define AF_INET 2로 UDP, TCP 프로토콜 이용할 때 사용
    // SOCK_STREAM : 스트림 방식의 소켓 (TCP) 생성
    // 0 : 구체적인 프로토콜을 정의할 때 사용
    */
    client_sock = socket(PF_INET, SOCK_STREAM, 0);

    /*
    // int connect(int socket, const struct sockaddr *address,
    // socklen_t address_len);
    // 
    */

    return 0;
}
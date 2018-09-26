// https://www.joinc.co.kr/w/Site/Network_Programing/Documents/Socket_Sample
// https://github.com/openbsd/src/blob/master/sys/sys/socket.h
// http://pubs.opengroup.org/onlinepubs/7908799/xns/socket.html

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTION 5

using namespace std;

int main(void){
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    client_addr_size = sizeof(client_addr);
    /*
    // int socket(int domain, int type, int protocol);
    // 서버 소켓을 생성한다.
    // PF_INET : 인터넷 프로토콜 체계, # define AF_INET 2로 UDP, TCP 프로토콜 이용할 때 사용
    // SOCK_STREAM : 스트림 방식의 소켓 (TCP) 생성
    // 0 : 구체적인 프로토콜을 정의할 때 사용
    */
    server_sock = socket(PF_INET, SOCK_STREAM, 0); 
    
    /*
    // int bind(int socket, const struct sockaddr *address,
    // socklen_t address_len);
    // 소켓에 주소를 할당한다.
    // server_sock : 소켓 번호
    // server_addr : 소켓의 주소를 담는 구조체
    // sizeof(server_addr) : 구조체의 크기
    */
    if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1 ){
        // 주소 할당에 성공하면 0, 실패하면 -1을 리턴한다.
        cout<<"Bind error"<<endl;
    }

    /*
    // int listen(int socket, int backlog);
    // 연결 요청을 기다린다.
    // server_sock : 소켓 번호
    // MAX_CONNECTION : 연결을 기다리는 최대 클라이언트의 수
    */
    if(listen(server_sock, MAX_CONNECTION) == -1){
        // 성공하면 0, 실패하면 -1을 리턴한다.
        cout<<"listen error"<<endl;
    }

    /*
    // int accept (int socket, struct sockaddr *address, socklen_t *address_len);
    // 연결 요청을 수락한다.
    // server_sock : 소켓 번호
    // client_addr : 클라이언트 소켓 구조체
    // client_addr_size : 클라이언트 소켓 구조체의 크기
    */
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    cout<<"hello socket" ;
    return 0;
}

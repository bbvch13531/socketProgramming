#include "myheader.h"

using namespace std;

int main(void){
    int client_sock;
    int data_len;
    char message[50];
    socklen_t client_addr_size;
    struct sockaddr_in client_addr;

    client_addr_size = sizeof(client_addr);
    /*
    // int socket(int domain, int type, int protocol);
    // 클라이언트 소켓을 생성한다.
    // PF_INET : 인터넷 프로토콜 체계, # define AF_INET 2로 UDP, TCP 프로토콜 이용할 때 사용
    // SOCK_STREAM : 스트림 방식의 소켓 (TCP) 생성
    // 0 : 구체적인 프로토콜을 정의할 때 사용
    */
    client_sock = socket(PF_INET, SOCK_STREAM, 0);

    /*
    // .sin_family : 주소 체계
    // .sin_addr.s_addr : IP 주소
    // .sin_port : 포트번호
    */
    client_addr.sin_family = AF_INET; 
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_addr.sin_port = htons(PORT); 

    /*
    // int connect(int socket, const struct sockaddr *address,
    // socklen_t address_len);
    // 서버로 연결을 요청한다.
    // client_sock : 클라이언트 소켓 번호
    // client_addr : 클라이언트 소켓 구조체
    // client_addr_size : 클라이언트 소켓 구조체의 크기
    */
    if(connect(client_sock, (struct sockaddr*)&client_addr, client_addr_size) == -1){
        printf("Connect error\n");
    }
    else printf("Connection established\n");

    /*
    // ssize_t recv(int socket, void *buffer, size_t length, int flags);
    // 서버에서 데이터를 수신한다.
    // client_sock : 클라이언트 소켓 번호
    // message : 전송할 데이터
    // sizeof(message) : 데이터의 크기
    // flag : 데이터 전송의 타입을 정의.
    */

    char send_msg[50] = "Hello server! I'm client";
    send(client_sock, (void*)send_msg, sizeof(send_msg), 0);

    int flag = 0;
    data_len = recv(client_sock, (void *)message, sizeof(message), flag);

    if(data_len!=0) printf("recv from server: %s\n",(char *)message);
    // 전송받은 데이터가 있으면 출력

    /*
    // close(int socket)
    // 소켓 통신을 종료한다.
    // client_sock : 클라이언트 소켓 번호
    */
   
    close(client_sock);

    return 0;
}

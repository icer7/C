#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet.h>
#include <arpa/inet.h>
#include"hacking.h" 

#define PORT 7890 // ユーザーが接続するポート番号

int main(void) {
	int sockfd, new_sockfd; // sockfd上で待ち受ける、new_fdは新たな接続
        struct sockaddr_in host_addr, client_addr; // 自らのアドレス情報
        socklen_t sin_size;
        int recv_length=1,yes=1;
        char buffer[1024];

	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		fatal("ソケットが生成できませんでした。");

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		fatal("ソケットをSO_REUSEADDRに設定します。");


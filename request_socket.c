#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>


void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char const *argv[])
{
	int sockfd, portno;
	struct sockaddr_in addr;

	portno = 80;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		error("ERROR opening socket");
	}

	memset((char*)&addr, 0, sizeof(addr));

	addr.sin_port = htons(portno);
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, "183.63.251.70", &addr.sin_addr);

	if(connect(sockfd, (struct sockaddr *)&addr, sizeof addr) < 0) {
		close(sockfd);
		error("ERROR connecting to server");
	}

	char request[] = "GET /SingleWindow/SingleWindowMessageService.svc/json/ HTTP/1.1\r\nHost: 183.63.251.70\r\nConnection: close\r\n\r\n";
	char response[1024];

	send(sockfd, request, sizeof(request), 0);

	while(recv(sockfd, response,sizeof(response), 0) > 0) {
		printf(response);
	}

	close(sockfd);
	return 0;

}
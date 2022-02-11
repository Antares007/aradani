// Client
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  struct sockaddr_in address = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = inet_addr("127.0.0.1"),
      .sin_port = htons(7000),
  };
  char str1[] = "ABCDE";
  char str2[] = "ABCDEFGHIJK";
  int client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  int len = sizeof(address);
  int result = connect(client_sockfd, (struct sockaddr *)&address, len);
  if (result == -1)
    perror("oops: client2"), exit(1);
  // First reading and writing
  write(client_sockfd, str1, sizeof(str1));
  sleep(5);
  // Second reading and writing
  write(client_sockfd, str2, sizeof(str2));
  close(client_sockfd);
  return 0;
}

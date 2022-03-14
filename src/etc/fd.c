#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redirect_stdout(char *);

int main() {
  printf("Hello world\n"); /* this printf goes to standard output*/
  fflush(stdout);
  redirect_stdout("foo");            /* redirect standard output*/
  printf("Hello to you too, foo\n"); /* printf goes to file foo */
  fflush(stdout);
}

void redirect_stdout(char *filename) {
  int fd;
  if ((fd = open(filename, O_CREAT | O_WRONLY, 0666)) < 0) /* open a new file */
    perror(filename), exit(1);
  close(1);         /* close old standard output*/
  if (dup(fd) != 1) /* dup new fd to standard input*/
    fprintf(stderr, "Unexpected dup failure\n"), exit(1);
  close(fd); /* close original, new fd, no longer needed*/
}

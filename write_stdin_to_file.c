
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>
#include <errno.h>


void fatal (char *msg)
{
  perror (msg);
  exit (1);
}


#define BUFSIZE 0x1000
int main (int argc, char **argv)
{
  int ofd, ifd, n;
  char buf[BUFSIZE];

  if (argc != 2) {
     fprintf (stderr, "Need exactly one argument (file-to-write-to)\n");
     exit (1);
  }
  ofd = open (argv[1], O_WRONLY | O_CREAT, 0666);
  if (ofd < 0) fatal (argv[1]);

  ifd = 0;  // STDIN
  while (1) {
     n = read (ifd, buf, BUFSIZE);
     if (n <= 0) break;
     n = write (ofd, buf, n);
     if (n < 0) fatal ("writing");
  }
  exit (0);
}

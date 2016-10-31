//JYLT
//10-28-16

#include <stdio.h>
#include <stdlib.h>

#include <errno.h> //error check
#include <string.h> //string

#include <fcntl.h> //open
#include <unistd.h> //close
#include <sys/stat.h> //umask
#include <sys/types.h>
#include <time.h>

/*There is a function called stat. It is used to get information about a file.
With your table partner, write a program that uses stat to display the
following information about a file:

    file size
    mode (permissions)
    time of last access (displayed in the following format:
Fri Oct 28 09:03:01 2016
int stat(const char *path, struct stat *buf);
*/

int main() {

  struct stat *buf = (struct stat *)malloc(sizeof(struct stat));

  stat("stat.c", buf);

  printf("File Size : %ld bytes\n", buf->st_size);

  printf("File Mode : %o\n", buf->st_mode);

  printf("Time of Last Access : %s\n", ctime(&(buf->st_atime)));

  free(buf);

  return 0;

}
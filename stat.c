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

Added 10/31. In the same file:

◾Modify the size so it is printed out in human readable form (that is using B, KB, MB, GB).
◾Attempt to print out the permissions in ls -l form, ignoring the early bits that include the file type information (the permissions section of the mode is stored in the last 9 bits of the data type).


int stat(const char *path, struct stat *buf);
*/

char * convert(int o){
  char mode[9];
  if (o & S_IRUSR) mode[0] = 'r';
  else mode[0] = '-';
  if (o & S_IWUSR) mode[1] = 'w';
  else mode[1] = '-';
  if (o & S_IXUSR) mode[2] = 'x';
  else mode[2] = '-';
  if (o & S_IRGRP) mode[3] = 'r';
  else mode[3] = '-';
  if (o & S_IWGRP) mode[4] = 'w';
  else mode[4] = '-';
  if (o & S_IXGRP) mode[5] = 'x';
  else mode[5] = '-';
  if (o & S_IROTH) mode[6] = 'r';
  else mode[6] = '-';
  if (o & S_IWOTH) mode[7] = 'w';
  else mode[7] = '-';
  if (o & S_IXOTH) mode[8] = 'X';
  else mode[8] = '-';
  return mode;
}

int main() {

  struct stat *buf = (struct stat *)malloc(sizeof(struct stat));

  stat("stat.c", buf);

  printf("File : stat.c\n");
  printf("File Size : %ld bytes\n", buf->st_size);
  printf("File Size : %lf kilobytes\n", (buf->st_size)/1000.0f);
  printf("File Size : %lf megabytes\n", (buf->st_size)/1000000.0f);
  printf("File Size : %lf gigabytes\n", (buf->st_size)/1000000000.0f);

  printf("File Mode : %o\n", buf->st_mode);
  char * mode = convert(buf->st_mode);
  printf("File Mode : -%s\n", mode);

  printf("Time of Last Access : %s\n", ctime(&(buf->st_atime)));

  free(buf);

  return 0;

}

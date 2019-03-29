#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  struct stat buf;

  // Parse command line
  /* if there are no extra arguements show contents of current directory
      otherwise show contents of given directory */
  if(argc == 1){
    argv[1] = ".";
  }

  // Open directory
  dir = opendir(argv[1]);

  printf("Reading directory %s\n", argv[1]);

  // Repeatly read and print entries
  while((entry = readdir(dir)) != NULL)
  {
    char *f_name = entry->d_name;
    char *fullpath = argv[1] + "/" + f_name; // need to be properly concatenated
    int f_size = stat(fullpath, &buf);
    printf("%10lld %s\n", buf.st_size, f_name);
  }



  // Close directory
  closedir(dir);
  return 0;
}
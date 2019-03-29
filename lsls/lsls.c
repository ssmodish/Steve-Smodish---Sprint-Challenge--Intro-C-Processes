#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  // Parse command line
  /* if there are no extra arguements show contents of current directory
      otherwise show contents of given directory */
  if(argc == 1){
    argv[1] = ".";
  }

  // Open directory
  dir = opendir(argv[1]);

  // Repeatly read and print entries
  while((entry = readdir(dir)) != NULL)
  {
    printf("Reading directory item\n");
  }



  // Close directory
  closedir(dir);
  return 0;
}
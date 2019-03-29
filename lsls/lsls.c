#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  struct stat buf;
  char path[128], f_name[128], fullpath[256];

  // Parse command line
  /* if there are no extra arguements show contents of current directory
      otherwise show contents of given directory */
  if(argc == 1){
    strcpy(path, ".");
  } else {
    strcpy(path, argv[1]);
  }

  // Open directory
  dir = opendir(path);

  printf("Reading directory %s\n", path);

  // Repeatly read and print entries
  while((entry = readdir(dir)) != NULL)
  {
    fullpath[0] = '\0';
    strcpy(f_name, entry->d_name);
    strcat(fullpath, path);
    strcat(fullpath, "/");
    strcat(fullpath, f_name);
    // printf("%s\n", fullpath);
    stat(fullpath, &buf);
    printf("%10li %s\n", buf.st_size, f_name);
  }



  // Close directory
  closedir(dir);
  return 0;
}
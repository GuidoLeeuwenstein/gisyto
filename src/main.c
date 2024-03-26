#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int addFileToWatch(char* filepath) {
  char* fileContents;
  FILE* fileptr;
  long fileCount;

  fileptr = fopen(filepath, "r");
  printf("%s\n", filepath);
  if(NULL == fileptr) {
    printf("could not read file\n");
    return 1;
  }
  fseek(fileptr, 0, SEEK_END);
  fileCount = ftell(fileptr);
  rewind(fileptr);
  fileContents = malloc(fileCount*8+1);
  for (int i = 0; i < fileCount; i++ ) {
    fileContents[i] = (char) fgetc(fileptr);
  }
  fileContents[fileCount+1] = 0;
  fclose(fileptr);
  printf("%s\n", fileContents);
  free(fileContents);

  return 0;
}

int main(int argc, char* argv[]) {
  if (1 == argc) {
    printf("Not enough arguments given: %s\n", *argv);
    return 2;
  }

  if (3 == argc) {
    if(0 == strcmp("watch", argv[1])) {
      return addFileToWatch(argv[2]);
    } else {
      printf("argument was not recognized: %s\n", argv[1]);
    }
  }

  printf("Something went wrong");
  return 1;
}

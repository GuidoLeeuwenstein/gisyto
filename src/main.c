#include <stdio.h>
#include <string.h>

typedef struct {
  char filePath[sizeof(char) * 4096];
  unsigned long long hash;
  long dataCreated;
  long dateLastUpdated;
} LocFile;

unsigned long long genHash(char *contents) {
  unsigned long long hash = 4268;
  int c;
  while ((c = *contents++)) {
    hash = (hash << 4) + hash * c;
  }
  return hash;
}

int addLocalFileToBuffer() {
  printf("Not yet inplemented\n");
  return 1;
};

int sync() {
  printf("Not yet inplemented\n");
  return 1;
};

int download() {
  printf("Not yet inplemented\n");
  return 1;
};

int upload() {
  printf("Not yet inplemented\n");
  return 1;
};

int load() {
  printf("Not yet inplemented\n");
  return 1;
}

int main(int argc, char *argv[]) {
  if (1 == argc) {
    printf("No arguments supplied\n");
    return 1;
  }
  if (0 == strcmp(argv[1], "status")) {
    printf("You send status which is not yet implemented\n");
    return 1;
  };
  if (0 == strcmp(argv[1], "add")) {
    if (2 == argc) {
      printf("No route parameter was supplied\n");
      return 1;
    }
    printf("You send add which is not yet implemented\n");
    return 1;
  };
  if (0 == strcmp(argv[1], "init")) {
    printf("You send init which is not yet implemented\n");
    return 1;
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// 0xff 0xd8 0xff 0xe

int main(int argc, char *argv[])
{
  if (argc !=2)
  {
      printf("Usage: ./recover image\n");
      return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
      printf("Error ocurred while opening the raw file.\n");
      return 1;
  }




}
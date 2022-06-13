#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>


// 0xff 0xd8 0xff 0xe
#define BLOCK_SIZE 512

bool isJpegheader(uint8_t buffer[])
{
  return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char* argv[])
{
  if (argc !=2)
  {
      printf("Usage: ./recover image\n");
      return 1;
  }

  FILE *inputPtr = fopen(argv[1], "r");
  if (inputPtr == NULL)
  {
      printf("Error ocurred while opening the raw file.\n");
      return 1;
  }

  char filename[8];// xxx.jpg'\0'
  FILE * outputPtr = NULL;
  uint8_t buffer[BLOCK_SIZE];
  int jpg_counter = 0;

  while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, inputPtr) || feof(inputPtr)==0)
  {
    if(isJpegheader(buffer))
    {
        if (outputPtr!=NULL)
        {
          fclose(outputPtr);
        }
        sprintf(filename, "%03i.jpg", jpg_counter);
        outputPtr = fopen(filename, "w");
        jpg_counter++;
    }
    if (outputPtr!= NULL)
    {
      fwrite(buffer, sizeof(buffer), 1, outputPtr);
    }
  }
  if (inputPtr==NULL)
  {
    fclose(inputPtr);
  }

  if (outputPtr==NULL)
  {
    fclose(outputPtr);
  }

}
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
	 if (argc != 2)
    {
      printf("Wrong number of arguments\n");
      exit(1);
    }
  FILE* test;
  test = fopen(argv[1], "w");
	fprintf(test,"1\n");
	fprintf(test,"1000000\n");
	fprintf(test,"999999\n");
	for(int i=0;i<999999;i++){
		fprintf(test, "%d %d ",i+1,i+2);
	}
}

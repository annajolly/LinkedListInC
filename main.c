//Anna Jolly 260447198

#include "list.h"

int main(int argc, char *argv[])
{
	FILE *file_ptr;
	char input[100];
	printf("Enter a filename\n");
	fgets(input, 100, stdin);
	//Remove carriage return
	char *p = strchr(input, '\n');
	if(p) *p = 0;
	file_ptr = fopen(input, "r");
	while( file_ptr == NULL)
	{
		printf("Enter a filename\n");
        	fgets(input, 100, stdin);
        	//Remove carriage return
        	char *q = strchr(input, '\n');
        	if(q) *q = 0;
        	file_ptr = fopen(input, "r");
	}
	int i;
	while ( fscanf(file_ptr, "%d", &i) > 0)
	{
		add(i);
	}
	prettyPrint();
	char answer[5];
	int repeat = 1;
	while(repeat)
	{
		int toDelete;
		printf("Enter an integer to delete:\n");
		scanf("%d", &toDelete);
		int isDelete = delete(toDelete);
		if(isDelete == 0)
		{
			printf("NUMBER WAS NOT FOUND\n");
		}
		else
		{
			printf("NUMBER WAS DELETED\n");
		}
		prettyPrint();
		printf("Do you wish to delete another number?\n");
		scanf("%s", answer);
		if(strncmp("Y", answer, 1) == 0 || strncmp("y", answer, 1) == 0 || strncmp("YES", answer, 3) == 0 || strncmp("yes", answer, 3) == 0 || strncmp("Yes", answer, 3) == 0)
		{
			repeat = 1;
		}
		else
		{
			repeat = 0;
		}
	}
	fclose(file_ptr);
	return 0;
}
		

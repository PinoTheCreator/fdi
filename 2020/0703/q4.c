#include <stdio.h>
#include <string.h>

#define MAXS 30
void upper(char[]);
int ometti(char[], char[], char[]);

int main(int argc, char* argv[]){
	if(argc == 4){
		printf("%d\n", ometti(argv[1], argv[2], argv[3]));
	}else
		printf("ERRORE\n");

	return 0;
}

void upper(char str[]){
	int i;
	
	for(i = 0; str[i] != '\0'; i++)
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
}

int ometti(char src[], char dst[], char voc[]){
	int count;
	FILE *fp, *fa;
	char *tmp;
	
	fp = fopen(src, "r");
	if(fp){
		fa = fopen(dst, "w");
		if(fa){
			count = 0;
			fscanf(fp, "%s", tmp);
			/*punto 2*/
			upper(voc);
			while(!feof(fp)){
				upper(tmp);
				if(strcmp(voc, tmp))
					count++;
				else
					fprintf(fa, "%s", tmp);

				fscanf(fp, "%s", tmp);
			}

			fclose(fa);
		}else{
			printf("ERRORE\n");
			count = -1;
		}

		fclose(fp);
	}else{
		printf("ERRORE\n");
		count = -1;
	}

	return count;
}

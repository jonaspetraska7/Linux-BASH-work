#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ftw.h>
#include <dlfcn.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/time.h>

FILE *desk;

int apdoroti(const char *p, const struct stat *st, int fl, struct FTW *fbuf){
        char c = 'x';
	char e = 'x';
	char l = 'x';
	char f = 'x';
	FILE *file;
	static int cnt = 0;
        cnt ++;
	
		
	if(cnt > 1 && S_ISREG(st->st_mode) && fbuf->level < 2) {
		file = fopen(p,"r");
		e = getc(file);
                l = getc(file);
                f = getc(file); 
		printf(" %c %c %c \n",e,l,f);

		fprintf(desk," vardas : %s, inode : %d, dydis : %d ",p,(int)st->st_ino
		,(int)st->st_size); 
		if(e=='#' && l =='!' && f=='/') { 
			fprintf(desk, " SKRIPTAS "); }

		fprintf(desk,"\n"); 
		

		}

	return 0;


	if(cnt > 1 && S_ISREG(st->st_mode) && fbuf->level < 2 && fopen(p,"r")) {
		

		puts(p);
		file = fopen(p,"r");
		if(st->st_size > 20) {
                c = getc(file);
                e = getc(file);
                l = getc(file);
                f = getc(file); } }
        if(cnt > 1 && S_ISREG(st->st_mode) && fbuf->level < 2 && 
dlopen(p,RTLD_LAZY | RTLD_LOCAL) != NULL){	
		printf(" %c %c %c \n",e,l,f);
                printf(" INF  DINAMINE BIB   INF  inode : %d size : %d\n ",
 (int)st->st_ino,
                        (int)st->st_size); }
		if(dlopen(p,RTLD_LAZY | RTLD_LOCAL) == NULL && e=='E' && 
l == 'L' && f=='F'){
			printf(" %c %c %c \n",e,l,f);
			printf("NE DINAMINE BIB BET ELF FAILAS\n"); } 

   return 0;
}


int main(int argc, char *argv[]){
        if( argc != 2 ){ printf("Error: Netinkamas argumentu kiekis\n");
	return -1; }
	if( (desk=fopen("f_info.txt", "r≈≈+")) != NULL )
	{
		chmod("f_info.txt", S_IRWXU);
		 printf("veikia");
		nftw(argv[1],apdoroti,20,FTW_PHYS); }
	else { perror("Neatidaro failo\n");
		return -1; }
	
	fclose(desk);
	return 0;
}


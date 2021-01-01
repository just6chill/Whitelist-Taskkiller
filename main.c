#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



int main()
{
	remove("killer.bat");
	
	FILE *List;
	List = fopen("whitelist.txt", "r"); 
	
	fseek(List, 0L, SEEK_END); 

	long int res = ftell(List); 
	
	fclose(List);
	
	char list[res];
	int c;
	int i;
	
	res = res + 1;
	
	List = fopen("whitelist.txt", "r");
	
	fgets (list, res, List);
	
	printf("%s", list);
	
	
	
	char one[]={'%', '%', 'i', '\0'};
	char two[]={'%', 'u', '\0'};
	char fou[]={'"', '%', 'w', '\0'};
	char fiv[]={'%', '%', 'i', '"', '\0'};
    FILE *File;

    File = fopen("killer.bat", "a+t");

    fprintf(File, "@echo off \nTitle whitelist taskkiller by just6chill github \
			\nset \"whitelist=Taskkiller %s\" \n\n@For /f \"skip=3 tokens=1\" %s in ( \
			\n'TASKLIST /FI \"USERNAME eq %sserdomain%%\\%%username%%\" /FI \
			\n\"STATUS eq running\" ^| findstr /VI %shitelist%%\"'\n) Do ( \n	Taskkill /IM \"%s /F \
			\n) \npause & exit", list, one, two, fou, fiv);

    fclose(File);
	fclose(List);
	system("killer.bat");
	
	Sleep(25);
	remove("killer.bat");

    return 0;
}


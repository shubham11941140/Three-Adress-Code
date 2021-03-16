#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fptr; 
  
    char filename[10000], c; 
    char s[109];
    fptr = fopen(argv[1], "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    char d[10];
    while(fgets(s,100,fptr) != NULL) 
    {
        strcpy(d,"int");
        int cpr = 0;
        if(strstr(s, d) != NULL)
        {
            int l = strlen(s);
            int i;
            cpr = 1;
            for (i = 0; i < l; i++)
            {
                printf("%c",s[i]);
                if (s[i] == ',')
                {                    
                    printf(" %s ",d);
                }
                
            }
        }

        strcpy(d,"float");
        if(strstr(s, d) != NULL) 
        {
            int l = strlen(s);
            int i;
            cpr = 1;
            for (i = 0; i < l; i++)
            {
                printf("%c",s[i]);
                if (s[i] == ',')
                {
                    printf(" %s ",d);
                }                
            }
        }

        strcpy(d,"char");
        if(strstr(s, d) != NULL)
        {
            int l = strlen(s);
            int i;
            cpr = 1;
            for (i = 0; i < l; i++)
            {
                printf("%c",s[i]);
                if (s[i] == ',')
                {
                    printf(" %s ",d);
                }                
            }
        }
        if (cpr == 0)
            printf("%s",s);
    }     
    fclose(fptr); 
    return 0; 
}
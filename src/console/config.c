#include "config.h"

char* returnvalue(char str[], char mode[])
{
	int len = strlen(mode);
	char* value = str + len;
	return value;
}

void get_template(char str[], char mode[], char value[])
{
	int len = strlen(mode);
	int i;
	for (i = len + 1; str[i] != '\n'; i++)
	{
		value[i - len - 1] = str[i];
	}
}

// //поиск символа в строке
int schr(char str[], char ch)
{
    int i, idx = -1;
    for (i = 0; (str[i] != '\0') && (str[i] != ch); i++);
    if (str[i] == ch) 
    {
        idx = i;
    }
    return idx;
}
//посимвольное сравнивание строк
int sequal(char s1[], char s2[])
{
    int i, flg = 1;
    for (i = 0; flg && (s1[i] != '\0' || s2[i] != '\0'); i++) 
    {
        if (s1[i] != s2[i])
            flg = 0;
    }
    return flg;
}

//поиск подстроки в строке
int sstr(char txt[], char p[])
{
    char *suf = txt;
    int len = strlen(p);
    int i, pos = -1;
    while (((i = schr(suf, p[0])) >= 0) && (pos < 0)) {
        char tmp;
        suf = suf + i;
        tmp = suf[len];
        suf[len] = '\0';
        if (sequal(suf, p)) {   // посимвольное сравнение строк
            pos = suf - txt;    // разность указателей = индекс
        }
        suf[len] = tmp;
        suf++;
    }
    return pos;
}

//копирование строки в строку
void copy(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\n'; i++)
        s2[i] = s1[i];
}

int confreader(char *path, PassGenOptions *options)
{
    char* buff;
    char cdef[] = "DEFAULT_MODE=";
    char ctem[] = "TEMPLATE_MODE=";
    char cstren[] = "PASS_STRENGTH="; 
    char csize[] = "PASS_SIZE=";
    char ctemplate[] = "TEMPLATE=";
    
    FILE *config = fopen(path, "r");

    if (config != NULL)
    {
      printf("OPENED\n");
       while ( !feof(config) )
       {
            int i = 0;
            buff = calloc(128, sizeof(char));
            while ((buff[i] = fgetc(config)) != '\n' && (buff[i] != EOF)) 
            {
                i++;
            }

            // printf("%s", buff);

            if ((sstr(buff, cdef) > -1))
           {
                char* value = returnvalue(buff, cdef);

                if (atoi(value) == 1)
                    options->mode = MODE_DEFAULT;
           }
           
           if ((sstr(buff, ctem) > -1) )
           {
                
                char* value = returnvalue(buff, ctem);
                
                if (atoi(value) == 1)
                    options->mode = MODE_TEMPLATE;
           }

           if ((sstr(buff, cstren) > -1))
           {
                char* value = returnvalue(buff, cstren);
                int x = atoi(value);
                options->pass_strength = x;
           }
           
          if ((sstr(buff, csize) > -1))
           {
                char* value = returnvalue(buff, csize);
                int x = atoi(value);
                options->pass_size = x;
           }
           
           if ((sstr(buff, ctemplate) > -1) && (buff[0] == 'T'))
           {
                char* t_value = calloc(128, sizeof(char));
                if (t_value != NULL)
                {
                    get_template(buff, ctemplate, t_value);                 
                    options->template = t_value;
                }
                
                free(t_value);
           }
           free(buff);       
       }
        printf("options.mode = %d\n", options->mode);
        printf("options.pass_strength = %d\n", options->pass_strength);
        printf("options.pass_size = %d\n", options->pass_size);
        printf("options.template = %s\n", options->template);
      fclose(config);    
    }       
}


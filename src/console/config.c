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
	for (i = len; str[i] != '\n'; i++)
	{
		value[i - len] = str[i];
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


#ifndef CONFIG_H
#define CONFIG_H

#include <strings.h>

//поиск символа в строке
int schr(char str[], char ch);

//разбиение строки на поля
int stok(char str[], char delim, int *ptr[]);

//посимвольное сравнивание строк
int sequal(char s1[], char s2[]);

//поиск подстроки в строке
int sstr(char txt[], char p[]);

//копирование строки в строку
void copy(char s1[], char s2[]);

//значение параметра
char* returnvalue(char *str, char *mode);

void get_template(char str[], char mode[], char value[]);

#endif
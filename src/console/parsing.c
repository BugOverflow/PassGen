#include "parsing.h"

#include <stdio.h>

int parsing(char *input, char **output)
{
	int flg = 0;
	
	if (input == NULL) {
		return -1; // нулевая строка
	}
	
	int size = strlen(input);
	char key[] = {'C', 'c', 'd' ,'s', '?', '\0'};
	char sum[] = {'0','1','2','3','4','5','6','7','8','9', '\0'};
	int i;
	//проверка входной строки на допустимые символы
	char *tmp1, *tmp2;
	
	for (i = 0; i < size; i++) {
		if (input[i] == key[4]) {
			tmp1 = strchr(&(input[i+1]),key[4]);
			if (tmp1 == NULL) {
				return -2;// не нашёл второй ?
			}
			int step = tmp1	- &(input[i]);
			i = i + step;
		}
		tmp1 = strchr(key,input[i]);
		tmp2 = strchr(sum,input[i]);
		if ((tmp1 == NULL) && (tmp2 == NULL)) {
			return -3; // символ не из словаря
		}
	}

	char *buf_key = malloc(size * sizeof(char));
	int *buf_sum = malloc(size * sizeof(int));
	
	for (i = 0; i < size; i++) {
		buf_sum[i] = 0;
	}
	
	int j = 0;
	//запись ключей в буфер
	int step;
	
	for (i = 0; i < size; i++) {
		tmp1 = strchr(key,input[i]);
		if (tmp1 != NULL) {
			if (input[i] == key[4]) {
				tmp1 = strchr(&(input[i+1]),key[4]);
				step = tmp1	- &(input[i])+1;
				memcpy(&(buf_key[j]),&(input[i]),step);
				i = i + step - 1;
				//-
				if (i + 1 != size) {
					tmp2 = strchr(sum,input[i + 1]);
					if (tmp2 != NULL) {
						buf_sum[j] = atoi(&(input[i+1]));
					}
					else {
						buf_sum[j] = 1;
					}
				}
				else {
					buf_sum[j] = 1;
				}
				//-
				j = j + step;
			}
			else {
				buf_key[j] = input[i];
				//-
				if ((i+1) != size) {
					tmp2 = strchr(sum,input[i+1]);
					if (tmp2 != NULL) {
						buf_sum[j] = atoi(&(input[i+1]));
					}
					else {
					buf_sum[j] = 1;
					}
				}	
				else {
					buf_sum[j] = 1;
				}
				//-
				j++;
			}	
		}
		else if (i == 0)
		    return -4; //первый символ не принадлежит ключам
	}
	buf_key[j] = '\0';
	
	int out_size = 0;
	
	int word = 0;
	for (i = 0; i < size; i++) {
		if (buf_key[i] == key[4]) {
			tmp1 = strchr(&(buf_key[i+1]),key[4]);
			if (tmp1 != NULL) {
				word = tmp1 - &(buf_key[i]) + 1;
				out_size = out_size + word*(buf_sum[i]);
				i = i + word-1;
			}
		}
		else {
			out_size = out_size + buf_sum[i];
		}
	}

	char* tmp = NULL;
	tmp = malloc((out_size + 1) * sizeof(char));
	if (tmp == NULL) {
		return  -1;
	}
	int y = 0;
	for (i = 0; buf_key[i] != '\0'; i++) {
		for(j = 0; j < buf_sum[i]; j++) {
			if (buf_key[i] == key[4]) {
				tmp1 = strchr(&(buf_key[i+1]),key[4]);
				step = tmp1	- &(buf_key[i])+1;
				for (int k = 0; k < buf_sum[i]; k++) {
					memcpy(&(tmp[y + j]),&(buf_key[i]),step);
					y = y + step;
				}
				y = y-1;		
				i = i + step - 1;
			}
			else
				tmp[y+j] = buf_key[i];
		}
		y = y+j;
	}
	free(buf_key);
	free(buf_sum);
	tmp[out_size] = '\0';
	*output = tmp;
	return flg;
}

#include "gen.h"

char *generator_template(char *input)
{
	char NUM[] = {'0','1','2','3','4','5','6','7','8','9'};
	char UP[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	char SYM[] = {'!','@','#','$','%','^','&','*','(',')'};
	char DOWN[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	
	char *out = malloc(sizeof(char) * strlen(input));
    int i, j = 0;
    char *str_data = malloc(sizeof(char) * size_data);
    char *h = NULL;
    data(&str_data);
    hash(str_data, &h);
    int seed;
    
    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'C':
                seed = h[(i + j % strlen(input))] % strlen(UP);
                out[i] = UP[seed];
                j++;
                break;
            case 'c':
                seed = h[(i +j % strlen(input))] % strlen(DOWN);
                out[i] = DOWN[seed];
                j++;
                break;
            case 'd':
                seed = h[(i  + j % strlen(input))] % strlen(NUM);
                out[i] = NUM[seed];
                j++;
                break;
            case 's':
                seed = h[(i + j % strlen(input))] % strlen(SYM);
                out[i] =SYM[seed];
                j++;
        }
    }
	return out;
}

char *generator_default(char *input, int complexity)
{
    return "Don't ready";
}

void data(char **str)
{
    char time[32]; // pointer on time
    char buf[size_data]; // the firsh use to Mhz
    char name[64]; // login
    char ip[32]; // IP
    
    system("who >buf.txt");
    system("ifconfig > buf2.txt");

    // Found user's login +
    FILE *foo;
    foo = fopen("buf.txt", "r");

    fscanf(foo, "%s\n", name);
    // Found user's login -

    // Found ip +
    foo = fopen("buf2.txt", "r");

    while(strcmp(ip, "inet") != 0) {
        fscanf(foo, "%s\n",  ip);
    }
    
    fscanf(foo, "%s\n", ip);
    sprintf(ip, "%s", (ip + 5)); // Delete "addr"
    //Found ip -

    // Found MHz +
    FILE *file_proc;
    file_proc = fopen("/proc/cpuinfo", "r");

     while (strcmp(buf, "MHz") != 0) {
         fscanf(file_proc, "%s", buf);
     }
     
     fscanf(file_proc, "%s", buf);
     fscanf(file_proc, "%s", buf);
    // Found MHz -

    // printf("MHZ %s\n", buf);
    // printf("Name %s\n", name);
    // printf("Ip %s\n", ip);
    sprintf(time, "%f", wtime());

    strcat(buf, name);
    strcat(buf, ip);
    strcat(buf, time);

    //printf("Reuslt %s\n", buf);
    strcpy(*str, buf);
    system("rm buf.txt buf2.txt");
    fclose(foo);
    fclose(file_proc);
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

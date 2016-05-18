#include "data.h"

char *read_pipe(FILE * input)
{
    size_t buf = 64;
    size_t readed = 0;
    char *output = calloc(buf, sizeof(char));
    while (!feof(input)) {
        if (readed == buf) {
            buf += 64;
            output = realloc(output, buf);
        }
        output[readed] = fgetc(input);
        readed++;
    }
    return output;
}

void data(char **str)
{
    char time[18];              // pointer on time
    char *name;                 // login
    char mac_buf[18];           // mac

    FILE *pipe = popen("ifconfig", "r");
    char *ifconf = read_pipe(pipe);
    pclose(pipe);

    char *HWaddr = strstr(ifconf, "HWaddr");
    memcpy(mac_buf, HWaddr + 7, 17);
    mac_buf[17] = '\0';

    pipe = popen("who", "r");
    char *login = read_pipe(pipe);
    pclose(pipe);

    name = strtok(login, " ");

    pipe = fopen("/proc/cpuinfo", "r");
    char *cpu = read_pipe(pipe);
    fclose(pipe);
    char *cpu_buf = strstr(cpu, "cpu MHz");
    cpu_buf = strtok(cpu_buf + 11, "\n");

    sprintf(time, "%f", wtime());

    char *buf = calloc(256, sizeof(char));
    memcpy(buf, mac_buf, strlen(mac_buf));
    strcat(buf, time);
    strcat(buf, name);
    strcat(buf, cpu_buf);

    *str = buf;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}

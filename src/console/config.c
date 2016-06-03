#include "config.h"

char *returnvalue(char str[], char mode[])
{
    int len = strlen(mode);
    char *value = str + len;
    return value;
}

void get_template(char str[], char mode[], char value[])
{
    int len = strlen(mode);
    int i;
    for (i = len + 1; str[i] != '\n'; i++) {
        value[i - len - 1] = str[i];
    }
}

int confreader(char *path, PassGenOptions * options)
{
    char *buff;
    char cdef[] = "DEFAULT_MODE=";
    char ctem[] = "TEMPLATE_MODE=";
    char cstren[] = "PASS_STRENGTH=";
    char csize[] = "PASS_SIZE=";
    char ctemplate[] = "TEMPLATE=";

    FILE *config = fopen(path, "r");

    if (config != NULL) {
        printf("OPENED\n");
        while (!feof(config)) {
            int i = 0;
            buff = calloc(128, sizeof(char));
            while ((buff[i] = fgetc(config)) != '\n' && (buff[i] != EOF)) {
                i++;
            }

            // printf("%s", buff);

            if ((strstr(buff, cdef) != NULL)) {
                char *value = returnvalue(buff, cdef);

                if (atoi(value) == 1)
                    options->mode = MODE_DEFAULT;
            }

            if ((strstr(buff, ctem) != NULL)) {

                char *value = returnvalue(buff, ctem);

                if (atoi(value) == 1)
                    options->mode = MODE_TEMPLATE;
            }

            if ((strstr(buff, cstren) != NULL)) {
                char *value = returnvalue(buff, cstren);
                int x = atoi(value);
                options->pass_strength = x;
            }

            if ((strstr(buff, csize) != NULL)) {
                char *value = returnvalue(buff, csize);
                int x = atoi(value);
                options->pass_size = x;
            }

            if ((strstr(buff, ctemplate) != NULL) && (buff[0] == 'T')) {
                char *t_value = calloc(128, sizeof(char));
                if (t_value != NULL) {
                    get_template(buff, ctemplate, t_value);
                    options->template = t_value;
                }

                free(t_value);
            }
            free(buff);
        }
        printf("options.mode = %d\n", options->mode);
	if (options->mode == 1) {
	    printf("options.template = %s\n", options->template);
	}
	else if (options->mode == 0){
	    printf("options.pass_strength = %d\n", options->pass_strength);
	    printf("options.pass_size = %d\n", options->pass_size);
	}
        fclose(config);
    }
}

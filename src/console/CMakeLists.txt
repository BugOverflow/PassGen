set(PASSGEN_CONSOLE_HEADERS application.h md5.h parsing.h gen.h hash.h)
set(PASSGEN_CONSOLE_SOURCES main.c md5.c parsing.c gen.c hash.c	application.c)

add_executable(${PROJECT_NAME} ${PASSGEN_CONSOLE_HEADERS} ${PASSGEN_CONSOLE_SOURCES})

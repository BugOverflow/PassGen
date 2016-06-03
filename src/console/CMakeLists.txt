set(PASSGEN_CONSOLE_HEADERS application.h
							gen.h
							hash.h
							liters.h
							md5.h
							parsing.h
							data.h
							config.h)
							
set(PASSGEN_CONSOLE_SOURCES parsing.c
							md5.c
							hash.c
							gen.c
							application.c
							data.c
							config.c
							main.c)

add_executable(${PROJECT_NAME} ${PASSGEN_CONSOLE_HEADERS} ${PASSGEN_CONSOLE_SOURCES})

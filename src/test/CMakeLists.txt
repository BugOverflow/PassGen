set(CF_TEST_HEADERS ctest.h)
set(CF_TEST_SOURCES main.c
				    ../console/parsing.c
				    parsing_test.c)
					

add_executable(${PROJECT_NAME}Test ${CF_TEST_HEADERS} ${CF_TEST_SOURCES})

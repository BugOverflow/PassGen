set(CF_TEST_HEADERS ctest.h)
set(CF_TEST_SOURCES main.c
						)
					

add_executable(${PROJECT_NAME}Test ${CF_TEST_HEADERS} ${CF_TEST_SOURCES})

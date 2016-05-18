set(CF_TEST_HEADERS ctest.h)
set(CF_TEST_SOURCES main.c
				    ../console/parsing.c
				    ../console/gen.c
				    ../console/md5.c
					../console/hash.c
					../console/application.c
					../console/data.c
				    parsing_test.c
				    template_test.c)
					

add_executable(${PROJECT_NAME}Test ${CF_TEST_HEADERS} ${CF_TEST_SOURCES})

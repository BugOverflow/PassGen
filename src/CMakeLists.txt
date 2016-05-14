add_subdirectory(console)

if(BUILD_TEST)
	add_subdirectory(test)
endif(BUILD_TEST)

if(BUILD_GUI)
	add_subdirectory(gui)
endif(BUILD_GUI)

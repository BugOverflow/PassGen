message("")
if( UNIX )
  message("* PassGen buildtype	 : ${CMAKE_BUILD_TYPE}")
endif()

# output information about installation-directories and locations

message("* Install to		 : ${CMAKE_INSTALL_PREFIX}")
message("")

# Show infomation about the options selected during configuration

if(BUILD_GUI)
  message("* Build gui		 : Yes")
  message("* Qt5 path               : ${QT_PATH}")
else()
  message("* Build gui		 : No (default)")
endif()

if(BUILD_TEST)
  message("* Build test             : Yes")
else()
  message("* Build test          : No (default)")
endif()

if(WITH_WARNINGS)
  message("* Show all warnings      : Yes")
else()
  message("* Show compile-warnings  : No (default)")
endif()
message("")

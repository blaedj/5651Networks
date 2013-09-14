cmake_minimum_required(VERSION 2.8)

add_library (cs5651-util ${LIB_TYPE}
  ArgumentParsing.cpp ArgumentParsing.h
  fileHandling.h
  handleNetworkArgs.cpp handleNetworkArgs.h
  Random.cpp Random.h
  Timer.cpp Timer.h
)

FILE(GLOB files "*.h")
INSTALL(FILES ${files} DESTINATION include/util)
INSTALL(TARGETS cs5651-util LIBRARY ARCHIVE DESTINATION lib)


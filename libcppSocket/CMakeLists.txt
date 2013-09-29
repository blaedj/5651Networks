cmake_minimum_required (VERSION 2.8)

add_library( libcppSocket ${LIB_TYPE}
  AddressNameMapper.cpp AddressNameMapper.h
  # put various library classes here
  )

## This may be needed to install and use the library
# FILE(GLOB files "*.h")
# INSTALL(FILES ${files} DESTINATION include/util)
# INSTALL(TARGETS cs5651-util LIBRARY ARCHIVE DESTINATION lib)

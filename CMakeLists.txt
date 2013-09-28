cmake_minimum_required (VERSION 2.8)

add_subdirectory(libcs5651)
add_subdirectory(Proj1)

add_library( libcppSocket ${LIB_TYPE}
  # put various library classes here
  )

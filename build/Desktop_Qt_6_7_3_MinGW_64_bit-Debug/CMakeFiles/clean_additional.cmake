# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SmartArchitect_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SmartArchitect_autogen.dir\\ParseCache.txt"
  "SmartArchitect_autogen"
  )
endif()

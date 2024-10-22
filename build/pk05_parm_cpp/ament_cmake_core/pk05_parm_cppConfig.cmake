# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_pk05_parm_cpp_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED pk05_parm_cpp_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(pk05_parm_cpp_FOUND FALSE)
  elseif(NOT pk05_parm_cpp_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(pk05_parm_cpp_FOUND FALSE)
  endif()
  return()
endif()
set(_pk05_parm_cpp_CONFIG_INCLUDED TRUE)

# output package information
if(NOT pk05_parm_cpp_FIND_QUIETLY)
  message(STATUS "Found pk05_parm_cpp: 0.0.0 (${pk05_parm_cpp_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'pk05_parm_cpp' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${pk05_parm_cpp_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(pk05_parm_cpp_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${pk05_parm_cpp_DIR}/${_extra}")
endforeach()

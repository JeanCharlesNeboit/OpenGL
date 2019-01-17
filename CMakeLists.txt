cmake_minimum_required ( VERSION 2.8.9 )

# Project #-----------------------------------------------------------------------------------------
project ( OpenGL )

# Package #-----------------------------------------------------------------------------------------
find_package ( X11 REQUIRED )

# C++11 #-------------------------------------------------------------------------------------------
include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++17" COMPILER_SUPPORTS_CPP17 )
check_cxx_compiler_flag ( "-std=gnu++14" COMPILER_SUPPORTS_CPP14 )
check_cxx_compiler_flag ( "-std=gnu++1y" COMPILER_SUPPORTS_CPP1Y )
check_cxx_compiler_flag ( "-std=gnu++11" COMPILER_SUPPORTS_CPP11 )
check_cxx_compiler_flag ( "-std=gnu++0x" COMPILER_SUPPORTS_CPP0X )

if ( COMPILER_SUPPORTS_CPP17 )
  set ( CMAKE_CXX_FLAGS "-std=gnu++17 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP14 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP1Y )
 set ( CMAKE_CXX_FLAGS "-std=gnu++1y ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP11 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}" )
elseif( COMPILER_SUPPORTS_CPP0X )
 set ( CMAKE_CXX_FLAGS "-std=gnu++0x ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++11/14 support." )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_REQUIRED_FLAGS -std=c++17)

# Libraries #---------------------------------------------------------------------------------------
add_subdirectory (${CMAKE_SOURCE_DIR}/lib/glfw)
add_subdirectory (${CMAKE_SOURCE_DIR}/lib/assimp)
add_subdirectory (${CMAKE_SOURCE_DIR}/lib/glm)

# Includes #----------------------------------------------------------------------------------------
configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

include_directories (${CMAKE_SOURCE_DIR}/include)
include_directories (${CMAKE_SOURCE_DIR}/lib/glfw/include)
include_directories (${CMAKE_SOURCE_DIR}/lib/assimp/include)
include_directories (${CMAKE_SOURCE_DIR}/lib/glm/glm)

# Sources #-----------------------------------------------------------------------------------------
set ( HEADERS_FILES
  include/shader.hpp
  include/vertex.hpp
  include/texture.hpp
  include/mesh.hpp
  include/model.hpp
  include/stb/stb_image.h
  include/camera.hpp
  include/filesystem.hpp
  configuration/root_directory.h
)

set ( SOURCES_FILES
  src/shader.cpp
  src/mesh.cpp
  src/model.cpp
  src/stb/stb_image.cpp
  src/camera.cpp
  src/scene/mainscene.cpp
)

# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}_exe
                 src/glad.c
                 src/main.cpp
                 ${HEADERS_FILES}
                 ${SOURCES_FILES}
)

# Build #-------------------------------------------------------------------------------------------
set_target_properties ( ${CMAKE_PROJECT_NAME}_exe PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_exe glfw assimp::assimp glm ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} )

# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("SFML")
# 包含子项目。

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Dubug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

#一下两行用于copy其他dll到输出目录
#file(COPY ${<some_var>}
   # DESTINATION ${EXECUTABLE_OUTPUT_PATH})
# set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/SFML/;${CMAKE_MODULE_PATH}")
#set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR "./lib")
#find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
#find_package(SFML REQUIRED)

#macro(build_chapter CHAPTER_NAME)

	
	#parse_argument_list("CHAPTER" "SOURCES" "${ARGN}")

	# Status output
	#message(STATUS "-> Chapter ${CHAPTER_NAME}")


	#set(CHAPTER_DIR "${PROJECT_SOURCE_DIR}/..")
	#include_directories("${CHAPTER_DIR}//Include")

	# Executable: Add only Main.cpp, set name without _EXE postfix
	#add_executable(${PROJECT_NAME} Main.cpp ${CHAPTER_SOURCES})
	#set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${CHAPTER_NAME})

	# Build static or shared libraries? Set chapter-specific DLL import macro
	#if(SFML_STATIC_LIBRARIES)
		#set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS "SFML_STATIC")
	#endif()

	# Link SFML
	#target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

	#install(TARGETS ${PROJECT_NAME}	RUNTIME DESTINATION ${CHAPTER_NAME})

	#install(DIRECTORY ${CHAPTER_DIR}/Media
			#DESTINATION ${PROJECT_NAME}
			#PATTERN "CMakeLists.txt" EXCLUDE)
#endmacro()



add_subdirectory ("SFML")
add_subdirectory ("terris")

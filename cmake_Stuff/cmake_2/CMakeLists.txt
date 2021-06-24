#cmake -S source_folder_path -B build_folder_path -> generates Makefile
cmake_minimum_required(VERSION 3.16.3)

project(cmake_2) #set PROJECT_NAME

add_executable(${PROJECT_NAME} main.cpp) # tell cmake to build an excutable 
#with same name as project name using the main.cpp source file

# running `make` in the folder that contains Makefile will build the project
# this should spit out "Build target ${PROJECT_NAME}"
target_include_directories(${PROJECT_NAME} PUBLIC functions)
target_link_directories(${PROJECT_NAME} PRIVATE functions/)
add_subdirectory(functions) # add library folder and build
target_link_libraries(${PROJECT_NAME} functions) #link library to project

#UNDERSTANDING CMAKE SCOPE
#For some uiser created library A that uses the Boost library:
#target_include_directories(A PRIVATE ${Boost_INCLUDE_DIRS}) if you only use those Boost headers inside your source files (.cpp) or private header files (.h).
#target_include_directories(A INTERFACE ${Boost_INCLUDE_DIRS}) if you don't use those Boost headers inside your source files (therefore, not needing them to compile A). I can't actually think of a real-world example for this.
#target_include_directories(A PUBLIC ${Boost_INCLUDE_DIRS}) if you use those Boost headers in your public header files, which are included BOTH in some of A's source files and might also be included in any other client of your A library.
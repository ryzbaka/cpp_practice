#cmake -S source_folder_path -B build_folder_path -> generates Makefile
cmake_minimum_required(VERSION 3.16.3)

project(cmake_1) #set PROJECT_NAME

add_executable(${PROJECT_NAME} main.cpp) # tell cmake to build an excutable with same name as project name using the main.cpp source file

# running `make` in the folder that contains Makefile will build the project -> "Build target ${PROJECT_NAME}"
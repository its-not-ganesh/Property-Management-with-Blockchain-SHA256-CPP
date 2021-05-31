cmake_minimum_required(VERSION 3.15)
project(OOPS_COURSE_Project)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp)

add_executable(OOPS_COURSE_Project main.cpp sha256.h sha256.cpp errorException.h Date.h Adhaar.h Person.h Property.h TransactionData.h Block.h BlockChain.h Property_Db.h SuperUser.h)
cmake_minimum_required(VERSION 3.12)
project(lrparser)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

message("hi\n")
message(${lrparser_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#add_custom_target(calc COMMAND make -C ${lrparser_SOURCE_DIR}
#        CLION_EXE_DIR=${PROJECT_BINARY_DIR} && cp ${lrparser_SOURCE_DIR}/calc ./
#        )
include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(BISON)
BISON_TARGET(MyParser calc3.y ${CMAKE_CURRENT_BINARY_DIR}/calc3.tab.c)


find_package(FLEX)
FLEX_TARGET(MyScanner calc3.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)

message(${BISON_MyParser_OUTPUTS})
add_executable(calc main.c ast.c ${BISON_MyParser_OUTPUTS} ${FLEX_MyScanner_OUTPUTS})
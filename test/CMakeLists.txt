cmake_minimum_required(VERSION 3.10)

set(This exampleTests)

add_subdirectory(
	../gtest
	${PROJECT_BINARY_DIR}/gtest
)
include(CTest)

add_executable(${This} exampleTests.cpp)


target_link_libraries(${This} PUBLIC
	gtest gtest_main
	ticTacToe
)

add_test(
	NAME ${This}
	COMMAND ${This}
)


#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

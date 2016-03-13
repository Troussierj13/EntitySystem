CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(test_EntitySystem C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT bin/${CMAKE_BUILD_TYPE})

find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

file(
	GLOB_RECURSE
	sourceFiles
	./src/*.cpp
	)

file(
	GLOB_RECURSE
	includeFiles
	./include/*.hpp
	)

include_directories(include/)
add_executable(${PROJECT_NAME} ${includeFiles} ${sourceFiles})

target_link_libraries(
    ${PROJECT_NAME}
    Storm-Log
    Storm-Core
    Storm-Config
    Storm-State
    Storm-Entity
    ${SFML_LIBRARIES}
)

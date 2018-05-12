cmake_minimum_required(VERSION 3.0)

PROJECT(entrega1
	LANGUAGES C
VERSION 0.1.0)

INCLUDE(./cmake/CMakeBuildFlags.cmake)

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    set(LIBOPENMP "${OpenMP_C_FLAGS}")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()

enable_testing()
add_subdirectory("ejercicio1")
add_subdirectory("ejercicio2")

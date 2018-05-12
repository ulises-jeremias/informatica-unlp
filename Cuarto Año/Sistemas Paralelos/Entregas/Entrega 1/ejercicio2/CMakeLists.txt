include_directories(${CMAKE_SOURCE_DIR}/ejercicio2)

add_executable(ejercicio2_secuencial secuencial.c)
add_executable(ejercicio2_pthread pthread.c)
add_executable(ejercicio2_openmp openmp.c)

target_link_libraries(ejercicio2_pthread ${LIBTHREADS})
target_link_libraries(ejercicio2_openmp pthread)

add_test(NAME ejercicio2_secuencial_32 COMMAND ejercicio2_secuencial 32)
add_test(NAME ejercicio2_pthread_32_2 COMMAND ejercicio2_pthread 32 2)
add_test(NAME ejercicio2_pthread_32_4 COMMAND ejercicio2_pthread 32 4)
add_test(NAME ejercicio2_openmp_32_2 COMMAND ejercicio2_openmp 32 2)
add_test(NAME ejercicio2_openmp_32_4 COMMAND ejercicio2_openmp 32 4)

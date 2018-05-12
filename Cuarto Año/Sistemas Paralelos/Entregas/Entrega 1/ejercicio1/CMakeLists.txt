include_directories(${CMAKE_SOURCE_DIR}/ejercicio1)

add_executable(ejercicio1_secuencial matrix.c secuencial/main.c)
add_executable(ejercicio1_pthread matrix.c pthread/main.c)
add_executable(ejercicio1_openmp matrix.c openmp/main.c)

target_link_libraries(ejercicio1_pthread ${LIBTHREADS})
target_link_libraries(ejercicio1_openmp pthread)

add_test(NAME ejercicio1_secuencial_512 COMMAND ejercicio1_secuencial 16 32)
add_test(NAME ejercicio1_secuencial_1024 COMMAND ejercicio1_secuencial 32 32)
add_test(NAME ejercicio1_secuencial_2048 COMMAND ejercicio1_secuencial 32 64)

add_test(NAME ejercicio1_pthread_512_2 COMMAND ejercicio1_pthread 16 32 2)
add_test(NAME ejercicio1_pthread_1024_2 COMMAND ejercicio1_pthread 32 32 2)
add_test(NAME ejercicio1_pthread_2048_2 COMMAND ejercicio1_pthread 32 64 2)
add_test(NAME ejercicio1_pthread_512_4 COMMAND ejercicio1_pthread 16 32 4)
add_test(NAME ejercicio1_pthread_1024_4 COMMAND ejercicio1_pthread 32 32 4)
add_test(NAME ejercicio1_pthread_2048_4 COMMAND ejercicio1_pthread 32 64 4)

add_test(NAME ejercicio1_openmp_512_2 COMMAND ejercicio1_openmp 16 32 2)
add_test(NAME ejercicio1_openmp_1024_2 COMMAND ejercicio1_openmp 32 32 2)
add_test(NAME ejercicio1_openmp_2048_2 COMMAND ejercicio1_openmp 32 64 2)
add_test(NAME ejercicio1_openmp_512_4 COMMAND ejercicio1_openmp 16 32 2)
add_test(NAME ejercicio1_openmp_1024_4 COMMAND ejercicio1_openmp 32 32 2)
add_test(NAME ejercicio1_openmp_2048_4 COMMAND ejercicio1_openmp 32 64 2)

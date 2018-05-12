include_directories(${CMAKE_SOURCE_DIR}/ejercicio1)

add_executable(ejercicio1_secuencial matrix.c secuencial/main.c)
add_executable(ejercicio1_pthread matrix.c pthread/main.c)
add_executable(ejercicio1_openmp matrix.c openmp/main.c)

target_link_libraries(ejercicio1_pthread ${LIBTHREADS})
target_link_libraries(ejercicio1_openmp pthread)

add_test(NAME ejercicio1_secuencial COMMAND ejercicio1_secuencial 32 32)
add_test(NAME ejercicio1_pthread COMMAND ejercicio1_pthread 32 32 2)
add_test(NAME ejercicio1_openmp COMMAND ejercicio1_openmp 32 32 2)

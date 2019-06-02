#!/usr/bin/env bash

# Desarrolle un script que guarde en un arreglo todos los archivos del directorio actual (incluyendo
# sus subdirectorios) para los cuales el usuario que ejecuta el script tiene permisos
# de ejecución. Luego, implemente las siguientes funciones:
# (a) cantidad: Imprime la cantidad de archivos que se encontraron
# (b) archivos: Imprime los nombres de los archivos encontrados en orden alfabético

arreglo=(`find . -type f -perm -111`)

# Las funciones en bash son como comandos nuevos, y al igual que los scripts
# reciben parámetros por posición (se los accede mediante las variables $1, $2,
# ..., $9, $* y $#).

cantidad(){
    echo "${#arreglo[@]}"	
}

archivos(){
    IFS=$'\n' sorted=($(sort <<<"${arreglo[*]}"))
    echo "${sorted[@]}"
}
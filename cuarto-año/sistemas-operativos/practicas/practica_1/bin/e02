#!/usr/bin/env bash

# Implemente un script que reciba como parámetro el nombre de un proceso e informe cada 15 segundos cuántas instancias de ese proceso están en ejecución.

while : ; do
  pgrep $1 | wc -l
  sleep 15s
done
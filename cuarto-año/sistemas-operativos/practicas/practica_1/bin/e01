#!/usr/bin/env bash

# Relice un script que guarde en el archivo /tmp/usuarios los nombres de los usuarios del
# sistema cuyo UID sea mayor a 1000.

while IFS=':' read user passwd uid gid full home shell;  do
    if [ $uid -gt 1000 ] ; then
        echo $user >> /tmp/usuarios
    fi
done < /etc/passwd
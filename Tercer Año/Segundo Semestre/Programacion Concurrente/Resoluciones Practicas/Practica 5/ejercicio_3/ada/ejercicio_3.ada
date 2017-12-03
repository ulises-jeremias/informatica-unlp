Procedure Buscador IS

    TASK Contador IS
        ENTRY numeroABuscar(numero: IN Integer);
    END Contador

    TASK Administrador IS
        ENTRY cantidadEncontrada(cantidad: IN Integer)
    END Administrador

    TYPE Contadores IS ARRAY (1..N) OF Contador;

    TASK BODY Contador IS
        mi_parte IS ARRAY (1..C) OF Integer;
        coincidencias: Integer;
        coincidencias := 0;

        BEGIN
            ACCEPT numeroABuscar(num) DO
                numeroABuscar := num;
            END numeroABuscar;

            FOR I IN 1..C LOOP
                IF (mi_parte(i) = numeroABuscar) THEN
                    coincidencias := coincidencias + 1;
                END IF
            END LOOP

            Administrador.cantidadEncontrada(coincidencias);
        END Contador

    TASK BODY Administrador IS
        numeroABuscar: Integer;

        BEGIN
            numeroABuscar:= random();
            FOR I IN 1..N LOOP
                Contadores(I).numeroABuscar(numeroABuscar);
            END LOOP

            FOR I IN 1..N LOOP
                ACCEPT cantidadEncontrada(cantidad) DO
                    total := total + cantidad;
                END cantidadEncontrada;
            END LOOP
        END Administrador
END Buscador;

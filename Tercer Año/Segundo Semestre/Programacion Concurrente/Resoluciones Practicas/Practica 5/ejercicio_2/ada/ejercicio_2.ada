PROCEDURE Banco IS

    TASK TYPE Cliente;

    TASK Empleado IS
        ENTRY cliente_solicita_atencion;
    END Empleado;

    TASK BODY Empleado IS
    BEGIN
        LOOP
            ACCEPT cliente_solicita_atencion DO
                atender();
            END cliente_solicita_atencion;
        END LOOP;
    END Empleado;

    TASK BODY Cliente IS
    BEGIN
        SELECT Empleado.cliente_solicita_atencion;
        OR DELAY 10.0*60;
        END SELECT;
        irse();
    END Cliente;

BEGIN
    null;
END Banco;

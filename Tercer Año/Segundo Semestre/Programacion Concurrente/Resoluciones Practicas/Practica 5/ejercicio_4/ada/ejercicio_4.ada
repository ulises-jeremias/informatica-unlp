procedure BaseDeDatos is

    task type Tipo1;
    task type Tipo2;
    task type Tipo3;

    task DataBase is
        entry pedido_escritura;
        entry finalizar_escritura;
        entry pedido_lectura;
        entry finalizar_lectura;
    end;

    task body DataBase is
        cantProcesos: Integer;
        cantLeyendo: Integer;

        begin
            loop
                select
                    when (pedido_escritura'COUNT = 0 ) =>
                        accept pedido_lectura;
                        cantLeyendo:= cantLeyendo + 1;
                or
                    accept finalizar_lectura;
                    cantLetendo:= cantLeyendo - 1;
                or
                    when (cantLeyendo = 0) =>
                        accept pedido_escritura;
                        accept finalizar_escritura;
                end select;
            end loop;
        end;

        TASK BODY Tipo1 IS
            BEGIN
                LOOP
                    SELECT
                        Base.pedido_escritura;
                        escribir();
                        Base.finalizar_escritura;
                    OR DELAY 2*60;
                        DELAY 5*60;
                    END SELECT
                END LOOP
            END Tipo1

        TASK BODY Tipo2 IS
            BEGIN
                LOOP
                    SELECT
                        Base.pedido_escritura;
                        escribir();
                        Base.finalizar_escritura;
                    OR DELAY 5*60;
                        SELECT
                            Base.pedido_lectura;
                            leer();
                            Base.finalizar_lectura;
                        OR DELAY 5*60;
                        END SELECT
                    END SELECT
                END LOOP
            END Tipo2;

        TASK BODY Tipo3 IS
            BEGIN
                LOOP
                    SELECT
                        Base.pedido_lectura;
                        leer();
                        Base.finalizar_lectura;
                    ELSE
                        Base.pedido_escritura;
                        escribir();
                        Base.finalizar_escritura;
                    END SELECT
                END LOOP
            END Tipo3;

end BaseDeDatos;

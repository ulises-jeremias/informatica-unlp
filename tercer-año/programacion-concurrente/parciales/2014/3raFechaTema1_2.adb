procedure Estadistica is
    task type Sede is
        entry calcularCantidadParaEnfermedad(e: IN String);
    end Sede;

    type Sedes is array(1..15) of Sede;

    task Central is
        entry enviarCantidad(cant: IN Integer);
    end Central;

    task Central is
        e: String;
        total: Integer := 0;
        cant: Integer;
        begin
            loop
                e := ElegirEnfermedad();
                for I in 1..15 loop
                    Sedes(I).calcularCantidadParaEnfermedad(e);
                end loop;

                for I in 1..15 loop
                    accept enviarCantidad(cant: IN Integer) is
                        total += cantidad;
                    end;
                end loop;
            end loop;
        end;

    task Sede is
        cant: Integer;
        begin
            loop
                accept calcularCantidadParaEnfermedad(e: IN String);
                cant := ElegirEnfermedad(e);
                Central.enviarCantidad(cant);
            end loop;
        end;
begin -- ${1/([a-zA-Z0-9_]*).*$/Estadistica/}
    null;
end ${1/([a-zA-Z0-9_]*).*$/Estadistica/};

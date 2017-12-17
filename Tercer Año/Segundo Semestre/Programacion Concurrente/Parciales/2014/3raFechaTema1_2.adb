procedure Estadistica is
    task type Sede is
        entry calcularCantidad(e: IN String, cant: OUT Integer);
    end Sede;

    type Sedes is array(1..15) of Sede;

    task Central;
    task Central is
        e: String;
        total: Integer := 0;
        cant: Integer;
        begin
            for I in 1..15 loop
                e := ElegirEnfermedad();
                Sedes(I).calcularCantidad(e, cant);
                total += cant;
            end loop;
        end;

    task Sede is
        begin
            accept calcularCantidad(e: IN String, cant: OUT Integer) is
                cant = ElegirEnfermos(e);
            end;
        end;
begin -- ${1/([a-zA-Z0-9_]*).*$/Estadistica/}
    null;
end ${1/([a-zA-Z0-9_]*).*$/Estadistica/};

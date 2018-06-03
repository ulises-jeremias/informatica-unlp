procedure Seniales is
    task type Process1;
    task type Process2;

    task Timer is
        entry init;
    end Timer;

    task Central is
        entry enviaSenial1(senial1: IN String);
        entry enviaSenial2(senial2: IN String);
        entry finishTime;
    end Central;

    task body Timer is
    begin
        accept init do
          null;
        end;
          delay(3.0*60);
          Central.finishTime;
    end Timer;

    task body Central is
    senial1: String := "";
    endTime: boolean := false;
    begin
        accept enviaSenial1(senial1: IN String) do
          null;
        end enviaSenial1;

        loop
            select
                accept enviaSenial1(senial1: IN String) do
                  null;
                end;
            or
                accept enviaSenial2(senial2: IN String) do
                  null;
                end;
                Timer.init;

                while not endTime loop
                    select
                        when (finishTime 'count = 0) =>
                            accept enviaSenial2(senial2: IN String) do
                              null;
                            end enviaSenial2;
                    or
                        accept finishTime;
                        endTime := true;
                    end select;
                end loop;
            end select;
        end loop;
    end Central;

    task body Process1 is
    senial: CONSTANT string := "Puto el que lee";
    begin
        loop
            select
                Central.enviaSenial1(senial);
            or
                delay(2.0*60);
            end select;
        end loop;
    end Process1;

    task body Process2 is
    envioExitoso: Boolean;
    senial: String := "";
    begin
        while not envioExitoso loop
            select
                Central.enviaSenial2(senial);
                envioExitoso := true;
            else
                delay(60.0);
            end select;
        end loop;
    end Process2;


begin
  null;
end Seniales;

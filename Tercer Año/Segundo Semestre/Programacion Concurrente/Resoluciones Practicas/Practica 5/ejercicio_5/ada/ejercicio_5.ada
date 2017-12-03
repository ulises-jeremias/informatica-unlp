procedure Señales is
    task type Process1;
    task type Process2;
    task type Timer;

    task Central is
        entry enviaSeñal1(señal1: IN señal);
        entry enviaSeñal2(señal2: IN señal);
        entry finishTime();
    end Central;

    task body Central is
    begin
        accept enviaSeñal1(señal1);

        loop
            select
                accept enviaSeñal1(señal1);
            or
                accept enviaSeñal2(señal2);
                Timer.init();

                while !endTime loop
                    select
                        when count' finishTime() = 0 => accept enviaSeñal2(señal);
                    or
                        accept endTime();
                        endTime := true;
                    end select;
                end loop;
            end select;
        end loop;
    end Central;

    task body Process1 is
    begin
        loop
            señal := generarSeñal();
            select
                enviaSeñal1(señal);
            or
                delay(2*60);
            end select;
        end loop;
    end Process1;

    task body Process2 is
    envioExitoso: Boolean;
    begin
        while !envioExitoso loop
            select
                Centrar.enviaSeñal2(señal);
                envioExitoso := true;
            else
                delay(60);
            end select;
        end loop;
    end Process2;

    task Timer is
    begin
        entry init();
    end Timer;

    task body Timer is
    begin
        accept init();
        delay(3*60);
        Central.finishTime();
    end Timer;


begin -- ${1/([a-zA-Z0-9_]*).*$/Señales/}
    -- Main program
end ${1/([a-zA-Z0-9_]*).*$/Señales/};

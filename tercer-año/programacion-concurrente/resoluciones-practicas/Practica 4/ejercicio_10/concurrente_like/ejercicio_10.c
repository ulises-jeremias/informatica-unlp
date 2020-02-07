process Empleado
{
        int personaId;
        string personaEstado;

        while (true) {
                Cola!empleadoPidePersona();
                Cola?desencolarPersona(personaId);
                EstadoPersona[personaId]!empleadoConsultaEstado();
                if (EstadoPersona[personaId]?empleadoRecibeEstado(personaEstado)) -> {
                        if (personaEstado != "atendido") {
                                EstadoPersona[personaId]!empleadoSetteaEstado("atendido");
                                atenderPersona(idPersona);
                                Persona[idPersona]!esperarAtencion();
                        }
                }
        }
}

process Cola
{
        int personaId;
        cola colaPersonas

        while (true) {
                if (Persona?encolarPersona(personaId)) -> {
                        encolar(colaPersonas, personaId);
                } [](!empty(colaPersonas); Empleado?empleadoPidePersona()) -> {
                        Empleado!desencolarPersona(desencolar(colaPersonas));
                }
        }
}

process EstadoPersona[i = 1..P]
{
        string estado = "esperando";

        do Empleado?empleadoConsultaEstado() -> {
                Empleado!empleadoRecibeEstado(estado);
                Empleado?empleadoSetteaEstado(nuevoEstado);
                estado = nuevoEstado;
                Persona[i]!resultadoEspera(estado);
        } [] Timer?timerConsultaEstado() -> {
                Timer!timerRecibeEstado(estado);
                Timer?timerSetteaEstado(nuevoEstado);
                estado = nuevoEstado;
                Persona[i]!resultadoEspera(estado);
        }
}

process Timer[i = 1..P]
{
        string personaEstado;

        Persona?iniciarTimer();
        delay(10*60);

        EstadoPersona[i]!timerConsultaEstado();
        if (EstadoPersona[i]?TimerRecibeEstado(personaEstado)) -> {
                if (personaEstado == "esperando") {
                        EstadoPersona[i]!timerSetteaEstado("irse");
                }
        }
}

process Persona[i = 1..P]
{
        string estado;

        Timer[i]!iniciarTimer();
        Cola!encolarPersona(i);
        EstadoPersona[i]?resultadoEspera(estado);

        if (estado == "atendido") {
                Empleado?esperarAtencion();
        }
}

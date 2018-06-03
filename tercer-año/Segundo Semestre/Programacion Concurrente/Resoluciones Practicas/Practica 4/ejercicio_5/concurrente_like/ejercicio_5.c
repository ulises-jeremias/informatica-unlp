chan startTimer[1..N]();
chan timer[1..N]();
chan llegaPersona(int id);
chan estadoPersona[1..N](string estado);
chan avisarPersona[1..N]();

process Persona[i = 1..N]
{
        send startTimer[i]();
        receive timer[i]();
        send llegaPersona(i);
        send estadoPersona[i]('esperando');
        receive avisarPersona[i]();
}

process Timer[i = 1..N]
{
        receive startTimer[i]();
        send timer[i]();
        delay(15*60);
        receive estadoPersona[i](estado);
        if (estado == 'esperando') {
                send estadoPersona[i]('yendo');
                send avisarPersona[i]();
        }
}

process Empleado[i = 1..2]
{
        int id;
        string estado;

        while (true) {
                receive llegaPersona(id);
                receive estadoPersona[id](estado);
                if (estado == 'esperando') {
                        send estadoPersona[id]('atendido');
                        // empleado atiende a la persona
                        send avisarPersona[id]();
                }
        }
}

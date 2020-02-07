process Cliente[i = 1..C]
{
        Coordinador !avisarLlegada(i);
        Empleado ? liberar();
}

process Coordinador
{
        queue cola;
        int id;

        while (true) {
                if (Cliente[*]?avisarLlegada(id)) -> {
                        encolar(cola, id);
                } [](!empty(cola); Empleado[*]?libre(id)) -> {
                        Empleado[id]!atender(desencolar(cola));
                }
        }
}

process Empleado[i = 1..3]
{
        int cliente;

        while (true) {
                Coordinador!libre(i);
                Coordinador?atender(cliente);
                atender(cliente);
                Cliente[cliente]!liberar();
        }
}

// Cola de tareas precargada
cola tareas;
sem llegada = 1;
sem tarea = 0;
sem access = 1;
int empleado[E] = ([E] 0);
int presentes = 0;

Process Empleado[i = 1..E]
{
        int local_counter, i;
        int t;
        P(llegada);
        presentes++;
        local_counter = presentes;
        V(llegada);

        // BARRERA

        if (local_counter = E) {
                for (i = 0; i < E; i++) {
                        V(tarea);
                }
        } else {
                P(tarea);
        }

        // FIN BARRERA

        P(access);
        while (!empty(tareas)) {
                t = desencolar(tareas);
                V(access);
                // hago tarea
                empleado[i]++;
                P(access);
        }
        V(access);
}

Process Main
{
        int winner, i;
        while (!empty(tareas)) ;

        for (i = 0; i < E; i++) {
                if (empleado[i] > winner) {
                        winner = empleado[i];
                }
        }

        // dar premio
}

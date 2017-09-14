sem choise = 1;
sem entrega[10] = ([10] 1);
sem maestra[10] = ([10] 5);
cola entregas;
cola tareas[10];
int alumnos[50];
int cant = 10;

Process Alumno[i = 1..50]
{
        int tarea;
        P(choise);
        alumnos[i] = tarea = elegir();
        V(choise);
        // hacer tarea
        P(entrega[tarea]);
        encolar(entregas, i);
        encolar(tareas[tarea], i);
        V(entrega[tarea]);
        P(maestra[tarea]);
}

Process Maestra
{
        while (cant != 0) {
                if (empty(entregas)) {
                        continue;
                }

                int id = desencolar(entregas);
                int tarea = alumnos[id];

                if (size(tareas[tarea]) != 5) {
                        continue;
                }

                for (int i = 1; i <= 5; i++) {
                        int alumno = desencolar(tareas[tarea]);
                        // dar puntaje
                        V(maestra[tarea]);
                }

                cant--;
        }
}

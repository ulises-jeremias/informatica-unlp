sem choise = 1;
sem maestra[50] = ([50] 1);
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
        encolar(entregas, i);
        encolar(tareas[tarea], i);
        P(maestra[i]);
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
                }

                cant--;
        }
}

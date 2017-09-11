sem tarea[40] = ([40] 0);
sem maestra[40] = ([40] 0);
boolean correcciones[40] = ([40] false);
cola entregas;
int cant = 40;

Process alumnos[i = 1..40]
{
        while(!correcciones[i]){
                P(tareas[i]);
                // Hago tarea
                encolar(entregas, i);
                V(tareas[i]);
                P(maestra[id]);
        }
}

Process maestra
{
        for(int i = 1; i < 40; i++){
                V(tarea[i]);
        }

        while(cant != 0){
                if(empty(entregas)) {
                        continue;
                }
                int id = desencolar(entregas);
                P(tareas[id]);
                if(//tarea es correcta){
                        cant--;
                        correcciones[id] = true;
                }
    
                V(tarea[id]);
                V(maestra[id]);  
        }
}

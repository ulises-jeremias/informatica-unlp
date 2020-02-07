int grupo = 1;
int personas = 0;
int current_tarea = 1;
int elementos_restantes[N] = ([N] X);
int elementos_terminados[N] = ([N] 0);
sem s_llegada = 1;
sem s_hacer_elemento[N] = 1;
sem s_hacer_tarea[N] = ([N] 0);
sem s_retirada[N] = ([N] 0);

Process Operario[i = 1..M]
{
        int cant_personas, mi_grupo, tarea;
        P(s_llegada);
        mi_grupo = grupo;
        P(cant_personas);
        cant_personas = personas++;
        V(cant_personas);
        if (cant_personas = M/N) {
                for (int i = 1; i <= cant_personas; i++) {
                        V(s_hacer_tarea[i]);
                }
                grupo++;
                personas = 0;
        }
        V(s_llegada);

        P(s_hacer_tarea[mi_grupo]);
        tarea = tarea();

        P(s_hacer_elemento[tarea]);
        while (elementos[tarea] > 0) {
                elementos_restantes[tarea]--;
                V(s_hacer_elemento[tarea]);
                // hacer elemento
                P(s_hacer_elemento[tarea]);
                elementos_terminados[tarea]++;
        }
        if (elementos_terminados[tarea] == X) {
                for (int i = 1; i < M/N; i++) {
                        V(s_retirada[tarea]);
                }
        }
        V(s_hacer_elemento[tarea]);

        P(s_retirada[tarea]);
}

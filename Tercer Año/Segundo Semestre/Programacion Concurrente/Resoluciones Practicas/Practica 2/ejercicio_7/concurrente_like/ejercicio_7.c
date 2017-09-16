sem s_access = 1;
sem s_timer[P] = ([P] 1);
sem s_state_mod[P] = ([P] 1);
sem s_espera[P] = ([P] 0);
sem s_atender = 0;
sem s_llega_cliente = 0;
int state[P] = ([P] 1);
cola personas;

Process Timer[i = 1..P]
{
        P(s_timer[i]);
        delay(10);
        P(s_state_mod[i]);
        state[i]--;
        V(s_state_mod[i]);
        V(s_espera[i]);
}

Process Persona[i = 1..P]
{
        int stado;
        P(s_access);
        encolar(personas, i);
        V(s_access);
        V(s_timer[i]);
        V(s_llega_cliente);
        P(s_espera[i]);
        P(s_state_mod[i]);
        stado = state[i];
        V(s_state_mod[i]);
        if (!state) {
                P(s_access);
                desencolar(personas);
                V(s_access);
        } else {
                P(s_atender);
        }
}

Process Empleado
{
        int id, state;

        while (true) {
                P(s_llega_cliente);
                P(s_access);
                id = desencolar(personas);
                V(s_access);
                P(s_state_mod[id]);
                state = state[id];
                V(s_state_mod[id]);
                if (state) {
                        V(s_espera[id]);
                        // atender persona
                        V(s_atender);
                }

        }
}

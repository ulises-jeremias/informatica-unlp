sem semaphore = 6;
sem alta = 4;
sem baja = 5;

Process usuario_alta[i = 1 to L]
{
        P(alta);
        P(semaphore);
        // Usa la BD
        V(semaphore);
        V(alta);
}

Process usuario_baja[i = 1 to K]
{
        P(baja);
        P(semaphore);
        // Uso la BD
        V(semaphore);
        V(baja);
}

sem semaphore = 1;

Process pasajero[i = 1 to N]
{
        P(semaphore);
        // Hacer cosas
        V(semaphore);
}

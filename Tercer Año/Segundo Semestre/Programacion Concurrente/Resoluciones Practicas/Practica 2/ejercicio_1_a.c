sem semaphore = 1;

Process pasajero[i = 1..N]
{
        P(semaphore);
        // detector
        V(semaphore);
}

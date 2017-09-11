sem semaphore = 3;

Process pasajero[i = 1..N]
{
        P(semaphore);
        // detector
        V(semaphore);
}

sem semaphore = 3;

Process pasajero[i = 1 to N]
{
        P(semaphore);
        // detector
        V(semaphore);
}

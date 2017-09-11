sem semaphore = 5;
recurso recursos[5];

Process Recurso[i = 1..N]
{
        P(semaphore);
        recurso r = desencolar(recursos);
        // utilizar recurso
        encolar(recursos, r);
        V(semaphore);
}

sem habilitador[1..10] = ([10], 0);
sem trabajar[1..10] = ([10], 0);
sem finalizado[1..10] = ([10], 0);
int resultado;

process Central
{
        int i, e;

        for (i = 0; i < 10; i++) {
                p(habilitador[i]);
        }

        while (true) {
                e = TrabajaProcesoCentral();
                v(trabajar[e]);
                p(finalizado[e]);
                printf("%d\n", resultado);
        }
}

process Sede[int i = 1..10]
{
        v(habilitador[i]);

        while (true) {
                p(trabajar[i]);
                resultado = trabajar();
                v(finalizado[i]);
        }
}

chan llegaCorredor();
chan puedenLargar();

process Portero
{
        for (int i = 0; i < C; i++) {
                receive llegaCorredor();
        }

        for (int i = 0; i < C; i++) {
                send puedenLargar();
        }
}

process Corredor[i = 1..C]
{
        send llegaCorredor();
        receive puedenLargar();
}

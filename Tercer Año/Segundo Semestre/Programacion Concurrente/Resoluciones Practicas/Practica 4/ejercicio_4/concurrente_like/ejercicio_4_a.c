chan llegaCorredor();
chan puedenLargar();
chan llegaronTodos();

process Portero
{
        receive llegaronTodos();
        for (int i = 0; i < C; i++) {
                send puedenLargar();
        }
}

process Coordinador
{
        for (int i = 0; i < C; i++) {
                receive llegaCorredor();
        }
        send llegaronTodos();
}

process Corredor[i = 1..C]
{
        send llegaCorredor();
        receive puedenLargar();
}

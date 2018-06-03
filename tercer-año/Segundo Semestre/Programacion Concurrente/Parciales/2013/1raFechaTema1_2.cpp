process Servidor
{
        int cantidad = 10;

        do (cantidad; Usuario[*]?solicitarEntrar()) -> {
                cantidad--;
        } [](Usuario[*]?finalizar()) -> {
                cantidad++;
        }
}

process Usuario[int i = 1..N]
{
        Servidor!solicitarEntrar();
        // trabajando
        Servidor!finalizar();
}

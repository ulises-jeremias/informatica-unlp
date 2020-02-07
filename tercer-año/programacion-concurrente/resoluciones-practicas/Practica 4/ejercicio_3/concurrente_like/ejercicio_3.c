chan llegoCliente(int id, int pedido)
chan pedido[1..C](string comida)
chan esperaPedido[1..3](int id)
chan tomarPedido[1..3](int cliente, string pedido)
chan cocinarPedido(int cliente, string pedido)

process Cliente[i = 1..C]
{
        string pedido = generarPedido();
        send llegoCliente(id, pedido);
        receive pedido[id](comida);
}

process Coordinador[i = 1..3]
{
        string pedido;
        int id, cliente;

        while (true) {
                receive esperaPedido[i](id);

                if (!empty(llegoCliente)) {
                        receive llegoCliente(cliente, pedido);
                } else {
                        pedido = null;
                        cliente = null;
                }

                send tomarPedido[id](cliente, pedido);
        }
}

process Vendedor[i = 1..3]
{
        string pedido;
        int cliente;

        while (true) {
                receive tomarPedido[i](cliente,pedido);

                if (pedido == NULL) {
                        delay(rand(1,3) * 60);
                } else {
                        send cocinarPedido(cliente, pedido);
                }
        }
}

process Cocinero[i = 1..2]
{
        while (true) {
                receive cocinarPedido(cliente, pedido);
                // Prepara pedido
                send pedido[cliente](pedido);
        }
}

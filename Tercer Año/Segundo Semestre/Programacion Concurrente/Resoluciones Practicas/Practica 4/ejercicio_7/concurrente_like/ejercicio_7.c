process Radar[i  = 1..10]
{
        string datos;

        while (true) {
                delay(15);
                datos = detectar();
                Buffer!enviarDatos(datos);
        }
}

process Buffer
{
        queue cola;
        string datos;

        while (true) {
                if (Radar?enviarDatos(datos)) -> {
                        encolar(cola, datos);
                } [](!empty(cola); Unidad?recibirDatos()) -> {
                        Unidad!enviarDatos(desencolar(cola));
                }
        }
}

process Unidad
{
        string datos;

        while (true) {
                Buffer!recibirDatos();
                Buffer?enviarDatos(datos);
                // Unidad procesa datos
        }
}

process Abuela
{
        int color = 10, negro = 15, id;

        while (true) {
                if (color > 0; NiñoC[*] ? pedirLapizColor(id)) ->{
                                NiñoC[id] !recibirLapizColor('color');
                                color--;
                        } [] (negro > 0; NiñoN[*] ? pedirLapizNegro(id))->{
                                NiñoN[id] !recibirLapizNegro('negro');
                                negro--;
                        } [] (color > 0; NiñoA[*] ? pedirLapizColor(id))->{
                                NiñoA[id] !recibirLapiz('color');
                                color--;
                        } [] (negro > 0; NiñoA[*] ? pedirLapizNegro(id))->{
                                NiñoA[id] !recibirLapiz('negro');
                                negro--;
                        } [] NiñoC[*] ? devolverLapizColor()->color++;
                [] NiñoN[*] ? devolverLapizNegro()->negro++;
                [] NiñoA[*] ? devolverLapizColor()->color++;
                [] NiñoA[*] ? devolverLapizNegro()->negro++;
        }
}

process NiñoC[i = 1..C]
{
        string lapiz;

        while (true) {
                Abuela !pedirLapizColor(i);
                Abuela ? recibirLapizColor();
                delay(10*60);
                Abuela !devolverLapizColor();
        }
}

process NiñoN[i = 1..N]
{
        string lapiz;

        while (true) {
                Abuela !pedirLapizNegro(i);
                Abuela ? recibirLapizNegro();
                delay(10*60);
                Abuela !devolverLapizNegro();
        }
}

process NiñoA[i = 1..A]
{
        string lapiz;

        while (true) {
                Abuela !pedirLapiz(i);
                Abuela ? recibirLapiz(lapiz);
                delay(10*60);
                if (lapiz == 'negro') {
                        Abuela !devolverLapizNegro();
                } else {
                        Abuela !devolverLapizColor();
                }
        }
}

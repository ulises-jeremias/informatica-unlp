sem s_cant_marcos = 0;
sem s_cant_vidrios = 0;
sem s_lugar_marcos = 30;
sem s_lugar_vidrios = 50;
sem s_marcos_access = 1;
sem s_vidrios_access = 1;
stack marcos;
stack vidrios;

Process Carpintero[i = 1..4]
{
        while (true) {
                marco_t m;
                m = hacer_marco();
                P(s_lugar_marcos);
                P(s_marcos_access);
                apilar(marcos, m);
                V(s_marcos_access);
                V(s_cant_marcos);
        }
}

Process Vidriero
{
        while (true) {
                vidrio_t v;
                v = hacer_vidrio();
                P(s_lugar_vidrios);
                P(s_vidrios_access);
                apilar(vidrios, v);
                V(s_vidrios_access);
                V(s_cant_vidrios);
        }
}

Process Armador[i = 1..2]
{
        while (true) {
                vidrio_t v;
                marco_t m;
                P(s_cant_marcos);
                P(s_cant_vidrios);
                P(s_marcos_access);
                m = desapilar(marcos);
                V(s_marcos_access);
                P(s_vidrios_access);
                v = desapilar(vidrios);
                V(s_vidrios_access);
                // armar ventana
                V(s_lugar_marcos);
                V(s_lugar_vidrios);
        }
}

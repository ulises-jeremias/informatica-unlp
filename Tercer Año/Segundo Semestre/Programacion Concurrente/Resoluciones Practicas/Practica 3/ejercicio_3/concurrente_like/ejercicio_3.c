monitor Machine
{
        condition queue[100];
        queue waiting;
        bool free = true;


        procedure in(int i)
        {
                if (free) {
                        free = false;
                } else {
                        encolar_ordenado(waiting, i, funtion(i, j) {
                                return i > j;
                        });
                        wait(queue[i]);
                }
        }

        procedure out()
        {
                if (empty(waiting)) {
                        free = true;
                } else {
                        desencolar(waiting, next);
                        signal(queue[next]);
                }
        }
}

Process Person[i = 1..100]
{
        Machine.in(i);
        // use Machine
        Machine.out();
}

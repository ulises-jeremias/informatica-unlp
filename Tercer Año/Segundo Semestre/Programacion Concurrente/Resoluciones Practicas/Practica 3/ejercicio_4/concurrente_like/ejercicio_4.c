monitor Bank
{
        cond queue;
        queue clients;
        bool attended[N] = ([N], false);

        wait(int i)
        {
                push(clients, i);
                wait(queue);
        }

        attend()
        {
                while (!empty(queue)) {
                        p = pop(clients);
                        attended[p] = true;
                        signal(queue);
                }
        }

        go(int i)
        {
                if (!attended[i]) {
                        pop(clients);
                        signal(queue);
                }
        }
}

monitor TimerMonitor
{
        cond pos;
        bool s = false;

        v()
        {
                s = true;
                signal(pos);
        }

        p()
        {
                if (s == false) {
                        wait(pos);
                }

                s = false;
        }

}

process Employee[ i = 1..2 ]
{
        while (true) {
                Bank.attend();
        }
}

process Person[ i = 1..N ]
{
        TimerMonitor[i].v();
        Bank.wait(i);
}

process Timer[ i = 1..N]
{
        TimerMonitor[i].p();
        delay(15);
        Bank.go(i);
}

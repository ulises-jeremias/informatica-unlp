bool attended[N] = ([N], false);

monitor Bank
{
        cond queue;
        queue clients;

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
        cond pos[N];
        bool s[N] = ([N], false);

        v(int i)
        {
                s[i] = true;
                signal(pos[i]);
        }

        p(int i)
        {
                if (s[i] == false) {
                        wait(pos[i]);
                }
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
        TimerMonitor.v(i);
        Bank.wait(i);
}

process Timer[ i = 1..N]
{
        TimerMonitor.p(i);
        delay(15);
        Bank.go(i);
}

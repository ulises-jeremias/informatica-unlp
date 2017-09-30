monitor DB
{
        condition queue;
        int count = 0;

        procedure in(int i)
        {
                if (count > 5) {
                        wait(queue);
                } else {
                        count++;
                }
        }

        procedure out(int i)
        {
                count--;
                signal(queue);
        }
}

Process Reader()[ i = 1..M]
{
        DB.in(i);
        //use DB
        DB.out(i);
}

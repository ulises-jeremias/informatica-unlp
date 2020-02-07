monitor DB
{
        condition queue;
        int count = 5;

        procedure in(int i)
        {
                if (!count) {
                        wait(queue);
                }
                
                count--;
        }

        procedure out(int i)
        {
                count++;
                signal(queue);
        }
}

process Reader()[ int i = 1..M]
{
        DB.in(i);
        //use DB
        DB.out(i);
}

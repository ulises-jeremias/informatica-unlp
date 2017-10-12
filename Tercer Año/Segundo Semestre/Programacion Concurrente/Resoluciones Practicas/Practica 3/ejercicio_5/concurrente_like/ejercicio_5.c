monitor Business
{
        int group[10] = ([10], 5);
        cond wattingGroup;
        int actual = 0;

        arrive(int i)
        {
                if (!group[actual]) {
                        actual++;
                        signal_all(wattingGroup);
                } else {
                        group[actual]--;
                        wait(cond|);
                }
        }
}

process Employee[ int i = 1..50 ]
{
        Business.arrive(i);
}

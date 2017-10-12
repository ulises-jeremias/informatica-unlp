monitor Business
{
        int group[10] = ([10], 5);
        cond wattingGroup;
        int actual = 0;

        arrive(int i)
        {
                group[actual]--;
                if (!group[actual]) {
                        actual++;
                        signal_all(wattingGroup);
                } else {
                        wait(cond|);
                }
        }
}

process Employee[ int i = 1..50 ]
{
        Business.arrive(i);
}

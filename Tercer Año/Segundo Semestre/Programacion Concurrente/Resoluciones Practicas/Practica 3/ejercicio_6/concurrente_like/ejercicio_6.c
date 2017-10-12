monitor Training
{
        cond waittingTeam[4];
        queue teams;
        int players[4] = ([4], 5);
        int field = 1;

        in(int team)
        {
                players[team]--;
                if (!players[team]) {
                        if (empty(teams)) {
                                push(teams, team);
                                wait(waittingTeam[team]);
                        } else {
                                signal_all(team);
                                signal_all(desencolar(next(teams));
                        }
                } else {
                        wait(waittingTeam[team]);
                }
        }
}

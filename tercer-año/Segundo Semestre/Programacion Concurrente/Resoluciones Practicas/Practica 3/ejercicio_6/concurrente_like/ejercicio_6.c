monitor Training
{
        cond waittingTeam[4];
        queue teams;
        int players[4] = ([4], 5);
        bool busy[2] = ([2], false);
        int field = 1;

        in(int team)
        {
                players[team]--;
                if (!players[team]) {
                        if (empty(teams)) {
                                push(teams, team);
                                wait(waittingTeam[team]);
                        } else {
                                busy[field++] = true;
                                signal_all(team);
                                signal_all(desencolar(teams));
                        }
                } else {
                        wait(waittingTeam[team]);
                }
        }
}

process Player()[ i = 1..20 ]
{
        int e = DarEquipo();
        Training.in(e);
}

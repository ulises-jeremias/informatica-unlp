#define P 105
#define N 5

chan box_request(int*);
chan finished_request(int*);
chan treat_request[1..N](int*);

chan box_response(int*);
chan treat_response[1..N](bool*);

Process Bank
{
        int queue[N], person_id, box_id;

        while (true) {
                if (!empty(finished_request)) -> {
                        receive finished_request(&box_id);
                        queue[box_id]--;
                } [](!empty(box_request) && empty(finished_request)) -> {
                        receive box_request(&person_id);
                        sort(queue.begin(), queue.end());
                        box_id = queue.begin().index();
                        queue[box_id]++;
                        send box_response(&box_id);
                }
        }
}

Process Person[i = 1..P]
{
        int box_id;
        bool atendido = 0;

        send box_request(&i);
        receive box_response(&box_id);
        send treat_request[box_id](i);
        receive treat_response[box_id](&atendido);
        send finished_request(&box_id);
}

Process Box[i = 1..N]
{
        int person_id;
        bool result;

        while (true) {
                receive treat_request[i](&person_id);
                result = treate(person_id);
                send treat_response[i](&result);
        }
}

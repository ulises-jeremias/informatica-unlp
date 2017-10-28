#define N 105
#define TIME 10

chan request_n(int*);
chan request_c(int*);
chan request_a(int*);

chan renturn_request(char*);

chan response_n[1..N](char*);
chan response_c[1..N](char*);
chan response_a[1..N](char*);

Process Abuela
{
        int c = 10, n = 15;
        int child;
        while (true) {
                if (!empty(request_c) && c--) -> {
                        recive request_c(&child);
                        send response_c[child]("C");
                } [](!empty(request_n) && n--) -> {
                        recive request_n(&child);
                        send response_n[child]("N");
                } [](!empty(request_a) && (c + n)) -> {
                        recive request_a(&child);
                        if (empty(request_n) && n--) -> {
                              send request_a[child]("N");
                        } [](empty(request_c) && c--) -> {
                              send request_c[child]("C");
                        }
                } [](!empty(return_request)) -> {
                        char pencil;
                        recive return_request(&pencil);
                        pencil == 'C' ? c-- : n--;
                }
        }
}

Process Child_N[i = 1..N]
{
        char pencil;
        while (true) {
                send request_n(i);
                recieve response_n[i](&pencil);
                delay(TIME * 60);
                renturn_request(pencil);
        }
}

Process Child_C[i = 1..N]
{
        char pencil;
        while (true) {
                send request_c(i);
                recieve response_c[i](&pencil);
                delay(TIME * 60);
                renturn_request(pencil);
        }
}

Process Child_A[i = 1..N]
{
        char pencil;
        while (true) {
                send request_a(i);
                recieve response_a[i](&pencil);
                delay(TIME * 60);
                renturn_request(&pencil);
        }
}

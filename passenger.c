#include "local.h"

int randomNum = 1;

int shmID;
int shmID2;
int shmID3;
int shmID4;
int shmID5;
int shmID6;
int shmID7;
int shmID8;
int shmID9;
int shmID11;

struct person *s;
struct person *s1;
struct person *s2;
struct person *s4;
int *s3;
int *s5;
int *s11;


sem_t *sem_queues[waiting_room_capacity];
sem_t *sem_queues3;
sem_t *sem_officer;
sem_t *sem_print;
sem_t *sem_teller1;
sem_t *sem_teller2;
sem_t *sem_teller3;
sem_t *sem_teller4;

struct person p;
int shmP = 0;
int Gnum = 0;

void send_request(int teller,int postion,int shmp);
void unhappy_signal();
void satisfied_signal();
void wait_signal();

int main(int argc, char *argv[]) {
    
    sleep(1);
    sigset(SIGUSR2,satisfied_signal);
    sigset(SIGALRM,unhappy_signal);


    p.ID = getpid();
    srand((unsigned) getpid()*randomNum);
    randomNum = (int) (0 + (rand() % 2));
    if (randomNum == 0) {
        p.gander = 'M';
    } else {
        p.gander = 'F';
    }

    randomNum = (int) (0 + (rand() % 4));
    p.request = randomNum;

    randomNum = (int) (0 + (rand() % 4));
    p.incomplete = randomNum;

    randomNum = (int) (0 + (rand() % 4));
    p.has_metal = randomNum;

    randomNum = (int) (0 + (rand() % 30));
    p.patiant = randomNum;


    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Attached shared memory & semaphores >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    sleep(1);

    
    char sem_name[8];

    for (int i = 0; i < waiting_room_capacity; i++) {
        sprintf(sem_name, "sem_%c%d", p.gander, i);
        if ((sem_queues[i] = sem_open(sem_name, 0)) == SEM_FAILED) {
            perror(sem_name);
            exit(1);
        }
    }


      
    if ((sem_queues3 = sem_open("sem_IR", 0)) == SEM_FAILED) {
        perror("sem_IR");
        exit(1);
    }
    
    
    for (int i = 0; i < waiting_room_capacity; i++)
    {
        sem_post(sem_queues3);
    }

    
    if ((sem_print = sem_open("print1", 0)) == SEM_FAILED) {
        perror("print1");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }

    
    if ((sem_teller1 = sem_open("Bx", 0)) == SEM_FAILED) {
        perror("Bx");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }

    
    if ((sem_teller2 = sem_open("Tx", 0)) == SEM_FAILED) {
        perror("Tx");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }

    
    if ((sem_teller3 = sem_open("Rx", 0)) == SEM_FAILED) {
        perror("Rx");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }

    
    if ((sem_teller4 = sem_open("Ix", 0)) == SEM_FAILED) {
        perror("Ix");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }


    sleep(1);

    
    

    if (p.gander == 'M') {
        shmID = shmget(7654, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
        if (shmID < 0) {
            printf("error shmIDM\n");
            exit(1);
        }
        
        if ((sem_officer = sem_open("officer1", 0)) == SEM_FAILED) {
            perror("officer1");
            printf("oooooppppsssss\n");
            fflush(stdout);
            exit(1);
        }
        Gnum = 0;
    } else if (p.gander == 'F') {
        shmID = shmget(1234, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
        if (shmID < 0) {
            printf("error shmIDF\n");
            exit(1);
        }
        if ((sem_officer = sem_open("officer2", 0)) == SEM_FAILED) {
            perror("officer2");
            printf("oooooppppsssss\n");
            fflush(stdout);
            exit(1);
        }
        Gnum = 1;
    }

    
    shmID5 = shmget(4567, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
    if (shmID5 < 0)
    {
        printf("error shmID5\n");
        exit(1);
    }

    
    shmID2 = shmget(7891, sizeof(struct person), 0666 | IPC_CREAT);
    if (shmID2 < 0)
    {
        printf("error shmID2\n");
        exit(1);
    }

    
    shmID3 = shmget(159, sizeof(int), 0666 | IPC_CREAT);
    if (shmID3 < 0)
    {
        printf("error shmID3\n");
        exit(1);
    }

    
    shmID4 = shmget(1010, sizeof(int)*number_of_tellers, 0666 | IPC_CREAT);
    if (shmID4 < 0)
    {
        printf("error shmID4\n");
        exit(1);
    }

    
    shmID6 = shmget(6666, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID6 < 0)
    {
        printf("error shmID6\n");
        exit(1);
    }

    
    shmID7 = shmget(7777, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID7 < 0)
    {
        printf("error shmID7\n");
        exit(1);
    }

    
    shmID8 = shmget(8888, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID8 < 0)
    {
        printf("error shmID8\n");
        exit(1);
    }

    
    shmID9 = shmget(9999, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID9 < 0)
    {
        printf("error shmID9\n");
        exit(1);
    }

    shmID11 = shmget(1111, sizeof(int)*8 , 0666 | IPC_CREAT);
    if (shmID11 < 0)
    {
        printf("error shmID11\n");
        exit(1);
    }

    sleep(1);


    ////////////////////////////// first stage (gate and waiting room) /////////////////////

    for (int i = 0; i < waiting_room_capacity; i++) {
        sem_wait(sem_queues[i]);

        sleep(1);
        s = (struct person *) shmat(shmID, NULL, 0);

        s[i].ID = p.ID;
        s[i].gander = p.gander;
        s[i].request = p.request;
        s[i].has_metal = p.has_metal;
        s[i].incomplete = p.incomplete;
        s[i].patiant = p.patiant;

        if (i > 0) {
            
            s[i - 1].ID = 0;
            s[i - 1].gander = ' ';
            s[i - 1].request = 0;
            s[i - 1].has_metal = 0;
            s[i - 1].incomplete = 0;
            s[i - 1].patiant = 0;
            sem_post(sem_queues[i - 1]);

        }
        else if(i == 0)
        {
            s11 = (int *) shmat(shmID11, NULL, 0);
            s11[Gnum]++;
            shmdt(s11);
        }
        shmdt(s);
        /*sem_wait(sem_print);

        kill(getppid(), SIGALRM);

        sem_post(sem_print);*/
    }


    ////////////////////////////  secand stage (wait for officer and enter metal machine ) ////

    s3 = (int *)shmat(shmID3, NULL, 0);

    kill(s3[0],SIGUSR1);

    shmdt(s3);

    sem_wait(sem_officer);
    
    s = (struct person *) shmat(shmID, NULL, 0);

    s[waiting_room_capacity-1].ID = 0;
    s[waiting_room_capacity-1].gander = ' ';
    s[waiting_room_capacity-1].request = 0;
    s[waiting_room_capacity-1].has_metal = 0;
    s[waiting_room_capacity-1].incomplete = 0;
    s[waiting_room_capacity-1].patiant = 0;

    s11 = (int *) shmat(shmID11, NULL, 0);
    s11[Gnum]--;
    shmdt(s11);

    shmdt(s);

    

    sem_post(sem_queues[waiting_room_capacity-1]);

    ///////////////////////////////// metal machine \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    s2 = (struct person *) shmat(shmID2, NULL, 0);

    s2[0].ID = p.ID;
    s2[0].gander = p.gander;
    s2[0].request = p.request;
    s2[0].has_metal = p.has_metal;
    s2[0].incomplete = p.incomplete;
    s2[0].patiant = p.patiant;

    s11 = (int *) shmat(shmID11, NULL, 0);
    s11[2]++;
    shmdt(s11);


    if(s2[0].has_metal == 3)
    {
        kill(getppid(),SIGUSR1);
        s2[0].ID = 0;
        s2[0].gander = ' ';
        s2[0].request = 0;
        s2[0].has_metal = 0;
        s2[0].incomplete = 0;
        s2[0].patiant = 0;
        s11 = (int *) shmat(shmID11, NULL, 0);
        s11[2]--;
        shmdt(s11);
        shmdt(s2);
        kill(getpid(),SIGKILL);
    }
    else if(s2[0].has_metal == 2)
    {
        s2[0].has_metal = 0;
        randomNum = (int) (0 + (rand() % 3));
        sleep(randomNum);
        s2[0].has_metal = 1;
    }
    else
    {
        randomNum = (int) (0 + (rand() % 2));
        sleep(randomNum);
    }

    

    shmdt(s2);


    /*sem_wait(sem_print);

    kill(getppid(), SIGALRM);

    sem_post(sem_print);*/

    ////////////////////////////// enter inner room \\\\\\\\\\\\\\\\\\\\\\\\\\\\

    sem_wait(sem_queues3);

    int postion = -1;

    for (int i = 0; i < waiting_room_capacity; i++) {
        
        
        s1 = (struct person *) shmat(shmID5, NULL, 0);

        if(s1[i].ID == 0)
        {
            s1[i].ID = p.ID;
            s1[i].gander = p.gander;
            s1[i].request = p.request;
            s1[i].has_metal = p.has_metal;
            s1[i].incomplete = p.incomplete;
            s1[i].patiant = p.patiant;
            shmdt(s1);
            postion = i;
            

            s2 = (struct person *) shmat(shmID2, NULL, 0);
            s2[0].ID = 0;
            s2[0].gander = ' ';
            s2[0].request = 0;
            s2[0].has_metal = 0;
            s2[0].incomplete = 0;
            s2[0].patiant = 0;
            shmdt(s2);

            s11 = (int *) shmat(shmID11, NULL, 0);
            s11[3]++;
            s11[2]--;
            shmdt(s11);

            break;
        }
        
        shmdt(s1);
    }
    sleep(3);
    /*sem_wait(sem_print);

    kill(getppid(), SIGALRM);

    sem_post(sem_print);*/

    ///////////////////////////// last stage (wait teller) \\\\\\\\\\\\\\\\\\\\\\ 

    while (1)
    {
        if(p.request == 0)
        {
            
            s4 = (struct person *) shmat(shmID6, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(0,postion,6);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID7, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(1,postion,7);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID8, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(2,postion,8);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID9, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(3,postion,9);
                
            }
            shmdt(s4);

        }
        else if(p.request == 1)
        {
            
            s4 = (struct person *) shmat(shmID7, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(1,postion,7);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID6, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(0,postion,6);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID8, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(2,postion,8);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID9, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(3,postion,9);
                
            }
            shmdt(s4);

        }
        else if(p.request == 2)
        {
            
            s4 = (struct person *) shmat(shmID8, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(2,postion,8);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID6, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(0,postion,6);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID7, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(1,postion,7);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID9, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(3,postion,9);
                
            }
            shmdt(s4);

        }
        else if(p.request == 3)
        {
            
            s4 = (struct person *) shmat(shmID9, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(3,postion,9);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID6, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(0,postion,6);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID7, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(1,postion,7);
                
            }
            shmdt(s4);
            s4 = (struct person *) shmat(shmID8, NULL, 0);
            if (s4[0].ID == 0)
            {
                shmdt(s4);
                send_request(2,postion,8);
                
            }
            shmdt(s4);

        }
    }

    


    return 0;
}

void send_request(int teller,int postion,int shmp)
{
    shmP = shmp;
    s5 = (int *)shmat(shmID4, NULL, 0);
    s1 = (struct person *) shmat(shmID5, NULL, 0);
    kill(s5[teller],SIGUSR1);
    if(teller==0)
    {
        sem_wait(sem_teller1);
    }
    else if(teller==1)
    {
        sem_wait(sem_teller2);
    }
    else if(teller==2)
    {
        sem_wait(sem_teller3);
    }
    else if(teller==3)
    {
        sem_wait(sem_teller4);
    }
    if(shmp == 6)
    {
        s4 = (struct person *) shmat(shmID6, NULL, 0);
    }
    else if(shmp == 7)
    {
        s4 = (struct person *) shmat(shmID7, NULL, 0);
    }
    else if(shmp == 8)
    {
        s4 = (struct person *) shmat(shmID8, NULL, 0);
    }
    else if(shmp == 9)
    {
        s4 = (struct person *) shmat(shmID9, NULL, 0);
    }
    s4[0].ID = p.ID;
    s4[0].gander = p.gander;
    s4[0].request = p.request;
    s4[0].has_metal = p.has_metal;
    s4[0].incomplete = p.incomplete;
    s4[0].patiant = p.patiant;

    s1[postion].ID = 0;
    s1[postion].gander = ' ';
    s1[postion].request = 0;
    s1[postion].has_metal = 0;
    s1[postion].incomplete = 0;
    s1[postion].patiant = 0;

    s11 = (int *) shmat(shmID11, NULL, 0);
    s11[shmp-2]++;
    s11[3]--;
    shmdt(s11);
    
    shmdt(s1);

    sleep(1);
    sem_post(sem_queues3);
    if(p.patiant<teller_period_of_time)
    {
        s4[0].ID = 0;
        s4[0].gander = ' ';
        s4[0].request = 0;
        s4[0].has_metal = 0;
        s4[0].incomplete = 0;
        s4[0].patiant = 0;

        s11 = (int *) shmat(shmID11, NULL, 0);
        s11[shmp-2]--;
        shmdt(s11);

        kill(s5[teller],SIGUSR2);
        kill(getppid(),SIGUSR1);
        shmdt(s4);
        shmdt(s5);
        kill(getpid(),SIGKILL);
    }
    shmdt(s4);
    shmdt(s5);
    wait_signal();
}

void unhappy_signal()
{

    if(shmP == 6)
    {
        s4 = (struct person *) shmat(shmID6, NULL, 0);
    }
    else if(shmP == 7)
    {
        s4 = (struct person *) shmat(shmID7, NULL, 0);
    }
    else if(shmP == 8)
    {
        s4 = (struct person *) shmat(shmID8, NULL, 0);
    }
    else if(shmP == 9)
    {
        s4 = (struct person *) shmat(shmID9, NULL, 0);
    }
    else{
        printf("shmP wrong\n");
        fflush(stdout);
        kill(getpid(),SIGKILL);
    }

    s4[0].ID = 0;
    s4[0].gander = ' ';
    s4[0].request = 0;
    s4[0].has_metal = 0;
    s4[0].incomplete = 0;
    s4[0].patiant = 0;

    s11 = (int *) shmat(shmID11, NULL, 0);
    s11[shmP-2]--;
    shmdt(s11);

    shmdt(s4);
    kill(getppid(),SIGUSR2);
    /*sem_wait(sem_print);

    kill(getppid(), SIGALRM);

    sem_post(sem_print);*/
    kill(getpid(),SIGKILL);
}

void satisfied_signal()
{
    if(shmP == 6)
    {
        s4 = (struct person *) shmat(shmID6, NULL, 0);
    }
    else if(shmP == 7)
    {
        s4 = (struct person *) shmat(shmID7, NULL, 0);
    }
    else if(shmP == 8)
    {
        s4 = (struct person *) shmat(shmID8, NULL, 0);
    }
    else if(shmP == 9)
    {
        s4 = (struct person *) shmat(shmID9, NULL, 0);
    }
    else{
        printf("shmP wrong\n");
        fflush(stdout);
        kill(getpid(),SIGKILL);
    }
    s4[0].ID = 0;
    s4[0].gander = ' ';
    s4[0].request = 0;
    s4[0].has_metal = 0;
    s4[0].incomplete = 0;
    s4[0].patiant = 0;

    s11 = (int *) shmat(shmID11, NULL, 0);
    s11[shmP-2]--;
    shmdt(s11);

    shmdt(s4);
    kill(getppid(),SIGTSTP);
    /*sem_wait(sem_print);

    kill(getppid(), SIGALRM);

    sem_post(sem_print);*/
    kill(getpid(),SIGKILL);
}
void wait_signal()
{
    while (1)
    {
        continue;
    }

}
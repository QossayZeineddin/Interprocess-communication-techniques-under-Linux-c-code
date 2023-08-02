#include "local.h"


char name[2];

sem_t *sem_teller;
sem_t *sem_print;

int shmID;

struct person *s1;

void wait_signal();
void pass();

int main(int argc, char *argv[])
{
    name[0] = argv[0][0];
    name[1] = argv[0][1];

    sigset(SIGUSR1,pass);
    sigset(SIGUSR2,wait_signal);

    
    char sem_name[8];

    sem_unlink(name);
    if ((sem_teller = sem_open(name, O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
        perror(name);
        printf("oooooppppsssss1\n");
        fflush(stdout);
        exit(1);
    }
    sem_init(sem_teller, 1, 0);
   
    


    
    if ((sem_print = sem_open("print1", 0)) == SEM_FAILED) {
        perror("print1");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }


    if(name[0] == 'B' && name[1] == 'x')
    {
        shmID = shmget(6666, sizeof(struct person) , 0666 | IPC_CREAT);
        if (shmID < 0)
        {
            printf("error shmID6\n");
            exit(1);
        }
    }
    else if(name[0] == 'T' && name[1] == 'x')
    {
        shmID = shmget(7777, sizeof(struct person) , 0666 | IPC_CREAT);
        if (shmID < 0)
        {
            printf("error shmID7\n");
            exit(1);
        }
    }
    else if(name[0] == 'R' && name[1] == 'x')
    {
        shmID = shmget(8888, sizeof(struct person) , 0666 | IPC_CREAT);
        if (shmID < 0)
        {
            printf("error shmID8\n");
            exit(1);
        }
    }
    else if(name[0] == 'I' && name[1] == 'x')
    {
        shmID = shmget(9999, sizeof(struct person) , 0666 | IPC_CREAT);
        if (shmID < 0)
        {
            printf("error shmID9\n");
            exit(1);
        }
    }

    kill(getpid(),SIGUSR2);

}

void pass()
{
    sem_post(sem_teller);
    sleep(teller_period_of_time);
    s1 = (struct person *)shmat(shmID, NULL, 0);
    if(s1[0].incomplete == 3)
    {
        /*sem_wait(sem_print);

        kill(getppid(), SIGALRM);

        sem_post(sem_print);*/
        kill(s1[0].ID,SIGALRM);
        
    }
    else
    {
        /*sem_wait(sem_print);

        kill(getppid(), SIGALRM);

        sem_post(sem_print);*/
        kill(s1[0].ID,SIGUSR2);
        
    }
    
    shmdt(s1);
    kill(getpid(),SIGUSR2);
}

void wait_signal()
{
    while (1)
    {
        sigpause(SIGUSR1);
    }
    
}
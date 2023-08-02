#include "local.h"

int randnum = 1;
int  shmOFC;
int shmMP;
int shmFP;

struct person *sFC;
struct person *sm;
struct person *sf;

sem_t *sem_officer1;
sem_t *sem_officer2;


int numInRoome = 0;

void pass();
void wait_signal();

int main(int argc, char *argv[])
{

    sigset(SIGUSR1,pass);
    sigset(SIGUSR2,wait_signal);

    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Attached shared memory & semaphores >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    srand((unsigned)getpid() * randnum);

    
    if ((sem_officer1 = sem_open("officer1", 0)) == SEM_FAILED)
    {
        perror("officer1");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }

    
    if ((sem_officer2 = sem_open("officer2", 0)) == SEM_FAILED)
    {
        perror("officer2");
        printf("oooooppppsssss\n");
        fflush(stdout);
        exit(1);
    }

    //============******Attached to sh m inner grouping area ******===========

    shmOFC = shmget(7891, sizeof(struct person), 0666 | IPC_CREAT);
    if (shmOFC < 0)
    {
        printf("error shmOFC\n");
        exit(1);
    }

    shmMP = shmget(7654, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
    if (shmMP < 0)
    {
        printf("error shmMP\n");
        exit(1);
    }

    shmFP = shmget(1234, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
    if (shmFP < 0)
    {
        printf("error shmFP\n");
        exit(1);
    }    
    
    kill(getpid(),SIGUSR2);

    return;
}

void pass()
{
    sFC = (struct person *)shmat(shmOFC, NULL, 0);
        
    
    if (sFC[0].ID == 0)
    {
        sm = (struct person *)shmat(shmMP, NULL, 0);
        sf = (struct person *)shmat(shmFP, NULL, 0);
        if (sm[waiting_room_capacity-1].ID == 0 && sf[waiting_room_capacity-1].ID == 0)
        {
            kill(getpid(),SIGUSR2);
        }
        else if(sm[waiting_room_capacity-1].ID > 0 && sf[waiting_room_capacity-1].ID == 0)
        {
            sem_post(sem_officer1);
            
        }
        else if(sm[waiting_room_capacity-1].ID == 0 && sf[waiting_room_capacity-1].ID > 0)
        {
            sem_post(sem_officer2);
            
        }
        else{
            int maxRoundNumber = 10;
            randnum = (int)(0 + (rand() % maxRoundNumber));
            
            if (randnum > maxRoundNumber / 2)
            {
                sem_post(sem_officer1);
            }
            else
            {
                sem_post(sem_officer2);
            }
        }
        shmdt(sm);
        shmdt(sf);
        
    }
    shmdt(sFC);
    sleep(3);
    kill(getpid(),SIGUSR1);
}

void wait_signal()
{
    while (1)
    {
        sigpause(SIGUSR1);
    }
    
}
#include "local.h"


int finish_state;
int shmID1;
int shmID2;
int shmID3;
int shmID4;
int shmID5;
int shmID6;
int shmID7;
int shmID8;
int shmID9;
int shmID10;
int shmID11;
int number_of_unserved = 0;
int number_of_unhappy = 0;
int number_of_satisfied =0;
int number_of_finished = 0;
int time_counter = 0;


int limit_unserved = 20;
int limit_unhappy = 20;
int limit_satisfied = 20;


struct person *s1;
struct person *s2;
struct person *s3;
struct person *s4;
struct person *s6;
struct person *s7;
struct person *s8;
struct person *s9;
int *s5;
int *s10;
int *s11;
int opg;

pid_t pid,officer_pid,tellers_pid[number_of_tellers], pid_array[number_of_people];


void print_view();

void print_MQ();

void print_FQ();

void print_IQ();
    
void print_MD();

void print_tellers();

void print_time();

void print_unserved();

void print_unhappy();

void print_satisfied();

void kill_all();

void check_unserved();

void check_unhappy();

void check_satisfied();

void wait_signal();


int main(int argc, char *argv[]) {

    sigset(SIGALRM, print_view);
    sigset(SIGINT, kill_all);
    sigset(SIGUSR1,check_unserved);
    sigset(SIGUSR2,check_unhappy);
    sigset(SIGTSTP,check_satisfied);
    sigset(SIGTTIN,wait_signal);


    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< create shared memory & semaphores >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


    sem_t *sem_queues1[waiting_room_capacity];
    char sem_name[8];


    for (int i = 0; i < waiting_room_capacity; i++) {
        sprintf(sem_name, "sem_M%d", i);
        sem_unlink(sem_name);
        if ((sem_queues1[i] = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
            perror(sem_name);
            exit(1);
        }
        sem_init(sem_queues1[i], 1, 1);

    }

    sem_t *sem_queues2[waiting_room_capacity];
    for (int i = 0; i < waiting_room_capacity; i++) {
        sprintf(sem_name, "sem_F%d", i);
        sem_unlink(sem_name);
        if ((sem_queues2[i] = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
            perror(sem_name);
            exit(1);
        }
        sem_init(&sem_queues2[i], 1, 1);

    }

    sem_t *sem_queues3;
    
    
    sem_unlink("sem_IR");
    if ((sem_queues3 = sem_open("sem_IR", O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
        perror("sem_IR");
        exit(1);
    }
    sem_init(&sem_queues3, 1, 0);

    
    

    


    sem_t *sem_officer1;
    sem_unlink("officer1");
    if ((sem_officer1 = sem_open("officer1", O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
        perror("officer1");
        printf("oooooppppsssss1\n");
        fflush(stdout);
        exit(1);
    }
    sem_init(sem_officer1, 1, 0);

    sem_t *sem_officer2;
    sem_unlink("officer2");
    if ((sem_officer2 = sem_open("officer2", O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
        perror("officer2");
        printf("oooooppppsssss1\n");
        fflush(stdout);
        exit(1);
    }
    sem_init(sem_officer2, 1, 0);


    sem_t *sem_print;
    sem_unlink("print1");
    if ((sem_print = sem_open("print1", O_CREAT, 0644, 1)) == SEM_FAILED) {
        perror("print1");
        printf("oooooppppsssss1\n");
        fflush(stdout);
        exit(1);
    }
    sem_init(sem_print, 1, 1);

    sleep(1);


    
    // ================***********sh m For MAlE **************** ==================
    shmID1 = shmget(7654, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
    if (shmID1 < 0) {
        printf("error shmID1\n");
        exit(1);
    }
    // ================*********** sh m For FEMALE **************** ==================

    shmID2 = shmget(1234, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
    if (shmID2 < 0) {
        printf("error shmID2\n");
        exit(1);
    }
    // ================*********** sh m inner grouping area **************** ==================
    shmID3 = shmget(4567, sizeof(struct person) * waiting_room_capacity, 0666 | IPC_CREAT);
    if (shmID3 < 0) {
        printf("error shmID3\n");
        exit(1);
    }
    // ================*********** sh m detector machines **************** ==================
    shmID4 = shmget(7891, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID4 < 0) {
        printf("error shmID4\n");
        exit(1);
    }

    // ================*********** sh m for Bx **************** ==================
    shmID6 = shmget(6666, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID6 < 0) {
        printf("error shmID6\n");
        exit(1);
    }

    // ================*********** sh m for Tx **************** ==================
    shmID7 = shmget(7777, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID7 < 0) {
        printf("error shmID7\n");
        exit(1);
    }

    // ================*********** sh m for Rx **************** ==================
    shmID8 = shmget(8888, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID8 < 0) {
        printf("error shmID8\n");
        exit(1);
    }

    // ================*********** sh m for Ix **************** ==================
    shmID9 = shmget(9999, sizeof(struct person) , 0666 | IPC_CREAT);
    if (shmID9 < 0) {
        printf("error shmID9\n");
        exit(1);
    }

    // ================*********** sh m for officer pid **************** ==================
    shmID5 = shmget(159, sizeof(int) , 0666 | IPC_CREAT);
    if (shmID5 < 0) {
        printf("error shmID5\n");
        exit(1);
    }

    // ================*********** sh m for tellers pid **************** ==================
    shmID10 = shmget(1010, sizeof(int)*number_of_tellers , 0666 | IPC_CREAT);
    if (shmID10 < 0) {
        printf("error shmID10\n");
        exit(1);
    }

    // ================*********** sh m for number of male **************** ==================
    shmID11 = shmget(1111, sizeof(int)*8 , 0666 | IPC_CREAT);
    if (shmID11 < 0) {
        printf("error shmID10\n");
        exit(1);
    }

    // ================*********** Set All valuse to Zero **************** ==================

    s1 = (struct person *) shmat(shmID1, NULL, 0);
    s2 = (struct person *) shmat(shmID2, NULL, 0);
    s3 = (struct person *) shmat(shmID3, NULL, 0);
    s4 = (struct person *) shmat(shmID4, NULL, 0);
    s6 = (struct person *) shmat(shmID6, NULL, 0);
    s7 = (struct person *) shmat(shmID7, NULL, 0);
    s8 = (struct person *) shmat(shmID8, NULL, 0);
    s9 = (struct person *) shmat(shmID9, NULL, 0);
    s11 = (int *) shmat(shmID11, NULL, 0);
    


    for (int i = 0; i < waiting_room_capacity; i++) {
        s1[i].ID = 0;
        s1[i].gander = ' ';
        s1[i].request = 0;
        s1[i].has_metal = 0;
        s1[i].incomplete = 0;
        s1[i].patiant = 0;
        ////
        s2[i].ID = 0;
        s2[i].gander = ' ';
        s2[i].request = 0;
        s2[i].has_metal = 0;
        s2[i].incomplete = 0;
        s2[i].patiant = 0;
        ///
        s3[i].ID = 0;
        s3[i].gander = ' ';
        s3[i].request = 0;
        s3[i].has_metal = 0;
        s3[i].incomplete = 0;
        s3[i].patiant = 0;
    }

    s4[0].ID = 0;
    s4[0].gander = ' ';
    s4[0].request = 0;
    s4[0].has_metal = 0;
    s4[0].incomplete = 0;
    s4[0].patiant = 0;

    s6[0].ID = 0;
    s6[0].gander = ' ';
    s6[0].request = 0;
    s6[0].has_metal = 0;
    s6[0].incomplete = 0;
    s6[0].patiant = 0;

    s7[0].ID = 0;
    s7[0].gander = ' ';
    s7[0].request = 0;
    s7[0].has_metal = 0;
    s7[0].incomplete = 0;
    s7[0].patiant = 0;

    s8[0].ID = 0;
    s8[0].gander = ' ';
    s8[0].request = 0;
    s8[0].has_metal = 0;
    s8[0].incomplete = 0;
    s8[0].patiant = 0;

    s9[0].ID = 0;
    s9[0].gander = ' ';
    s9[0].request = 0;
    s9[0].has_metal = 0;
    s9[0].incomplete = 0;
    s9[0].patiant = 0;

    for (int i = 0; i < 8; i++)
    {
        s11[i] = 0;
    }
    


    shmdt(s1);
    shmdt(s2);
    shmdt(s3);
    shmdt(s4);
    shmdt(s6);
    shmdt(s7);
    shmdt(s8);
    shmdt(s9);
    shmdt(s11);

    sleep(1);

// ================*********** Fork a Process based of number of people **************** ==================
    opg = fork();
    if(opg == 0)
     {
		execlp("./opg", "opg", (char*) NULL);
     }


    for (int i = 0; i < number_of_people; i++) {
        pid = fork();
        if (pid == -1) {
            perror("failed fork!!\n");
            exit(-1);
        } else if (pid == 0) {
            kill(getpid(), SIGSTOP);
            execl("./passenger", "", NULL);
            return 0;
        } else {
            pid_array[i] = pid;
            red();
            printf("I'm parent and I has a new child his num is %d\n", pid);
            normals();

        }
    }

    officer_pid = fork();
    if (officer_pid == -1) {
        perror("failed fork!!\n");
        exit(-1);
    } else if (officer_pid == 0) {
        execl("./officer", "", NULL);
        return 0;
    }

    s5 = (int *)shmat(shmID5, NULL, 0);
    s5[0] = officer_pid;
    shmdt(s5);

    for (int i = 0; i < number_of_tellers; i++) {
        pid = fork();
        if (pid == -1) {
            perror("failed fork!!\n");
            exit(-1);
        } else if (pid == 0) {
            char tr[2];
            if(i==0)
            {
                tr[0]='B';
                tr[1]='x';
            }
            else if(i==1)
            {
                tr[0]='T';
                tr[1]='x';
            }
            else if(i==2)
            {
                tr[0]='R';
                tr[1]='x';
            }
            else if(i==3)
            {
                tr[0]='I';
                tr[1]='x';
            }
            char * arg_list[] =
            {
                tr,
                NULL
            };
            execl("./tellers",tr, NULL);
            return 0;
        } else {
            tellers_pid[i] = pid;
        }
    }

    for (int i = 0; i < number_of_tellers; i++)
    {
        s10 = (int *)shmat(shmID10, NULL, 0);
        s10[i] = tellers_pid[i];
        shmdt(s10);
    }
    
    
        


    sleep(1);

    for (int j = 0; j < number_of_people; j++) {
        kill(pid_array[j], SIGCONT);
    }


    print_view();
    //sem_post(sem_print);

    wait_signal();


    return 0;

}



void kill_all() {
    for (int i = 0; i < number_of_people; i++) {
        kill(pid_array[i], SIGKILL);
    }
    for (int i = 0; i < number_of_tellers; i++) {
        kill(tellers_pid[i], SIGKILL);
    }
    kill(officer_pid,SIGKILL);
    kill(getpid(), SIGKILL);

}

void print_view() {
    sleep(3);
    
    s11 = (int *) shmat(shmID11, NULL, 0);
    tc_clear_screen();
    fflush(stdout);
    print_time();
    print_MQ();
    printf("number of male => %d\n",s11[0]);
    print_FQ();
    printf("number of female => %d\n",s11[1]);
    print_MD();
    printf("number of people in metal => %d\n",s11[2]);
    print_IQ();
    printf("number of people in inner => %d\n",s11[3]);
    print_tellers();
    //printf("number of Bx => %d | Tx => %d | Rx => %d | Ix => %d  \n",s11[4],s11[5],s11[6],s11[7]);
    
    kill(opg, SIGUSR1);
    if(number_of_finished==number_of_people || number_of_unserved==limit_unserved || number_of_unhappy==limit_unhappy || number_of_satisfied==limit_satisfied)
    {
        kill(getpid(),SIGINT);
    }
    kill(getpid(),SIGTTIN);
    
    
}

void print_MQ() {
    s1 = (struct person *) shmat(shmID1, NULL, 0);

    blue();
    printf(
            "########################################################male waiting room################################################################\n"
            "#"
    );
    fflush(stdout);
    for (int i = 0; i < waiting_room_capacity; i++) {
        printf(" %d #", s1[i].ID);
        fflush(stdout);
    }
    printf(
            "\n#########################################################################################################################################\n"
    );
    normals();
    fflush(stdout);

    shmdt(s1);

}

void print_FQ() {
    s2 = (struct person *) shmat(shmID2, NULL, 0);

    red();
    printf(
            "######################################################female waiting room################################################################\n"
            "#"
    );
    fflush(stdout);

    for (int i = 0; i < waiting_room_capacity; i++) {
        printf(" %d #", s2[i].ID);
        fflush(stdout);
    }
    printf(
            "\n#########################################################################################################################################\n"
    );
    normals();
    fflush(stdout);
    shmdt(s2);
}
void print_IQ() {
    s3 = (struct person *) shmat(shmID3, NULL, 0);

    green();
    printf(
            "########################################################ienner room######################################################################\n"
            "#"
    );
    fflush(stdout);

    for (int i = 0; i < waiting_room_capacity; i++) {
        printf(" %d #", s3[i].ID);
        fflush(stdout);
    }
    printf(
            "\n#########################################################################################################################################\n"
    );
    normals();
    fflush(stdout);
    shmdt(s3);
}

void print_MD() {
    s4 = (struct person *) shmat(shmID4, NULL, 0);

    yellow();
    printf(
            "############metal machine############\n"
            "#"
    );
    fflush(stdout);

    
    printf(" %d #", s4[0].ID);
    fflush(stdout);

    printf(
            "\n#####################################\n"
    );
    normals();
    fflush(stdout);
    shmdt(s4);
}

void print_tellers() {
    s6 = (struct person *) shmat(shmID6, NULL, 0);
    s7 = (struct person *) shmat(shmID7, NULL, 0);
    s8 = (struct person *) shmat(shmID8, NULL, 0);
    s9 = (struct person *) shmat(shmID9, NULL, 0);

    cyan();
    printf(
            "#####Bx#####\t\t#####Tx#####\t\t#####Rx#####\t\t#####Ix#####\n"
            "#" 
    );
    fflush(stdout);

    
    printf("   %d   #\t\t#   %d   #\t\t#   %d   #\t\t#   %d   #", s6[0].ID,s7[0].ID,s8[0].ID,s9[0].ID);
    fflush(stdout);

    printf(
            "\n############\t\t############\t\t############\t\t############\n"
    );
    normals();
    fflush(stdout);
    shmdt(s6);
    shmdt(s7);
    shmdt(s8);
    shmdt(s9);
}

void print_time()
{
    normals();
    printf(
            "####time####\t\t##finished##\t\t##satisfied#\t\t###unhappy##\t\t##unserved##\n"
            "#" 
    );
    fflush(stdout);

    
    printf("   %d   #\t\t#   %d   #\t\t#   %d   #\t\t#   %d   #\t\t#   %d   #", time_counter,number_of_finished,number_of_satisfied,number_of_unhappy,number_of_unserved);
    fflush(stdout);

    printf(
            "\n############\t\t############\t\t############\t\t############\t\t############\n"
    );
    normals();
    fflush(stdout);
}

void check_unserved()
{
    number_of_unserved++;
    number_of_finished++;
    if(number_of_unserved == limit_unserved || number_of_finished == number_of_people)
    {
        kill(getpid(),SIGALRM);
    }
    kill(getpid(),SIGTTIN);
}

void check_unhappy()
{
    number_of_unhappy++;
    number_of_finished++;
    if(number_of_unhappy == limit_unhappy || number_of_finished == number_of_people)
    {
        kill(getpid(),SIGALRM);
    }
    kill(getpid(),SIGTTIN);
}

void check_satisfied()
{
    number_of_satisfied++;
    number_of_finished++;
    if(number_of_satisfied == limit_satisfied || number_of_finished == number_of_people)
    {
        kill(getpid(),SIGALRM);
    }
    kill(getpid(),SIGTTIN);
}

void wait_signal()
{
    while (1)
    {
        sleep(1);
        time_counter++;
        if(time_counter<8 || time_counter>=13)
        {
            for (int i = 0; i < number_of_people; i++)
            {
                kill(pid_array[i],SIGSTOP);
            }
            for (int i = 0; i < number_of_tellers; i++)
            {
                kill(tellers_pid[i],SIGSTOP);
            }
            kill(officer_pid,SIGSTOP);

            
            
        }
        else if(time_counter>=8 && time_counter<13) {
            for (int i = 0; i < number_of_people; i++)
            {
                kill(pid_array[i],SIGCONT);
            }
            for (int i = 0; i < number_of_tellers; i++)
            {
                kill(tellers_pid[i],SIGCONT);
            }
            kill(officer_pid,SIGCONT);
        }

        if(time_counter == 24)
        {
            time_counter = 0;
        }
        
        print_view();
    }
    

    kill(getpid(),SIGINT);
}

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid, parentPID;

    pid = fork();

    if(pid > 0){
        printf("Soy el Nodo P, mi PID es: #%d\n", getpid());
        wait(NULL);

        pid = fork();
        if(pid == 0){
            // Nodo E
            parentPID = getppid();
            printf("Soy el Nodo E, mi PID es: #%d\n", getpid());
            printf("y mi padre es: %d\n", parentPID);

            pid = fork();
            if(pid == 0){
                // Nodo F
                parentPID = getppid();
                printf("Soy el Nodo F, mi PID es: #%d\n", getpid());
                printf("y mi padre es: %d\n", parentPID);

                pid = fork();
                if(pid == 0){
                    parentPID = getppid();
                    printf("Soy el Nodo G, mi PID es: #%d\n", getpid());
                    printf("y mi padre es: %d\n", parentPID);

                    wait(NULL);
                    return 0;
                }

                wait(NULL);
                return 0;
            }

            wait(NULL);
            return 0;
        }
        wait(NULL);

    } else if(pid == 0){
        // Nodo A
        parentPID = getppid();
        printf("Soy el Nodo A, mi PID es: #%d\n", getpid());
        printf("y mi padre es: %d\n", parentPID);

        pid = fork();  
        wait(NULL);

        if(pid == 0){
            // Nodo B 
            parentPID = getppid();
            printf("Soy el Nodo B, mi PID es: #%d\n", getpid());
            printf("y mi padre es: %d\n", parentPID);

            pid = fork();

            if(pid == 0){
                // Nodo C
                parentPID = getppid();
                printf("Soy el Nodo C, mi PID es: #%d\n", getpid());
                printf("y mi padre es: %d\n", parentPID);

                wait(NULL);
                return 0;
            }

            wait(NULL);
            return 0;

        }
    
        pid = fork();
        if(pid == 0){
            //Nodo D
            parentPID = getppid();
            printf("Soy el Nodo D, mi PID es: #%d\n", getpid());
            printf("y mi padre es: %d\n", parentPID);
            wait(NULL);
            return 0;
        }
    } 


    return 0;
}
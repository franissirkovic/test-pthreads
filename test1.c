#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>

void* timer_thread(void* arg)
{
    while (1)
    {
        usleep(3000000);
        printf("\nHello from pthread!\n");
        printf("Enter 'q' to exit:");
    }
    return NULL;
}

int  main(int argc, char* argv[])
{
    char res[80] = "";
    int err;
    pthread_t thread;

    printf("Hello world!\n");
    err = pthread_create(&thread, NULL, timer_thread, NULL);
    do
    {
        printf("Enter 'q' to exit:");
        fgets(res, sizeof(res), stdin);
    } while (0 != strncasecmp("q", res, 1));
    printf("Goodbye!\n");
    return 0;
}

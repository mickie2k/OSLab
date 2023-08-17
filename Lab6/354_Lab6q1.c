#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum;

void *runner(void * param);
// void parentRunner(void * param);
int main(int argc, char *argv[])
{
    /* code */
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid,&attr,&runner, argv[1]);
    printf("mom waiting for child\n");
    
    // parentRunner(argv[1]);
    int upper = atoi(argv[1]);
    int i;
    int msum = 0;
    printf("parent\n");
    if(upper > 0){
        for(i = 0; i<= upper; i++){
            msum+= i;
        }
    }
    printf("msum = %d\n", msum);

    // pthread_join(tid, NULL);
    // printf("child is finish\n");
        printf("csum = %d\n", csum);
    printf("csum - msum = %d\n", csum-msum);
    return 0;

}

void *runner (void * param){
    int upper = atoi(param);
    int i;
    csum = 0;
    printf("child\n");
    if(upper > 0){
        for(i = 0; i<= upper*2; i++){
            csum += i;
        }
    }
    pthread_exit(0);
}

// void parentRunner(void * param){
//    int upper = atoi(param);
//     int i;
//     msum = 0;
//     printf("parent\n");
//     if(upper > 0){
//         for(i = 0; i<= upper; i++){
//             msum+= i;
//         }
//     }
//     printf("msum = %d\n", msum);
// }

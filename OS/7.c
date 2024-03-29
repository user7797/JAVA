#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum;
void *runner(void *param);

int main(int argc,char *argv[])
{
   pthread_t tid;
   pthread_t tid1;
   pthread_attr_t attr;
   pthread_attr_t attr1;

   if(argc!=3)
   {
     fprintf(stderr,"usage: a.out <integer value>\n");
     return -1;
   }
   if(atoi(argv[1])<0)
   {
     fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
     return -1;
   }
   if(atoi(argv[2])<0)
   {
     fprintf(stderr,"%d must be >= 0\n",atoi(argv[2]));
     return -1;
   }

   pthread_attr_init(&attr);
   pthread_create(&tid,&attr,runner,argv[1]);
   pthread_join(tid,NULL);
   printf("sum = %d\n",sum);
   pthread_attr_init(&attr1);
   pthread_create(&tid1,&attr1,runner,argv[2]);
   pthread_join(tid1,NULL);
   printf("sum = %d\n",sum);
   pthread_attr_init(&attr);
   pthread_create(&tid,&attr,runner,argv[1]);
   pthread_join(tid,NULL);
   printf("sum = %d\n",sum);
   pthread_attr_init(&attr1);
   pthread_create(&tid1,&attr1,runner,argv[2]);
   pthread_join(tid1,NULL);
   printf("sum = %d\n",sum);
}

void *runner(void *param)
{
   int i,upper=atoi(param);
   sum=0;
   for(i=1;i<=upper;i++)
     sum+=i;

   pthread_exit(0);
}

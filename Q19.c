#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[256];
    int  age;
    char sex[256];
}profile;

void pro_scan(profile *data1);
void pro_print(profile data1);

int main(void)
{
    int i = 0;
    int count,datasize;;
    profile *data1;

    datasize = 10;
    data1 = malloc(sizeof(profile)*10);
    if(data1 == NULL){exit(0);}

    do{
        if(i >= datasize){
            datasize++;
            profile *p_;
            p_ = realloc(data1,sizeof(profile)*datasize);

            if(p_ == NULL){
                perror("Failed to reallocate profile buffer!");
                free(data1);
                exit(1);
            }

            data1 = p_;
        }
        pro_scan(&data1[i]);
    }while(data1[i++].age != -1);
    
    for(count = 0;count < i;count++)
    {
       pro_print(data1[count]); 
    }
    
    free(data1);

    return 0;
}
void pro_scan(profile *data1)
{
    printf("input your name :");
    fgets(data1->name,256,stdin);
    printf("input your sex :");
    fgets(data1->sex,256,stdin);
    printf("input your age :");
    char pvalue[256];
    fgets(pvalue,256,stdin);
    data1->age = atoi(pvalue);
    printf("\n");
    return;
}

void pro_print(profile data1)
{
    printf("name = %s\n",data1.name);
    printf("sex = %s\n",data1.sex);
    printf("age = %d\n",data1.age);
    printf("\n");
    return;
}
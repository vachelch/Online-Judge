#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

void count(int **ptrArray[]){
    int **s_layer[512];
    int s_layer_count[512] = {0};

    int *t_layer[512];
    int t_layer_count[512] = {0};


    int i, j;
    int len1 = 0;
    int len2 = 0;
    int len3 = 0;


    for(i = 0; ptrArray[i]; i++){
        len1++;
        int flag = 1;
        for(j = 0; j<i; j++){
           if(ptrArray[i] == s_layer[j]){
                s_layer_count[j]++;
                flag = 0;
           }

        }

        if(flag){
            s_layer[len2] = ptrArray[i];
            s_layer_count[len2]++;
            len2++;
        }

    }

    for(i = 0; i<len2; i++){
        int flag = 1;
        for(j = 0; j<i; j++){
           if(*s_layer[i] == t_layer[j]){
                t_layer_count[j]+= s_layer_count[i];
                flag = 0;
           }
        }
        if(flag){
           t_layer[len3] = *s_layer[i];
           t_layer_count[len3]+= s_layer_count[i];
            len3++;
        }

    }

    //sort value and count
    for(i=len3 - 2; i>=1; i--)
        for(j=0; j<=i; j++){
            int *tmp_p;
            int tmp_value;

            if(t_layer_count[j] > t_layer_count[j+1]){
                tmp_p = t_layer[j+1];
                t_layer[j+1] = t_layer[j];
                t_layer[j] = tmp_p;

                tmp_value = t_layer_count[j+1];
                t_layer_count[j+1] = t_layer_count[j];
                t_layer_count[j] = tmp_value;

            }
            else if(t_layer_count[j] == t_layer_count[j+1]){
                    if(*t_layer[j] > *t_layer[j+1]){
                        tmp_p = t_layer[j+1];
                        t_layer[j+1] = t_layer[j];
                        t_layer[j] = tmp_p;

                        tmp_value = t_layer_count[j+1];
                        t_layer_count[j+1] = t_layer_count[j];
                        t_layer_count[j] = tmp_value;
                    }


            }
        }

    //output
    for(i = 0; i<len3; i++){
        printf("%d %d\n",*t_layer[i], t_layer_count[i]);
    }


}



int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];

  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];

  count(ptrArray);

  return 0;
}


























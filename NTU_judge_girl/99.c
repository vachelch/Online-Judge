#include <stdio.h>
#include <stdlib.h>

int main()
{

    int number, n, m, flag = 1;

    scanf("%d %d", &n, &m);
    char * name[n][10];
    int a[n][m][m] , check[n][m][m], indice[n];
    int row_flag, col_flag, diag_flag, diag_rev_flag;

    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                check[i][j][k] = 0;
            }
        }
    }
    for(int i =0; i<n; i++){
        indice[i]= 0;
    }

    for(int i = 0; i<n; i++){
//        scanf("%s", &name[i]);
        for(int j = 0; j< m; j++){
            for(int k = 0; k<m; k++){
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    while(scanf("%d", &number) != EOF){
        int i, j, k;
        for(i = 0; i<n; i++){
            for(j=0; j< m; j++){
                for(k=0; k<m; k++){
                    if(a[i][j][k] == number){
                        check[i][j][k] = 1;
//                        printf("i: %d, j: %d, k: %d\n", i, j, k);

                        //row full 1
                        for(int h=0; h<m; h++){
                            row_flag = 1;
                            for(int l=0; l< m; l++){
                                if(check[i][h][l] == 0){
                                    row_flag = 0;
                                    break;
                                }
                            }
                            if(row_flag)
                                break;
                        }
                        for(int h=0; h<m; h++){
                            col_flag = 1;
                            for(int l=0; l< m; l++){
                                if(check[i][l][h] == 0){
                                    col_flag = 0;
                                    break;
                                }
                            }
                            if(col_flag)
                                break;
                        }

                        //diagonal full 1
                        diag_flag = diag_rev_flag = 1;
                        for(int h=0; h<m; h++){
                            if(check[i][h][h] == 0)
                                diag_flag = 0;
                            if(check[i][h][m-h-1] == 0)
                                diag_rev_flag = 0;
                        }

                        //ΕΠΆΟbingo
                        if(row_flag || col_flag || diag_flag || diag_rev_flag){
                            if(flag){
                                flag = 0;
                                printf("%d", number);
                            }
//                            printf(" %s", name[i]);
                                printf(" %d", i);
                        }
                        break;
                    }

                }
//                if(a[i][j][k] == number)
//                    break;
            }
        }
        if(flag == 0)
                break;
    }
    //print name
//    for(int i = 0; i<n; i++){
//        if(indice[i]){
//            printf(" %s", name[i]);
//        }
//
//    }


//    //test
//    int n;
//    scanf("%d", &n);
//    char *a[n][10];
//
//    for(int i= 0; i<n; i++){
//        scanf("%s", &a[i]);
//        printf("%s\n", a[i]);
//    }

    printf("\n");


    return 0;
}
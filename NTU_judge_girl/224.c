#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id( Employee *set, int n, int id ){
    for(int i=0; i<n; i++)
        if(set[i].id == id)
            return set + i;
}

Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i=0; i<n; i++){
        int first = strcmp(set[i].first_name, first_name);
        int last = strcmp(set[i].last_name, last_name);

        if(!first && !last)
            return set + i;
    }

}

Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    if (employee->id == employee->boss_id)
        return employee;
    Employee* boss = find_employee_by_id(set, n, employee->boss_id);
    return find_root_boss(set, n, boss);
}

int is_boss(Employee* set, int n, Employee* A, Employee* B){
    if(B->id == B->boss_id)
        return 0;
    if(A->id == B->boss_id)
        return 1;

    Employee* tmp = (Employee *) malloc(sizeof(struct employee));
    tmp = find_employee_by_id(set, n, B->boss_id);
    return is_boss(set, n, A, tmp);

}

int check_relationship(Employee* set, int n, Employee* A, Employee* B){
    if(is_boss(set, n, B, A))
        return 1;
    else if(is_boss(set, n, A, B))
        return 2;
    else if(find_root_boss(set, n, A) == find_root_boss(set, n, B))
        return 3;
    else
        return 4;
}









int main()
{
    int n, m;
    int i;
    Employee *set = NULL;
 
    scanf("%d", &n);
    init_storage(&set, n);
    for ( i = 0 ; i < n ; i++ )
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;
 
    scanf("%d", &m);
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%s %s", first_name_A, last_name_A);  
        A = find_employee_by_name(set, n, first_name_A, last_name_A);
 
        scanf("%s %s", first_name_B, last_name_B);  
        B = find_employee_by_name(set, n, first_name_B, last_name_B);
 
        type = check_relationship(set, n, A, B);
        switch(type){
            case 1:
                printf("subordinate\n"); break;
            case 2:
                printf("supervisor\n"); break;
            case 3:
                printf("colleague\n"); break;
            default:
                printf("unrelated\n"); break;
        }
    }
    free_storage(&set);
    return 0;
}
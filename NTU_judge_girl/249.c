#include <stdio.h>
#include <string.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
} Employee;

int N, Q;
Employee employees[32];

int is_subordinate(Employee *front, Employee *behind){
	if(front->id == front->boss_id)
		return 0;
	if(front->boss_id == behind->id)
		return 1;	
	//find the boss of front ,and update front
	Employee front_;
	for(int i=0; i<N; i++){
		if(employees[i].id == front->boss_id){
			front_.id = employees[i].id;
			front_.boss_id = employees[i].boss_id;

			return is_subordinate(&front_, behind);
		}
	}

	return 0;
}

int find_final_boss(Employee *front){
	if (front->id == front->boss_id)
		return front->id;
	Employee front_;
	for(int i=0; i<N;i++){
		if(front->boss_id == employees[i].id)
			return find_final_boss(&employees[i]);
	}
}


int is_colleague(Employee *front, Employee *behind){
	int front_boss_id = find_final_boss(front);
	int behind_boss_id = find_final_boss(behind);

	return (front_boss_id == behind_boss_id? 1:0);
}

void relationship(Employee *front, Employee *behind){
	for(int i=0; i<N; i++){
		int front_first = strcmp(employees[i].first_name, front->first_name);
		int front_last = strcmp(employees[i].last_name, front->last_name);
		int behind_first = strcmp(employees[i].first_name, behind->first_name);
		int behind_last = strcmp(employees[i].last_name, behind->last_name);

		if(!front_first && !front_last){
			front->id = employees[i].id;
			front->boss_id = employees[i].boss_id;
		}
		else if(!behind_first && !behind_last){
			behind->id = employees[i].id;
			behind->boss_id = employees[i].boss_id;
		}

	}
	if(is_subordinate(front, behind))
		printf("subordinate\n");
	else if(is_subordinate(behind, front))
		printf("supervisor\n");
	else if(is_colleague(front, behind))
		printf("colleague\n");
	else
		printf("unrelated\n");

	return;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %s %s %d", &employees[i].id, employees[i].first_name, employees[i].last_name, &employees[i].boss_id);
	
	scanf("%d", &Q);
	Employee front, behind;
	for(int i=0; i<Q; i++){
		scanf("%s %s %s %s", front.first_name, front.last_name, behind.first_name, behind.last_name);
		relationship(&front, &behind);
	}

	return 0;
}

























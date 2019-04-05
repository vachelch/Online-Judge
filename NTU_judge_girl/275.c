#include <stdio.h>
 
typedef unsigned long long Set;
void init(Set *set);
void add(Set *set, int i);
void has(Set set, int i);
Set setUnion(Set a, Set b);
Set setIntersect(Set a, Set b);
Set setDifference(Set a, Set b);

void init(Set *set){
	*set = 0;
	return ;
}

void add(Set *set, int i){
	Set tmp = 1;
	tmp = tmp << i;
	*set = *set | tmp;
	return;
}

void has(Set set, int i){
	Set tmp = 1;
	tmp = tmp <<i;
	Set result = set & tmp;
	if(result)
		printf("set has %d\n", i);
	else
		printf("set does not have %d\n", i);
	return;
}

Set setUnion(Set a, Set b){
	return a | b;
}

Set setIntersect(Set a, Set b){
	return a & b;
}

Set setDifference(Set a, Set b){
	return a ^ b;
}



int main()
{
  Set a, b, c;
 
  init(&a);
  add(&a, 3);
  add(&a, 5);
  add(&a, 2);
 
  init(&b);
  add(&b, 3);
  add(&b, 7);
  add(&b, 9);
 
  c = setUnion(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setIntersect(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setDifference(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  return 0;
}
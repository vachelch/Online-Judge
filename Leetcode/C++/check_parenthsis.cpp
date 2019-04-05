int func(struct ArrayStack s, char *input){
	int i;
	char c;

	for(i=0; i<strlen(input); i++){
		switch(input[i]){
			case '[':
				Push(s, input[i]);
				break;
			case '(':
				Push(s, input[i]);
				break;
			case '{':
				Push(s, input[i]);
				break;
			case ']':
				if(Pop(s) != input[i]) return 0;
				break;
			case ')':
				if(Pop(s) != input[i]) return 0;
				break;
			case '}':
				if(Pop(s) != input[i]) return 0;
				break;
		}
	}

	if(is_empty(s)) return 1;
	return 0;

}
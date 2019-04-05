#include <stdio.h>
int relation[32768][256] = {-1};

int main(int argc, char const *argv[])
{
	int N, E;

	int host[32786], in_party[32786];
	int friends[32786] ;

	int node1, node2;
	int h;
	int hoster;

	scanf("%d%d", &N, &E);

	for (int i = 0; i < E; ++i)
	{
		scanf("%d%d", &node1, &node2);
		relation[node1][friends[node1]] = node2;
		relation[node2][friends[node2]] = node1;
		friends[node1]++;
		friends[node2]++;
	}

	h = 0;
	while(scanf("%d", &hoster) != EOF){
		host[h] = hoster;
		in_party[hoster] = 1;
		h++;
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < 256; ++k)
			{
				if (relation[host[i]][k] == j)
				{
					in_party[j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{	
		if(in_party[i] != 1)
			printf("%d\n", i);
	}
	return 0;
}
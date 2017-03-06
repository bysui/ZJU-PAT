#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int ad, key, next;
}Node;

int comp(const void *a, const void *b)
{
	Node *n1, *n2;

	n1 = (Node*)a;
	n2 = (Node*)b;
	return n1->key - n2->key;
}

Node input[100001], out[100001];

int main()
{
	int i, n, head;
	int ad, key, next, index;

	scanf("%d %d", &n, &head);
	for (i = 0; i < n; i++){
		scanf("%d %d %d", &ad, &key, &next);
		input[ad].ad = ad;
		input[ad].key = key;
		input[ad].next = next;
	}
	if (head == -1){
		printf("0 -1\n");
		return 0;
	}
	index = 0;
	while (head != -1){
		out[index] = input[head];
		head = input[head].next;
		index++;
	}
	qsort(out, index, sizeof(Node), comp);
	printf("%d %05d\n", index, out[0].ad);
	for (i = 0; i < index - 1; i++)
		printf("%05d %d %05d\n", out[i].ad, out[i].key, out[i + 1].ad);
	printf("%05d %d -1\n", out[i].ad, out[i].key);
	return 0;
}
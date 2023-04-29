#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	//exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void queue_print(QueueType* q) {
	printf("Queue (front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("Queue is full.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("Queue is empty.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("Queue is empty.");
	return q->data[(q->front + 1)];
}
int main(void) {
	QueueType queue;
	int element;


	init_queue(&queue);

	while (1)
	{
		int num;
		printf("===== MENU ====\n");
		printf("1.Input data and Enqueue\n");
		printf("2.Deqeue and Print data\n");
		printf("3.print Queue\n");
		printf("4.Exit\n");
		printf("Select number: ");
		scanf_s("%d", &num);

		if (num == 1) {
			printf("\n");
			if (!is_full(&queue)) {
				printf("Input data : ");
				scanf_s("%d", &element);
				enqueue(&queue, element);
				printf("Enqueue: %d\n", element);
			}
			else printf("queue is full\n");


		}

		if (num == 2) {
			if (!is_empty(&queue)) {
				element = dequeue(&queue);
				printf("Dequeue : %d\n", element);
			}
			else printf("Queue is empty\n");

		}
		if (num == 3) {
			printf("\n");
			queue_print(&queue);
		}
		if (num == 4) {
			printf("Exit the program.\n");
			exit(1);
		}

		printf("\n");

	}
	return 0;
}
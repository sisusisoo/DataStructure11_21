#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20



int count,once;//once�� 20�� �ݺ��߿� �ѹ��� print�ϰ� 
int move_count;//�̵� ī��Ʈ
int list_count[2];//�� Ƚ���� �̵�Ƚ�� 
int select_total,select_total_move;//�������� ī��Ʈ ����
int insert_total_compare, insert_total_move;//�������� ī��Ʈ ����
int bubble_total_compare, bubble_total_move;//�������� ī��Ʈ ���� ���߿� ��� ���� ��� 


void swap(int a, int b, int temp) {
	temp = a;
	a=b ;
	b = temp;
}
void print_all(int list[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d->", list[i]);
		
	}
	printf("\n");
}

void selection_sort(int list[], int n) {
	int i, j, least,temp;
	count = 0;
	move_count = 0;
	temp = 0;
	//�������� �ڵ� 
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			count++;//�� ī��Ʈ 
		}
		//swap(list[i], list[least], temp);
		//�ڸ� �ٲٱ� ��� ****���ڸ��� �ٲ��� �ʰ��� ****
		if (list[i] !=list[least]) {
			temp = list[i];
			list[i] = list[least];
			list[least] = temp;
			move_count += 1;
		}
		if (once == 0) {
			print_all(list);
		}

	}
	
	list_count[0]=count;
	list_count[1]=move_count;
	once = 1;
}

//��������
void insertion_sort(int list[],int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--) {
			list[j + 1] = list[j];//ū���̸� �ڷ� ��ĭ�̵�
			list_count[0]++;//�� ī��Ʈ 
			list_count[1]++;//�̵� ī��Ʈ 
			
		}
		list_count[0]++;//���������� ���Ѱ� �ϳ��� ī��Ʈ 
		list[j + 1] = key;//���������� j--�� �Ǿ j+1�� �Űܰ�j�� key���� �� �� ����
		list_count[1]++;//�̵� ī��Ʈ 
		if(once ==0) print_all(list);//ó�� �ѹ��� �� ����ϰ� 
	}
}


//���������� �Ἥ �����ѹ��ϴ� ����Ŭ 
void insertion_cycle() {
	int i;

	int n = MAX;
	int list[MAX];
	int count_p;



	if (once == 0)printf("����Ŭ ���� \n");

	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		if(once==0)	printf("%d->", list[i]);
	
	}
	if (once == 0) { printf("\n"); }
	insertion_sort(list,MAX);

	if (once == 0) {
		for (i = 0; i < n; i++) printf("%d->", list[i]);
		printf("\n");
		printf("compare count : %d\n", list_count[0]);
		printf("move count : %d\n", list_count[1]);

		insert_total_compare += list_count[0];
		insert_total_move += list_count[1];
		printf("����Ŭ ��\n");
	}

}

//÷���� ����Ʈ �ǰ��� 
void selecet_cycle_print_Ver() {
	int i;

	int n = 20;
	int list[MAX];
	int count_p;



	printf("����Ŭ ���� \n");

	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		printf("%d->", list[i]);
	}
	printf("\n");

	selection_sort(list, MAX);

	for (i = 0; i < n; i++) printf("%d->", list[i]);
	printf("\n");
	printf("compare count : %d\n",list_count[0]);
	printf("move count : %d\n", list_count[1]);
	select_total += list_count[0];
	select_total_move += list_count[1];
	printf("����Ŭ ��\n");

}
//����Ʈ���ϰ� ��� ���� �޼��� 
void selecet_cycle() {
	int i;

	int n = 20;
	int list[MAX];
	int count_p;




	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		
	}
	selection_sort(list, MAX);
	select_total += list_count[0];
	select_total_move += list_count[1];


}
void bubble_sort(int list[], int n) {
	int i, j, temp;
	temp = 0;
	for (i = n - 1; i > 0; i--) {//�ε����� 0���� �����ؼ�  n-1
		for (j = 0; j < i; j++) {
			list_count[0]++;//�� ī��Ʈ
			if (list[j] >list[j + 1]) {
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
				list_count[1]++;//�̵� ī��Ʈ
				if (once == 0) print_all(list);
			}
		}


	}
}

void bubble_sort_cycle()
{
	int i;
	int n = MAX;
	int list[MAX];




	if (once == 0)printf("����Ŭ ���� \n");

	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		if (once == 0)	printf("%d->", list[i]);

	}
	if (once == 0) { printf("\n"); }
	bubble_sort(list, MAX);

	if (once == 0) {
		for (i = 0; i < n; i++) printf("%d->", list[i]);
		printf("\n");
		printf("compare count : %d\n", list_count[0]);
		printf("move count : %d\n", list_count[1]);

		bubble_total_compare += list_count[0];
		bubble_total_move += list_count[1];
		printf("����Ŭ ��\n");
		printf("\n");
	}
}

int main() {

	srand(time(NULL));
	printf("��������---------------------------------------------------------------\n");
	selecet_cycle_print_Ver();
	srand(time(NULL));// �޼��� �ȿ� �����ϱ� ������ �ݺ� �׷��� �����Լ� for�� �ۿ� 
	for (int i = 0; i < 19; i++) {//������ �ѹ� ���������ϱ� 

	
		//printf("rand : %d\n", rand() % 100);
		selecet_cycle();
	}
	printf(" compare count avg:%f\n ", (float)select_total/ (float)20);
	printf("move count avg:%f\n ", (float)select_total_move/ (float)20);


	//ī��Ʈ�� �ʱ�ȭ 
	once = 0;//�ٽ� �������Ŀ��� ù��°�� ����Ʈ�ǰ� 0���� �ʱ�ȭ 
	list_count[0] = list_count[1] = 0;//�� ī��Ʈ�� �̵�ī��Ʈ �ʱ�ȭ
	printf("\n");
	printf("\n");


	printf("��������---------------------------------------------------------------\n");
	insertion_cycle();
	once = 1;

	for (int j = 0; j < 19; j++) {
		//printf("rand : %d\n", rand() % 100);
		insertion_cycle();
	}
	printf(" compare count total:%d , avg:%f\n ", insert_total_compare, (float)insert_total_compare / (float)20);
	printf("move count total:%d, avg:%f\n ", insert_total_move, (float)insert_total_move / (float)20);

	printf("\n");
	//ī��Ʈ�� �ʱ�ȭ 
	once = 0;//�ٽ� �������Ŀ��� ù��°�� ����Ʈ�ǰ� 0���� �ʱ�ȭ 
	list_count[0] = list_count[1] = 0;//�� ī��Ʈ�� �̵�ī��Ʈ �ʱ�ȭ

	printf("��������---------------------------------------------------------------\n");
	bubble_sort_cycle();
	once = 1;

	for (int j = 0; j < 19; j++) {
		//printf("rand : %d\n", rand() % 100);
		bubble_sort_cycle();
	}
	printf(" compare count total:%d , avg:%f\n ", bubble_total_compare, (float)(bubble_total_compare / (float)20));
	printf("move count total:%d, avg:%f\n ", bubble_total_move, (float)bubble_total_move / (float)20);



	return 0;
}
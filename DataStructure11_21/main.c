#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20



int count,once;//once는 20번 반복중에 한번만 print하게 
int move_count;//이동 카운트
int list_count[2];//비교 횟수와 이동횟수 
int select_total,select_total_move;//선택정렬 카운트 총합
int insert_total_compare, insert_total_move;//삽입정렬 카운트 총합
int bubble_total_compare, bubble_total_move;//버블정렬 카운트 총합 나중에 평균 낼때 사용 


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
	//선택정렬 코드 
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			count++;//비교 카운트 
		}
		//swap(list[i], list[least], temp);
		//자리 바꾸기 기능 ****제자리는 바꾸지 않게함 ****
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

//삽입정렬
void insertion_sort(int list[],int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--) {
			list[j + 1] = list[j];//큰값이면 뒤로 한칸이동
			list_count[0]++;//비교 카운트 
			list_count[1]++;//이동 카운트 
			
		}
		list_count[0]++;//마지막으로 비교한거 하나더 카운트 
		list[j + 1] = key;//마지막으로 j--가 되어서 j+1로 옮겨간j에 key값이 들어갈 수 있음
		list_count[1]++;//이동 카운트 
		if(once ==0) print_all(list);//처음 한번만 다 출력하게 
	}
}


//삽입정렬을 써서 정렬한번하는 싸이클 
void insertion_cycle() {
	int i;

	int n = MAX;
	int list[MAX];
	int count_p;



	if (once == 0)printf("싸이클 시작 \n");

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
		printf("싸이클 끝\n");
	}

}

//첨에만 프린트 되게함 
void selecet_cycle_print_Ver() {
	int i;

	int n = 20;
	int list[MAX];
	int count_p;



	printf("싸이클 시작 \n");

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
	printf("싸이클 끝\n");

}
//프린트안하고 평균 내는 메서드 
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
	for (i = n - 1; i > 0; i--) {//인덱스는 0부터 시작해서  n-1
		for (j = 0; j < i; j++) {
			list_count[0]++;//비교 카운트
			if (list[j] >list[j + 1]) {
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
				list_count[1]++;//이동 카운트
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




	if (once == 0)printf("싸이클 시작 \n");

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
		printf("싸이클 끝\n");
		printf("\n");
	}
}

int main() {

	srand(time(NULL));
	printf("선택정렬---------------------------------------------------------------\n");
	selecet_cycle_print_Ver();
	srand(time(NULL));// 메서드 안에 넣으니까 같은값 반복 그래서 메인함수 for문 밖에 
	for (int i = 0; i < 19; i++) {//위에서 한번 실행했으니까 

	
		//printf("rand : %d\n", rand() % 100);
		selecet_cycle();
	}
	printf(" compare count avg:%f\n ", (float)select_total/ (float)20);
	printf("move count avg:%f\n ", (float)select_total_move/ (float)20);


	//카운트값 초기화 
	once = 0;//다시 삽입정렬에서 첫번째만 프린트되게 0으로 초기화 
	list_count[0] = list_count[1] = 0;//비교 카운트와 이동카운트 초기화
	printf("\n");
	printf("\n");


	printf("삽입정렬---------------------------------------------------------------\n");
	insertion_cycle();
	once = 1;

	for (int j = 0; j < 19; j++) {
		//printf("rand : %d\n", rand() % 100);
		insertion_cycle();
	}
	printf(" compare count total:%d , avg:%f\n ", insert_total_compare, (float)insert_total_compare / (float)20);
	printf("move count total:%d, avg:%f\n ", insert_total_move, (float)insert_total_move / (float)20);

	printf("\n");
	//카운트값 초기화 
	once = 0;//다시 삽입정렬에서 첫번째만 프린트되게 0으로 초기화 
	list_count[0] = list_count[1] = 0;//비교 카운트와 이동카운트 초기화

	printf("버블정렬---------------------------------------------------------------\n");
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
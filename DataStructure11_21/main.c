#include<stdio.h>
#include <stdlib.h>
#define MAX 20



int count,once;//once는 20번 반복중에 한번만 print하게 
int move_count;//이동 카운트
int list_count[2];//비교 횟수와 이동횟수 
int select_total,select_total_move;


void swap(int list[], int list1[], int temp) {
	temp = list;
	list = list1;
	list1 = temp;
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
			count++;
		}
		//swap(list[i], list[least], temp);
		//자리 바꾸기 기능 
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
		move_count += 1;
		if (once == 0) {
			print_all(list);
		}

	}
	
	list_count[0]=count;
	list_count[1]=move_count;
	once = 1;
}


//첨에만 프린트 되게함 
void selecet_cycle_print_Ver() {
	int i;

	int n = 20;
	int list[MAX];
	int count_p;


	srand(time(NULL));
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


	srand(time(NULL));


	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		
	}
	selection_sort(list, MAX);
	select_total += list_count[0];
	select_total_move += list_count[1];


}



int main() {

	
	selecet_cycle_print_Ver();
	for (int i = 0; i < MAX; i++) {
		selecet_cycle();
	}
	select_total, select_total_move;
	printf(" compare count avg:%d\n ", select_total/20);
	printf("move count avg:%d\n ", select_total_move/20);


	return 0;
}
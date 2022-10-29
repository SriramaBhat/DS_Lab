//Add two time 

#include <stdio.h>
#include <stdlib.h>

struct time{
	int hours;
	int min;
	int sec;
};
typedef struct time STT;

void validate(STT *p){
	if(p->sec>=60){
		p->min += (int)(p->sec/60);
		p->sec = p->sec % 60;
	}
	if(p->min>=60){
		p->hours += (int)(p->min/60);
		p->min = p->min % 60;
	}
	if(p->hours>=60){
		p->hours = p->hours % 24;
	}
}
void display(STT *p){
	printf("%d:%d:%d",p->hours,p->min,p->sec);
}
void read(STT *p){
	printf("Enter the hour:");
	scanf("%d",&p->hours);
	printf("Enter the min:");
	scanf("%d",&p->min);
	printf("Enter the sec:");
	scanf("%d",&p->sec);
	validate(p);
}

void add(STT *t1){
	STT time2;
	read(&time2);
	time2.sec=time2.sec + t1->sec;
	time2.min=time2.min + t1->min;
	time2.hours=time2.hours + t1->hours;
	validate(&time2);
	display(&time2);
}

void main(){
	int ch;
	STT time;
	read(&time);
	for(;;){
		printf("\n1.Read\n2.Display\n3.Add two time\nEnter your choice:");
		fflush(stdin);
		scanf("%d",&ch);
		switch (ch){
			case 1:read(&time);break;
			case 2:display(&time);break;
			case 3:add(&time);break;
			default:
				printf("\n%d is Invalid Choice\n",ch);
		}
	}
}

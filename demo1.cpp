/*
 * 停车场管理
 * 
 * 问题描述：
 * 设停车场是一个可停放n辆汽车的狭长通道，且只有一个大门可供汽车进出。
 * 汽车在停车场内按车辆到达时间的先后顺序，依次由北向南排列（大门在最
 * 南端，最先到达的第一辆车停放在停车场的最北端）,若停车场内已停满n辆
 * 汽车，则后来的汽车只能在门外的便道上等候，一旦有车开走，则排在便道
 * 上的第一辆车即可开入；当停车场内某辆车要离开时，在它之后进入的车辆
 * 必须先退出车场为它让路，待该辆车开出大门外，其他车辆再按原次序进入
 * 车场，每辆停放在车场的车在它离开停车场时必须按它停留的时间长短交纳
 * 费用。试为停车场编制按上述要求进行管理的模拟程序。
 * 
 * 基本要求：
 * 以栈模拟停车场，以队列模拟车场外的便道，按照从终端读入的输入数据
 * 序列进行模拟管理。每一组输入数据包括三个数据项：汽车“到达”或“离去”
 * 信息、汽车牌照号码以及到达或离去的时刻。对每一组输入数据进行操作
 * 后的输出信息为：若是车辆到达，则输出汽车在停车场内或便道上的停车
 * 位置；若是车辆离去，则输出汽车在停车场内停留的时间和应交纳的费用
 * （在便道上停留的时间不收费）。栈以顺序结构实现，队列以链表结构实现。
 * 
 * 测试数据：
 * 设n=2,输入数据为：（‘A’，1，5），（‘A’，2，10），（‘D’，1，15），
 * （‘A’，3， 20）， （‘A’，4，25），（‘A’，5，30），（‘D’，2，35），
 * （‘D’，4，40），（‘E’，0，0）。每一组输入数据包括三个数据项：
 * 汽车“到达”或“离去”信息、汽车牌照号码及到达或离去的时刻，其中，
 * ‘A’表示到达；‘D’表示离去，‘E’表示输入结束。
 * 
 * 实现提示：
 * 需另设一个栈，临时停放为给要离去的汽车让路而从停车场退出来的汽车，
 * 也用顺序存储结构实现。输入数据按到达或离去的时刻有序。栈中每个元素
 * 表示一辆汽车，包含两个数据项：汽车的牌照号码和进入停车场的时刻。
 */

#include<bits/stdc++.h>
//#include "iostream"
//using namespace std;

#define VOLUME 2	//停车场容量
#define PRICE  1	//停车场收费单价
typedef int Status;	//函数返回状态
using namespace std;

//停车场内车辆信息
typedef struct CarNode {
	char		carnum;		//车牌号码
	int			reachTime;	//停车场到达时间
	int			leaveTime;	//离开停车场时间
}CarNode;
//停车场-栈
typedef struct SqCarPark {
	CarNode		*stack[VOLUME+1];	//栈顶
	int			stacksize;	//已停数目
}SqCarPark;

//便道上车辆信息
typedef struct QueueNode {
	CarNode		*data;		//基本车辆信息
	struct QueueNode *next; //线性表的下一个节点
}QueueNode;
//便道-队列
typedef struct QueueLine {
	QueueNode	*head;		//头节点
	QueueNode	*rear;		//上一个节点
}QueueLine;

/*********************子函数**********************/
Status InitStack(SqCarPark *s);	//初始化栈
Status InitQueue(QueueLine *q);	//初始化队列
Status arrival(SqCarPark *Enter, QueueLine *Wait, int carnum, int imin);	//到达
Status leave(SqCarPark *Enter, SqCarPark *Temp, QueueLine *Wait, int carnum, int imin);	//离开
void payment(CarNode *c);	//收费信息输出


Status main() {
	SqCarPark	Enter, Temp;
	QueueLine	Wait;
	char		ch;	//输入命令标志
	int			carnum;	//车牌号
	int			imin;	//到达时间

	InitStack(&Enter);
	InitStack(&Temp);
	InitQueue(&Wait);

	while (1) {
		printf("请输入：");
		//循环获取输入数据
		while (1) {
			cin >> ch >> carnum >> imin;
		//	scanf("%c %d %d", &ch, &carnum, &imin);
			if (ch == 'A' || ch == 'D' || ch == 'E')	break;
			else {
				printf("请正确输入数据，如：(A,1,5)\n");
				printf("请尝试重新输入:");
			}
		}
		switch (ch) {
		case 'A': arrival(&Enter, &Wait, carnum, imin);	break;	//车辆到达
		case 'D': leave(&Enter, &Temp, &Wait, carnum, imin); break;	//车辆离开
		case 'E': exit(0);						//结束，退出主程序
		default: break;
		}
	}
}

/*
* @ brief 初始化栈
*/
Status InitStack(SqCarPark *s) {
	//创建一个空栈
	int i = 0;
	s->stacksize = 0;
	for (i = 0; i < VOLUME; i++) {
		s->stack[s->stacksize] = NULL;
	}
	//s->base = (CarNode *)malloc(VOLUME * sizeof(CarNode));
	//if (!s->base)	return -1;
	//s->top = s->base;
	//s->stacksize = 0;
	return 1;
} //InitStack

  /*
  * @ brief 初始化队列
  */
Status InitQueue(QueueLine *q) {
	q->head = (QueueNode *)malloc(sizeof(QueueNode));
	if (!q->head)		return -1;
	q->head->next = NULL;
	q->rear = q->head;
	return 1;
} //InitQueue

  /*
  * @ brief 车辆到达
  */
Status arrival(SqCarPark *Enter, QueueLine *Wait, int carnum, int imin) {
	CarNode *s;
	QueueNode *q;
	s = (CarNode *)malloc(sizeof(CarNode));
	s->carnum = carnum;
	if (Enter->stacksize < VOLUME) {
		Enter->stacksize++;
		s->reachTime = imin;
		Enter->stack[Enter->stacksize] = s;
		return 1;
	}
	else {
		q = (QueueNode *)malloc(sizeof(QueueNode));
		q->data = s;
		q->next = NULL;
		Wait->rear->next = q;
		Wait->rear = q;
		return 1;
	}
}

/*
* @ brief 车辆离开
*/
Status leave(SqCarPark *Enter, SqCarPark *Temp, QueueLine *Wait, int carnum, int imin) {
	CarNode *s, *t;
	QueueNode *q;
	if (Enter->stacksize >= 0) {
		//需要离开的车辆前面的车辆进入临时停车区
		while (Enter->stack[Enter->stacksize]->carnum != carnum) {
			Temp->stacksize++;
			Temp->stack[Temp->stacksize] = Enter->stack[Enter->stacksize];
			Enter->stack[Enter->stacksize] = NULL;
			Enter->stacksize--;
		}
		//需要离开的车辆
		s = Enter->stack[Enter->stacksize];
		s->leaveTime = imin;
		payment(s);
		Enter->stack[Enter->stacksize] = NULL;
		Enter->stacksize--;
		//临时停车区的车辆移动回停车场内
		while (Temp->stacksize > 0) {
			Enter->stacksize++;
			Enter->stack[Enter->stacksize] = Temp->stack[Temp->stacksize];
			Temp->stack[Temp->stacksize] = NULL;
			Temp->stacksize--;
		}

		//判断便道上是否有车，把便道上的车移动到停车场内
		if (Wait->head != Wait->rear) {
			q = Wait->head->next;
			t = q->data;
			t->reachTime = imin;
			Enter->stacksize++;
			Enter->stack[Enter->stacksize] = t;
			Wait->head->next = q->next;
			if (q == Wait->rear) {	//队列中只有一个数据,操作后队列为空
				Wait->rear = Wait->head;
			}
			free(q);
		}
	}
	return 1;
}

/*
* @ brief 收费信息输出
*/
void payment(CarNode *c) {
	int ptime, pmoney;
	ptime = c->leaveTime - c->reachTime;
	pmoney = ptime * PRICE;
	printf("%d号车共停车%d时间，需缴费%d元。\n", c->carnum, ptime, pmoney);
	free(c);
}
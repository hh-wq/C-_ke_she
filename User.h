#ifndef USER_H
#define USER_H

#include<conio.h>
#include<windows.h>
#include<ctime>
#include"assistance.h"
#include"orderdata.h"
#include"DishClass.h"

class User
{
public:
	//�û��˵�
	void UserMenu(int user);
	//�û��ѵ��Ʒ����
	int DishNum = 0;
	//�û�ѡ��Ĳ�Ʒid����
	int UserDish[ORDERINF_COUNT];
	//�û�ѡ���Ʒ�ĵ�ǰ�ܼ�
	float TotalPrice = 0;
	//��֧�����
	int bill;

private:
	//�û�id
	int UserID;
	//��ѡ��Ʒ
	Dish* orderInf[ORDERINF_COUNT];

	//���
	bool OrderDish();
	//����
	bool Pay();
	//��ѯ��������
	bool QueryOrder( Order &order);
	//��ѯ���ж���
	void QueryAllOrder();
	//��Ʒ����
	bool DishScore();

};

#endif

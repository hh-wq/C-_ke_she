#ifndef ORDERDATA_H
#define ORDERDATA_H

#include "assistance.h"

#define MAX_CUSTOMERS 5000

struct Node {
	Order orderData;
	Node* next;
};

class CustomerClass {
public:
	CustomerClass();
	~CustomerClass();

	bool GetID(int id, Customer* c);	//��ѯ�û�
	bool AddC(Customer c);	//�����û�

	void ShowAll();

private:
	Customer customers[MAX_CUSTOMERS];
	int customerNum;
};
class OrderClass {
public:
	OrderClass();
	~OrderClass();

	bool GetID(int id, Order* order);	//���ڲ�ѯ�Ƿ��иö���������з����棬�Ҹ���һ�����ݸ��� order
	int* GetOrder(int userID);	//��ѯ���û������ж���������һ�����飬�������ж�����
	bool AddOrder(Order order);	//���Ӷ���
	bool DeleteOrder(int id);	//ɾ������
	void ShowAll();
	bool Pay(int id);
private:
	Node* first;
	int length;
};

#endif
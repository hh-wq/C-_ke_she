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

	bool GetID(int id, Customer* c);	//查询用户
	bool AddC(Customer c);	//增加用户

	void ShowAll();

private:
	Customer customers[MAX_CUSTOMERS];
	int customerNum;
};
class OrderClass {
public:
	OrderClass();
	~OrderClass();

	bool GetID(int id, Order* order);	//用于查询是否有该订单，如果有返回真，且复制一份数据给到 order
	int* GetOrder(int userID);	//查询该用户的所有订单，返回一个数组，包括所有订单号
	bool AddOrder(Order order);	//增加订单
	bool DeleteOrder(int id);	//删除订单
	void ShowAll();
	bool Pay(int id);
private:
	Node* first;
	int length;
};

#endif
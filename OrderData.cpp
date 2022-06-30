#include "orderdata.h"	
#include <fstream>


CustomerClass::CustomerClass()
{
	Customer _customer ;
	customerNum = 0;
	std::ifstream inf("customer.dat", std::ios::in | std::ios::binary);
	if (!inf)
	{
		std::cout << "no customer.dat file!!!" << std::endl;
		return;
	}

	inf.read(reinterpret_cast<char*>(&_customer), sizeof(_customer));

	while (!inf.eof())
	{
		customers[customerNum] = _customer;
		customerNum++;
		inf.read(reinterpret_cast<char*>(&_customer), sizeof(_customer));
	}
	inf.close();
}

CustomerClass::~CustomerClass()
{
	std::ofstream outf("customer.dat", std::ios::out | std::ios::binary);
	for (int i = 0; i < customerNum; i++)
	{
		outf.write(reinterpret_cast<char*>(customers + i), sizeof(Customer));
	}
	outf.close();
}


bool CustomerClass::GetID(int id, Customer* c)
{
	for (int i = 0; i < customerNum; i++)
	{
		if (customers[i].id == id)
		{
			*c = customers[i];
			return true;
		}
	}
	return false;
}

bool CustomerClass::AddC(Customer c)
{
	int i;
	for (i = 0; i < customerNum; i++)
	{
		if (customers[i].id == c.id)
		{
			return false;
		}
	}
	customers[i] = c;
	customerNum++;
	return true;
}

void CustomerClass::ShowAll()
{
	std::cout << std::endl;
	for (int i = 0; i < customerNum; i++)
	{
		std::cout << "user:" << customers[i].id << "\tpassword:" << customers[i].password << std::endl;
	}
}

OrderClass::OrderClass()
{
	Order _order;
	length = 0;
	first = NULL;
	std::ifstream inf("order.dat", std::ios::in | std::ios::binary);
	if (!inf)
	{
		std::cout << "no order.dat file!!!" << std::endl;
		return;
	}

	inf.read(reinterpret_cast<char*>(&_order), sizeof(_order));
	if (inf.eof())
	{
		std::cout << "order.dat is empty!!!" << std::endl;
		inf.close();
		return;
	}

	Node* node = new Node;
	node->orderData = _order;
	node->next = NULL;
	first = node;
	length++;

	inf.read(reinterpret_cast<char*>(&_order), sizeof(_order));
	while (!inf.eof())
	{
		Node* next = new Node;

		next->orderData = _order;	
		next->next = NULL;

		node->next = next;	

		node = next;	

		length++;

		inf.read(reinterpret_cast<char*>(&_order), sizeof(_order));
	}
	inf.close();
}

OrderClass::~OrderClass()
{
	std::ofstream outf("order.dat", std::ios::out | std::ios::binary);
	Node* next;
	for (int i = 0; i < length; i++)
	{
		if (first != NULL)
		{
			outf.write(reinterpret_cast<char*>(&(first->orderData)), sizeof(Order));
			next = first->next;
			delete first;
			first = next;
		}
	}
	outf.close();
}


bool OrderClass::GetID(int id, Order* order)
{
	Node* node = first;
	for (int i = 0; i < length; i++)
	{
		if ((node->orderData).id == id)
		{
			*order = node->orderData;
			return true;
		}
		node = node->next;
	}
	return false;
}

int* OrderClass::GetOrder(int userID)
{
	Node* node = first;
	int temp[100];
	temp[0] = 0;
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if ((node->orderData).cid == userID)
		{
			temp[0]++;
			temp[temp[0]] = (node->orderData).id;
		}
		node = node->next;
	}
	int* result = (int*)malloc(temp[0] + 1);
	for (i = 0; i <= temp[0]; i++)
	{
		result[i] = temp[i];
	}
	return result;
}

bool OrderClass::AddOrder(Order order)
{
	Node* node = first;
	if (first != NULL)
	{
		if ((node->orderData).id == order.id)
		{
			return false;
		}
		for (int i = 1; i < length; i++)
		{
			node = node->next;
			if ((node->orderData).id == order.id)
			{
				return false;
			}
		}
	}
	Node* newNode = new Node;

	newNode->orderData = order;
	newNode->next = NULL;

	if (node == NULL)
	{
		first = newNode;
	}
	else
	{
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = newNode;
	}
	length++;
	return true;
}

bool OrderClass::DeleteOrder(int id)
{
	Node* node = first;
	if ((node->orderData).id == id)
	{
		Node* temp;
		temp = first;
		first = first->next;
		delete temp;
		length--;
		return true;
	}
	for (int i = 1; i < length; i++)
	{
		if ((node->next->orderData).id == id)	
		{
			Node* temp;
			temp = node->next;
			node->next = temp->next;
			delete temp;
			length--;
			return true;
		}
		node = node->next;
	}
	return false;
}

void OrderClass::ShowAll()
{
	Node* node = first;
	std::cout << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << "id:" << (node->orderData).id << "\tCustomerID:" << (node->orderData).cid << "\ttime:" <<
			(node->orderData).time.year << "-" << (node->orderData).time.month << "-" << (node->orderData).time.day
			<< "\tstatus:";
		if ((node->orderData).os)
			std::cout << "ok" << std::endl;
		else
			std::cout << "fail" << std::endl;
		node = node->next;
	}
}
bool OrderClass::Pay(int id)
{
	Node* node = first;

	for (int i = 0; i < length; i++)
	{
		if ((node->orderData).id == id)
		{
			node->orderData.os = true;
			return true;
		}
		node = node->next;
	}
	return false;
}
#include "Start.h"


bool root() {
	cout << "���������Ա�û���";
	string UserID;
	cin >> UserID;
	cout << "���������룺";
	string Password;
	cin >> Password;
	if (!UserID.compare("root") && !Password.compare("123456")) return true;
	else return false;
}

void Start::StartMenu()
{
	system("cls");
	cout << "----------��ʼ----------" << endl << endl;
	cout << "1.�û���¼" << endl;
	cout << "2.����Ա��¼" << endl;
	cout << "3.�û�ע��" << endl;
	cout << "chioce:";
	int choice;
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		if (UserLogin())
		{
			cout << "��¼�ɹ���" << endl;
			User User1;
			User1.UserMenu(id);
		}
		else
			cout << "��¼ʧ�ܣ������˺������Ƿ���������" << endl;
		break;
	case 2:
		if (root()) manage(); else cout << "��¼ʧ�ܣ������˺������Ƿ���������" << endl;
		break;

	case 3:
		if (UserRegist())
		{
			cout << "ע��ɹ�����Ϊ���Զ���¼" << endl;
			cout << "��������Լ���" << endl;
			while (!_kbhit());
			User User1;
			User1.UserMenu(id);
		}
		else
			cout << "ע��ʧ�ܣ��˺��ظ�" << endl;
		break;
	}
}

bool Start::UserLogin()
{
	cout << "������ID��";
	int UserID;
	cin >> UserID;
	id = UserID;
	cout << "���������룺";
	int Password;
	cin >> Password;
	Customer customer;
	CustomerClass customer_class;
	if (customer_class.GetID(UserID, &customer))
		if (customer.password== Password) {
			return true;
		}
	return false;
}

bool Start::UserRegist()
{
	Customer customer=Customer();
	

	cout << "�������������ƣ�";
	cin >> customer.name;
	cout << "������ID��";
	cin >> customer.id;
	while (1)
	{
		cout << "���������룺";

		cin >> customer.password;
		cout << "���ٴ��������룺";
		int Password_tmp;
		cin >> Password_tmp;
		if (customer.password!=Password_tmp) {
			cout << "�������벻һ�£�����������";
			cin >> Password_tmp;
			
		}
		else
		{
			
			break;
		}
			
	}
	id = customer.id;
	CustomerClass customer_class;
	return customer_class.AddC(customer);
}

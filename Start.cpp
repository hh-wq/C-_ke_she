#include "Start.h"


bool root() {
	cout << "请输入管理员用户：";
	string UserID;
	cin >> UserID;
	cout << "请输入密码：";
	string Password;
	cin >> Password;
	if (!UserID.compare("root") && !Password.compare("123456")) return true;
	else return false;
}

void Start::StartMenu()
{
	system("cls");
	cout << "----------开始----------" << endl << endl;
	cout << "1.用户登录" << endl;
	cout << "2.管理员登录" << endl;
	cout << "3.用户注册" << endl;
	cout << "chioce:";
	int choice;
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		if (UserLogin())
		{
			cout << "登录成功！" << endl;
			User User1;
			User1.UserMenu(id);
		}
		else
			cout << "登录失败！请检查账号密码是否输入有误" << endl;
		break;
	case 2:
		if (root()) manage(); else cout << "登录失败！请检查账号密码是否输入有误" << endl;
		break;

	case 3:
		if (UserRegist())
		{
			cout << "注册成功！已为您自动登录" << endl;
			cout << "按任意键以继续" << endl;
			while (!_kbhit());
			User User1;
			User1.UserMenu(id);
		}
		else
			cout << "注册失败！账号重复" << endl;
		break;
	}
}

bool Start::UserLogin()
{
	cout << "请输入ID：";
	int UserID;
	cin >> UserID;
	id = UserID;
	cout << "请输入密码：";
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
	

	cout << "请输入您的名称：";
	cin >> customer.name;
	cout << "请输入ID：";
	cin >> customer.id;
	while (1)
	{
		cout << "请输入密码：";

		cin >> customer.password;
		cout << "请再次输入密码：";
		int Password_tmp;
		cin >> Password_tmp;
		if (customer.password!=Password_tmp) {
			cout << "两次密码不一致，请重新输入";
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

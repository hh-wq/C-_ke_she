
#ifndef Start_H

#define Start_H

#include<conio.h>
#include"User.h"
#include"manage.h"

class Start
{
public:
	//开始界面
	void StartMenu();
private:
	//用户登录
	bool UserLogin();
	//用户注册
	bool UserRegist();
	int id;
	//

};

#endif

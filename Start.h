
#ifndef Start_H

#define Start_H

#include<conio.h>
#include"User.h"
#include"manage.h"

class Start
{
public:
	//��ʼ����
	void StartMenu();
private:
	//�û���¼
	bool UserLogin();
	//�û�ע��
	bool UserRegist();
	int id;
	//

};

#endif

#include <iostream>
using namespace std;
#include "userh6.h"
#include "mraa.hpp"
#include "mktxt.h";
#include "sendfile/sendfile.h"
using namespace mraa;


int main(void) {
	cout << "Hello IOT2000." << endl;
	while(true){

	UserH6 LH6;

	//USER��LED����ʾ�Լ�ѭ����ʾ
	//LH6.LightH6();
	//LH6.LightAll();

	//��������״̬0/1��¼��txt�ļ���
	MKdir mk;
	mk.mkdir();
	//��linux�ϵ�txt�ĵ����䵽Windows��
	SendFile sf;
	sf.sendfile();
	//ÿ60sѭ��һ�Σ�֮ǰ����Ϊ1sʱ���г���
	sleep(1);
	}
	return 0;
}


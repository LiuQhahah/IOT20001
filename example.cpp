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

	//USER的LED灯显示以及循环显示
	//LH6.LightH6();
	//LH6.LightAll();

	//将按键的状态0/1记录到txt文件上
	MKdir mk;
	mk.mkdir();
	//将linux上的txt文档传输到Windows上
	SendFile sf;
	sf.sendfile();
	//每60s循环一次，之前设置为1s时，有出错。
	sleep(1);
	}
	return 0;
}


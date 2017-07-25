/*
 * Mkdir.cpp
 *
 *  Created on: 2017年7月16日
 *      Author: Administrator
 */


//#include <io.h>
#include <stddef.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "mraa.hpp"
#include "mktxt.h"
using namespace std;

void MKdir:: mkdir(){
	//ss 用于int转string的中间态
	std::stringstream ss;
	string buffer;

	/*
	 * 读取USER BUTTON按键的状态
		//export the pin 63 (USER button)
		ofstream outfile;
		outfile.open("/sys/class/gpio/export");
		outfile << "63";
		outfile.close();
		//read out the status of the USER Button
		ifstream infile;
		infile.open("/sys/class/gpio/gpio63/value");
		infile >> buffer;
		infile.close();
		//display the status in the console
		cout<<buffer<<endl;
	 	 */


		//read out the status of the  arduino Pin 13
		//设置2号引脚为输入模式，类似于Arduino的pinMode
			mraa:: Gpio* button_pin = NULL;
			button_pin = new mraa::Gpio(2, true, false);
			button_pin->dir(mraa::DIR_IN);
			//读取2号引脚值，并转化为string类型进行保存；
			int pin2 = button_pin->read();
			cout<<pin2<<endl;

			ss<<pin2;
			ss>>buffer;
			//new 一个Gpio对象，设置13引脚为输出模式，亮灭有2号引脚值决定
			mraa:: Gpio* d_pin = NULL;
			d_pin = new mraa::Gpio(13, true, false);
			d_pin->dir(mraa::DIR_OUT);
			d_pin->write(pin2);


			//只储存0/1,out:为输出（写）而打开文件，trunc：如果文件已存在则先删除文件
			//使用cin,cout进行输入输出，http://blog.csdn.net/kingstar158/article/details/6859379
			ofstream location_out;
			location_out.open("location_out.txt", std::ios::out | std::ios::trunc);
			if (location_out.is_open()){
				location_out << buffer << endl;
				cout<<"location_out.txt can  open"<<endl;
			}else{
				cout<<"location_out.txt not open"<<endl;
			}
			location_out.close();

}




/*
 * UserH6.cpp
 *
 *  Created on: 2017年7月16日
 *      Author: Administrator
 */
#include <iostream>
#include "mraa.hpp"
#include "userh6.h"
#include <sstream>
using namespace mraa;
using namespace std;

	void UserH6:: LightH6(){
		//调用IOT2000提供的setledcolor.py文件，以及system()函数
		string filename = "/etc/setledcolor.py 0";
		string command = "python ";
		command += filename;
		system(command.c_str());
	}
	void UserH6::LightAll() {

		while(true){
			//setledcolor共有四个状态0,1,2,3分别对应无，绿，红，橙。注：死循环显示（不推荐）
			for(int i=0;i<4;i++){
				string color[] ={"null","green","red","orange"};
				string filename = "/etc/setledcolor.py ";
				cout<<"i =:"<<i<<color[i]<<endl;
				//int 转为string
				stringstream sout;
				string s;
				sout<<i;
				s = sout.str();
				filename += s;
				string command = "python ";
				command += filename;
				system(command.c_str());
				sleep(1);
				}


		}

	}



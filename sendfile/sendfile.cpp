/*
 * sendfile.cpp
 *
 *  Created on: 2017年7月22日
 *      Author: Administrator
 */
#include "sendfile.h"
#include "string.h"
#include <unistd.h>
#include <iostream>
#include "mraa.hpp"

using namespace mraa;
using namespace std;

void SendFile::sendfile(){
	//调用python文件执行client代码
	string filename = "/mnt/client.py ";
	string command = "python  ";
	command += filename;
	system(command.c_str());
}



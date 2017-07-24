/*
 * sendfile.cpp
 *
 *  Created on: 2017Äê7ÔÂ22ÈÕ
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
	string filename = "/mnt/client.py ";
	string command = "python  ";
	command += filename;
	system(command.c_str());
	//sleep(10);
}



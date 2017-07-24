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

	std::stringstream ss;
	string buffer;
	/*
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

			mraa:: Gpio* button_pin = NULL;
			button_pin = new mraa::Gpio(2, true, false);
			button_pin->dir(mraa::DIR_IN);
			int pin2 = button_pin->read();
			cout<<pin2<<endl;

			ss<<pin2;
			ss>>buffer;
			mraa:: Gpio* d_pin = NULL;
			d_pin = new mraa::Gpio(13, true, false);
			d_pin->dir(mraa::DIR_OUT);
			d_pin->write(pin2);

			ofstream location_out;
			//只储存0/1
			location_out.open("location_out.txt", std::ios::out | std::ios::trunc);
			if (location_out.is_open()){
				location_out << buffer << endl;
			}else{
				cout<<"location_out.txt not open"<<endl;
			}
			location_out.close();




}




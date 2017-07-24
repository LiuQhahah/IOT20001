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
	//LH6.LightH6();
	//LH6.LightAll();

	/*
	 Gpio* d_pin = NULL;
		d_pin = new mraa::Gpio(13, true, false);
		d_pin->dir(mraa::DIR_OUT);
		d_pin->read();

				d_pin->write(1);
				sleep(1);
				d_pin->write(0);
				sleep(1);*/
		MKdir mk;
		mk.mkdir();
	SendFile sf;
	sf.sendfile();
	sleep(60);
	}
	return 0;
}


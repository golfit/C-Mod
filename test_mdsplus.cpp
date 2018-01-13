//============================================================================
// Name        : mode_survey.cpp
// Author      : Theodore Golfinopoulos
// Version     :
// Copyright   : 2018, All rights reserved, MIT License
// Description :
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <mdslib.h>
using namespace std;

int main(int argc, char *argv[]) {
	//Local variables
	int socket;

    /* Connect to MDSplus */
	socket=MdsConnect("alcdata.psfc.mit.edu");

	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	return 0;
}

#line 1 "c:\\Users\\Spencer\\Documents\\GitHub\\code-for-ee-lab-fixed\\vscode files\\src\\object_testing\\projIR.hpp"
#ifndef PROJIR_H  //Header gaurd for this header file
#define PROJIR_H
#pragma once
#include <IRremote.h>


// This is in a heeder file because it is gross and big.
// Also, I wanted to abstract it from the user.

const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

int getKey()
{
	uint32_t num = 0;
	if (irrecv.decode(&results))
	{
		num = results.value;
		irrecv.resume();

		// Decoding imputs from remote and giving them an integer value
		switch (num)
		{
		case 16732845:
			return 9;

		case 16730805:
			return 8;

		case 16728765:
			return 7;

		case 16734885:
			return 6;

		case 16726215:
			return 5;

		case 16716015:
			return 4;

		case 16743045:
			return 3;

		case 16718055:
			return 2;

		case 16724175:
			return 1;

		case 16738455:
			return 0;

		case 16753245:
			return 11; //value for on/off button

		default:
			return 10; // discaurded value for non expected key presses
		}
	}
	return 10;
}

#endif
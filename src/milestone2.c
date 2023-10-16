/*
============================================
Name		:	Nibardo Reyes Felix
Author		:	Me
Version		:	1.0
Date        :   October 15, 2023
Description	:	Milestone 2: Basic sudo code on project
============================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Some methods used in class that will be helpful later on
void decimal2Binary(int input, char output[]){
	int result = -1;
	int bit = strlen(output) - 1;

	//While last Quotient is not 0
	while(result != 0){
		//Get Quotient and Remainder
		result = input/2;
		int remainder = input % 2;
		//Set a 1 or 0 bit
		output[bit] = remainder ? '1' : '0';
		//next bit and set input for next interation
		--bit;
		input = result;
	}
}

int binary2Decimal(char input[]){
	int output = 0;
	int power = 1;

	//loops thry bit array and convert to decimal
	for(int x = strlen(input)-1; x >= 0; --x){
		output = output + ((input[x] - 48) * power);
		power = power * 2;
	}
	//return decimal value
	return output;
}
void binary2Hex(int input, char output[]){
	char digit[2] = "0\0";
	int nibbles = strlen(output);


	while(nibbles > 0){
		//Convert nibble to hex
		sprintf(&digit[0], "%1x", input & 0x0F);
		output[nibbles - 1] = digit[0];
		//next nibble
		--nibbles;
		input = input >> 4;
	}
}
//AND
int and(int b1, int b2){
	return (b1 & 1) & (b2 & 1);
}
//OR
int or(int b1, int b2){
	return (b1 & 1) | (b2 &1);
}
//NOT
int not(int b1){
	return (b1 & 1) ? 0 : 1;
}
//NAND
int nand(int b1, int b2){
	return not(and(b1, b2));
}
//NOR
int nor(int b1, int b2){
	return not(or(b1, b2));
}
//XOR
int xor(int b1, int b2){
	return (b1 & 1) == (b2 & 1) ? 0 : 1;
}

//BCD to 7-segment logic design
int bcd2sevenSegmentDecoder(int ABCD){
    //ABCD is the input decimal number that we covert into binary A, B, C, D bits
    char output[5] = {"0000\0"};//final array to keep all results in as chracters when done
    decimal2Binary(ABCD, output);
	int A = output[0] - 48;
	int B = output[1] - 48;
	int C = output[2] - 48;
	int D = output[3] - 48;

	//k-map logic design (a is the lsb of the output)
	//a = (~B*~D) + C + (B*D) + A
	int a = (~B & 0x01 & ~D & 0x01) | C | (B & D) | A;

	//b = ~B + (~C * ~D) + (C * D)
	int b = (~B & 0x01) | (~C & 0x01 & ~D & 0x01) | (C & D);

	//c = ~C + D + B
	int c = (~C & 0x01) | (D) | (B);

	//d = (~B * ~D) + (~B * C) + (B * ~C * D) + (C * ~D) + A
	int d = (~B & 0x01 & ~D & 0x01) | (~B & 0x01 & C) | (B & (~C & 0x01) & D) | (C & ~D & 0x01) | (A);

	//e = (~B * ~D) + (C * ~D)
	int e = (~B & 0x01 & ~D & 0x01) | (C & ~D & 0x01);

	//f =(~C * ~D) + (B * ~C) + (B* ~D) + A
	int f = (~C & 0x01 & ~D & 0x01) | ( B & ~C & 0x01) | (B & ~D & 0x01) | (A);

	//G = (~B * C) + (B * ~C) + (A) + (B * ~D)
	int g = (~B & 0x01 & C) | (B & ~C & 0x01) | A | (B * ~D & 0x01);

	//Calculate return values by converting each bit to a BInary Charaacter array and then convert that to a decimal naumber
	char values[9];
	values [0] = 48;
	values [1] = g + 48;
	values [2] = f + 48;
	values [3] = e + 48;
	values [4] = d + 48;
	values [5] = c + 48;
	values [6] = b + 48;
	values [7] = a + 48;
	values [8] = 0;
	return binary2Decimal(values);

}
//===========================
//methods specific to project
//===========================
//In charge of getting the time for the time zones
void time(){
	printf("Application has the correct time\n");
}
//In charge of displaying time on 7 segment display
void time7Segment(){
	printf("7-segment dispay is showing a time zone\n");
}
//will change time on display
void update7Segment(){
	printf("The time on the 7-sengment display has been changed");
}
//this method is in charge of outputing on the lcd screen
void lcdMain(){
	printf("LCD turns on with a welcom message that tells user to press button to choose what mode they would like to go into.(Create Alarm, Delete Alarm)\n");

}
//select button has been pressed
void userSelectButton(){
	printf("User is pressing slect button\n");
}
//up button has been pressed
void userUpButton(){
	printf("User is pressing up button\n");
}
//down button has been pressed
void userDownButton(){
	printf("User is pressing down button\n");
}
//will look at switch orientation to determine what time zone the user wishes to see
//Different switch orientations with output different times on the 7-segment display
void timeZone(){
	printf("In charge of checking switchs to determin what time zone the user want to be in.\n");

}
//this method will let the user create alarm time
void createAlarm(){
	printf("User is trying to create an alarm.\n");
}
//this method will let the user create alarm time
void deleteAlarm(){
	printf("User is trying to delete an alarm.\n");
}
//this method is in charge of what will happen when alarm goes off
void activateAlarm(){
	printf("Program is trying to communicate with leds to activate alarm.\n");
}
//user can press last button to stop alarm
void userStopAlarm(){
	printf("User wants to stop alarm\n");
}
//determin what switches are turned
void switches(){
	printf("Switches have been flipped...changing time zone now\n");
}
//change time to time zone 1
void switchTimeZoneOne(){
	printf("Changint time to time zone 1");
}
//change time to time zone 2
void switchTimeZoneTwo(){
	printf("Changint time to time zone 2");
}
//change time to time zone 3
void switchTimeZoneThree(){
	printf("Changint time to time zone 3");
}
//change time to time zone 4
void switchTimeZoneFour(){
	printf("Changint time to time zone 4");
}


int main(void){
	//----Initial Startup-------
	printf("\n=========================================");
	printf("\n=========== Initial Startup =============");
	printf("\n=========================================\n\n");
	//Program has just started running
	lcdMain();//message appears on lcd
	time();//get the time
	/*---Possible functions that may be called
	voidSwitchTimeZoneONE();
	voidSwitchTimeZoneTwo();
	voidSwitchTimeZoneThree();
	voidSwitchTimeZoneFour();
	*/
	time7Segment();//7-segnment dispay is now showing a time

	//---User Changes switches----
	printf("\n==== User Changes Switches ====\n\n");
	switches();//the user has changed the time on the 7-segment display
	update7Segment();//7-segnment display has changed

	//---User presses button to create an alarm---
	printf("\n==== User Creates Alarm ====\n\n");
	createAlarm();
	/*---Possible functions that may be called
	userUpButton();
	userDownButton();
	userSelectButton();
	*/

	//--User presses button to Delete an Alarm
	printf("\n==== Deletes Alarm ====\n\n");
	deleteAlarm();
	/*---Possible functions that may be called
	userUpButton();
	userDownButton();
	userSelectButton();
	*/

	printf("\n==== Alarm is going OFF ====\n\n");
	//--Situation when alarm time is met
	activateAlarm();//leds will flash when an alarm time has been met
	userStopAlarm();//user want to stop alarm

	printf("\n==== END ====\n\n");

}

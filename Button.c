#include <wiringPi.h>
#include <stdio.h>

#define LedPin 0
#define ButtonPin 1

int count;

int main(void){
// When initialize wiring failed, print message to screen
if(wiringPiSetup() == -1){
printf("setup wiringPi failed !");
return 1;
}

printf("here\n");

pinMode(LedPin, OUTPUT);
pinMode(ButtonPin, INPUT);
digitalWrite(LedPin, LOW);

count = 0;

while(1){
// Indicate that button has pressed down
//count = 0;

if(digitalRead(ButtonPin) == 0){
   
	//delay(1000);
	count++;
   	delay(1000);
   	printf("okok!\n");
	if(count >= 3){
		delay(100);
		printf("LED on!\n");
		digitalWrite(LedPin, HIGH);
		delay(1000);
		count = 0;
	}else{
		// no Led
		digitalWrite(LedPin, LOW);
   		// printf("no LED\n");
	}

	}else{
	digitalWrite(LedPin, LOW);
	}
}
return 0;
}



#define LED_MASK 0b00000111
#define TRIGGER_MASK 0b01000000
#define INPUT_MASK 0b00111000
#define OUTPUT_MASK 0b00000111

// From assembly
void outPortD(int);
int inPortD(void);
void initPortD(int);
//void delay(void);

void longDelay(void){
	int i;
	for(i=50;i>0;i--){
		//delay();
	}
}

void waitForTrigger(void){
	// Wait until zero
	while(inPortD() & TRIGGER_MASK);
	outPortD(1);
	longDelay();

	// Wait until one
	while(!(inPortD() & TRIGGER_MASK));
	outPortD(2);
	longDelay();
	
	// Wait until zero again
	while(inPortD() & TRIGGER_MASK);
	outPortD(3);
	longDelay();
}

// Fake main, called after stack initialized
void __main(void)
{
	initPortD(LED_MASK);
	outPortD(0b110);
	int a = 0;
	int b = 0;
	while(1){
		waitForTrigger();
		a = (inPortD() & INPUT_MASK) >> 3;
		waitForTrigger();
		b = (inPortD() & INPUT_MASK) >> 3;
		waitForTrigger();
		outPortD(a+b);
	}
}

// Regular outputs: 0 1 2
// Regular inputs:  3 4 5
// Trigger output:  6

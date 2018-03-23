#define LED_MASK 0b00000111
#define INPUT_MASK 0b01111000
#define OUTPUT_MASK 0b00000111

// From assembly
void outPortD(int);
int inPortD(void);
void initPortD(int);
void delay(void);

void longDelay(void){
	int i;
	for(i=240*240;i>0;i--){
		delay();
	}
}

// Fake main, called after stack initialized
void __main(void)
{
	initPortD(LED_MASK);
	outPortD(0b110);
	while(1){
		outPortD(0b010);
		delay();
		outPortD(0b101);
		delay();
		
	}
}

/* TA-BOT:MAILTO your.email@marquette.edu your.partners.email@marquette.edu */
/* COSC 2200 Hardware Systems			*/
/* Fall 2019					*/
/* Template for Braille Translator	        */

#define EOF 4

/* Functions provided in ARM Playground */
void kprintf(char *, ...);
int  kgetc(int);		/* Get character from serial port */

/* Encoding of Braille characters */
unsigned char brailleTable[] = {0x01, /* a */
	0x03, /* b */
	0x09, /* c */
	0x19, /* d */
	0x11, /* e */
	0x0B, /* f */
	0x1B, /* g */
	0x13, /* h */
	0x0A, /* i */
	0x1A, /* j */
	0x05, /* k */
	0x07, /* l */
	0x0D, /* m */
	0x1D, /* n */
	0x15, /* o */
	0x0F, /* p */
	0x1F, /* q */
	0x17, /* r */
	0x0E, /* s */
	0x1E, /* t */
	0x25, /* u */
	0x27, /* v */
	0x3A, /* w */
	0x2D, /* x */
	0x3D, /* y */
	0x35, /* z */
	0x1A, /* 0 */
	0x01, /* 1 */
	0x03, /* 2 */
	0x09, /* 3 */
	0x19, /* 4 */
	0x11, /* 5 */
	0x0B, /* 6 */
	0x1B, /* 7 */
	0x13, /* 8 */
	0x0A, /* 9 */
	0x3C, /* # */
	0x20, /* Capital */
	0x30, /* Letter */
	0x28, /* Radix */
	0x32}; /* Period */

unsigned char alph[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

#define CAPITAL 37
#define LETTER  38
#define RADIX   39
#define MAX 26

int _main_(void)
{
	char array[MAX];
	int c = 0;
	int i = 0;

	//one letter gets 5 spaces
	char chart[5];

	kprintf("Braille Translator\r\n");
	while ((c = kgetc(0)) != EOF)
	{
		/* TODO: Implement your program. */
		array[i] = c;
		i ++;
		
		kprintf("%c",c);

	}

	int j = 0;
	int a = 0;
	int alphind = 0;
	//kprintf("\r\n");
	for(j = 0; j < 26; j ++){
		if(array[a] == alph[j]){
			//finds the index of the specific letter in the alphabet so we can find it in the brail table and get the correct hex value
			alphind = j;
		}
		
	//	a ++;	
	}
	kprintf("\r\n");
	j = 0;
	//get hex value
	char hexx = brailleTable[alphind];
	for(int e =0;e<3;e++)	{
		for(int z=0;z<2;z++){
			if((hexx >> (z*3+e))& 1){
				kprintf("@");
				}
			else{
				kprintf(".");
				}		
		
			
			}
		kprintf("\r\n");
		}		


}


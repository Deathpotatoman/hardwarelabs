#define MAXSIZE 16		/* Assume max size of entry is 16 bytes long */
#define EOF 4

/* Functions provided in ARM Playground */
void bzero(void *, unsigned long); /* nullify memory space */
int  kprintf(const char *, ...);
int  kputc(char);		/* Write character to serial port */
int  kgetc(int);		/* Get character from serial port */
/* NOTE: To use kgetc, you must specify 0 as the parameter. 
 * This tells the operating system to use the UART device.
 *
 * Example: kgetc(0)
 * 
 */

// Function prototypes go here

int _main_(void)
{

	// TODO: Write your function
	char * str;
	str = (char *) malloc(MAXSIZE);
	bzero(str,MAXSIZE)
	int i = 0;
	char c;
	do{
	    c = kgetc(0);
	    kputc(c);
	    str[i] = c;
	    i = i+1;
	}while(c != '\n');
	kprintf("%s\r\n",str);		
	
	return 0;	// Main ends with return of zero
}

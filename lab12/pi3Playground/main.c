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
	char *str;
	str = (char *)malloc(MAXSIZE);
	bzero(str,MAXSIZE);
	int i = 0;
	char c;
	do{
	    c = kgetc(0);
	    kputc(c);
	//    kprintf("\r\nTHE CHAR WE GOT %c",c);
	    if(c == 97 || c == 101 || c == 105 || c == 111 || c == 117){	
	    	str[i] = c;
	     i = i+1;
	    }
	    else if ((c >= 48 && c<=56) && c%2 ==0){
	        str[i] =c;
	     i = i+1;
	    }
	}while(c != '\n');
	kprintf(" \r\n%s",str);		
	
	return 0;	// Main ends with return of zero
}

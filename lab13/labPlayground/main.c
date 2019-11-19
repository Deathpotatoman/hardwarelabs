/* Functions provided in ARM Playground */
int  kprintf(const char *, ...);
int  kputc(char);		/* Write character to serial port */
int  kgetc(int);		/* Get character from serial port */
/* NOTE: To use kgetc, you must specify 0 as the parameter. 
 * This tells the operating system to use the UART device.
 *
 * Example: kgetc(0)
 * 
 */

// Function prototypes go here.
int _main_(void)
{
	kprintf("Rows:\r\n");
	int row = getnum();
	kprintf("Columns:\r\n");
	int column = getnum();
	kprintf("Enter grid character:\r\n");
	char gridC = kgetc(0);
	kputc(gridC);
	int *entry;
	entry=(int *)malloc(row*4);
	bzero(entry,row);	 	
	for(int i=0;i<row;i++)
		{
		kprintf("\r\nentry for row %d",i);
		kprintf("\r\n");
		entry[i*4]=getnum();					
		}
	for(int i=0;i<row;i++)
		{
		for(int e=0;e<column;e++)
			{
			if(entry[i*4]==e)
				{
				kprintf("%c ",gridC);
				}
			else
				{
				kprintf(". ");	
				}
			}
		kprintf("\r\n");
		}
}

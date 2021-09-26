typedef unsigned char BOOLEAN; 
#define FALSE 0
#define TRUE  !FALSE
typedef unsigned char BYTE;
void uart0_init(void);
BYTE uart0_getchar(void);
void uart0_putchar(char ch);
void uart0_put(char *ptr_str);


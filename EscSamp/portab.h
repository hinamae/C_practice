//	--------------------------------------------
//	potable definition including file
//	--------------------------------------------
//  	Ver 0.01	2001/11/1	T.w
//  	Sample  Ver  2017/02/01
//	---------------------------------------------
//	Standard type definitions
//	---------------------------------------------
#define	BYTE	char		/* Signed byte		   */
#define UBYTE	unsigned char	/* Unsigned byte 	   */
#define BOOLEAN	int		/* 2 valued (true/false)   */
#define	WORD	int  		/* Signed word (16 bits)   */
#define	UWORD	unsigned int	/* unsigned word	   */

#define	LONG	long		/* signed long (32 bits)   */
#define	ULONG	long		/* Unsigned long	   */

#define	REG	register	/* register variable	   */
#define	LOCAL	auto		/* Local var on 68000	   */
#define	EXTERN	extern		/* External variable	   */
#define	MLOCAL	static		/* Local to module	   */
#define	GLOBAL	/**/		/* Global variable	   */
#define	VOID	/**/		/* Void function return	   */
#define	DEFAULT	int		/* Default size		   */
#define FLOAT	float		/* Floating Point	   */
#define DOUBLE	double		/* Double precision	   */

/************************************************************/
//	Miscellaneous Definitions:
/************************************************************/

#define	FAILURE	(-1)		/*	Function failure return val */
#define SUCCESS	(0)		/*	Function success return val */
#define	YES	1		/*	"TRUE"			    */
#define	NO	0		/*	"FALSE"			    */
#define	FOREVER	for(;;)		/*	Infinite loop declaration   */
#define NULLPTR (UBYTE *) 0	/*	Null pointer value	    */
#define	TRUE	(1)		/*	Function TRUE  value	    */
#define	FALSE	(0)		/*	Function FALSE value	    */
#define	OK		(0)

#define	ON		1
#define	OFF		0

#define	STATIC		static

#define	MAC	1	//PCがMacの場合

#ifdef MAC
#define		ESC	'\033'
#else
#define		ESC	'¥033'
#endif
// エスケープシーケンス組み込み関数
#define LOCATE(x,y) printf("\033[%d;%dH",(x)+1,(y)+1)
#define CLS printf("\033[2J")

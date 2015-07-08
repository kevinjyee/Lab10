#define C1   597   // 2093 Hz
#define B1   633   // 1975.5 Hz
#define BF1  670   // 1864.7 Hz
#define A1   710   // 1760 Hz
#define AF1  752   // 1661.2 Hz
#define G1   797   // 1568 Hz
#define GF1  845   // 1480 Hz
#define F1   895   // 1396.9 Hz
#define E1   948   // 1318.5 Hz
#define EF1  1004   // 1244.5 Hz
#define D1   1064   // 1174.7 Hz
#define DF1  1127   // 1108.7 Hz
#define C    1194   // 1046.5 Hz
#define B    1265   // 987.8 Hz
#define BF   1341   // 932.3 Hz
#define A    1420   // 880 Hz
#define AF   1505   // 830.6 Hz
#define G    1594   // 784 Hz
#define GF  1689   // 740 Hz
#define F   1790   // 698.5 Hz
#define E   1896   // 659.3 Hz
#define EF  2009   // 622.3 Hz
#define D   2128   // 587.3 Hz
#define DF  2255   // 554.4 Hz
#define C0  2389   // 523.3 Hz
#define B0  2531   // 493.9 Hz
#define BF0 2681   // 466.2 Hz
#define A0  2841   // 440 Hz
#define AF0 3010   // 415.3 Hz
#define G0  3189   // 392 Hz
#define GF0 3378   // 370 Hz
#define F0  3579   // 349.2 Hz
#define E0  3792   // 329.6 Hz
#define EF0 4018   // 311.1 Hz
#define D0  4257   // 293.7 Hz
#define DF0 4510   // 277.2 Hz
#define C7  4778   // 261.6 Hz
#define B7  5062   // 246.9 Hz
#define BF7 5363   // 233.1 Hz
#define A7  5682   // 220 Hz
#define AF7 6020   // 207.7 Hz
#define G7  6378   // 196 Hz
#define GF7 6757   // 185 Hz
#define F7  7159   // 174.6 Hz
#define E7  7584   // 164.8 Hz
#define EF7 8035   // 155.6 Hz
#define D7  8513   // 146.8 Hz
#define DF7 9019   // 138.6 Hz
#define C6  9556   // 130.8 Hz
/*
#define	q		40000000
#define e		20000000
#define	dot	60000000
#define	whole	80000000
*/
#define	s			10000000/2
#define	e			20000000/2
#define q			40000000/2
#define	dotq	60000000/2
#define ha		80000000/2
#define hae		100000000/2
#define	doth	120000000/2
#define	whole	16000000/2
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "Sound.h"
void EnableInterrupts(void);
void DisableInterrupts(void);
int m = 0;
/*
uint32_t song[35] = {E1,EF1,E1,EF1,E1,B,D1,C,A,C0,E,A,B,E,AF,B,C,E,E1,EF1,E1,EF1,E1,B,D1,C,A,C0,E,A,B,E,C,B,A};
uint32_t beats[35] = {e,e,e,e,e,e,e,e,dot,e,e,e,dot,e,e,e,dot,e,e,e,e,e,e,e,e,e,dot,e,e,e,dot,e,e,e, whole};
*/

int song[68] = {E1,EF1,D1,DF1,C,AF,C,E,G,F,
										E1,EF1,D1,DF1,C,AF,C,E,G,F,
										C0,E,G,C,G,E,C0,E,G,C,G,E,
										BF0,D,F,BF,F,D,BF0,D,F,BF,F,D,
										C0,E,G,C,G,E,C0,E,G,C,G,E,
										F,A,C,F1,C,A,F,A,C,F1,C,A};
int beats[68] = {hae,e,e,e,doth,q,ha,q,q,whole,
									hae,e,e,e,doth,q,ha,q,q,whole,
									s,s,s,s,s,s,s,s,s,s,s,s,
									s,s,s,s,s,s,s,s,s,s,s,s,
									s,s,s,s,s,s,s,s,s,s,s,s,
									s,s,s,s,s,s,s,s,s,s,s,s};
extern uint32_t started;
	
void Song_Out(void){
	TIMER0_ICR_R = TIMER_ICR_TATOCINT;
	TIMER0_TAILR_R = beats[m]-1;
	Sound_Play(song[m]);
	m++;
	EnableInterrupts();
}

void Timer0A_Handler(void){
	TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
	if(started ==1){
		TIMER0_TAILR_R = beats[m]-1;	            	
		Sound_Play(song[m]);		
		//NVIC_ST_RELOAD_R = song[m]-1;// reload value
	  m=(m+1)%68; 
		}
	}
	
void Stop_Out(void){
		DisableInterrupts();
	}
	

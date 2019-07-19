#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
double * top;
double * sp;
double ** atop;
double t0 , t1 , t2 , t3 , t4 , t5 , t6 , t7 , t8 , t9 , t10 , t11 , t12 , t13 , t14 , t15 , t16 ;
double *tt0 , *tt1 , *tt2 , *tt3 , *tt4 , *tt5 , *tt6 , *tt7 , *tt8 , *tt9 , *tt10 , *tt11 , *tt12 , *tt13 , *tt14 , *tt15 , *tt16 , *tt17 , *tt18 , *tt19 , *tt20 , *tt21 , *tt22 , *tt23 , *tt24 , *tt25 , *tt26 , *tt27 , *tt28 , *tt29 , *tt30 , *tt31 , *tt32 , *tt33 , *tt34 , *tt35 , *tt36 , *tt37 , *tt38 , *tt39 , *tt40 , *tt41 , *tt42 , *tt43 , *tt44 , *tt45 , *tt46 , *tt47 , *tt48 , *tt49 , *tt50 , *tt51 , *tt52 , *tt53 , *tt54 ;
double **v0 , **v1 , **v2 , **v3 , **v4 , **v5 , **v6 ;
int i0 , i1 , i2 ;
int main() {
top = (double *) malloc(sizeof(double) *10001);
atop = (double **) malloc(sizeof(double*) *1001);
top = top + 10000;
atop = atop + 1000;
sp = top;

*top = 0;

//program decleration:  
	top = top - 2; 
		goto L2; 
L0:
	sp = top; 
//proc decleration: p1 
	top = top - 0; 
L1:
//return  
	top = top + 0; 
	v0 = atop + 1; 
	tt0 = *v0; 
		goto *tt0; 
L2:
		goto L11; 
L3:
	sp = top; 
//func decleration: f1bonachi 
	top = top - 12; 
	tt1 = sp + 4; 
	t0 = *tt1; 
	tt2 = sp - 1; 
	*tt2 = t0; 
	tt3 = sp - 1; 
	t0 = *tt3; 
	t1 = t0 - 1; 
	tt4 = sp - 2; 
	*tt4 = t1; 
	tt5 = sp + 4; 
	*tt5 = t1; 
L4:
	tt6 = sp + 4; 
	t2 = *tt6; 
	tt7 = sp - 3; 
	*tt7 = t2; 
	tt8 = sp - 3; 
	t2 = *tt8; 
if ( t2 == 0 )
		goto L7; 
L5:
		goto L8; 
L6:
L7:
	tt9 = sp + 6; 
	t3 = *tt9; 
	tt10 = sp - 4; 
	*tt10 = t3; 
	tt11 = sp + 5; 
	t4 = *tt11; 
	tt12 = sp - 5; 
	*tt12 = t4; 
	tt13 = sp - 4; 
	t3 = *tt13; 
	tt14 = sp - 5; 
	t4 = *tt14; 
	t5 = t3 + t4; 
	tt15 = sp - 6; 
	*tt15 = t5; 
	tt16 = sp + 1; 
	*tt16 = t5; 
//return  
	top = top + 12; 
	v1 = atop + 1; 
	tt17 = *v1; 
		goto *tt17; 
		goto L10; 
L8:
	tt18 = sp + 5; 
	t6 = *tt18; 
	tt19 = sp - 7; 
	*tt19 = t6; 
	tt20 = sp + 6; 
	t7 = *tt20; 
	tt21 = sp - 8; 
	*tt21 = t7; 
	tt22 = sp + 5; 
	t8 = *tt22; 
	tt23 = sp - 9; 
	*tt23 = t8; 
	tt24 = sp - 8; 
	t7 = *tt24; 
	tt25 = sp - 9; 
	t8 = *tt25; 
	t9 = t7 + t8; 
	tt26 = sp - 10; 
	*tt26 = t9; 
	tt27 = sp + 4; 
	t10 = *tt27; 
	tt28 = sp - 11; 
	*tt28 = t10; 
//functioncall: f1bonachi 
	top = top - 1; 
	tt29 = sp - 7; 
	t6 = *tt29; 
	*top = t6; 
//functioncall: f1bonachi 
	top = top - 1; 
	tt30 = sp - 10; 
	t9 = *tt30; 
	*top = t9; 
//functioncall: f1bonachi 
	top = top - 1; 
	tt31 = sp - 11; 
	t10 = *tt31; 
	*top = t10; 
	top = top - 1; 
	*top = 3; 
	top = top - 1; 
	tt32 = &&L9; 
	atop = atop - 1; 
	*atop = tt32; 
	top = top - 1; 
	top = top - 1; 
	*top = 2; 
	atop = atop - 1; 
	*atop = sp; 
		goto L3; 
//return after func call  
L9:
	top = top + 1; 
	t11 = *top; 
	top = top + 2; 
	i0 = *top; 
	i0 = i0 + 1; 
	top = top + i0; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: f1bonachi 
	tt33 = sp - 12; 
	*tt33 = t11; 
	tt34 = sp + 1; 
	*tt34 = t11; 
//return  
	top = top + 12; 
	v2 = atop + 1; 
	tt35 = *v2; 
		goto *tt35; 
L10:
//return  
	top = top + 12; 
	v3 = atop + 1; 
	tt36 = *v3; 
		goto *tt36; 
L11:
		goto L19; 
L12:
	sp = top; 
//func decleration: f1bonachiSequence 
	top = top - 4; 
	tt37 = sp + 4; 
	t12 = *tt37; 
	tt38 = sp - 1; 
	*tt38 = t12; 
	tt39 = sp - 1; 
	t12 = *tt39; 
if ( t12 < 3 )
		goto L15; 
L13:
		goto L16; 
L14:
L15:
	tt40 = sp + 1; 
	*tt40 = 1; 
//return  
	top = top + 4; 
	v4 = atop + 1; 
	tt41 = *v4; 
		goto *tt41; 
L16:
	tt42 = sp + 4; 
	t13 = *tt42; 
	tt43 = sp - 2; 
	*tt43 = t13; 
	tt44 = sp - 2; 
	t13 = *tt44; 
	t14 = t13 - 2; 
	tt45 = sp - 3; 
	*tt45 = t14; 
//functioncall: f1bonachi 
	top = top - 1; 
	*top = 1; 
//functioncall: f1bonachi 
	top = top - 1; 
	*top = 1; 
//functioncall: f1bonachi 
	top = top - 1; 
	tt46 = sp - 3; 
	t14 = *tt46; 
	*top = t14; 
	top = top - 1; 
	*top = 3; 
	top = top - 1; 
	tt47 = &&L17; 
	atop = atop - 1; 
	*atop = tt47; 
	top = top - 1; 
	top = top - 1; 
	*top = 2; 
	atop = atop - 1; 
	*atop = sp; 
		goto L3; 
//return after func call  
L17:
	top = top + 1; 
	t15 = *top; 
	top = top + 2; 
	i1 = *top; 
	i1 = i1 + 1; 
	top = top + i1; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: f1bonachi 
	tt48 = sp - 4; 
	*tt48 = t15; 
	tt49 = sp + 1; 
	*tt49 = t15; 
//return  
	top = top + 4; 
	v5 = atop + 1; 
	tt50 = *v5; 
		goto *tt50; 
L18:
//return  
	top = top + 4; 
	v6 = atop + 1; 
	tt51 = *v6; 
		goto *tt51; 
L19:
//functioncall: f1bonachiSequence 
	top = top - 1; 
	*top = 40; 
	top = top - 1; 
	*top = 1; 
	top = top - 1; 
	tt52 = &&L20; 
	atop = atop - 1; 
	*atop = tt52; 
	top = top - 1; 
	top = top - 1; 
	*top = 3; 
	atop = atop - 1; 
	*atop = sp; 
		goto L12; 
//return after func call  
L20:
	top = top + 1; 
	t16 = *top; 
	top = top + 2; 
	i2 = *top; 
	i2 = i2 + 1; 
	top = top + i2; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: f1bonachiSequence 
	tt53 = sp - 2; 
	*tt53 = t16; 
	tt54 = sp - 1; 
	*tt54 = t16; 
L21:
return 0;
}

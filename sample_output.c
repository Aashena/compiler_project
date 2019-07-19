#include <stdio.h>

int main(){
	int i1, i2, i3;
	double r1var, r2var;
	
	double T0, T1, T2, T3, T4, T5;
	
	i2 = -23;
	T0 = 2 - 1;
	T1 = 3 / T0;
	T2 = 0 - T1;
	i3 = T2;
	T3 = 23.003 + i1;
	r1var = T3;
	T4 = 1 + 3;
	i1 = i2;
	i2 = i3;
	T5 = i1 / i2;
	i1 = T5;
	i2 = i3;
	i1 = i3;
	
	/* The following statements will be added manually
	to later verify the validity of the code. 
	Same goes for the #include statement at the top. */
	printf("%lf\n", r1var);
	printf("%d\n", i3);
	
	return 0;
}

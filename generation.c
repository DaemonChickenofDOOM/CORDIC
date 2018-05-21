#include <stdio.h>
#include <math.h>

int main(){
	int i, j;
	scanf("%d",&i);
	double angle, sangle, cangle, rangle;
	j = 0;
	while(j < (i)){
	// while(1){
		scanf("%lf", &angle);
		rangle = angle * M_PI / 180;
		sangle = sin(rangle);
		cangle = cos(rangle);
		printf("{%.15lf, %.15lf, %.15lf},\n",angle, sangle, cangle);
		j++;
	}
	return 0;
}
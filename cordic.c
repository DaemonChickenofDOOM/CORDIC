#include <stdio.h>

int main(){
	/*
	 * First dimension is step number, second dimension is row contains
	 * individual data from that element.
	 * 
	 * Element 0 is the angle in degrees
	 * Element 1 is the sine value
	 * Element 2 is the cosine value
	 */
	double steps[20][3] = {{45.000000, 0.70710678118655, 0.70710678118655}, {22.500000, 0.38268343236509, 0.92387953251129}, {11.250000, 0.19509032201613, 0.98078528040323}, {5.625000, 0.09801714032956, 0.99518472667220}, {2.812500, 0.04906767432742, 0.99879545620517}, {1.406250, 0.02454122852291, 0.99969881869620}, {0.703125, 0.01227153828572, 0.99992470183914}, {0.351562, 0.00613587592267, 0.99998117533615}, {0.175781, 0.00306795239966, 0.99999529382296}, {0.087891, 0.00153398673126, 0.99999882344166}, {0.043945, 0.00076698486459, 0.99999970586707}, {0.021973, 0.00038350118714, 0.99999992646342}, {0.010986, 0.00019174187045, 0.99999998161753}, {0.005493, 0.00009587093567, 0.99999999540438}, {0.002747, 0.00004794419453, 0.99999999885068}, {0.001373, 0.00002396337063, 0.99999999971288}, {0.000687, 0.00001199041196, 0.99999999992812}, {0.000343, 0.00000598647933, 0.99999999998208}, {0.000172, 0.00000300196631, 0.99999999999549}, {0.000086, 0.00000150098316, 0.99999999999887},}; 

	double target = 0, currentangle = 0, vector[2] = {1,0};
	/*
	 * for vector, Element 0 is x portion, Element 1 is y portion
	 */

	printf(">> ");
	scanf("%lf", &target);

	for(int i = 0; i < 20; i++){
		if(currentangle < target){
			currentangle += steps[i][0];
		}
		else if (currentangle > target){
			currentangle -= steps[i][0];
		}
	}
	printf("%lf",currentangle);
	// printf("%lf, %lf, %lf\n", steps[0][0], steps[0][1], steps[0][2]);
	return 0;
}
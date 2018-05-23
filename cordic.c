#include <stdio.h>

int main(){
	/*
	 * CORDIC-like program for Math Open House
	 * 

	/*
	 * First dimension is step number, second dimension is row contains
	 * individual data from that element.
	 * 
	 * Element 0 is the angle in degrees
	 * Element 1 is the sine value
	 * Element 2 is the cosine value
	 */

	// Dear future me. Please forgive me. 
	// I can't even begin to express how sorry I am.  

	// Yourself from four days later: 
	// What the [censored] were you thinking? This is practically a 
	// crime against humanity
	double steps[25][3] = {{45.000000000000000, 0.707106781186547, 0.707106781186548}, {22.500000000000000, 0.382683432365090, 0.923879532511287}, {11.250000000000000, 0.195090322016128, 0.980785280403230}, {5.625000000000000, 0.098017140329561, 0.995184726672197}, {2.812500000000000, 0.049067674327418, 0.998795456205172}, {1.406250000000000, 0.024541228522912, 0.999698818696204}, {0.703125000000000, 0.012271538285720, 0.999924701839145}, {0.351562500000000, 0.006135884649154, 0.999981175282601}, {0.175781250000000, 0.003067956762966, 0.999995293809576}, {0.087890625000000, 0.001533980186285, 0.999998823451702}, {0.043945312500000, 0.000766990318743, 0.999999705862882}, {0.021972656250000, 0.000383495187571, 0.999999926465718}, {0.010986328125000, 0.000191747597311, 0.999999981616429}, {0.005493164062500, 0.000095873799096, 0.999999995404107}, {0.002746582031250, 0.000047936899603, 0.999999998851027}, {0.001373291015625, 0.000023968449808, 0.999999999712757}, {0.000686645507812, 0.000011984224905, 0.999999999928189}, {0.000343322753906, 0.000005992112453, 0.999999999982047}, {0.000171661376953, 0.000002996056226, 0.999999999995512}, {0.000085830688477, 0.000001498028113, 0.999999999998878}, {0.000042915344238, 0.000000749014057, 0.999999999999719}, {0.000021457672119, 0.000000374507028, 0.999999999999930}, {0.000010728836060, 0.000000187253514, 0.999999999999982}, {0.000005364418030, 0.000000093626757, 0.999999999999996}, {0.000002682209015, 0.000000046813379, 0.999999999999999},}; //pardon the massive array
	double target = 0, currentangle = 0, vector[2] = {1,0};
	/*
	 * for vector, Element 0 is x portion, Element 1 is y portion
	 */

	printf("> ");
	scanf("%lf", &target);

	/* This is O(scary), but seems quick enough in practice. */ 

	for(int i = 0; i < 25; i++){
		double x, y, sine, cosine;
		x = vector[0];
		y = vector[1];
		sine = steps[i][1];
		cosine = steps[i][2];
		if(currentangle < target){
			currentangle += steps[i][0];
			printf("%.15lf hey!\n",currentangle);

			/* Revalue the vector */

			x = vector[0] * cosine - vector[1] * sine;
			y = vector[1] * cosine + vector[0] * sine;
		}
		else if (currentangle > target){
			currentangle -= steps[i][0];
			printf("%.15lf ho!\n",currentangle);

			/* 
			 * Revalue the Vector 
			 * the signs for the sine function segments change because the angle
			 * is negative; you are subtracting the step from the current angle
			 */
			x = vector[0] * cosine + vector[1] * sine;
			y = vector[1] * cosine - vector[0] * sine;

		}
		else if (currentangle == target){
			/* do absolutely nothing and exit this loop */
			break; // dancing
		}
		else {
			/* 
			 * This shouldn't happen. The only way this can happen is if the 
			 * end user somehow manages to enter a nubmber that can not 
			 * logically exist. If this happens we can't recover, and there is 
			 * more than likely a rip in the space time continuum that the user
			  *is too distracted by to notice anything else. 
			 */
		}
		/*
		 * commit the change of the vector into the actual variable.
		 */

		vector[0] = x;
		vector[1] = y;

	}
	printf("%lf\n",currentangle);

	printf(">> %lf, %lf \n", vector[0], vector[1]);
	// printf("%lf, %lf, %lf\n", steps[0][0], steps[0][1], steps[0][2]);
	return 0;
}
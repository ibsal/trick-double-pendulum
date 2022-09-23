/******
PURPOSE: (Numerical double pendulum)
*****/

#include "../include/pendulum.h"
#include <math.h>
#include "trick/integrator_c_intf.h"
#define G -9.80665

int Pendulum::default_data(){
	m1 = 1; 
	l1 = 1;
	m2 = 1;
	l2 = 1;
	theta1 = 0 * M_PI/180;
	theta2 = 20 * M_PI/180;
	return 0;

}


int Pendulum::state_init(){ //Initial position 
	pos1[0] = l1 * sin(theta1);
	pos1[1] = -1 * l1 * cos(theta1);
	pos2[0] = pos1[0] + l2 * sin(theta2);
	pos2[1] = pos1[1] - l2 * cos(theta2);  
	return 0;
	

}

int Pendulum::state_deriv(){

	pos1[0] = l1 * sin(theta1);  //Position isn't used in the actual numerical method, however we want to record it to plot it 
	pos1[1] = -1 * l1 * cos(theta1);
	pos2[0] = pos1[0] + l2 * sin(theta2);
	pos2[1] = pos1[1] - l2 * cos(theta2);

	thetaPrimePrime1 = (-1*m2*l2*pow(thetaPrime1, 2) * sin(theta1-theta2)*cos(theta1-theta2) + G * m2 * sin(theta2) * cos(theta1-theta2) - m2 * l2 * pow(thetaPrime1, 2) * sin(theta1-theta2)
				 - (m1+m2) * G * sin(theta1))
			     / (l1*(m1 + m2) - m2 * l2 * pow(cos(theta1-theta2),2)); //Source: 5 pages of derivation, using lagrangian mechanics. PAIN
	thetaPrimePrime2 = (m2 * l2 * pow(thetaPrime1, 2) * sin(theta1-theta2) * cos(theta1-theta2) + G *  sin(theta1 ) * cos(theta1-theta2) * (m1+m2)
				+ l1 * pow(thetaPrime1, 2) * sin(theta1-theta2) * (m1+m2) - G * sin(theta2) * (m1 +m2))
				/ (l2 * (m1+m2) - m2 * l2 * pow(cos(theta1-theta2),2));
	return 0;
}

int Pendulum::state_integ(){
	int integration_step; 
	
	load_state(&thetaPrime1, &thetaPrime2, &theta1, &theta2, NULL);
	load_deriv(&thetaPrimePrime1, &thetaPrimePrime2, &thetaPrime1, &thetaPrime2, NULL);
	integration_step = integrate();
	
	unload_state(&thetaPrime1, &thetaPrime2, &theta1, &theta2, NULL);
	return integration_step;
	
}

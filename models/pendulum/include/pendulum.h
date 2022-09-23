/*******************
PURPOSE: (Represent state of both pendulum masses)
**************/

#ifndef PENDULUM_H
#define PENDULUM_H

class Pendulum {
public:
	double m1; /* kg mass of first ball */
	double m2; /* kg mass of second ball */
	double l1; /* m length of first string */
	double l2; /* m length of second string */

	//Initial conditions
	double theta1; /* rad Angle between first line and the vertical, measured clockwise */
	double theta2; /* rad Angle between second line and the vertical, measured clockwise */
	
	
	//Mass 1 derivatives
	double pos1[2]; /*m x,y position of mass 1*/
	double thetaPrime1; /* rad/s rate of change of angle */
	double thetaPrimePrime1; /* rad/s^2 2nd derivative of angle */
	
	//Mass 2 derivatives
	double pos2[2]; /*m x,y position of mass 2*/
	double thetaPrime2; /* rad/s rate of change of angle */
	double thetaPrimePrime2; /* rad/s^2 2nd derivative of angle */
	
	//Pendulum class functions
	
	int default_data();
	int state_init();
	int state_deriv();
	int state_integ();
	


};
#endif

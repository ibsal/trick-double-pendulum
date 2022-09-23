#Double Pendulum Simulation

##Mechanics

Because the double pendulum is difficult to represent using forces, the state derivatives 
are calculated using functions derived from the Lagrangian of the system and the Euler-Lagrange equation.

The Lagrangian is defined as the kinetic energy of the system minus its potential energy. By 
writing the lagrangian in terms of the angles of the pendulum rods, the pendulum's mass,
and the length of the rods, we can use the Euler-Lagrange equation to create a formula solving 
for the second derivative of both angles. This becomes our state derivative for the simulation.

![The Euler-Lagrange equation](https://i.imgur.com/Bd2PtAF.png)

##Simulation Structure

The simulation has 4 main functions: default_data(), state_init(), state_deriv(), and state_integ().

###default_data()

In default_data(), we set the values for the lengths of the pendulum rods, masses of the pendulums, 
and the initial angles of the rodes measured from the vertical axis. 

###state_init()

In state_init(), the initial x and y positions of the pendulum are derived from information set in 
default_data(). 

###state_deriv()

Here we first calculate the x and y positions of the pendulum for data recording purposes, than 
we calculate the second derivative of both angles using the formula derived from the Euler-Lagrange 
equation. 

###state_integ()

In state_integ(), we pass the state derivatives - which are the second derivative of both angles 
as well as the first derivative - to the integrator. This allows us to calculate values for theta, 
which can be used to calculate the x and y positions of the masses. 

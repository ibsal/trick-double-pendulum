# Double Pendulum Simulation

## Mechanics

Because the double pendulum is difficult to represent using forces, the state derivatives 
are calculated using functions derived from the Lagrangian of the system and the Euler-Lagrange equation.

![The Euler-Lagrange equation](https://i.imgur.com/Bd2PtAF.png)

The Lagrangian is defined as the kinetic energy of the system minus its potential energy. By 
writing the lagrangian in terms of the angles of the pendulum rods, the pendulum's mass,
and the length of the rods, we can use the Euler-Lagrange equation to create a formula solving 
for the second derivative of both angles. This becomes our state derivative for the simulation.

Note that the mass of the rods, drag, and friction at the pendulum joints are not yet considered by the simulation.

## Simulation Structure

The simulation has 4 main functions: default_data(), state_init(), state_deriv(), and state_integ().

### default_data()

In default_data(), we set the values for the lengths of the pendulum rods, masses of the pendulums, 
and the initial angles of the rods measured from the vertical axis. 

### state_init()

In state_init(), the initial x and y positions of the pendulum are derived from information set in 
default_data(). 

### state_deriv()

Here we first calculate the x and y positions of the pendulum for data recording purposes, than 
we calculate the second derivative of both angles using the formula derived from the Euler-Lagrange 
equation.

### state_integ()

In state_integ(), we pass the state derivatives - which are the second derivative of both angles 
as well as the first derivatives - to the integrator. This allows us to calculate values for theta, 
which can be used to calculate the x and y positions of the masses. 

## Results 

The plot below was created with masses of 1 kg each, rod lengths of 1 m each, theta1 at 0 degrees, 
theta2 at 20 degrees, and a total time of 20 seconds. 

![Plot of the x and y positions of both masses](https://github.com/ibsal/trick-double-pendulum/blob/main/scripts/Figure_1.png)

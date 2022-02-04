# Obstacle Balancing Control System 

## Aim 
The idea behind this project is to develop a system which can be **measured** and **controlled**.  It's a 1 Degree of Freedom system where there's an ultrasonic sensor(HCSRO4) and servo motor(MG995) that controls the pitch of the beam on which the obstacle is balancing. Several algoritms like PID can be implemented on this and it can be a great educational platform for students who are interested to test out various different control techniques. 

## Implementation
An unltrasonic sensor and servo motor were used for the implementation purposes. The sensor calculates the real time distance from the object and then this is transformed into an angle value that is fed to the servo motor and accordingly the system in controlled. The PID algorithm was used to control the system, even though the system is highly non-linear cause of the friction between the obstacle and beam the control system works as expected. Different control algorithms like Fuzzy and LQR control can also be implemented on systems as such. 


## Build and Operation 
An image of the entire system can be viewed in the following  photos: 



![Photo](https://i.ibb.co/jHr4qjN/beam2.png)

for more photos and videos of the in depth operation the system Click [here](https://drive.google.com/drive/folders/13yd-YHXUhJwEobwfMw7FmKKDsTUq_G1D).  

# Application

An app was developed in Qt Creator using C++ so that the response of the system could be plotted in real-time and through the app the setpoint of the system can also be altered. This was all handled via serial port. 

![Photo](https://i.ibb.co/DWXMf37/app1.png)

![Photo](https://i.ibb.co/n1td7s1/app2.png)


# References
There were several online references that helped us with the implementation of the system. 
* They're as follows: 
  *  [Mechatronics Tutorials](https://mechatronicstutorials.blogspot.com/2014/07/balancing-of-ball-on-beam-using-arduino.html)
  *  [Balancing a ball on a beam](https://reference.wolfram.com/language/MicrocontrollerKit/workflow/BallAndBeamControl)
  *  [System Modeling](https://ctms.engin.umich.edu/CTMS/index.php?example=BallBeam&section=SystemModeling)

We would also like to thank our Professor, mgr inż. Adrian Wójcik without whose help and guidance this project wouldn't have been succesfull. 


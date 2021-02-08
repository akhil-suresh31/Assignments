# Random number generator
  This program takes a user input(n) , and generates a random number between 0 and (n-1).  
  The function retrieves the system time (time elapsed since January 1 ,1970 in milliseconds) and then gets the remainder when that time is divided by n.
  You can try the program over here:<br/>
  You can run the test.cpp to see the unit testing results( It might take some time to compile compared to the application),Or see the results over here.
  
  Shortcomings:
Since this program is dependant on time , if called multiple times for same n it will produce same no. because the speed of execution of modern processor is so good.

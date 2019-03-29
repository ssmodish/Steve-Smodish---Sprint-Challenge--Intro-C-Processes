**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

My research shows there is not a consistent model of the states a process could be in. Some common ones however are:

1. _Running_ - the process is running, this is can be broken down to `Kernel running` and `User running`.
2. _Ready to run_ - the process is ready to run, this is broken down into `Ready to Run in memory` and `Ready to run, swapped`.
3. _Asleep_ - process is in a blocked state, this one is also broken down to `in memory` and `swapped` states.
4. _Created_ - process is a newly created system call but is not ready to run.
5. _Preempted_ - when a process switches from Kernel to User running.
6. _Zombie_ - the process is terminated but has not been cleared by it's parent process.


**2. What is a zombie process?**

A zombie process is a child process that has completed but hasn't been closed.


**3. How does a zombie process get created? How does one get destroyed?**

A zombie process is created when a child process completes but can't report back to its parent process for some reason. The zombie process eventually gets destroyed by either the parent get's around to removing the child or, if the parent process exited before the child, it will then be up to the OS to handle the zombie process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The two biggest benefits of a compiled language over a scripted one are the size and speed of the executable. In a scripted language, while the size of your file is the size of your progam the system requires some type of runtime executable in order to interpret the script and make it useable to the OS. Both of these things are taken care of with compiling, which yeilds a file that is directly executable by the os and is usually signifigantly smaller than the code used to create the program.
# System Programming - Midterm exam
## Problem 1
Write a program that can print the process ID in the parent process, while the process ID and the parent process ID in the child process. (30 points)
1. Comment on major functions or code blocks of the source code
1. The explanation of the source code and the result screen should be clearly written on the answer sheet, which you need to send via email.
### Result Screen (Example)
~~~
Child PID is 5510, Parent PID is 5509.
Parent PID is 5509
~~~

## Problem 2
Write a program that uses _execl()_ function executing the _ls_ command then returns to the program and displays the string "execl() function execution" on the screen. (30 points)
1. Comment on major functions or code blocks of the source code
1. The explanation of the source code and the result screen should be clearly written on the answer sheet, which you need to send via email.
1. You need to use the _fork()_ function.

## Problem 3
A Programmer created a program calculating an average value of the three subjects such as 'system', 'network', and 'algorithm'. However, if you run the program, you can see that it does not work properly. Check ou the code of the program through GDB to find out errors in the code. You need to modify the code based on the check result via GDB so that the program work without errors. (40 points)
1. Based on the code check through GDB, the average value of the three subjects must be accurately printed. Note that the average value must be printed into two decimal places. (Provide your answer sheet wherein you need to describe the approach along with the screen capture to meet the requirements of the problem.) [Program download path](https://github.com/kwonsoonhong/system-programming-midterm-exam.git)
1. Provide the following in your answer sheet. Explain the result with the execution screen capture and then the symbol information for the Stack Smashing Protector (SSP), which is a protection technique against stack overflow attacks. Note that you must do this after above (1) task.

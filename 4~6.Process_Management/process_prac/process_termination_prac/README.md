# Process Termination Practice

## Normal Termination
- _return()_ from _main()_
- _exit()_
	- enables clean shutdown
	- releases all resources used by standard libraries before terminating
		- invoke _fclose()_ on all open streams
		- invoke exit handlers
			- _atexit()_: register exit handlers that will be executed upon the clean shutdown (last-registered-handler first-approach: ex. _term.c_)
- _\_exit()_  


Process send __termination status__ to its parent process.

## Abnormal Termination
- Abort
- Receipt of a signal  


Process cannot send __termination status__ to its parent process, therefore __kernel__ prepares a termination status to report.

![Process Termination](https://lh3.googleusercontent.com/proxy/SpLJFXsnl5SNS4PqF0EdLeUjBi-hSwjOLtMm5hKWz0bkXUjiZ3ehUztnT8k7e8VdZreBOEtSEbIqeIEkBOllckg2jYlIKxaZOiFAnaUIWKMOISTMfxhYFopp2Gxl_3v0qd7K_Qrp1b5YGyI87DnI7aU9KkRIiGRyqN-08L8j5RPHFZ4QfhKOH3gT9wGltNPQA01s9UVO13DWr24S0h3Bcy0U "Process Termination")

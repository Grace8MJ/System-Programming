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

## Abnormal Termination
- Abort
- Receipt of a signal

![Process Termination](http://poincare.matf.bg.ac.rs/~ivana/courses/ps/sistemi_knjige/pomocno/apue/APUE/0201433079/images/0201433079/graphics/07fig02_alt.gif;423615 "Process Termination")

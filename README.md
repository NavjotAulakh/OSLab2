# OSLab2
MyShell Project that simulates a CMD in Windows or BASHSHELL in Linux but with limited functionality <br />
Contributors: Name: Jeffrey Zhang ID: 100585611 || Name: Jehro Celemin ID: 100582918 || Name: Nicolas Zarfino ID: 100599899 || Name: Navjot Aulakh ID: 100488741 ||


 Instructions to get accesss to the internal commands for the Project Shell
--------------------------------------------------------

-To enter an internal command follow the next instructions:<br />
1 open the terminal and select the directory where myshell.<br />
2 execute the program  ./myshell <br />
3 type help to check all the internal commands that are in myshell <br />


--------------------COMMANDS-----------------------------<br />
help: Display the user manual using the more filter.

cd *directory*:  change current directory to the next *directory*, if the next *directory* name doesn't exist, error " No such directory or file' is printed.

clr: Clear the screen terminal.

dir <directory> :  List the content of the directory selected or dir iwht no selected directory  list the content of the current directory too (as the ls command)

environ: List all the environment strings.

echo <comment>: Display <comment> on the display followed by a new line (multiple spaces/tabs may be reduced to a single space).


pause: Pause operation of the shell until 'Enter' is pressed.

quit: Quit the shell.

The shell environment should contain shell=<pathname>/myshell where <pathname>/myshell is the full path for the shell executable (not a hardwired path back to your directory, but the one from which it was executed).




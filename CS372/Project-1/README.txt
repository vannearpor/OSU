Project ran and was tested on flip3.engr.oregonstate.eduINSTRUCTIONS ON HOW TO COMPILE, EXECUTE, AND CONTROL PROGRAM1. EXECUTE chatserve.py by typing in the command line: 
	python chatserve.py <port#>
2. COMPILE chatclient.c by typing in the command line:	gcc -o chat chatclient.c

   OR(ALTERNATIVELY) by typing in the command line:
	make
3. EXECUTE chatclient.c by typing in the command line:	./chat <server hostname> <port#> (SAME PORT # AS USED IN chatserve.py)	--NOTE: <server hostname> should be either flip1 or flip2 or flip3--
4. chatclient.c should prompt user to enter a user handle:	-Please ENTER a user handle name	-After entering handle name, ENTER the message to send to server and press <enter>	-Client message should send and display on chatserve.py
5. After chatclient.c sends message, on chatserve.py:	a. ENTER the message to send back to the client and press <enter>	b. Server message should send and display on chatclient.c
6. Repeat steps 4 & 5 until either program enters "\quit" to end the chat connection.
SETTING UP THE FILES:

	1. Make sure that ftserver.c and ftclient.py are in DIFFERENT directories.
	2. Make sure that ftserver.c and ftclient.py are ran on DIFFERENT versions of the flip servers.
		Ex: If ftserver.c is running on flip1; ftclient.py MUST be running on either flip2 or flip3


RUNNING ftserver.c:
	
	1. Compile ftserver.c by using this command in the directory containing ftserver.c and Makefile: make
	2. To execute ftserver use this command: ./ftserver <PORT NUMBER>
		NOTE: Make sure <PORT NUMBER> is a number between 1024 and 65535.


AFTER SERVER STARTS LISTENING, GO TO OTHER DIRECTORY WHERE ftclient.py IS LOCATED.

RUNNING ftclient.py:

	1. Set permissions by using this command: chmod +x ftclient.py

	2. THERE ARE NOW 2 OPTIONS TO RUN ftclient.py:
		a) To request a file, use this command: python ftclient.py <FLIP SERVER> <SERVER PORT NUMBER> -g <FILE NAME> <CONNECTION PORT>
			NOTE:  <FLIP SERVER> is the flip# server that ftserver.c is listening on. 
				<SERVER PORT NUMBER> is the port designated when executing ftserver.c
				<FILE NAME> is the name of the file requesting from server
				<CONNECTION PORT> Next connection, add 1 to <SERVER PORT NUMBER>
			EXAMPLE:
				python ftclient.py 7000 -g requestedFile.txt 7001

		b) To request the directory contents, use this command: python ftclient.py <FLIP SERVER> <SERVER PORT NUMBER> -l <CONNECTION PORT>
			NOTE:  <FLIP SERVER> is the flip# server that ftserver.c is listening on.
				<SERVER PORT NUMBER> is the port designated when executing ftserver.c
				<CONNECTION PORT> Next connection, add 1 to <SERVER PORT NUMBER>
			EXAMPLE:
				python ftclient.py 7000 -l 7001
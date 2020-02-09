/**
 * @majdhish_assignment1
 * @author  Majd Abughazaleh <majdhish@buffalo.edu>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * This contains the main function. Add further description here....
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include "../include/server.h"
#include "../include/client.h"
#include "../include/global.h"
#include "../include/logger.h"

/**
 * main function
 *
 * @param  argc Number of arguments
 * @param  argv The argument list
 * @return 0 EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	/*Init. Logger*/
	cse4589_init_log(argv[2]);

	/*Clear LOGFILE*/
	fclose(fopen(LOGFILE, "w"));

	/*Start Here*/
	  if (strcmp(argv[1],(char*)"c") == 0)
    		
 	 if (strcmp(argv[1],(char*)"s") == 0)

	void loop()
	{	
		if (strcmp(command, "AUTHOR") == 0)
		{
			cse4589_print_and_log("[%s:SUCCESS]\n", command);
			cse4589_print_and_log("I, majdhish, have read and understood the course academic integrity policy.\n");
			cse4589_print_and_log("[%s:END]\n", command);
		}
		else if (strcmp(command, "IP") == 0)
		{
			cse4589_print_and_log("[%s:SUCCESS]\n", command);
			ip();
			cse4589_print_and_log("[%s:END]\n", command);
		}
		else if (strcmp(command, "EXIT") == 0)
		{
			cse4589_print_and_log("[%s:SUCCESS]\n", command);
			exit_chat();
			cse4589_print_and_log("[%s:END]\n", command);
		}
		else if (strcmp(command, "PORT") == 0)
		{
			cse4589_print_and_log("[%s:SUCCESS]\n", command);
			port();
			cse4589_print_and_log("[%s:END]\n", command);
		}
		else if (strcmp(command, "LIST") == 0)
		{
			cse4589_print_and_log("[%s:SUCCESS]\n", command);
			list_clients();
			cse4589_print_and_log("[%s:END]\n", command);
		}
		else
		{
			cse4589_print_and_log("[%s:ERROR]\n", command);
			cse4589_print_and_log("[%s:END]\n", command);
		}
	}
   		

	return 0;
}

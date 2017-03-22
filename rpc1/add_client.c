/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "add.h"


void
addnum_1(char *host, int a, int b)
{
	CLIENT *clnt;
	int  *result_1;
	num  add_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ADDNUM, ADDNUM_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	add_1_arg.num1=a;
	add_1_arg.num2=b;
	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("Result:%d\n",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host NUMBER NUMBER\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	addnum_1 (host, atoi(argv[2]), atoi(argv[3]));
exit (0);
}

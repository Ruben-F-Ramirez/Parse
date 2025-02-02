
/************************************************************************
* Programmer: Ruben Ramirez
*
* Course:  CSCI 1320.01
*
* Date: April 14, 2016
*
* Assignment Number | Keyword : 19 |parse
*
* Point Value :  100
*
* Environment:  Visual Studio 2013
*
* Files Included: none
*
* Purpose: Purpose:  To read a file name given on the command line. 
* To parse an input line using strtok and atoi. To have a function modify values in the main part of the program.
* To re-use (after modifying) previous user-developed functions.  
*
* Input: coefficients of quadratic equation
*
* Preconditions: none
*
* Output: real roots of quadratic equation
*
* Postconditions: none
*
* Algorithm: The function implements the quadratic formula.
*
*
*
* Errors: This program does not have to handle complex roots.
*         Any testing with a quadratic equation that has complex roots
*         is at the risk of the (student) user.
*
* Example: Show an example in terms of input and output (if appropriate)
*
* History: modified code from quadratic program
***********************************************************************/






#include <stdio.h>  // printf
#include <stdlib.h>  // atoi
#include <string.h>  // strtok
#include <math.h>  // sqrt


int polysolver(double aa, double bb, double cc, double discriminant, double *root1, double *root2);
double discriminant(double AA, double BB, double CC);



int main(int argc, char * argv[])
{
	FILE * input;
	char aLine[1023]; // a "buffer" to hold the current line
	char * curStr; // pointer to the current string
	
	int retVal;  // return value 
	double root1; // The roots of the quadratic equation
	double root2; // The roots of the quadratic equation

	// The coefficients of a quadratic equation
	double AA;
	double BB;
	double CC;


	if (argc < 2)
	{
		printf("\nOperator ERROR this program expects a file to read\n Exiting ...\n\n");
		return 1;
	}

	input = fopen(argv[1], "r");

	if (input == NULL)
	{
		printf("\nUnable to open file: %s\n", argv[1]);
		printf("Either the spelling does not match the filename or the file is in a different directory\n\n");
		return 2;
	}

	while (fgets(aLine, sizeof(aLine), input))
	{

		curStr = strtok(aLine, ",");  // point to first number

		AA = atoi(curStr);
		curStr = strtok(NULL, ",");  // IMPORTANT USE NULL

		BB = atoi(curStr);
		curStr = strtok(NULL, ",");  // IMPORTANT USE NULL ON SECOND USE

		CC = atoi(curStr);




		printf("The quadratic equation is %.2f X^2 + (%.2f) X + (%.2f) = 0 \n", AA, BB, CC);// This is the format of our printing


		retVal = polysolver(AA, BB, CC, discriminant(AA, BB, CC), &root1, &root2);
		if (retVal == 0)
		{
			printf("The roots are complex\n");
		}

		else
		{
			printf("The real roots of the quadratic eaquation are %.3f and %.3f\n\n", root1, root2);
		}




	}// end of while

	fclose(input);
	return 0;
}




/************************************************************************
* Purpose:   Find the two roots of the quadratic equation and have those roots available in main
*
* Parameters:
*
* Action:
*
***********************************************************************/
int polysolver(double aa, double bb, double cc, double discriminant, double *root1, double *root2)

{


	if (discriminant < 0)
	{
		return 0;  // bad
	}
	else
	{
		double x;
		x = sqrt(discriminant);
		*root1 = (-bb + x) / (2 * aa);
		*root2 = (-bb - x) / (2 * aa);
		return 1;
	}


}
	
	





/************************************************************************
* Purpose:   to return the discrimant of quadratic equation
*
* Parameters: coefficients of quadratic equation
*
* Action: square BB and subtract 4*AA*CC
*
***********************************************************************/

double discriminant(double AA, double BB, double CC)

{

	return(BB*BB - 4 * AA*CC);

}
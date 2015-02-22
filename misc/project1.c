#include <stdio.h>
#include "mydata.h"
	
float avgTeam(int teamNumber);  	// FUNCTION PROTOTYPES
float avgLeague(int teamNumber);
int totalTeam(int teamNumber);

int main()
{
    int input;  					// BEGIN MENU

    printf( "Select a number below to view score data for \n");
    printf( "the 1st four home games seasons 1971-1975.\n\n" );    
    printf( "1. Minnesota Vikings\n" );
    printf( "2. Chicago Bears\n" );
    printf( "3. Green Bay Packers\n" );
    printf( "4. Exit\n\n" );
    printf( "Selection: " );
    scanf( "%d", &input );
    
    switch ( input ) {
        case 1:           
            avgTeam(0);
			totalTeam(0);         
			avgLeague(2);
			break;
        case 2:          
            avgTeam(1);
			totalTeam(1);             
			avgLeague(2);
		break;
        case 3:         
            avgTeam(2);
           	totalTeam(2);    
			avgLeague(2);
		break;
        case 4:        
            printf( "Have a nice day!\n" );
            break;
        default:            
            printf( "Bad input, quitting!\n" );
            break;
		}
    getchar(); 					// END MENU
}

float avgTeam(int teamNumber)  //TEAM AVERAGE
	{
	int s, w;  // seasons and weeks
	float avg=0;
  
    for ( s = 0; s < 5; s++ ) {
        for ( w = 0; w < 4; w++ ) {
            avg+=teamScores[s][w][teamNumber];
		}
	}
	printf ("Their average points per game was %.1f\n", avg/20);
    return 0;
}

float avgLeague(int teamNumber)			// LEAGUE AVERAGE
	{
	int s, w, t;
	float total=0;

	for ( s = 0; s < 5 ; s++ ) {
		for ( w = 0; w < 4; w++ ) {
			for ( t = 0; t < 3; t++ ) {
			total+=teamScores[s][w][t];
			}
		}
	}
	printf ("The average amongst the 3 teams was %.1f\n", total/60);
	return 0;	
}

int totalTeam(int teamNumber)			// TEAM TOTALS
	{
	int s, w, t;
	int total=0;

	for ( s = 0; s < 5; s++ ) {
		for ( w = 0; w < 4; w++ ) {
			for ( t = 0; t < 3; t++ ) {
			total+=teamScores[s][w][teamNumber];
			}
		}
	}
	printf ("Their total points scored was %d\n", total);
	return 0;
}


#include <stdlib.h>
#include <string.h>
#include "team.h"

// function prototypes
void init_db(void);
void print_record(int, struct team *);
void print_all(void);
void print_num(void);
void print_size(void);
void add_new_team(struct team *);
void add_new_record(void);
void delete_record(void);
void print_db_access(void);

// global variables
struct team *team_db;
static int num_teams = 0;
static int num_access = 0;

// initialize database
void init_db()
	{

	team_db = calloc(5, sizeof (struct team));

	add_new_team(&Vikings);
	add_new_team(&Bears);
	add_new_team(&Packers);
	add_new_team(&Lions);
	add_new_team(&Chiefs);

	}

int main() 
	{
	// begin menu
	int input;

	init_db();
	do
		{
		printf( "Select a number below. \n");   
		printf( "1. Print all records\n" );
		printf( "2. Print number of records\n" );
		printf( "3. Print size of database\n" );
		printf( "4. Add record\n" );
		printf( "5. Delete record\n" );
		printf( "6. Print number of accesses to database\n" );
		printf( "7. Exit\n" );
		printf( "Selection: " );
		scanf( "%d", &input );
		
		switch ( input ) 
			{
			case 1:
				print_all();        
				break;
			case 2:
				print_num();  
				break;
			case 3:
				print_size();
				break;
			case 4:        
				add_new_record();
				break;
			case 5:
				delete_record();
				break;
			case 6:
				print_db_access();
				break;
			case 7:
				break;
			default:            
				printf( "Bad input, try again!\n" );
				break;
			}
		getchar();
		}
	while (input!=7);
	
	free(team_db);
	// set to null just to be sure
	team_db = NULL;
	num_access++;

	}
	
void print_record(int num, struct team *current_team)
	{

	printf("%d.\tTeam Name :		%s\n",             	(num+1), 	current_team->team_name);
	printf("\tTeam Points :			%d\n", 			   		current_team->team_points);
	printf("\tTeam Rushing TD's :		%d\n", 				 	current_team->team_runtd);
	printf("\tTeam Passing TD's:		%d\n", 				 	current_team->team_passtd);
	printf("\tTeam Sacks  :			%d\n", 					current_team->team_sacks);
	printf("\tTeam Interceptions :		%d\n", 				 	current_team->team_ints);
	printf("\tTeam Fumbles :			%d\n\n\n", 	 		current_team->team_fumble);
	}
	
// displays all records
void print_all()
	{
	
	struct team *current_team = team_db;
	int i = 0;

	for ( i = 0; i < num_teams; i++) {
		print_record ( i, current_team);
		current_team++;
		num_access++;
		}
	}

// print number of records
void print_num()
	{
	int i;
	i=sizeof(struct team);
	printf ("The total number of records is %d\n", i/sizeof(int));
	}

// print size of database
void print_size()
	{
	int i;
	i=sizeof(struct team);
	printf ("The total size of the database is %d.\n\n", i);
}
// this function assumes that team_db has been resized, and that new record will go at end
void add_new_team(struct team *new_info) 
	{

	//	start at the start of the db
	struct team *add_here = team_db;

	// go to the end of the db
	add_here = add_here + num_teams;

	// copy from the new_team_info into the end of the database
	memcpy(add_here, new_info, sizeof(struct team));

	// add one to database counter
	num_teams++;
	num_access++;
	}

// adds new record
void add_new_record() 
	{
	// creates temp team for new info	
	struct team *new_info = calloc(1, sizeof(struct team));

	printf( "Enter team name: \n" );
	scanf( "%s", &(new_info->team_name[0]) );

	printf( "Enter points scored: \n" );
	scanf( "%d", &(new_info->team_points) );

	printf( "Enter rushing TDs: \n" );
	scanf( "%d", &(new_info->team_runtd) );

	printf( "Enter passing TDs: \n" );
	scanf( "%d", &(new_info->team_passtd) );

	printf( "Enter sacks: \n" );
	scanf( "%d", &(new_info->team_sacks) );

	printf( "Enter interceptions: \n" );
	scanf( "%d", &(new_info->team_ints) );

	printf( "Enter fumbles lost: \n" );
	scanf( "%d", &(new_info->team_fumble) );

	// 2. realloc db
	team_db = realloc(team_db, (num_teams + 1) * sizeof(struct team));

	// 3. add_new team
	add_new_team(new_info);

	free(new_info);
	new_info=NULL;
	}

// delete record
 void delete_record()	
	{
	int input;
	// 1. promt user for selection.
	printf( "Enter the team number [1-%d] you wish to delete: \n", num_teams);
	scanf( "%d", &input);
	if ( input < 1 || input > num_teams ) 
		{
		printf (" Invalid selection, please try again.\n");
		}
	else 
		{
		
		// start copy at proper spot
		struct team *copy_from;
		struct team *copy_to;
		
		// go to the end of the db
		copy_from = team_db + input;
		copy_to = team_db + (input - 1);
		memcpy(copy_to, copy_from, (num_teams - input) * (sizeof(struct team)));	
		
		// 3. resize db
		team_db = realloc(team_db, (num_teams - 1) * sizeof(struct team));

		// 4. counters
		num_teams --;
					 
		}
	}

//print database access
void print_db_access() 
	{
	printf ("The number of accesses to the database is: %d\n", num_access);
 
	}

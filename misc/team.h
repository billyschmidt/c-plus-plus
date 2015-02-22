#include <stdio.h>
#define MAX_NAME	31

struct team{
	char team_name[MAX_NAME];
	int team_points;
	int team_runtd;
	int team_passtd;
	int team_sacks;
	int team_ints;
	int team_fumble;
};
/*						name		PT,	RUN	PAS	SAC	INT	FUM	*/
struct team Vikings = { "Vikings" , 21,	2,	1,	2,	1,	1 };

struct team Bears 	= { "Bears" ,	28,	1,	3,	1,	1,	1 };

struct team Packers	= { "Packers",	35, 1,	4,	4,	0,	0 };

struct team Lions 	= { "Lions",	14,	1,	1,	0,	2,	1 };

struct team Chiefs	= { "Chiefs",	7,	0,	1,	1,	2,	1 };

 



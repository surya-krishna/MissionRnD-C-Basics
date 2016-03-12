/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int j,i,month[2],day[2],year[2];
	//validation for month and day
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
	{
		return -1;
	}
	for (j = 0; j<10; j++)
	{
		if ((dob1[j]<48 || dob1[j]>57 || dob2[j]<48 || dob2[j]>57) && j != 2 && j != 5)
			return -1;
	}
	day[0] = (dob1[0] - 48) * 10 + (dob1[1] - 48) ;
	day[1] = (dob2[0] - 48) * 10 + (dob2[1] - 48) ;

	month[0] = (dob1[3] - 48) * 10+ (dob1[4] - 48) ;
	month[1] = (dob2[3] - 48) * 10+ (dob2[4] - 48) ;

	year[0] = (dob1[6] - 48) * 1000 + (dob1[7] - 48) * 100 + (dob1[8] - 48) * 10 + (dob1[9] - 48);
	year[1] = (dob2[6] - 48) * 1000 + (dob2[7] - 48) * 100 + (dob2[8] - 48) * 10 + (dob2[9] - 48);

	for (i = 0; i<2; i++)
	{
		if (day[i]>31||month[i]>12)
		{
			return -1;
		}
		else
		{
			if (month[i] == 2)
			{
				if (year[i] % 100 == 0 && year[i] % 400 == 0)
				{
					if (day[i]>29)
						return -1;
				}
				else
				if (year[i] % 4 == 0 && year[i] % 100 != 0)
				{
					if (day[i]>29)
						return -1;
				}
				else
				if (day[i]>28)
				{
					return -1;
				}
			}
			else
			if (0 < month[i] && month[i] < 8)
			{
				if (month[i] % 2 == 0 && day[i]>30)
				{
					return -1;
				}
			}
			else
			if (7 < month[i] && month[i]< 13)
			{
				if (month[i] % 2 != 0 && day[i]>30)
				{
					return -1;
				}
			}

		}

	}

	if (year[0] > year[1])
		return 2;
	else
	if (year[1] > year[0])
		return 1;
	else
	{
		if (month[0] > month[1])
			return 2;
		else
		if (month[1] > month[0])
			return 1;
		else
		{
			if (day[0] > day[1])
				return 2;
			else
			if (day[1] > day[0])
				return 1;
			else
				return 0;
		
		}
	}
}

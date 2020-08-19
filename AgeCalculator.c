/*this program calculates the days from an initial date to a final date
it takes input the initial date and final date*/
#include<stdio.h>

	int initialDay=30;
	int initialMonth=8;
	int initialYear=1995;
	int finalDay=3;
	int finalMonth=05;
	int finalYear=2019;
int fullYearDays(int initialYear,int finalYear);
int yearDays(int year);
int fullMonthDaysFinal(int finalMonth,int finalyear);
int fullMonthDaysInitial(int initialMonth,int initialYear);
int monthDays(int month,int year);
int restDays(int initialDay,int finalDay);
int main()
{
	int totalDays=0;
	totalDays+=fullYearDays(initialYear,finalYear);
	//if(totalDays!=0)
	{
	totalDays+=fullMonthDaysFinal(finalMonth,finalYear);
	totalDays+=fullMonthDaysInitial(initialMonth,initialYear);
	totalDays+=restDays(initialDay,finalDay);
	}
	printf("Total age in days is : %d\n",totalDays);
	printf("Total age in hours is : %d\n",totalDays*24);	
	printf("Total age in weeks is : %d and %d days\n",totalDays/7,totalDays%7);
}

//this function calculates days of full years
int fullYearDays(int initialYear,int finalYear)
{
	int i;
	int totalDays=0;
	for(i=initialYear+1;i<finalYear;i++)
	{
		totalDays+=yearDays(i);
	}
	return totalDays;
}
//this function returns days according to year(for leap 366 and for rest 365)
int yearDays(int year)
{
		if(year%400==0 || (year%4==0 && year%100!=0))
		{
			return 366;
		}
		else
			return 365;

}
//this function calculates full dates of final year as there are some months missing
int fullMonthDaysFinal(int finalMonth,int finalyear)
{
	int i;
	int totalDays=0;
	for(i=1;i<finalMonth;i++)
	{
		totalDays+=monthDays(i,finalYear);
	}
	return totalDays;
}
//this function calulates days of initial year
int fullMonthDaysInitial(int initialMonth,int initialYear)
{
	int i=0;
	int totalDays=0;
	for(i=initialMonth+1;i<=12;i++)
	{
		totalDays+=monthDays(i,initialYear);
	}
	return totalDays;
}
//this function return days in months
int monthDays(int month,int year)
{
	switch(month)
	{
	case 1: case 3:case 5: case 7: case 8:case 10: case 12:
			return 31;
	case 2://this checks for leap year as 2nd month of leap year has 29 days
		if(year%400==0 || (year%4==0 && year%100!=0))
		{
			return 29;
		}
		else 
			return 28;
	default: 
		return 30;
	}
}
//this function calculates remaining days(current date and initial month days)
int restDays(int initialDay,int finalDay)
{
	int totalDays=0;
	totalDays+=finalDay+(monthDays(initialMonth,initialYear)-initialDay);
	return totalDays;

//
//  TimeTool.cpp
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "TimeTool.h"
#include "time.h"

void TimeGetNowDate(int* year, int* month, int* day, int* hour, int* min, int* sec)
{
    const time_t t = time(NULL);
    tm* const now_date = localtime(&t);
	if( year )
	{
		*year = now_date->tm_year;
	}
	if( month )
	{
		*month = now_date->tm_mon;
	}
	if( day )
	{
		*day = now_date->tm_mday;
	}
	if( hour )
	{
		*hour = now_date->tm_hour;
	}
	if( min )
	{
		*min = now_date->tm_min;
	}
	if( sec )
	{
		*sec = now_date->tm_sec;
	}
};
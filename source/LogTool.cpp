//
//  Log.cpp
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LogTool.h"
#include "PathTool.h"
#include "TimeTool.h"

void LogGetLogNormalFilename(std::string& out_filename)
{
	out_filename = Path::GetDoc( LOG_FILENAME_NORMAL );
}
void LogGetLogTimeMark(std::string& out_str)
{
	char buffer[ 0x100 ];
	int year,month,day,hour,min,sec;
	TimeGetNowDate( &year, &month, &day, &hour, &min, &sec );
	sprintf( buffer, LOG_TIME_MARK_FORMAT,
		year,month,day,hour,min,sec  );
	out_str = buffer;
}
void Log(const char* format_text, ...)
{
	std::string log_filename;
	LogGetLogNormalFilename( log_filename );
	FILE* const fp = fopen( log_filename.c_str(), "a" );
	if( fp )
	{
		va_list arg_ptr;
		va_start( arg_ptr, format_text );
		//	写时间
		{
			std::string time_mark;
			LogGetLogTimeMark( time_mark );
			fprintf( fp, "\n%s>", time_mark.c_str() );
		}
		//	写正文
		vfprintf( fp, format_text, arg_ptr );
		va_end( arg_ptr );
		fclose( fp );
	}
}
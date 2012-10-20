//
//  Log.h
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef test_Log_tool_h
#define test_Log_tool_h
#include <string>

#define LOG_FILENAME_NORMAL "LogNormal.log"
#define LOG_TIME_MARK_FORMAT "[%d-%d-%d %d:%d:%d]"

void LogGetLogNormalFilename(std::string& out_filename);
void LogGetLogTimeMark(std::string& out_str);
void Log(const char* format_text,...);

#endif

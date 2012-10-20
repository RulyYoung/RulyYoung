//
//  PathTool.h
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef test_PathTool_h
#define test_PathTool_h
#include <string>

#define PATH_SEG "/"

//	接口
class Path
{
public:
	static std::string GetRes(const std::string& source_filename);
	static std::string GetDoc(const std::string& source_filename);
};

#endif

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
	explicit Path(const std::string&);
	std::string GetResFilename(void)	const;
	std::string GetDocFilename(void)	const;
private:
	static void PathGetDocumentPath(std::string& out_path);
	static void PathGetAppPath(std::string& out_path);
	static void PathGetLogPath(const std::string& filename,
		std::string& out_path);
	static void PathGetFilePath(const std::string& filename,
		std::string& out_filename);
private:
	std::string m_SourcePath;
};

#endif

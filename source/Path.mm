//
//  PathTool.mm
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "Path.h"

Path::Path(const std::string& inSourcePath)
	:	m_SourcePath( inSourcePath )
{}
std::string Path::GetResFilename(void)	const
{
	std::string result;
	PathGetLogPath( m_SourcePath, result );
	return result;
}
std::string Path::GetDocFilename(void)	const
{
	std::string result;
	PathGetLogPath( m_SourcePath, result );
	return result;
}
void Path::PathGetDocumentPath(std::string& out_path)
{
	NSArray* paths = NSSearchPathForDirectoriesInDomains
		(NSDocumentDirectory,NSUserDomainMask, YES);
	NSString* doc_dir = [paths objectAtIndex:0];
	out_path = [doc_dir UTF8String];
}
void Path::PathGetAppPath(std::string& out_path)
{
	NSString* doc_dir = NSHomeDirectory();
	out_path = [doc_dir UTF8String];
}
void Path::PathGetLogPath(const std::string& filename,
	std::string& out_path)
{
	std::string doc_path;
	PathGetDocumentPath( doc_path );
	std::string final_filename = doc_path;
	final_filename += PATH_SEG;
	final_filename += filename;
	out_path = final_filename;
}
void Path::PathGetFilePath(const std::string& filename,
	std::string& out_filename)
{
	std::string path;
	PathGetAppPath( path );
	out_filename = path + "/" + filename;
}

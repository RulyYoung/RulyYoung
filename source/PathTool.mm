//
//  PathTool.mm
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "PathTool.h"

void PathGetDocumentPath(std::string& out_path)
{
	NSArray* paths = NSSearchPathForDirectoriesInDomains
		(NSDocumentDirectory,NSUserDomainMask, YES);
	NSString* doc_dir = [paths objectAtIndex:0];
	out_path = [doc_dir UTF8String];
}
void PathGetAppPath(std::string& out_path)
{
	NSString* doc_dir = NSHomeDirectory();
	out_path = [doc_dir UTF8String];
}
void PathGetLogPath(const std::string& filename,std::string& out_path)
{
	std::string doc_path;
	PathGetDocumentPath( doc_path );
	std::string final_filename = doc_path;
	final_filename += PATH_SEG;
	final_filename += filename;
	out_path = final_filename;
}
void PathGetFilePath(const std::string& filename,std::string& out_filename)
{
	std::string path;
	PathGetAppPath( path );
	out_filename = path + "/" + filename;
}


std::string Path::GetRes(const std::string& source_filename)
{
	std::string filename;
	PathGetFilePath( source_filename, filename );
	return filename;
}
std::string Path::GetDoc(const std::string& source_filename)
{
	std::string filename;
	PathGetLogPath( source_filename, filename );
	return filename;
}
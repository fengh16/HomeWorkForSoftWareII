#ifndef FH_FIND_H
#define FH_FIND_H

#include <fstream>
#include <string>

using namespace std;

extern int GetEndLine(string FilePath, string OutPath = "");//如果出错，返回false
string Get_File_Name(string FilePath);

#endif
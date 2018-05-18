#include <iostream>
#include <fstream>
#include <vector>
#include "CodeGenerator.h"

using namespace std;

CodeGen::CodeGen (string filename, LexicalAnalyzer * L)
{
  lex = L;
  string cppname = filename.substr (0, filename.length()-3) + ".cpp"; 
  cpp.open (cppname.c_str());
  if (cpp.fail())
    cout << "Error" << endl;
  cpp << "// Autogenerated Scheme to C++ Code\n";
  cpp << "// File: " << cppname << "\n";
  cpp << "#include <iostream>\n";
  cpp << "#include \"Object.h\"\n";
  cpp << "using namespace std;\n\n";
}

/********************************************************************************/
/* This function will								*/
/********************************************************************************/
CodeGen::~CodeGen ()
{
	cpp.close();
}

/********************************************************************************/
/* This function will								*/
/********************************************************************************/
void CodeGen::WriteCode (int tabs, string code)
{
    
  for (int t = 0; t < tabs; t++)
    cpp << '\t';
  cpp << code;
}

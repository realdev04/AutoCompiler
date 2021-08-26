
#ifndef AUTOCMP_H
#define AUTOCMP_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <string>
#include <vector>

//#define _DEBUG_
#include "osdef.h"
#include "utilities.h"

using namespace std;

struct fileData
{
    string data;
    unsigned int lineCount;
    bool isPresent;
    fileData(string _data, unsigned int _lc, bool _isp){
        data = _data;
        lineCount = _lc;
        isPresent = _isp;
    }
};

struct filePathName{
    string filePath;
    string fileName;
    filePathName(string fp, string fn){
        filePath = fp;
        fileName = fn;
    }
};

struct CCppFileNameCount
{
    string fileNames;
    unsigned int fileCount;
    CCppFileNameCount(string fn, int fc){
        fileNames = fn;
        fileCount = fc;
    }
};

class autocmp
{
private:
    //Tools CMD Args
    int argc;
    char **argv;

    //Functions
    fileData getFileNamesfromFile(const char* fileName);
    char *getFileData(const char *fileName);
    bool isFSlashPresent(string word);
    bool isBSlashPresent(string word);
    string convertSlash(string _word);
    filePathName getOutNamePath(string name);
    string getFileName(string fileList, int fileNo);
    CCppFileNameCount getCCppFileNames(string fileList, int fileCount);
    bool isCCppFile(string fileName);
    bool isIncludeDir(string fileName);
    string getObjFileNames(CCppFileNameCount fnc);
    string getObjFileName(string fileName);
    void printUsage();

public:
    autocmp(int _argc, char **_argv);
    ~autocmp();
    void init(int _argc, char **_argv);
    int run();
};


#endif
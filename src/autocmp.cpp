#include "../include/autocmp.h"

autocmp::autocmp(int _argc, char **_argv)
{
    argc = _argc;
    argv = _argv;
}

autocmp::~autocmp()
{
    delete &argc;
    delete argv;
}

fileData autocmp::getFileNamesfromFile(const char* fileName){
    FILE *file;
    if (file = fopen(fileName, "r"))
    {
        char c;
        long char_count = 0;
        unsigned int lnc = 0;
        while (true)
        {
            if (fgetc(file) == EOF)
            {
                break;
            }
            char_count++;
        }
        //char *data = new char[char_count + 1];
        string data = "";
        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < char_count; i++)
        {
            c = fgetc(file);
            if(c == '\n'){
                data += " ";
                lnc++;
            }
            else{
                data += c;
            }
        }
        lnc++;
        fseek(file, 0, SEEK_SET);
        fclose(file);
        return fileData(data, lnc, true);
    }
    else
    {
        cout << "The file \"" << fileName << "\" does not exist!\n";
        return fileData("", 0, false);
    }
}

char* autocmp::getFileData(const char *fileName)
{
    FILE *file;
    if (file = fopen(fileName, "r"))
    {
        char c;
        long char_count = 0;
        while (true)
        {
            if (fgetc(file) == EOF)
            {
                break;
            }
            char_count++;
        }
        char *data = new char[char_count + 1];
        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < char_count; i++)
        {
            data[i] = fgetc(file);
        }
        data[char_count] = '\0';
        fclose(file);
        return data;
    }
    else
    {
        cout << "The file \"" << fileName << "\" does not exist!\n";
        return NULL;
    }
}

bool autocmp::isFSlashPresent(string word){
    if(word.find("/", 0) < word.size()+1){
        return true;
    }
    else{
        return false;
    }
}

bool autocmp::isBSlashPresent(string word){
    if(word.find("\\", 0) < word.size()+1){
        return true;
    }
    else{
        return false;
    }
}

string autocmp::convertSlash(string _word){
    char* word = new char[_word.size()+1];
    for(int i=0;i < _word.size()+1;i++){
        word[i] = _word[i];
    }
    if(isFSlashPresent(word)){
        unsigned long long slPos = 0;
        while(slPos < _word.length()+1){
            slPos = _word.find("/", 0);
            word[slPos] = '\\';
        }
        return string(word);
    }
    else{
        return string(word);
    }
}

filePathName autocmp::getOutNamePath(string name){
    unsigned long long sPos, prevPos = 0;
    string fileName, filePath = ".";
    while(true){
        sPos = name.find('/', prevPos);
        //cout << "sPos: " << sPos << "\n";
        if(sPos < name.size() + 1){
            filePath = "";
            for(int i=0; i<sPos; i++){
                filePath += name[i];
            }
            prevPos = sPos+1;
        }
        else{
            for(int i=prevPos; i<name.size(); i++){
                fileName += name[i];
            }
            break;
        }
    }
    return filePathName(filePath, fileName);
}

string autocmp::getFileName(string fileList, int fileNo)
{
    int spCount = 0;
    string currFile = "";
    for (int i = 0; i < fileList.size(); i++)
    {
        if (fileList[i] == ' ')
        {
            spCount++;
            if (spCount == fileNo)
            {
                return currFile;
            }
            else
            {
                currFile = "";
            }
        }
        else
        {
            currFile += fileList[i];
        }
    }
    return currFile;
}

CCppFileNameCount autocmp::getCCppFileNames(string fileList, int fileCount){
    string cCppFileNames = "", currFile = "";
    unsigned int count = 0;
    for(int i=1;i<=fileCount;i++){
        currFile = getFileName(fileList,i);
        if(currFile.find(".c", 0) < currFile.size()+1 || currFile.find(".cpp", 0) < currFile.size() + 1){
            cCppFileNames += currFile;
            cCppFileNames += " ";
            count++;
        }
    }
    return CCppFileNameCount(cCppFileNames, count);
}

bool autocmp::isCCppFile(string fileName){
    if(fileName.find(".c", 0) < fileName.size()+1 || fileName.find(".cpp", 0) < fileName.size() + 1){
        return true;
    }
    else{
        return false;
    }
}

bool autocmp::isIncludeDir(string fileName){
    if(fileName.find("-I", 0) < fileName.size()+1){
        return true;
    }
    else{
        return false;
    }
}

string autocmp::getObjFileNames(CCppFileNameCount fnc)
{
    string objFileNames = "", currFile = "", fObjFileName = "";
    int dotPos;
    for(int i=1;i<=fnc.fileCount;i++){
        currFile = getFileName(fnc.fileNames, i);
        for(int j=0; j < currFile.find(".", 0); j++){
            fObjFileName += currFile[j];
        }
        fObjFileName += ".o ";
        objFileNames += fObjFileName;
        fObjFileName = "";
    }
    return objFileNames;
}

string autocmp::getObjFileName(string fileName)
{
    string objFileName = "";
    for(int j=0; j < fileName.find(".", 0); j++){
        objFileName += fileName[j];
    }
    objFileName += ".o ";

    return objFileName;
}

void autocmp::printUsage()
{
    PRINT "\n";
    PRINT "  Auto Compiler:Usage\n";
    PRINT "\tautocmp [File Names] -o [Target Exe Name] [[+= Compiler Args +=]]\n";
    PRINT "\t\tEx: autocmp main.cpp test.cpp header.h -o program\n";
    PRINT "\t\tEx: autocmp main.cpp test.cpp header.h -o program += -Iinclude -Llibs -lmylib +=\n\n";
    PRINT "\tautocmp -f [File Names File] -o [Target Exe Name] [[+= Compiler Args +=]]\n";
    PRINT "\t\tEx: autocmp -f fileList.atc -o program\n";
    PRINT "\t\tEx: autocmp -f fileList.atc -o program += -Iinclude -Llibs -lmylib +=\n\n";
    PRINT "\t*Note: If your program is a continuous looping console application, that program might not work with autocmp!\n";
    PRINT "\tUse CTRL+C to Stop the Running Program in the CMD\n\n";
    PRINT "For more information visit our website -> https://realdev04.github.io \n\n";
}

int autocmp::run(){
    if (argc < 2)
    {
        printUsage();
        return 0;
    }
    else
    {
        string targetName = "test", strArgv = "", fileNames = "", compilerArgs = "", cppFileNames = "";
        bool isCompilerArg = false, isFromFile = false, isOutfileSpecified = false, isSrcsSpecified = false;
        unsigned int fileCount = 0;

        //Assign Values for the Variables
        for(int av=1; av<argc; av++){
            TODEBUG(cout << "Running Initializing Loop!\n");
            strArgv = argv[av];
            if(strArgv == "-f" && !isCompilerArg){
                av++;
                fileNames = getFileNamesfromFile((const char*)argv[av]).data;
                fileCount = getFileNamesfromFile((const char*)argv[av]).lineCount;
                TODEBUG(PRINT "Setting Mode to to Read File:- File List:\n" << fileNames << "\nFile Count: " << fileCount);
                isSrcsSpecified = getFileNamesfromFile((const char*)argv[av]).isPresent;
                if(!isSrcsSpecified){
                    break;
                }
            }
            else if(strArgv == "-o" && !isCompilerArg){
                av++;
                targetName = argv[av];
                isOutfileSpecified = true;
                TODEBUG(cout << "Setting Outfile to true\n");
            }
            else if(strArgv == "+="){
                isCompilerArg = !isCompilerArg;
                TODEBUG(cout << "Setting isCompilerArg to true\n");
            }
            else{
                if(!isCompilerArg){
                    fileNames += strArgv;
                    fileNames += " ";
                    fileCount++;
                    isSrcsSpecified = true;
                }
                else{
                    compilerArgs += strArgv;
                    compilerArgs += " ";
                }
            }
        }

        if(isOutfileSpecified == false){
            PRINT "Please Specify the Output Programme Name using \'-o\'.\n";
            PRINT "\tEx: autocmp test.cpp -o test\n\n";
            return 0;
        }

        if(!isSrcsSpecified){
            PRINT "Please Specify the Files.\n";
            PRINT "\tEx: autocmp hello.cpp test.h test.cpp -o program\n\n";
            return 0;
        }

        string data[fileCount];
        string prev_data[fileCount];
        bool isChangedAfile = false;
        string cmd = "";
        while (true)
        {
            for(int fc = 0; fc < fileCount; fc++){
                TODEBUG(PRINT "Inside Main For Loop!\n");
                data[fc] = getFileData(getFileName(fileNames, fc+1).c_str());
                TODEBUG(PRINT "Data of " << getFileName(fileNames, fc+1) << ": \n" << data[fc] << "\n");
                if(data[fc] != prev_data[fc]){
                    system(CLEAR_SCR);
                    TODEBUG(PRINT "File Changed -> " << getFileName(fileNames, fc+1) <<"\n");
                    if(isCCppFile(getFileName(fileNames, fc+1))){
                        TODEBUG(PRINT "Changed file is a C/C++ File\n");
                        cmd = CXXC;
                        cmd += "-c ";
                        cmd += compilerArgs;
                        cmd += getFileName(fileNames, fc+1);
                        cmd += " -o ";
                        cmd += getObjFileName(getFileName(fileNames, fc+1));
                        PRINT " - Compiling " << getFileName(fileNames, fc+1) << "\n";
                        system(cmd.c_str());
                    }
                    isChangedAfile = true;
                }
                TODEBUG(PRINT "Equalizing Data!\n");
                prev_data[fc] = data[fc];
            }
            if(isChangedAfile){
                cmd = CXXC;
                cmd += getObjFileNames(getCCppFileNames(fileNames, fileCount));
                cmd += compilerArgs;
                cmd += " -o ";
                cmd += targetName;
                TODEBUG(PRINT "Exe Build Cmd -> " << cmd << "\n");
                PRINT "->> Creating the Executable...\n\n";
                system(cmd.c_str());
                system(CLEAR_SCR);
                PRINT "OUTPUT:\n\n";
                #ifdef AT_WIN
                    cmd = "cd ";
                    cmd += convertSlash(getOutNamePath(targetName).filePath);
                    cmd += " && ";
                    cmd += getOutNamePath(targetName).fileName;
                    system(cmd.c_str());
                #else
                    cmd = RUN_SYMBOL;
                    cmd += targetName;
                    system(cmd.c_str());
                #endif
                cmd = "";
            }
            isChangedAfile = false;
            TODEBUG(PRINT "-------------------------------------------------\n");
            delay(500);
        }
    }
    
    return 0;
}
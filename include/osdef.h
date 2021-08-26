#ifndef OS_DEF_H
#define OS_DEF_H

#if defined (_WIN32)
    #include <windows.h>
    #define delay(time) Sleep(time) //Delay Milliseconds
    #define CLEAR_SCR "cls"
    #define REMOVE "del"
    #define MKDIR "mkdir"
    #define SLASH '\\'
    #define RUN_SYMBOL ""
    #define EXTEN ".exe"
    #define AT_WIN
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__)
    #include <unistd.h>
    #define delay(time) usleep(time*1000) //Delay Milliseconds
    #define CLEAR_SCR "clear"
    #define REMOVE "rm"
    #define MKDIR "mkdir"
    #define SLASH '/'
    #define RUN_SYMBOL "./"
    #define EXTEN ".exe"
    #define AT_UNIX
#else
    #error Your OS is not Supported!
#endif

#endif

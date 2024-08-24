#pragma once

#include "QR_Print.h"
#include <stdlib.h>



//###############################################
//MACROS
//###############################################

//stringify-----------------------
#define QR_stringify(s) QR_xstr(s)
#define QR_xstr(s) #s

#define PRIVATE_CONCAT(a, b) a ## b

#define CONCAT(a, b) PRIVATE_CONCAT(a, b)



//###############################################
//ASSERTS
//###############################################
#define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __LINE__, __FILE__ )
#define configASSERT( x, msg ) if( ( x ) == 0 ) vAssertCalled( msg, __LINE__, __FILE__ )

static void vAssertCalled(char* msg, unsigned long ulLine, const char * const pcFileName)
{
    QR_Print("Hadi: line %d\n file %s\n has failed a configassert. the assert message: %s",ulLine, pcFileName,msg );
    //QR_Print(msg);
    abort();

}

static void vAssertCalled(unsigned long ulLine, const char * const pcFileName)
{
    vAssertCalled("No assert message has been provided.",ulLine, pcFileName);
}






//###############################################
//Common utility functions
//###############################################



#include <algorithm>
#include <cctype>
#include <locale>


namespace QR
{
    //-----------------------------
    //strings
    //-----------------------------

    // trim from start (in place)
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // trim from both ends (in place)
    static inline void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }


}

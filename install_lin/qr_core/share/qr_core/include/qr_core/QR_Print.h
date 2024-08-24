#pragma once

#include "iostream"
#include "stdarg.h"

#ifdef ROS2_PROJECT
#include "rclcpp/rclcpp.hpp"
extern rclcpp::Node* AOGlobalNode;
#ifdef AllSurrogates
extern rclcpp::Node* TheNodeForAllSurrogates;
#endif

#else
#include <cstring>
#endif




#include <stdexcept>
#include <memory>
#include <stdio.h>
#include <string>



//solution given by
//https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
static std::string string_format(const std::string fmt_str, ...) {
    int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
    std::unique_ptr<char[]> formatted;
    va_list ap;
    while(1) {
        formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
        strcpy(&formatted[0], fmt_str.c_str());
        va_start(ap, fmt_str);
        final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);
        if (final_n < 0 || final_n >= n)
            n += abs(final_n - n + 1);
        else
            break;
    }
    return std::string(formatted.get());
}


static void _QR_Print(const char* msg)
{
    #ifdef ROS2_PROJECT
#ifdef AllSurrogates
        auto nodeToUse = TheNodeForAllSurrogates;
#else
        auto nodeToUse = AOGlobalNode;

#endif
    if(nodeToUse != nullptr)
    {
        RCLCPP_INFO(nodeToUse->get_logger(),msg);// msg,lst);
    }
    else
    {
        printf(msg);
    }

    #else
    printf(msg);
    #endif
}


//const std::string&
//static void QR_Print2(const char* msg, ...)
#define QR_Print(...) \
{\
    std::string out = string_format(__VA_ARGS__);\
    _QR_Print(out.c_str());\
}


//
//  SimpleLogger
//
//  Created by Marcin Gebala on 24.08.2017.
//  Copyright © 2017 MG. All rights reserved.
//

#ifndef logger_hpp
#define logger_hpp

#include <algorithm>
#include <iostream>
#include <fstream>
#include "row.h"

#define SEP ";"

#define LOG_INIT(name) logger::Logger::getInstance().init(name)

#define LOG_TRACE LOG ( logger::LogLevel::Trace ) << __func__ << SEP;
#define LOG_DEBUG LOG ( logger::LogLevel::Debug )
#define LOG_INFO  LOG ( logger::LogLevel::Info )
#define LOG_WARN  LOG ( logger::LogLevel::Warning )
#define LOG_FATAL LOG ( logger::LogLevel::Fatal )

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LEVEL(l) strrchr(l, ':') + 1 << SEP
#define TIME __DATE__ << SEP <<  __TIME__ << SEP
#define LOCATION __FILENAME__ << ":" << __LINE__ << SEP
#define TRACE(x) #x << ":" << (x)

#define LOG(level) logger::Logger::getInstance() += logger::Row() << LEVEL(#level) << LOCATION

namespace logger
{
    enum class LogLevel
    {
        Trace,
        Debug,
        Info,
        Warning,
        Fatal,
    };
    
    class Logger
    {
    
    protected:
        Logger() {};
        ~Logger() { logFile.close(); };
        
    public:
        static Logger& getInstance();
        void init(const std::string& name);
        void operator+= ( const Row& row ) { write ( row ); }
       
    private:
        void init();
        static std::string getTimeString();
        static std::string getDefaultFileName();
        
        bool write ( const Row& row );
        
        std::ofstream logFile;
        
    };
    
    
    
}

#endif /* logger_hpp */

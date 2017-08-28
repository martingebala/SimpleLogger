//
//  SimpleLogger
//
//  Created by Marcin Gebala on 24.08.2017.
//  Copyright © 2017 MG. All rights reserved.
//

#include <iomanip>
#include <ctime>
#include "logger.h"

namespace logger {

    Logger& Logger::getInstance()
    {
        static Logger instance;
        return instance;
    }
    
    bool Logger::write ( const Row& row )
    {
        init();
        logFile <<  logger::Logger::getTimeString() << SEP << row.getContent() << std::endl;
        return true;
    }
    
    void Logger::init()
    {
        if ( !logFile.is_open() )
        {
            logFile.open( getDefaultFileName(), std::ios::out | std::ios::app );
        }
    }
    void Logger::init(const std::string& name)
    {
        if ( !logFile.is_open() && !name.empty() )
        {
            logFile.open( name, std::ios::out | std::ios::app );
        }
    }
    
    std::string Logger::getTimeString()
    {
        std::ostringstream str;
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        str << std::put_time(&tm, "%d.%m.%Y %T");
        return str.str();
    }
    
    std::string Logger::getDefaultFileName()
    {
        std::ostringstream str;
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        str << std::put_time(&tm, "Log_%d%m%Y%_%H%M%S.csv");
        return str.str();
    }
    
}

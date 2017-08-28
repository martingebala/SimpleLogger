//
//  SimpleLogger
//
//  Created by Marcin Gebala on 24.08.2017.
//  Copyright © 2017 MG. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <map>
#include "log/logger.h"


using namespace std;

int main(int argc, const char * argv[])
{
    LOG_INIT("test.csv");
    LOG_INFO << "Simple Log Message system";
    
    map< string, vector<int> > myMap;
    myMap["one"] = {1,2,3};
    myMap["two"] = {4,5};
    
    LOG_INFO << "Example print of map structure: " << myMap;
    
    cout << "Hello world!" << std::endl;

    return 0;
}

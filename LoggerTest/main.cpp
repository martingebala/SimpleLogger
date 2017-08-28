//
//  SimpleLogger
//
//  Created by Marcin Gebala on 25.08.2017.
//  Copyright © 2017 MG. All rights reserved.
//

#include <iostream>
#include "gtest/gtest.h"
#include "logger.h"

TEST (SequenceContainersTest, PrintNested)
{
    std::vector< std::array<int,3> > myMatrix;
    myMatrix.push_back( {1,2,3} );
    myMatrix.push_back( {4,5,6} );
    
    logger::Row row;
    row << myMatrix;
    
    EXPECT_EQ ("{{1,2,3},{4,5,6}}", row.getContent());
}

TEST (SequenceContainersTest, PrintMap)
{
    std::map<char,int> myMap;
    myMap['b'] = 200;
    myMap['a'] = 100;
    myMap['c'] = 300;
    
    logger::Row row;
    row << myMap;
    
    EXPECT_EQ ("{a:100,b:200,c:300}", row.getContent());
}

TEST (SequenceContainersTest, PrintMapOfVectors)
{
    std::map< std::string, std::vector<int> > myMap;
    myMap["one"] = {1,2,3};
    myMap["two"] = {4,5};
    
    logger::Row row;
    row << myMap;
    
    EXPECT_EQ ("{one:{1,2,3},two:{4,5}}", row.getContent());
}

TEST (SequenceContainersTest, PrintArray)
{
    std::array<double,5> myArray = {1,2,3,4,5};
    
    logger::Row row;
    row << myArray;
    
    EXPECT_EQ ("{1,2,3,4,5}", row.getContent());
}

TEST (SequenceContainersTest, PrintVector)
{
    std::vector<int> myVector {100,200,300};
    
    logger::Row row;
    row << myVector;
    
    EXPECT_EQ ("{100,200,300}", row.getContent());
}

TEST (SequenceContainersTest, PrintList)
{
    std::list<int> myList {100,200,300};
    
    logger::Row row;
    row << myList;
    
    EXPECT_EQ ("{100,200,300}", row.getContent());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

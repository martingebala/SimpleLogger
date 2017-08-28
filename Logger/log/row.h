//
//  SimpleLogger
//
//  Created by Marcin Gebala on 24.08.2017.
//  Copyright © 2017 MG. All rights reserved.
//

#ifndef row_h
#define row_h
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <map>

namespace logger
{
    class Row
    {
    public:
        Row (): m_separator(",") { }
        ~Row() { }
    
        std::string getContent() const { return m_content.str(); };
        
        //TODO: add support for all containers 
        
        template<typename T>
        Row& operator<< ( const std::vector<T>& v )  { return joined(v); }
        
        template<typename T>
        Row& operator<< ( const std::list<T>& l )    { return joined(l); }
        
        template<typename A, std::size_t S>
        Row& operator<< ( const std::array<A,S>& a ) { return joined(a); }
        
        template<typename T, typename U>
        Row& operator<< ( const std::map<T,U>& m )   { return joined(m); }
    
        template<typename T, typename U>
        Row& operator<< ( const std::pair<T,U>& p )
        {
            return (*this << p.first << ":" << p.second);
        }
        
        template<typename T>
        Row& operator<< ( const T& t )
        {
            m_content << t;
            return *this;
        }
        
    private:
        std::ostringstream m_content;
        std::string m_separator;
        
        template<typename Sequence>
        Row& joined ( const Sequence& sequence )
        {
            if ( !sequence.empty() )
            {
                auto it = sequence.cbegin();
                *this << "{" << *it;
                std::for_each ( ++it, sequence.cend(), [this](const typename Sequence::value_type i)
                               {
                                   *this << m_separator << i;
                               });
            }
            return *this << "}";
        }
        
    };
}

#endif /* row_h */

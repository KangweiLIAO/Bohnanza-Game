#include <string>  
#include <map>  
#include <iostream>  
#include <fstream>  
#include <sstream>  

using namespace std;

class Config { 
    public:
    Config(string filename,string delimiter = "=",string comment = "#" );  
    Config(); 
    // Modify keys and values
    template<class T> void Add( const string& in_key, const T& in_value ); 
    template<class T> static std::string T_as_string( const T& t );  
    static void Trim( std::string& inout_s ); 
};

template<class T>  
void Config::Add( const string& in_key, const T& value )  
{  
    // Add a key with given value  
    string v = T_as_string( value );  
    string key=in_key;  
    Trim(key);  
    Trim(v);  
    m_Contents[key] = v;  
    return;  
}  

template<class T>  
std::string Config::T_as_string( const T& t )  
{  
    // Convert from a T to a string  
    // Type T must support << operator  
    std::ostringstream ost;  
    ost << t;  
    return ost.str();  
}  
  
void Config::Trim( string& inout_s )  
{  
    // Remove leading and trailing whitespace  
    static const char whitespace[] = " \n\t\v\r\f";  
    inout_s.erase( 0, inout_s.find_first_not_of(whitespace) );  
    inout_s.erase( inout_s.find_last_not_of(whitespace) + 1U );  
}  
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <map>

#include <fstream>
#include <sstream>




std::vector<int> pref_subtract(std::vector<int> a, std::vector<int> b)
{
    //Takes two vectors a and b, then removes b elements from a
    // returns a


    std::sort( std::begin(b), std::end(b) );
    a.erase( std::remove_if( std::begin(a), std::end(a),
    [&](auto x){return std::binary_search(std::begin(b),std::end(b),x);}), std::end(a) );


    return a;

}

bool in(const int& key, const std::vector<int>& v)
{
    //Takes an int key and vector v
    //Iterates over to see if key is in there

    for (auto&& i : v)
        if ( key == i)
            return true;
    return false;
}







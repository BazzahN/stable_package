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




template <typename T>
T lexical_cast(const std::string& str)
{
    T var;
    std::istringstream iss;
    iss.str(str);
    iss >> var;
    // deal with any error bits that may have been set on the stream
    return var;
}

template<typename data_type,
template <typename... table_type_args> typename table_type,
template <typename... row_type_args> typename row_type>
table_type<row_type<data_type> > csvtable(const std::string& filename)
{
  table_type<row_type<data_type> > table;
  std::ifstream infile(filename);
  while(infile)
    {
      std::string s;
      if(!getline(infile,s)) break;
      std::istringstream ss(s);
      row_type<data_type> row;
      while(ss)
      {
         std::string s;
         if(!getline(ss,s,',')) break;
         row.push_back(lexical_cast<data_type>(s));
      }
      table.push_back(row);
    }
  return table;
}


//FUNCTION DEF: Reads from txt file -> preference map
std::map<int,std::vector<int>> file_rw_pref_dict(const std::string& filename)
{
    #define readtxt csvtable<int,std::list,std::vector>
    //takes file name, assuming .txt file (for now)
    //Removes contents of file by line and puts it into a dictionary for each individual


    std::map<int,std::vector<int>> pref_table;

    std::string txt {".txt"};

    //std::string {filename + txt};

    std::list<std::vector<int> > line {readtxt(filename + txt)};

    int i_count {0};

    for(std::vector<int>& pref : line)
        {
            pref_table[i_count+1] = pref;

            i_count++;
        }


    return pref_table;

}




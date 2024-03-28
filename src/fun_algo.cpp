#include <iostream>
#include <map>
#include <vector>
#include <list>

#include "utils.h"
#include "IS_STABLE.h"
#include "Rcpp.h"
using namespace Rcpp;


std::list<std::vector<int>> fun_algo(std::map<int,std::vector<int> > F_prefs, std::map<int,std::vector<int> > H_prefs, bool rout = false)
{
    //**Copy Pref Tables**
    const std::map<int,std::vector<int>> F_pref_cpy = F_prefs;
    const std::map<int,std::vector<int>> H_pref_cpy = H_prefs;





    //**Undesirable Match Initialise**
    std::map<int,int> fmtch;
    int omga {F_prefs.end() -> first + 1}; //Makes the undesirable man not included in the table

    for (auto it = F_prefs.begin(); it != F_prefs.end(); ++it)
    {
        fmtch[it -> first] = omga;

    }


    int x;
    int X;
    int X_hld;
    std::vector<int> x_p;
    std::vector<int> hld;




    for (auto it = H_prefs.begin(); it != H_prefs.end(); ++it)
    {
        X = it->first;


        while(X != omga)
        {
            x = H_prefs[X][0];
            x_p = F_prefs[x];

            if (in(X,x_p))
            {



                X_hld = fmtch[x];
                fmtch[x] = X;


                auto k = x_p.begin();

                while(k != x_p.end() && *k != X)
                {

                    hld.push_back(*k);

                    ++k;
                }

                F_prefs[x] = hld;
                hld.clear(); //removes contents of temp storage vector for next use

                X = X_hld;

            }


            if(X != omga)
            {

                H_prefs[X].erase(H_prefs[X].begin());

            }


        }

    }


    std::list<std::vector<int>> mtch;
    for (auto it = fmtch.begin(); it != fmtch.end(); ++it)
    {

        mtch.push_back({it -> first,it -> second});




    }



    if (rout)
    {
       if (IS_STABLE(mtch, F_pref_cpy, H_pref_cpy,false))
        {

        Rcout <<"Stable Match Found! \n" << std::endl;

        Rcout << "Identified Pairings:" << std::endl;
        Rcout << "  A    |" << " " << "  B  " << std::endl;
	Rcout << "-------|-------" << std::endl;
		
        for(auto i : mtch)
        {

            Rcout << "  " << i[0] << "    |   "  << i[1] << std::endl;
            Rcout << "-------|-------" << std::endl;
        }
        }
	else
	{
	    Rcout << "Obtained Match is Unstable:" << std::endl;
	    Rcout << "Mix or input different preferences tables" << std::endl;
	}

    }


    return mtch;

}

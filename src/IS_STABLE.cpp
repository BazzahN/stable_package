#include <iostream>
#include <map>
#include <vector>
#include <list>

#include "utils.h"



bool IS_STABLE(const std::list<std::vector<int> >& mtch, std::map<int, std::vector<int> > A_prefs, std::map<int,std::vector<int> > B_prefs, bool rout = false)
{

    //mtchs = {{A,B},{A,B}...}


    //**VARIABLE DECLARATION**

    bool stb = 1; //Stability Indicator stb = 0 (Un-Stable) stb = 1 (Stable)


    int k_1;
    int k_2;

    int pA;
    int pB;


    std::vector<int> WA;
    std::vector<int> WB;

    std::vector<int> LA;
    std::vector<int> LB;


    std::vector<int> hld;
    std::vector<int> hld_1; //re-usable temp storage





    for (auto& it: mtch){ //Declaration of the first for loop from my code

        k_1 = it[0];
        k_2 = it[1]; //stores and seperates A and B in matching


        pA = A_prefs[k_1][0];
        pB = B_prefs[k_2][0]; // stores first preference of paired man and women



        //MALE WIN/LOSS IDENT
        if (pA == k_2){

            A_prefs.erase(k_1); //removes winner's name from male preference tables
            WA.push_back(k_1); //adds winner to male winners vector

        } else
        {



            auto nh = A_prefs[k_1];

            auto k = nh.begin();

            while(k != nh.end() && *k != k_2){ //iterates over and stores values from 'losers' table till current partner is reached

                hld.push_back(*k);

                ++k;
            }

           A_prefs[k_1] = hld;
           hld.clear(); //removes contents of temp storage vector for next use


           LA.push_back(k_1); //adds key to loser list (Male)

        }



        //FEMALE WIN/LOSS IDENT
        if (pB == k_1){

            B_prefs.erase(k_2); //removes winner's name from male preference tables
            WB.push_back(k_2); //adds winner to female winners vector

        } else{

            auto nh = B_prefs[k_2];

            auto k = nh.begin();

            while(k != nh.end() && *k != k_1){ //iterates over and stores values from 'losers' table till current partner is reached

                hld.push_back(*k);

                ++k;
            }

           B_prefs[k_2] = hld;
           hld.clear(); //removes contents of temp storage vector for next use

           LB.push_back(k_2); //adds key to loser list (female)

        }
    }




        //AFFAIR PROCESS


        //Remove Winners of the opposite gender from the oposing preference table



        //VD: Affair Process
        auto k_A = LA.begin();
        auto k_B = LB.begin();

        std::list<int> LA_updt;
        std::list<int> LB_updt;


        int A;
        int B; //stores iterated value in vector as int






        while(k_A != LA.end() || k_B != LB.end())
        {

            if(k_A != LA.end())
            {

                A = *k_A;
                hld = A_prefs[A];


                A_prefs[A] = pref_subtract(hld,WB);

                if(A_prefs[A].empty())
                {
                    A_prefs.erase(A);


                }
                else
                {
                    LA_updt.push_back(A);
                }




                hld.clear();

                ++k_A;

            }



            if(k_B != LB.end())
            {
                B = *k_B;

                hld = B_prefs[B];
                B_prefs[B] = pref_subtract(hld,WA);

                if(B_prefs[B].empty())
                {
                    B_prefs.erase(B);

                }
                else
                {
                    LB_updt.push_back(B);
                }


                hld.clear();

                ++k_B;

            }


        }


    //Final Comparison: Identifies potential affairs from those remaining
    for(int& i : LA_updt)
    {
       for(int& j : LB_updt)
       {

           hld = A_prefs[i];
           hld_1 = B_prefs[j];

           if(in(j,hld) & in(i,hld_1))
           {
               stb=0;

           }
           hld.clear();
           hld_1.clear();
       }
    }


    if( rout == true)
    {
        if (stb)
        {
            std::cout << "Current Matching is Stable" << std::endl;
        }
        else if (!stb)
        {
            std::cout << "Current Matching is Un-Stable" << std::endl;
        }
    }



    return stb;
}



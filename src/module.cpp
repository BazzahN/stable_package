
#include "Rcpp.h"
using namespace Rcpp;

#include "fun_algo.h"

#include <vector>
#include <map>
#include <iostream>


std::list<std::vector<int>> stable_matcher_stble(Rcpp::NumericVector cv, Rcpp::NumericVector A, Rcpp::NumericVector B, bool rout = false)
{
    std::map<int, std::vector<int>> A_prefs;
    std::map<int, std::vector<int>> B_prefs;	

    int j {0};
  
    R_xlen_t n = cv.size();
  
    std::vector<int> hld_1;
    std::vector<int> hld_2;
  
    for (R_xlen_t i = 1; i < A.size() +1; i++) //Iterates starting at 1 instead of 0 so that the if modulo conditional can break up the vector accordingly
    {
  
    	hld_1.push_back(A[i-1]);
	hld_2.push_back(B[i-1]);
    
   	if(i % n  == 0)
    	{
    	  A_prefs.insert(std::make_pair(j+1, hld_1));
	  B_prefs.insert(std::make_pair(cv[j], hld_2));
      	  j++;
          hld_1.clear();
	  hld_2.clear();
    
    	}
    
   }

   std::list<std::vector<int>> sol = fun_algo(A_prefs,B_prefs,rout);


	
  return sol;
  
}

std::list<std::vector<int>> stable_matcher_intgr(const int& n, const Rcpp::NumericVector& A, const Rcpp::NumericVector& B)
{
    std::map<int, std::vector<int>> A_prefs;
    std::map<int, std::vector<int>> B_prefs;
  
    std::vector<int> hld_1;
    std::vector<int> hld_2;
    int j {1}; 
    int k {1};		
 
    for (R_xlen_t i = 1; i < A.size() +1; i++) 
    {
  
    	hld_1.push_back(A[i-1]);
	hld_2.push_back(B[i-1]);
    
   	if(k % n  == 0)
    	{
    	  A_prefs.insert(std::make_pair(j, hld_1));
	  B_prefs.insert(std::make_pair(j, hld_2));
      	  j++;
          hld_1.clear();
	  hld_2.clear();
    
    	}
	
	k++;
    
   }

   std::list<std::vector<int>> sol = fun_algo(A_prefs,B_prefs,false);

   Rcout <<"Stable Match Found! \n" << std::endl;

   Rcout << "Identified Pairings:" << std::endl;
   Rcout << "  A    |" << " " << " B  " << std::endl;

        for(auto i : sol)
        {

            Rcout << "  " << i[0] << "    |   "  << i[1] << std::endl;
            Rcout << "-------|-------" << std::endl;
        }
        

	
  return sol;
  
}


RCPP_MODULE(stablepack) 
{
function("rcpp_stable_matcher", &stable_matcher_stble);
function("rcpp_stable_int", &stable_matcher_intgr);
}

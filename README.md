# Details
```
Package: stablepackage
Type: Package
Title: Stable Marriage, fundamental algorithm, written in C++, interfaced with R.
Version: 1.0
Date: 2024-03-29
Author: Harry Newton
Maintainer: Harry Newton <h.newton3@lancaster.ac.uk>
Description: Contains an implementation of the 'fundamental algorithm'[1]; used to obtain a solution of stable matches based upon
                the preferences of two sets A and B of identical length.
                [1] Knuth, Donald Ervin. (1996). Stable Marriage and Its Relation to Other Combinatorial Problems: An Introduction to the Mathematical                           Analysis of Algorithms.”, 9-12.
License: GPL (>= 2)
Imports: Rcpp (>= 1.0.12)
LinkingTo: Rcpp
```
## Package Contents (User)
```
#R
Function(s):

stable_marriage(prefsA, prefsB, mix = F, output=T)
##Description:
  #stable_marriage takes two preference tables for each set A and B of length n
  #and outputs a list of stable matches. mix =T rearranges preference tables for B.
  #output = F turns off output.
  
  
  #Input: PrefsA, prefsB : "numeric": "list"/"vector"
  #       mix, output: "boolean"
  
  
  #Output: "list" of "vector" paris
Enviroment:

prefs_Av
prefs_Bv # <- Trial "vector" preference tables

prefs_Al 
prefs_Bl # <- Trial "list" preference tables

```
```
//C++ Function

rcpp_stablem_vec(names,prefs_A,prefs_B)

//Description:
  //rcpp_stablem_vec takes two preference tables for each set A and B of length n. If prefsB has been perturbed 
  //names includes the shuffled identifiers for B. This function allows for R input to be used by my C++ implementation of the fundamental algorithm.

  //Input: PrefsA, prefsB : "numeric": "list"/"vector" :R atomic types
  
  //Output: "list" of "vector" pairs (std::list<vector<int>> in C++)
```


## Installing & Running

**stablepackage** can be installed using one of two methods, either a local installation or via **git-hub**, here I will provide a brief tutorial on both methods. Both methods require the package [devtools](https://cran.r-project.org/web/packages/devtools/index.html)-available on CRAN. One can install **devtools** in **RStudio** using the command `install.packages('devtools')`

### Method 1: Git-Hub

Once **devtools** is fully installed **stable_package** can be obtained from this repository, and then included in the workspace using the code below:

```
install_github("BazzahN/stablepackage",force=TRUE)
library(stablepackage)
```
### Method 2: Local Installation
In addition to **devtools** you must also download the package from this repository and store it in the same drive as where-ever **R** was installed, in most cases this will be your C drive (C:) e.g. (C:\Users\user(you!)\Documents\Rstuff). 
Now **stablepackage** can be installed locally using the code below:

```
devtools::install('C:\\Users\\user(you!)\\Documents\\Rstuff')
library(stablepackage)
```
**Note:** The double backslahes `\\` have been included to prevent **R** from confusing the input and producing errors such as the one below:
```
Error: '\M' is an unrecognized escape in character string (<input>:1:22)
```

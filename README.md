# Details
```
Package: stablepackage
Type: Package
Title: What the Package Does in One 'Title Case' Line
Version: 1.0
Date: 2024-02-29
Author: Harry Newton
Maintainer: Harry Newton <h.newton3@lancaster.ac.uk>
Description: One paragraph description of what the package does as one
        or more full sentences.
License: GPL (>= 2)
Imports: Rcpp (>= 1.0.12)
LinkingTo: Rcpp
```
## Functions
```

rcpp_stable_matcher(names,prefs_A,prefs_B)

```

## Installing & Running

**stable_package** can be installed using one of two methods, either a local installation or via **git-hub**, here I will provide a brief tutorial on both methods. Both methods require the package [devtools](https://cran.r-project.org/web/packages/devtools/index.html)-available on CRAN. One can install **devtools** in **RStudio** using the command `install.packages('devtools')`

### Method 1: Git-Hub

Once **devtools** is fully installed **stable_package** can be obtained from this repository, and then included in the workspace using the code below:

```
install_github("BazzahN/stable_package",force=TRUE)
library(stablepackage)
```
### Method 2: Local Installation
In addition to **devtools** you must also download the package from this repository and store it in the same drive as where-ever **R** was installed, in most cases this will be your C drive (C:) e.g. (C:\Users\user(you!)\Documents\Rstuff). 
Now **stable_package** can be installed locally using the code below:

```
devtools::install('C:\\Users\\user(you!)\\Documents\\Rstuff')
library(stablepackage)
```
**Note:** The double backslahes `\\` have been included to prevent **R** from confusing the input and producing errors such as the one below:
```
Error: '\M' is an unrecognized escape in character string (<input>:1:22)
```

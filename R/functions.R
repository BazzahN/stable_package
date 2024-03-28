stable_marriage <- function(prefsA, prefsB, mix = F, output=T){
  ##Description:
  #stable_marriage takes two preference tables for each set A and B of length n
  #and outputs a list of stable matches. mix =T rearranges preference tables for B.
  #output = F turns off output.
  
  
  #Input: PrefsA, prefsB : "numeric": "list"/"vector"
  #       mix, output: "boolean"
  
  
  #Output: "list" of "vector" paris
  
  
  ###Utility Function
  
  mixer <- function(names_B, fnd){
    #Takes the names for set B and shuffles them if fnd is true.
    #names_B: 'numeric': 'list' / 'vector'
    nom_fon <- names_B
    
    if(fnd == T)
    {
      while(all(nom_fon == names_B))
      {
        nom_fon <- sample(names_B)
        
      }
      
    }
    
    return(nom_fon)
  }
  
  
  ###Input Check Error Code
  
  A_chk <- class(prefsA)
  B_chk <- class(prefsB)
  
  
  if(A_chk != B_chk) #Produces error if preference tables are of different types
  {
    
    stop("Preference Tables are not of the same type")
    
    
  }
  else
  {
    
    if(A_chk == "list")
    {
      
      prefsA <- unlist(prefsA) #Transforms list into a vector for easy input in rcpp_stablem_vec
      prefsB <- unlist(prefsB) #Note-Not proud of this one. 
      
      A_chk <- class(prefsA)
      B_chk <- class(prefsB)
      
    }
    
    
    if(!(A_chk == "numeric" & B_chk =="numeric")) #Rejects non numeric preference tables
    {
      stop("Preference Tables are not of the correct type please input a 'numeric': 'vector'  'list' ")
      
    }
    
    Amax <- max(prefsA)
    Bmax <- max(prefsB)
    len_A <- length(prefsA)
    len_B <- length(prefsB)
    if(!(len_A == len_B) | !(len_A == Amax^2) | !(len_B == Bmax^2)) #ensures preference tables are of the same length
      #additionally checks if they are of length n^2
    {
      
      stop("A and/or B preference table(s) are of incorrect length")
      
    }
    
    
  }
  
  
  
  names<- mixer(c(seq(1,max(prefsB),by=1)),mix) #perturbs preference tables for B as fundamental algorithm
  # 'favors' (gives individuals their most preferred) if they
  #are first in the list. 
  
  return(rcpp_stablem_vec(names,prefsA,prefsB,output))
}



# --------------------------------------------------------------
###Test Inputs

##Vector

prefs_Av_1 <- c(1,2,4,3,
             3,1,4,2,
             3,2,4,1,
             2,1,3,4)

prefs_Bv_1 <- c(3,2,4,1,
             2,1,3,4,
             2,4,1,3,
             3,1,4,2)

#or

prefs_Av_2 <- c(c(1,2,4,3),
                c(3,1,4,2),
                c(3,2,4,1),
                c(2,1,3,4))

prefs_Bv_2 <- c(c(3,2,4,1),
                c(2,1,3,4),
                c(2,4,1,3),
                c(3,1,4,2))


##List

prefs_Al <- list(c(1,2,4,3),c(3,1,4,2),c(3,2,4,1),c(2,1,3,4))
prefs_Bl <- list(c(3,2,4,1),c(2,1,3,4),c(2,4,1,3),c(3,1,4,2))



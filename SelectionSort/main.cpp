#include <iostream>
#include <chrono>
#include <cctype>
#include <random>

void selectionSort(int d [] , int n){
  for(int k=n-1;k>0;k--){
    int maxI = 1;
    
    for(int i=0;i<=k;i++){
        if(d[i]>d[maxI])
            maxI = i;
        }
    
        int tmp = d[k];
        d[k] = d[maxI];
        d[maxI] = tmp;
    }
}

int main(int argc,char** argv){
  
  const int iter = 100;
  
  //set up our random number generator
  std::random_device os_seed;
  const uint_least32_t seed = os_seed();
  std::mt19937 generator( seed );
  std::uniform_int_distribution< uint_least32_t > distribute( 1, 20000 );

  //set up timing measurement
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::chrono::time_point<std::chrono::high_resolution_clock> end;

  //measure the running time for each problem size n  
  for(int n=0 ; n<=20000 ; n+=1000){
    
    int * d = new int[n];
    
    long duration = 0;
    
    //repeat iter times for each problem size n
    for(int k=0;k<iter;k++){
      
      //initialize the array randomly
      for(int i=0;i<n;i++) 
      {
          d[i] = distribute(generator);
      }
      
      start = std::chrono::high_resolution_clock::now();
      
      selectionSort(d,n);
      
      end = std::chrono::high_resolution_clock::now();
      
      duration += std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    }
    
    //compute the average running time for the problem size
    std::cout << "Sorting\t" << n  << "\telements" << "\ttook\t" << (double)(duration/iter) << "\tmicroseconds." << std::endl;
    
    delete [] d;
  }
    
  return 0;
}

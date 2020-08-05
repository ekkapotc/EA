#include <iostream>
#include <chrono>

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
  
  int iter = 100;
  
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::chrono::time_point<std::chrono::high_resolution_clock> end;

  
  for(int n=0;n<=20000;n+=1000){
    
    int * d = new int[n];
    
    long duration = 0;
    
    for(int k=0;k<iter;k++){
        
      for(int i=0;i<n;i++) { d[i] = i; }
      
      start = std::chrono::high_resolution_clock::now();
      
      selectionSort(d,n);
      
      end = std::chrono::high_resolution_clock::now();
      
      duration += std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    }
    
    std::cout << n << "\t" << "took\t" << (double)(duration/iter) << "\tmicroseconds." << std::endl;
    
    delete [] d;
  }
    
  return 0;
}

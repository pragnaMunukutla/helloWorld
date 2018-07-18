#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    
    long long int n;
    
    scanf("%lld",&n);
    
    bool* array= (bool*)calloc(n+1,sizeof(bool));
    
    array[0]=false;
    array[1]=false;
    
    for(long long int i=2;i<=n;i++)
        array[i]=true;
        
    for(long long int i=2;i*i<=n;i++){
        if(array[i]==true){
            for(long long int j=i*2;j<=n;j+=i)
                array[j]=false;
        }
    }
    
    long long int* cumArray = (long long int*)calloc(n,sizeof(long long int));
    long long int j=4,i=1,count=1;
    cumArray[0]=5;
    
    while(j<=n){
        if(array[j]==true){
            cumArray[i]=cumArray[i-1]+j;
            if(array[cumArray[i-1]+j]==true)
                count++;
            i++;
        }
        j++;
    }
    
    printf("%lld ",count);
    return 0;

}

#include <iostream>
using namespace std;
void coinChange(int amount){
    int coins[]={100, 25, 10, 5, 1};
    int count[5]={0};
    for(int i=0; i<5; i++){
        while(amount>=coins[i]){
            amount-=coins[i];
            count[i]++;
        }
    }
    cout<<"Coin change solution:"<<endl;
    cout<<"Dollars:"<<count[0]<<endl;
    cout<<"Quarters:"<<count[1]<<endl;
    cout<<"Dimes:"<<count[2]<<endl;
    cout<<"Nickels:"<<count[3]<<endl;
    cout<<"Pennies:"<<count[4]<<endl;
}
struct Item{
    int weight;
    int value;
};
double fractionalKnapsack(int W, Item items[], int n){
    for (int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            double r1=(double)items[j].value/items[j].weight;
            double r2=(double)items[j+1].value/items[j+1].weight;
            if(r1<r2){
                Item temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }
    double maxValue=0.0;
    int currentWeight=0;
    
    for(int i=0; i<n; i++){
        if(currentWeight+items[i].weight<=W){
            currentWeight+=items[i].weight;
            maxValue+=items[i].value;
        } 
        else{
            int remainingWeight=W-currentWeight;
            maxValue+=items[i].value*((double)remainingWeight/items[i].weight);
            break;
        }
    }
    return maxValue;
}
int main(){
    int amount=289;
    coinChange(amount);
    Item items[]={{4,12}, {2,1}, {2,2}, {1,1}, {10,4}};
    int n=sizeof(items)/sizeof(items[0]);
    int capacity=11;
    double maxProfit=fractionalKnapsack(capacity, items, n);
    cout<<"Maximum profit for fractional knapsack:"<<maxProfit<<endl;
    return 0;
}

#include<iostream>
#include<fstream>
using namespace std;
int S[100];
int n;
int big;

int read_data()
{
fstream f;
f.open("input.dat",ios::in);
f>>n;
}
int factorial()
{for(int i=0;i<=n;i++){S[i]=n-i+1;}}
int init_data()
{
for(int i=1;i<=n;i++) S[i]=n-i+1;
}

int search_index()
{
int carrier=n;
while ( (carrier>=1) && (S[carrier]<S[carrier-1]) ) carrier--;
return carrier;
big=carrier;
}

int search_big(){
int carrier=n;
while ((carrier>=1) && (S[carrier]<=S[carrier-1]))carrier--;
if(big>S[carrier-1]){
    return big;
}
else big++;
}

int sort_data(int some_data[],int from_start,int to_final)
{
int done=0;
while (done==0)
    {
      done=1;
      for(int i=from_start;i<=to_final-1;i++)
        {
           if (some_data[i]>some_data[i+1])
            {
              swap(some_data[i],some_data[i+1]);
              done=0;
            }
        }
       to_final=to_final--;
    }
}

int data_order(){
int gata=0;
while(gata==0){
    gata=1;
    for(int i=2;i<=n;i++){
        if(S[i-1]>S[i]){
            swap(S[i-1],S[i]);
            gata=0;
        }
    }
}
}

int print_data()
{
for(int i=1;i<=n;i++)
    {
     cout<<S[i]<<" ";
    }
}




int main()
{
read_data();
init_data();
print_data();
cout<<endl;
search_index();
search_big();
sort_data(S,1,n);
data_order();
print_data();
}

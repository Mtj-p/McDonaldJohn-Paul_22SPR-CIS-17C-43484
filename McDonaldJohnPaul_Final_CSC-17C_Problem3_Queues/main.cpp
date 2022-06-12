/*
 * file: McDonaldJohnPaul_Final_CSC-17C_Problem3_Queues
 * Author: John-Paul McDonald
 * Date: 06/12/2022
 * Purpose: 
 * Let us say you are in a line at the grocery store or bank like I was last weekend. One
 * line, yet there are 3 clerks/tellers which service the same line. Simulate the following,
 * Clerk 1 - Services customers on the average 1/min
 * Clerk 2 - Services customers on the average 0.5/min
 * Clerk 3 - Services customers on the average 0.75/min
 * Customers - Arrive at 4/minute intervals. When the line gets to 5 customers add one
 * more Clerk with the same service rate as Clerk 1. Add one more clerk similarly for each
 * 5 customers. Take tellers away when they have serviced the line according to how they
 * were added. For instance, if a 4th clerk was added to the line because there were 5
 * customers waiting then remove the clerk when the customer count in line goes to zero.
 * What is my average customer wait time? What is the max number of customers in the
 * line? If you randomize servicing and arrival times by +-50how does this change the
 * results?
 */

//System Libraries
#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
    //srand(time(0));
    int arriving = 4; //(at a time every 60 seconds
    int servicenum = 1;
    int current=0;
    vector<int> servicetime (20000);
    int clerk1=0;
    bool clerk1busy = false;
    int clerk2=0;
    bool clerk2busy = false;
    int clerk3=0;
    bool clerk3busy = false;
    queue<int> customers;
    int temp1=0;
    bool temp1busy = false;
    bool temp1active = false;
    int temp2=0;
    bool temp2busy = false;
    bool temp2active = false;
    int temp3=0;
    bool temp3busy=false;
    bool temp3active=false;
    int temp4=0;
    bool temp4busy=false;
    bool temp4active=false;
    int temp5=0;
    bool temp5busy=false;
    bool temp5active=false;
    
    int maxcustomers=0;
    for(int i=0;i<=28800;i++){//8hours
        if(customers.size()>maxcustomers){
            maxcustomers=customers.size();
        }
        if(clerk1==0){
            clerk1busy=false;
        }
        if(clerk2==0){
            clerk2busy=false;
        }
        if(clerk3==0){
            clerk3busy=false;
        }
        if(temp1==0){
            temp1busy=false;
        }
        if(temp2==0){
            temp2busy=false;
        } 
        if(temp3==0){
            temp3busy=false;
        } 
        if(temp4==0){
            temp4busy=false;
        } 
        if(temp5==0){
            temp5busy=false;
        } 
        if(i%(60+rand()%50)==0){
            for(int k=0;k<arriving;k++){
                customers.push(servicenum);
                servicenum++;
                servicetime[servicenum]=i;
            }
        }
        if(customers.size()>0){
            if(customers.size()>5){
                temp1active=true;
            }
            if(customers.size()==0){
                temp1active=false;
            }
            if(customers.size()>10){
                temp2active=true;
            }
            if(customers.size()==5){
                temp2active=false;
            }
            if(customers.size()>15){
                temp3active=true;
            }
            if(customers.size()==10){
                temp3active=false;
            }
            if(customers.size()>20){
                temp4active=true;
            }
            if(customers.size()==15){
                temp4active=false;
            }
            if(customers.size()>25){
                temp5active=true;
            }
            if(customers.size()==20){
                temp5active=false;
            }
            if(clerk1busy==false&&customers.size()>0){
                clerk1busy=true;
                clerk1=(60+rand()%30);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
            if(clerk2busy==false&&customers.size()>0){
                clerk2busy=true;
                clerk2=(120+rand()%60);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
      
            }
            if(clerk3busy==false&&customers.size()>0){
                clerk3busy=true;
                clerk3=(80+rand()%40);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
            if(temp1busy==false&&temp1active==true){
                temp1busy=true;
                temp1=(60+rand()%30);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
            if(temp2busy==false&&temp2active==true){
                temp2busy=true;
                temp2=(60+rand()%30);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
            if(temp3busy==false&&temp3active==true){
                temp3busy=true;
                temp3=(60+rand()%30);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
            if(temp4busy==false&&temp4active==true){
                temp4active=true;
                temp4=(60+rand()%30);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
            if(temp5busy==false&&temp5active==true){
                temp5busy=true;
                temp5=(60+rand()%30);
                current = customers.front();
                customers.pop();
                servicetime[current]=(i-servicetime[current]);
            }
        }
        if(clerk1>0){
            clerk1--;
        }
        if(clerk2>0){
            clerk2--;
        }
        if(clerk3>0){
            clerk3--;
        }
        if(temp1>0){
            temp1--;
        }
        if(temp2>0){
            temp2--;
        }
        if(temp3>0){
            temp3--;
        }
        if(temp4>0){
            temp4--;
        }
        if(temp5>0){
            temp5--;
        }
        
    }
    cout<<"Maximum # of customers in line at one time = "<<maxcustomers<<endl;
    int avgwaittime=0;
    int waitingcus=0;
    for(int z=0;z<20000;z++){
        if(servicetime[z]!=0){
            avgwaittime+=servicetime[z];
            waitingcus++;
        }
    }
    cout<<"The average wait-time was "<<avgwaittime/waitingcus<<" seconds"<<endl;
    
    return 0;
}

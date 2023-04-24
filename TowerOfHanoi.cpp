// // Question from Pepcoding (YT link for video sol: https://www.youtube.com/watch?v=uwrc4H3yaJ4&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=11)
// 1. There are 3 towers. Tower 1 has n disks, where n is a positive number. Tower 2 and 3 are empty.
// 2. The disks are increasingly placed in terms of size such that the smallest disk is on top and largest disk is at bottom.
// 3. You are required to 
//     3.1. Print the instructions to move the disks.
//     3.2. from tower 1 to tower 2 using tower 3 
//     3.3. following the rules
//         3.3.1 move 1 disk at a time.
//         3.3.2 never place a smaller disk under a larger disk.
//         3.3.3 you can only move a disk at the top.

// // Output Format
// n[n1 -> n2] 
// ..
// A set of instructions in above format to represent, move nth disc from n1 tower to n2 tower


#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id, int &countofsteps){

    if(n==0) return;

    toh(n-1, t1id, t3id, t2id, countofsteps); // putting n-1 disks on t1 above nth disk to t3 
    cout<<n<<"["<<t1id<<" -> "<<t2id<<"]"<<endl; //putting nth disk from t1 to t2
    countofsteps++; 
    toh(n-1, t3id, t2id, t1id, countofsteps); //putting n-1 disks from t3 to t2 

    // and after all above steps we put all disks from t1 to t2

}

int main(){
    int n = 5;
    int t1id = 10;
    int t2id = 20;
    int t3id = 30;
    int countofsteps = 0;
    toh(n, t1id, t2id, t3id, countofsteps);    
    cout<<"No. of steps to complete the tower of hanoi problem for "<<n<<" disks is "<<countofsteps;
    // minimum number of steps to complete a tower of hanoi problem is (2^n)-1, where n is the number of disks
}

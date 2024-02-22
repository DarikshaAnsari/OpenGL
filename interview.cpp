// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.
// 1->2->3->4
// 4->5->6->7


// 1 2 3 4 
// 1 3 5

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for (int i = a; i < b; i++)

class linkedlist{
    public:
    int data;
    linkedlist* node;
};
linkedlist* solve(linkedlist* head1,linkedlist* head2){
// 1 2 3 4 
// 1 3 5

    linkedlist* temp2=head2;
    unordered_map<int,int> mp;
    while(temp2!=NULL){           
        mp[temp2->data]=1;
        temp2=temp2->node;
    } 
    // unordered_map
    // 1->1
    // 3->1
    // 5->1

     //1 2 3 4
    // temp1=1;
    // temp

    // temp=1
    // temp1=2
    // 1 2 3 4 
    // 1 3 5

    // 2 5
    // 1 3 4
     linkedlist* curr=head1;
     linkedlist* prev;
     while(curr!=NULL){
        if(curr==head1 && mp.find(curr->data)==mp.end()){
           head1=head1->node;
           curr=head1;
        }
        else if(mp.find(curr->data)==mp.end()){
            prev->node=curr->node;
            curr=curr->node;
        }else{
            prev=curr;
            curr=curr->node;
        }
     }
     return head1;
}


int main(){
   linkedlist* head1;
   linkedlist* head2;

   return 0;
}


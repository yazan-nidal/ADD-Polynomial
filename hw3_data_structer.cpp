#include<iostream>
using namespace std;
struct node{//node
int power;
int factor;
node *next;
};//end node
struct linglist{//ling
	node *first;
	node *last;
};//end ling

void cleaR(linglist &L){L.first=NULL;
	L.last=NULL;}//clear ling; true

bool emptY(const linglist &L){//empty test
	if((L.first==NULL)&&(L.last==NULL)){return true;}
else{return false;}
}//test detirm empty ling true

void insertF(linglist &L,int *R){//inset first
	node *m=new node;
	m->factor=R[0];
	m->power=R[1];
	m->next=NULL;
	if(emptY(L)){L.first=m;
	L.last=m;}
	else{m->next=L.first;
	L.first=m;}
}//end insert first trs

void insertL(linglist &L,int *R){//inset last
	node *m=new node;
	m->factor=R[0];
	m->power=R[1];
	m->next=NULL;
	if(emptY(L)){L.first=m;
	L.last=m;}
	else{L.last->next=m;
	L.last=m;}
}//end insert last trs

int* deleteF(linglist &L){
	if(!emptY(L)){node *m=L.first; // delete F
	L.first=L.first->next;
int *R=new int[2];
R[0]=m->factor;
R[1]=m->power;
m->next=NULL;
if(m==L.last){cleaR(L);}
delete m;
return R;}
	else{cout<<"	ERROR Delete empty Ling list \n";}
}//end delete F trs

int* deleteL(linglist &L){ // delete L
if(!emptY(L)){node *m=L.last;
	node *o=L.first;
	if(m==L.first){cleaR(L);}
while(o->next != m){o=o->next;}
o->next=L.last->next;
L.last=o;
int *R=new int[2];
R[0]=m->factor;
R[1]=m->power;
m->next=NULL;
delete m;
return R;}
else{cout<<"	ERROR Delete empty Ling list \n";}}//end delete L trs

bool operand(char m){if((m>='0')&&(m<='9')){return true;}else{return false;}}// test if the input number

int reaD(linglist &L){//read matrix
cout<<"	Enter Polynomial  end in input ' . '\n ";
cleaR(L);
int pol[2];
int rt=1;
while(true){
char m[100]=" ";
cout<<"\n	Enter limit "<<(rt++)<<" : \n";
pol[0]=0;
pol[1]=0;
cout<<"	Enter Factor X : ";
cin>>m;
if(m[0]=='.'){return 0;}
int k=1;
int i=0;
if(m[i]=='-'){k=-1; i++;}
if(operand(m[i])==1){
while(operand(m[i])==1 && m[i]!=NULL && m[i]!='.'){
pol[0]=pol[0]*10+(m[i++]-'0');}
pol[0]*=k;
}
if(m[i]=='.'){pol[1]=0;
insertL(L,pol);
return 0;}
//
cout<<"	Enter Power X : ";
cin>>m;
k=1;
i=0;
if(m[i]=='.'){pol[1]=0;
insertL(L,pol);
return 0;}
if(m[i]=='-'){k=-1; i++;}
if(operand(m[i])==1){
while(operand(m[i])==1 && m[i]!=NULL && m[i]!='.'){
pol[1]=pol[1]*10+(m[i++]-'0');}
pol[1]*=k;
}
insertL(L,pol);
if(m[i]=='.'){
	 return 0; }
}
}//end read

void prinT(const linglist &L){
if(!emptY(L)){cout<<"	The Polynomial : \n";
cout<<"	";
node *m=L.first;
int yl=0;
while(m!=NULL){if(yl==0){
	if((m->factor)>0){cout<<m->factor;
	switch(m->power){
case 1:{cout<<"X "; break;}
case 0:{cout<<" "; break;}
default :{cout<<"X^"<<m->power<<" ";}
	}}
else{if((m->factor)<0){cout<<" - "<<(m->factor)*(-1);
if((m->power)==1){cout<<"X "; }
else{if((m->power)==0){cout<<" "; }
else{cout<<"X^"<<m->power<<" ";}}

}
else{if((m->factor)==0){cout<<"0";}}}
yl++;
}else{
if((m->factor)>0){cout<<" + "<<m->factor;if((m->power)==1){cout<<"X "; }
else{if((m->power)==0){cout<<" "; }
else{cout<<"X^"<<m->power<<" ";}}
}
else{if((m->factor)<0){cout<<" - "<<(m->factor)*(-1);
if((m->power)==1){cout<<"X "; }
else{if((m->power)==0){cout<<" "; }
else{cout<<"X^"<<m->power<<" ";}}
}
else{if((m->factor)==0){cout<<" + 0";}}}}
m=m->next;

}}
	else{cout<<" Error not input Polynomial \n";}
}

linglist addPOLY(const linglist &L,const linglist L2){//add
linglist L3;
cleaR(L3);
node* M1=L.first;
node *M2=NULL;
while(M1!=NULL){
	M2=L3.first;
	while((M2!=NULL)&&((M1->power)!=(M2->power))){M2=M2->next;}
	if(M2==NULL){int R[2];
	R[0]=M1->factor;
	R[1]=M1->power;
	insertL(L3,R);}
	else{if((M1->power)==(M2->power)){(M2->factor)+=(M1->factor);}}
	M1=M1->next;
}
M1=L2.first;
M2=NULL;
while(M1!=NULL){
	M2=L3.first;
	while((M2!=NULL)&&((M1->power)!=(M2->power))){M2=M2->next;}
	if(M2==NULL){int R[2];
	R[0]=M1->factor;
	R[1]=M1->power;
	insertL(L3,R);}
	else{if((M1->power)==(M2->power)){(M2->factor)+=(M1->factor);}}
	M1=M1->next;
}
if(emptY(L3))
{cout<<"	Error the Tow Polynomial has an empty \n";}
return L3;
}//add

void sortedPOLY(linglist &L){//sorted
	linglist H;
	cleaR(H);
	int *R=NULL;
	linglist KL=L;//to point in old memory lockated py L pefor changet after aggregate the boundary and deleted after
	L=addPOLY(L,H);//to aggregate the boundary in the Polynomial 
	while(!emptY(KL)){deleteF(KL);}
	cleaR(KL);
	while(!emptY(L)){
		R=deleteF(L);
		if(emptY(H)){insertF(H,R);
		delete R;
		R=NULL;}
		else{
			if(R[1]>(H.first->power)){insertF(H,R);
			delete R;
			R=NULL;}
		else{
			if(R[1]<(H.last->power)){insertL(H,R);
			delete R;
			R=NULL;}
			else{node *m=H.first;
			node *l=NULL;
			while(((m->power)>R[1])){l=m; m=m->next;}
			node *t=new node;
			t->factor=R[0];
			t->power=R[1];
			t->next=l->next;
			l->next=t;
			delete R;
			R=NULL;
			}}}}
	L.first=H.first;
	L.last=H.last;
	H.first=NULL;
	H.last=NULL;
}//end sorted

void main(){//main
linglist L;
cleaR(L);
cout<<"	 Enter The First Polynomial ---> \n";
reaD(L);
linglist A;
cleaR(A);
cout<<"\n\n	 Enter The sacand Polynomial ---> \n";
reaD(A);
system("cls");
linglist C=addPOLY(L,A);
cout<<"\n	the first polynomial befor sorted  and aggregate the boundary \n";
prinT(L);
cout<<"\n\n	the sacand polynomial befor sorted  and aggregate the boundary \n";
prinT(A);
cout<<"\n\n	-------------------------------------------\n";
cout<<"\n	the first polynomial after sorted  and aggregate the boundary \n";
sortedPOLY(L);
prinT(L);
cout<<"\n\n	the sacand polynomial after sorted  and aggregate the boundary \n";
sortedPOLY(A);
prinT(A);
cout<<"\n\n	-------------------------------------------\n\n";
cout<<"\n\n	The ADD Polynomial befor sorted :\n";
prinT(C);
cout<<"\n";
cout<<"\n\n	The ADD Polynomial after sorted :\n";
sortedPOLY(C);
prinT(C);

cout<<"\n\n	~~~ End of PrOGrAM ~~~ \n";
}//end main
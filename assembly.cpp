#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


///////////////////////////////////////////////////////////////
/********************     TEST CASE 1       *****************/

//            Please Uncomment to check

//int a1[] = {3,2,5,4,1};
//int a2[] = {3,2,1,6,1};
//int a3[] = {7,8,1,2,3};
//
//int t12[] = {1,3,4,7};			//Transfer time from assembly line 1 to 2
//int t21[] = {7,6,1,2};			//Transfer time from assembly line 2 to 1
//int t31[] = {5,1,1,2};			//Transfer time from assembly line 3 to 1
//int t13[] = {2,7,2,4};			//Transfer time from assembly line 1 to 3
//int t23[] = {8,2,5,1};			//Transfer time from assembly line 2 to 3
//int t32[] = {1,2,1,2};			//Transfer time from assembly line 3 to 2
//
//int path[5] = {0};
//
//int e1 = 4;
//int e2 = 2;
//int e3 = 3;
//
//int x1 = 1;
//int x2 = 6;
//int x3 = 5;
//
//char line;
//
//int noStations =5;

/******************************************************************/
////////////////////////////////////////////////////////////////////











///////////////////////////////////////////////////////////////
/********************     TEST CASE 2       *****************/

int r[100];


int a1[1000];
int a2[1000];
int a3[1000];

int t12[999];			//Transfer time from assembly line 1 to 2
int t21[999];			//Transfer time from assembly line 2 to 1
int t31[999];			//Transfer time from assembly line 3 to 1
int t13[999];			//Transfer time from assembly line 1 to 3
int t23[999];			//Transfer time from assembly line 2 to 3
int t32[999];			//Transfer time from assembly line 3 to 2

int path[5] = {0};

int e1 = 4;
int e2 = 2;
int e3 = 3;

int x1 = 1;
int x2 = 6;
int x3 = 5;

char line;

int noStations =1000;

/******************************************************************/
////////////////////////////////////////////////////////////////////








void FASTEST_WAY_A(){

	int f1 = e1 + a1[0];			//assembly line 1 intial cost  // Unit test: 7
	//int f2 = e2 + a2[0];			//assembly line 2 intial cost  //Unit test: 5

	cout<<"Start:		Assembly Line 1:		Path cost: "<<f1<<endl;

	line = 'a';

	for(int j=1; j<noStations ; j++){

		if( line == 'a'){
			if( f1 + a1[j]  <= f1 + a2[j] + t12[j-1]){
				f1 = f1 + a1[j];
				cout<<"			Assembly Line 1:		Path cost: "<<f1<<endl;
				line = 'a';
			}
			else{
				f1 = f1 + a2[j] + t12[j-1];
				cout<<"Change Path:		Assembly Line 2:		Path cost: "<<f1<<endl;
				line = 'b';
			}
		}
		else{
			if( f1 + a1[j] + t21[j-1] <= f1 + a2[j] ){
				f1 = f1 + a1[j] + t21[j-1];
				line = 'a';
				cout<<"Change Path:		Assembly Line 1:		Path cost: "<<f1<<endl;
			}
			else{
				f1 = f1 + a2[j];
				line = 'b';
				cout<<"			Assembly Line 2:		Path cost: "<<f1<<endl;
			}
		}
	}

	if(line = 'a'){
		f1 = f1 + x1;
		cout<<"Exit:	Assembly Line 1(exit):		Path cost: "<<f1<<endl;
	}
	else{
		f1 = f1 + x2;
		cout<<"Exit:	Assembly Line 2(exit):		Path cost: "<<f1<<endl;
	}
}

void FASTEST_WAY_B(){

	int f1 = e1 + a1[0];			//assembly line 1 intial cost  // Unit test: 7
	int f2 = e2 + a2[0];			//assembly line 2 intial cost  //Unit test: 5

	line = 'b';

	for(int j=1; j<noStations ; j++){

		if( line == 'b'){
			if( f2 + a2[j]  <= f2+ a1[j] + t21[j-1]){			//when cost of path from assembly line 2 to its next node is less as compare to path from one assembly line to another
				f2 = f2 + a2[j];
				cout<<"			Assembly Line 2:		Path cost: "<<f2<<endl;
				line = 'b';
			}
			else{
				f2 = f2 + a1[j] + t21[j-1];						//Change assembly line if cost lower
				cout<<"Change Path:		Assembly Line 1:		Path cost: "<<f2<<endl;
				line = 'a';
			}
		}
		else{
			if( f2 + a1[j] + t12[j-1] <= f2 + a1[j] ){			
				f2 = f1 + a1[j] + t12[j-1];
				line = 'b';
				cout<<"Change Path:		Assembly Line 2:		Path cost: "<<f2<<endl;
			}
			else{
				f2 = f2 + a1[j];
				line = 'a';
				cout<<"			Assembly Line 1:		Path cost: "<<f2<<endl;
			}
		}
	}

	//ADD EXITING COST

	if(line = 'a'){
		f2 = f2 + x1;
		cout<<"Exit:		Assembly Line 1:		Path cost: "<<f2<<endl;
	}
	else{
		f2 = f2 + x2;
		cout<<"Exit;		Assembly Line 2:		Path cost: "<<f2<<endl;
	}
}

//void RECURSIVE_A() {
//	int f1 = e1 + a1[0];			//assembly line 1 intial cost  // Unit test: 7
//	//int f2 = e2 + a2[0];			//assembly line 2 intial cost  //Unit test: 5
//
//	cout<<"Start:		Assembly Line 1:		Path cost: "<<f1<<endl;
//
//	line = 'a';
//
//	RECURSIVE_A_CHECK(line,f1);
//}
//
//void RECURSIVE_A_CHECK(char line, int f1){
//
//		for(int j=1; j<noStations ; j++){
//
//			if( line == 'a'){
//				if( f1 + a1[j]  <= f1 + a2[j] + t12[j-1]){
//					f1 = f1 + a1[j];
//					cout<<"			Assembly Line 1:		Path cost: "<<f1<<endl;
//					line = 'a';
//				}
//				else{
//					f1 = f1 + a2[j] + t12[j-1];
//					cout<<"Change Path:		Assembly Line 2:		Path cost: "<<f1<<endl;
//					line = 'b';
//				}
//			}
//			else{
//				if( f1 + a1[j] + t21[j-1] <= f1 + a2[j] ){
//					f1 = f1 + a1[j] + t21[j-1];
//					line = 'a';
//					cout<<"Change Path:		Assembly Line 1:		Path cost: "<<f1<<endl;
//				}
//				else{
//					f1 = f1 + a2[j];
//					line = 'b';
//					cout<<"			Assembly Line 2:		Path cost: "<<f1<<endl;
//				}
//			}
//	}
//
//	if(line = 'a'){
//		f1 = f1 + x1;
//		cout<<"Exit:	Assembly Line 1(exit):		Path cost: "<<f1<<endl;
//	}
//	else{
//		f1 = f1 + x2;
//		cout<<"Exit:	Assembly Line 2(exit):		Path cost: "<<f1<<endl;
//	}
//
//}



int main(){

	///////////////////////////////////////////////////////
	/**********  FOR 1000 NODES IN ASSEMBLY LINE  ********/

	int totalCosta = 0, totalCostb = 0;

	for (int i = 0; i < 1000; ++i) {
		a1[i] = rand() % 15 + 1;
		totalCosta = totalCosta + a1[i];
	}
	for (int i = 0; i < 1000; ++i) {
		a2[i] = rand() % 12 + 1;
		totalCostb = totalCostb + a2[i];
	}
	for (int i = 0; i < 999; ++i) {
		t12[i] = rand() % 9 + 1;
	}
	for (int i = 0; i < 999; ++i) {
		t21[i] = rand() % 10 + 1;
	}



	/////////////////////////////////////////////////////////

	FASTEST_WAY_A();		//USER SELECTS ASSEMBLY LINE 1
	//FASTEST_WAY_B();		//USER SELECTS ASSEMBLY LINE 2

	cout<<"Cost of total line with no transition between two lines:"<<endl;
	cout<<"Assembly line A:	"<<totalCosta<<endl;
	cout<<"Assembly line B:	"<<totalCostb<<endl;

	int terminate;
	cin >> terminate;

}
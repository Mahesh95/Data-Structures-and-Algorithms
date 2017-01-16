#include <iostream>
using namespace std;

void selectMaxActivities(int *start, int *finish, int noOfActivites){
	int activitiesIncludedCount = 0;
	int *activities = new int[noOfActivites];
	activities[0] = 0;
	for(int i = 1; i < noOfActivites; i++){
		if(start[i] > activities[activitiesIncludedCount]){
			activities[++activitiesIncludedCount] = i;
		}
	}

	for(int i = 0; i < activitiesIncludedCount; i++){
		cout << activities[i] << endl;
	}
}

int main(){
	int start[] = {1,3,0,5,8,5};
	int finish[] = {2,4,6,7,9,9};

	selectMaxActivities(start,finish,6);
}
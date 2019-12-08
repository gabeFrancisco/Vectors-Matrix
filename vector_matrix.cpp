#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void Vector();
void Matrix();

//Function to set the return menu operation with an argument inside
int Return(int selecTask);

int main(){

	//Builind the menu for selecting the subject[vector ou matrix]

	menu:

	int a;
	cout << "\nSelect the subject:\nType 1 for vectors or 2 for matrices: ";
	cin >> a;

	if(a == 1){
		Vector();
	}
	else if(a == 2){
		Matrix();
	}
	else{
		cout << "\n\nType again\n";
		goto menu;
	}


	return 0;
}

void Vector(){

	//Setting a variable to store the number of item in the vector
	int num;
	cout << "\nWhat's the lenght of the vector? ";
	cin >> num;

	//Setting vectors and variables
	int vector[num], i;

	//Building a for loop to register values into each item of the vector
	for(i = 0; i < num; i++){
		cout << "\nSet a value for the vector[" << i << "]: ";
		cin >> vector[i];
	}

	//Printing the registered values for the vector's itens in the console
	for(i = 0; i < num; i++){
		cout << "\nValue of the vector[" << i << "] = " << vector[i];
	}

	char option;

	repSearch:

	cout << "\nDo you want to make a simple search on the vector?[Y to make or ANY KEY to skip]: ";
	cin >> option;

	if(option == 'Y' or option == 'y'){
        goto simpleSearch;
	}
	else{
        Return(1);
	}

	simpleSearch:

        char Ok;
        int foundValue, foundPosition;
        bool searchedValue;

        cout << "\nLet's do a simple search for the previous vector!\n";

        for(i = 0; i < num; i++){
		cout << "\nValue of the vector[" << i << "] = " << vector[i];
        }

        cout << "\n";

        cout << "\nType a number of the vector: ";
        cin >> foundValue;

        for(i = 0; i < num; i++){
            if(vector[i] == foundValue){
            	system("cls");
                searchedValue = true;
                cout << "\nThe value was found in the position " << i;
                goto repSearch;
            }
            system("cls");
            if(searchedValue == false){
                cout << "\nThe value was not found! Type again";
                goto simpleSearch;
			}
        }
}

void Matrix(){

	//Setting the size of the matrix with two variables
	int i, j, a, b;

	cout << "\nWhat's the 'i' term of the matrix?: ";
	cin >> a;

	cout << "\nWhat's the 'j' term of the matrix?: ";
	cin >> b;

	//Setting the matrices and variables for the setting and printing
	int matrix[a][b];

	//Getting the data for the matrix' terms
	for(i = 0; i < a; i++){
		for(j = 0; j < b; j++){
			cout << "\nEnter the [" << i+1 << "][" << j+1 << "] = ";
			scanf("%d", &matrix[i][j]);
		}
	}

	//Printing the data of the matrix
	for(i = 0; i < a; i++){
		for(j = 0; j < b; j++){
			cout << " " << matrix[i][j];
		}
		cout << "\n";
	}

	Return(2);

}

//========================================================================================
//This next block is a code section that asks you if you want to go back to the main menu,
//to repeat the actual task or simply exit the program.
//========================================================================================


int Return(int selecTask){

	//Variable that will store the menu option to return to menu, to the actual task or exit
	int menu;
	cout << "\nDo you want to return to the main menu[1], repeat the actual task[2] or exit[any key]\n";
	cin >> menu;
	if(menu == 1 ){
		system("cls");
		main();
	}
	else if(menu == 2 && selecTask == 1){
		system("cls");
		Vector();
	}
	else if(menu == 2 && selecTask == 2){
		system("cls");
		Matrix();
	}
	else{
		exit(0);
	}

}

#include<iostream>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

void Intro();
void gamePlay();
char play_again;

int main(){
	system("color 3E");
	Intro();
	do{
		system("cls");
		gamePlay();
		cout<<"Do you want to play Again? (Y/N):";
		cin>>play_again;
	}while(play_again!='n'&& play_again!='N');
}
void Intro()
{
	cout<<"\n\n\n\t\t\t\t\t--------------------------------------------------------------------------------  "<<endl;
	cout<<"\t\t\t\t\t__||__||____||__||____||__||____||__||____||__||____||__||____||__||____||__||__  "<<endl;
	cout<<"\n\t\t\t\t\t  <><><><><> ...     Welcome To Number Guessing Game           ... <><><><><> "<<endl;
	cout<<"\n\t\t\t\t\t  <><><><><> ...   Developed By Ahsan Ali (ID == CA/CP/11906) ... <><><><><> "<<endl;
	cout<<"\n\t\t\t\t\t  <><><><><> ...   CodeALPHA Internship Task (01)                ... <><><><><> "<<endl;
	cout<<"\t\t\t\t\t________________________________________________________________________________"<<endl;
	cout<<"\t\t\t\t\t________________________________________________________________________________"<<endl;
    cout<<"Press Any key!";
	getch();
}

void gamePlay(){
	srand(time(0));  //For changing the random numbers on every time after execution.
	int secret_number=rand()%10+1;		//This genereate the actual random numbers b/w 1 to 15.
	int guess;
	
	  cout<<"\n\n\t\t\t    <><><><><> ...<><><><><> ...<><><><><>... NUMBER GUESS GAME ...<><><><><> ...<><><><><> ...<><><><><> \n\n\n";
	  do{
	  	   cout<<"\t\t\t\tGuess any Number of your own choice b/w (1 and 15): ";
     	   cin>>guess;
     	if (guess<secret_number)
            cout<<"\t\t\t\t\t\t\t\t\tIt's Too Low as compare to secret number (Try again)!\n"<<endl;
        else if(guess>secret_number)
            cout<<"\t\t\t\t\t\t\t\t\tIt's Too High as compare to secret number (Try again)!\n"<<endl;
        else
            cout<<"\t\t\t\t\t\t\t\t\tCongratulations! You guessed the secret number."<<endl;
            
    } while (guess!=secret_number);
}



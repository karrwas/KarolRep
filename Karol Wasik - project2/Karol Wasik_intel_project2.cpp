/*
Project of Caesar Code's decryption I prepared during my studies of electronics and telecommunication
at Gdansk University of Technology.

It finds the most frequently appearing letter in encrypted polish sentence, then compares it with a letter "a" in ASCII table
as it is the most frequent letter in polish sentences. Finally based on that information, the program counts how many
positions the letters have been moved and moves them back to decrypt the message.

Karol Wasik
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
 
void correction(string &text)     //correcting chosen letter
{
	int i;
	char letter, dec = 'y', n;
	
	while(dec){
		cout << "\nType in a position index that needs to be corrected: ";
		cin >> i;
		
		if((i > text.length() + 1) || isdigit(text[i-1]) || ispunct(text[i-1]) || isspace(text[i-1]))		//correcting only letters
			cout << "\nChosen position doesn't exist or is not a letter'!\n";
		
		else{
			cout << "\nType in a new letter: ";
			cin >> letter;

			text[i-1] = letter;
			}
			
			cout << "\nIs there more to be corrected? y/n ";
			cin >> dec;
				
		
		if(dec == 'n') break;
	}	
	
}


void decryption(string &text, int x)
{	
	char d, dec, y, n;
	
	cout << "\nReplacement table: " << endl;
	
		for(int i = 0 ; i < text.length() ; i++){									
			if(ispunct(text[i]) || isspace(text[i]) || isdigit(text[i])) continue;
																					
			if(text[i] + x < 65)									//Avoiding program leaving the letter section in ASCII table
				d = text[i] + x + 26;								//Capital letters
			
			else if(text[i] + x < 97 && text[i] + x > 90)			//lower case letters
				d = text[i] + x + 26;
				
			else
				d = text[i] + x;									// "d" stands for Decrypted letter
			
			if(i < 9) 
				cout << " ";
						
				cout << i+1 << ". " << text[i] << " --> ";  printf("%c" , d ); 
				cout << endl; 
				
				text[i] = d;  
			}
			
	cout << "\nDo you wish to make changes?  y/n ";
	cin >> dec;
		
		if(dec == 'y') correction(text);
} 
 

void histogram(double count[], double sum)			//printing histogram using ASCII table
{
	char histo[11][27];
			
	for(int i = 0 ; i < 11 ; i++){
		for(int j = 0 ; j < 27 ; j++){
				
			if((count[j] * 100 / sum) >= (10-i) * 10 && i != 10) histo[i][j] = 177;		//printing columns
				else histo[i][j] = 196;														//printing background
				}
		}
	
	for(int j = 1 ; j < 27 ; j++)								//describing horizontal axis
		histo[10][j] = char(96+j);
		
	for(int i = 0 ; i < 11 ; i++){
		for(int j = 0 ; j < 27 ; j++){	
					
				if(j==0){
					if(10-i != 0)  cout << (10-i)*10 << "%";
					
					if(10-i == 10) cout << " ";					//leveling with vertical axis of histogram
									
					else if(10-i == 0) cout << "     ";
						
					else
						cout << "  ";	
				}
				
				else	
					cout << setw(2) << histo[i][j];	}	
					cout << endl;
	}
}


void counting(string text, int &x)
{
		transform(text.begin(), text.end(), text.begin(), ::tolower);	//converting given letters to lower case
		
        double count[26] = {};
        double sum = 0;
        
        for(int i = 0 ; i < text.length() ; i++){		//counting letters to create a histogram
        	if(text[i] == 'a') count[1]++;			
        	if(text[i] == 'b') count[2]++;				// "i" represents each letter's position in alphabet
        	if(text[i] == 'c') count[3]++;			
        	if(text[i] == 'd') count[4]++; 
        	if(text[i] == 'e') count[5]++;			
        	if(text[i] == 'f') count[6]++;			
        	if(text[i] == 'g') count[7]++;			
        	if(text[i] == 'h') count[8]++;			
        	if(text[i] == 'i') count[9]++;			
        	if(text[i] == 'j') count[10]++;			
        	if(text[i] == 'k') count[11]++;			
        	if(text[i] == 'l') count[12]++;			
        	if(text[i] == 'm') count[13]++;			
        	if(text[i] == 'n') count[14]++;			
        	if(text[i] == 'o') count[15]++;			
        	if(text[i] == 'p') count[16]++;
			if(text[i] == 'q') count[17]++;			
        	if(text[i] == 'r') count[18]++;			
        	if(text[i] == 's') count[19]++;			
        	if(text[i] == 't') count[20]++;			
        	if(text[i] == 'u') count[21]++;
			if(text[i] == 'v') count[22]++;			
        	if(text[i] == 'w') count[23]++;			
        	if(text[i] == 'x') count[24]++;			
        	if(text[i] == 'y') count[25]++;			
        	if(text[i] == 'z') count[26]++;			
        }
        int max = count[1];
			      
        for(int i = 1 ; i < 27 ; i++){
			if(count[i] > max) max = i + 96;		//indexing the most frequently appearing letter
        		sum += count[i];
    		}
    		
    	histogram(count, sum); 	
		x = 97 - max;	 		  			//finding the most probable movement
}


int main()
{
	ofstream file2;					 //decrypted file
	ifstream file;					//encrypted file
	int x;	
	
	file.open("encrypted.txt");
	file2.open("decrypted.txt" , ios::app);
	
	string text;
	string line;
	
	while(!file.eof())			//uploading file row by row
	{
		getline(file, line);
		text = text + line + " ";		
	}
		 
 	file.close();
 	
	counting(text, x);				//sending letters to be counted
	decryption(text, x);			//decrypting the message
	
	cout << "\nDecrypting...\n";		
	
	file2 << text << endl;			
	file2.close();
	
system("pause");
return 0;
}

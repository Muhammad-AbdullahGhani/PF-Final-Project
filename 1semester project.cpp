/*
Member 1:
Muhammad Abdullah Ghani
22I-2683
CS-B
Member 2:
Ali Ahmad Shah
22I-1252
CS-B
*/


#include<iostream>
#include<windows.h>
const char dot = '.';
void opponentturn(char grid[][8]);
void opponentking(char grid[][8], int krow, int kcol);
void clearking(char grid[][8], int *Krow, int *Kcol);
void clearopponentking(char grid[][8], int krow, int kcol);
void opponentbishop(char grid[][8], int brow, int bcol);
void clearbishop(char grid[][8], int Brow, int Bcol);
void clearopponentbishop(char grid[][8], int brow, int bcol);
void opponentrock(char grid[][8], int rowr, int colr);
void clearrock(char grid[][8], int rowr, int colr);
void clearopponentrock(char grid[][8], int rowr, int colr);
void queen(char grid[][8], int Krow, int Kcol);
void opponentqueen(char grid[][8], int qrow, int qcol);
void setColor(int colorCode);
void Knight(char grid[][8], int Hrow, int Hcol);
void opponentknight(char grid[][8], int hrow, int hcol);
using namespace std;

void display(char grid[][8]) {
    // Displaying chess board
    
    cout<<"--------------------------------- "<<endl;
    cout<<"| "<<grid[0][0]<<" | "<<grid[0][1]<<" | "<<grid[0][2]<<" | "<<grid[0][3]<<" | "<<grid[0][4]<<" | "<<grid[0][5]<<" | "<<grid[0][6]<<" | "<<grid[0][7]<<" | "<<endl;
    cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[1][0]<<" | "<<grid[1][1]<<" | "<<grid[1][2]<<" | "<<grid[1][3]<<" | "<<grid[1][4]<<" | "<<grid[1][5]<<" | "<<grid[1][6]<<" | "<<grid[1][7]<<" | "<<endl;
	cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[2][0]<<" | "<<grid[2][1]<<" | "<<grid[2][2]<<" | "<<grid[2][3]<<" | "<<grid[2][4]<<" | "<<grid[2][5]<<" | "<<grid[2][6]<<" | "<<grid[2][7]<<" | "<<endl;
    cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[3][0]<<" | "<<grid[3][1]<<" | "<<grid[3][2]<<" | "<<grid[3][3]<<" | "<<grid[3][4]<<" | "<<grid[3][5]<<" | "<<grid[3][6]<<" | "<<grid[3][7]<<" | "<<endl;
    cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[4][0]<<" | "<<grid[4][1]<<" | "<<grid[4][2]<<" | "<<grid[4][3]<<" | "<<grid[4][4]<<" | "<<grid[4][5]<<" | "<<grid[4][6]<<" | "<<grid[4][7]<<" | "<<endl;
    cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[5][0]<<" | "<<grid[5][1]<<" | "<<grid[5][2]<<" | "<<grid[5][3]<<" | "<<grid[5][4]<<" | "<<grid[5][5]<<" | "<<grid[5][6]<<" | "<<grid[5][7]<<" | "<<endl;
    cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[6][0]<<" | "<<grid[6][1]<<" | "<<grid[6][2]<<" | "<<grid[6][3]<<" | "<<grid[6][4]<<" | "<<grid[6][5]<<" | "<<grid[6][6]<<" | "<<grid[6][7]<<" | "<<endl;
    cout<<"|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"| "<<grid[7][0]<<" | "<<grid[7][1]<<" | "<<grid[7][2]<<" | "<<grid[7][3]<<" | "<<grid[7][4]<<" | "<<grid[7][5]<<" | "<<grid[7][6]<<" | "<<grid[7][7]<<" | "<<endl;
    cout<<"--------------------------------- "<<endl;
}
// for displaying king
void king(char grid[][8], int *Krow, int *Kcol) {
    int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
int clearkingrow=0,clearkingcol=0;
    cout << endl;

   // grid[Krow][Kcol] = 75;

    // Store the original color code to restore it later
    int originalColorCode = 7;

    // Set the color to red for highlighting possible moves
    

    if (grid[*Krow - 1][*Kcol] == 32){
        grid[*Krow - 1][*Kcol] = dot;
	dot , 	setColor(redColorCode);
	}
    if (grid[*Krow - 1][*Kcol + 1] == 32){
        grid[*Krow - 1][*Kcol + 1] = dot;
        dot , setColor(redColorCode);
	}
    if (grid[*Krow][*Kcol + 1] == 32){
        grid[*Krow][*Kcol + 1] = dot;
        dot ,  setColor(redColorCode);
	}
    if (grid[*Krow][*Kcol - 1] == 32){
        grid[*Krow][*Kcol - 1] = dot;
       dot,  setColor(redColorCode);
	}
    if (grid[*Krow + 1][*Kcol - 1] == 32)
        grid[*Krow + 1][*Kcol - 1] = dot;
    if (grid[*Krow + 1][*Kcol] == 32){
        grid[*Krow + 1][*Kcol] = dot;
       dot , setColor(redColorCode);
	}
    if (grid[*Krow + 1][*Kcol + 1] == 32)
        grid[*Krow + 1][*Kcol + 1] = dot;
    if (grid[*Krow - 1][*Kcol - 1] == 32)
        grid[*Krow - 1][*Kcol - 1] = dot;
        
       
    
    

    display(grid);
    setColor(originalColorCode);
    grid[*Krow][*Kcol] = 32;
    clearking(grid, &clearkingrow, &clearkingcol);
grid[*Krow][*Kcol] = 32;
    // display current grid
    cout << "Now enter the row and column number of the king (8x8 Grid): " << dot << endl;
    while (true) {
        cin >> *Krow >> *Kcol;
        if (*Krow >= 1 && *Krow <= 6 && *Kcol >= 1 && *Kcol <= 6 && *Krow - 1 != dot && *Kcol != dot && *Krow - 1 != dot && *Kcol + 1 != dot && *Krow != dot && *Kcol + 1 != dot && *Krow != dot && *Kcol - 1 != dot && *Krow + 1 != dot && *Kcol - 1 != dot && *Krow + 1 != dot && *Kcol != dot && *Krow + 1 != dot && *Kcol + 1 != dot && *Krow - 1 != dot && *Kcol - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
grid[*Krow][*Kcol] = 32;
    grid[*Krow][*Kcol] = 75;
    display(grid);
    
}
// for displaying bishop
void bishop(char grid[][8], int Brow, int Bcol) {


	grid[Brow][Bcol] = 66;
	if(grid[Brow - 1][Bcol - 1]==32 || grid[Brow - 1][Bcol - 1]==66)
    grid[Brow - 1][Bcol - 1] = dot;
    if(grid[Brow - 2][Bcol - 2]==32 ||grid[Brow - 2][Bcol - 2]==66)
    grid[Brow - 2][Bcol - 2] = dot;
    if(grid[Brow - 3][Bcol - 3]==32 || grid[Brow - 3][Bcol - 3]==66)
    grid[Brow - 3][Bcol - 3] = dot;
    if(grid[Brow + 1][Bcol + 1]==32 || grid[Brow + 1][Bcol + 1]==66)
    grid[Brow + 1][Bcol + 1] = dot;
    if(grid[Brow + 2][Bcol + 2]==32 || grid[Brow + 2][Bcol + 2]==66)
    grid[Brow + 2][Bcol + 2] = dot;
    if(grid[Brow + 3][Bcol + 3]==32 || grid[Brow + 3][Bcol + 3]==66)
    grid[Brow + 3][Bcol + 3] = dot;
    if(grid[Brow - 1][Bcol + 2]==32 || grid[Brow - 1][Bcol + 2]==66)
    grid[Brow - 1][Bcol + 2] = dot;
    if(grid[Brow - 2][Bcol +3]==32 || grid[Brow - 2][Bcol + 3]==66)
    grid[Brow - 2][Bcol + 3] = dot;
    if(grid[Brow - 3][Bcol + 4]==32 || grid[Brow - 3][Bcol + 4]==66)
    grid[Brow - 3][Bcol + 4] = dot;
    if(grid[Brow + 1][Bcol - 1]==32 || grid[Brow + 1][Bcol - 1]==66)
    grid[Brow + 1][Bcol - 1] = dot;
    if(grid[Brow + 2][Bcol - 2] ==32 || grid[Brow + 2][Bcol - 2]==66)
    grid[Brow + 2][Bcol - 2] = dot;
    if(grid[Brow + 3][Bcol - 3]==32 || grid[Brow + 3][Bcol - 3]==66)
    grid[Brow + 3][Bcol - 3] = dot;
    if(grid[Brow + 4][Bcol + 4]==32 || grid[Brow + 4][Bcol + 4]==66)
    grid[Brow + 4][Bcol + 4] = dot;
	display(grid);
	grid[Brow][Bcol] = 32;
	clearbishop(grid , Brow , Bcol);
	
    cout << "Now enter row and column number of Bishop (8x8 Grid)" << endl;
    while (true) {

        cin >> Brow >> Bcol;
        if (Brow >= 1 && Brow + 3 < grid[7][7] && Bcol >= 1 && Bcol + 3 < grid[0][7] &&
    (grid[Brow - 1][Bcol - 1] == 32 || grid[Brow - 1][Bcol - 1] == 66) &&
    (grid[Brow - 2][Bcol - 2] == 32 || grid[Brow - 2][Bcol - 2] == 66) &&
    (grid[Brow - 3][Bcol - 3] == 32 || grid[Brow - 3][Bcol - 3] == 66) &&
    (grid[Brow + 1][Bcol + 1] == 32 || grid[Brow + 1][Bcol + 1] == 66) &&
    (grid[Brow + 2][Bcol + 2] == 32 || grid[Brow + 2][Bcol + 2] == 66) &&
    (grid[Brow + 3][Bcol + 3] == 32 || grid[Brow + 3][Bcol + 3] == 66) &&
    (grid[Brow - 1][Bcol + 2] == 32 || grid[Brow - 1][Bcol + 2] == 66) &&
    (grid[Brow - 2][Bcol + 3] == 32 || grid[Brow - 2][Bcol + 3] == 66) &&
    (grid[Brow - 3][Bcol + 4] == 32 || grid[Brow - 3][Bcol + 4] == 66) &&
    (grid[Brow + 1][Bcol - 1] == 32 || grid[Brow + 1][Bcol - 1] == 66) &&
    (grid[Brow + 2][Bcol - 2] == 32 || grid[Brow + 2][Bcol - 2] == 66) &&
    (grid[Brow + 3][Bcol - 3] == 32 || grid[Brow + 3][Bcol - 3] == 66) &&
    (grid[Brow + 4][Bcol + 4] == 32 || grid[Brow + 4][Bcol + 4] == 66))
			{
            cout << "Enter input again" << endl;
            continue;
        }
        else {
        	grid[Brow][Bcol] = 66;
            break;
        }
    }
    
    display(grid);



}
// for displaying rock
void rock(char grid[][8],int rowR,int colR) {
  int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
grid[rowR][colR] = 82,setColor(yellowColorCode);
if (grid[rowR][colR - 1] == 32)
    grid[rowR][colR - 1] = dot;
if (grid[rowR][colR - 2] == 32)
    grid[rowR][colR - 2] = dot;
if (grid[rowR][colR - 3] == 32)
    grid[rowR][colR - 3] = dot;
if (grid[rowR][colR - 4] == 32)
    grid[rowR][colR - 4] = dot; 
if (grid[rowR][colR - 6] == 32)
    grid[rowR][colR - 6] = dot;
if (grid[rowR][colR - 5] == 32)
    grid[rowR][colR - 5] = dot;
if (grid[rowR - 1][colR] == 32)
    grid[rowR - 1][colR] = dot;
if (grid[rowR - 2][colR] == 32)
    grid[rowR - 2][colR] = dot;
if (grid[rowR - 3][colR] == 32)
    grid[rowR - 3][colR] = dot;	
if (grid[rowR - 4][colR] == 32)
    grid[rowR - 4][colR] = dot;	
if (grid[rowR - 5][colR] == 32)
    grid[rowR - 5][colR] = dot;
if (grid[rowR - 6][colR] == 32)
    grid[rowR - 6][colR] = dot;				    
if (grid[rowR][colR + 1] == 32)
    grid[rowR][colR + 1] = dot;
if (grid[rowR][colR + 2] == 32)
    grid[rowR][colR + 2] = dot;
if (grid[rowR][colR + 3] == 32)
    grid[rowR][colR + 3] = dot;
if (grid[rowR][colR + 4] == 32)
    grid[rowR][colR + 4] = dot; 
if (grid[rowR][colR + 5] == 32)
    grid[rowR][colR + 5] = dot; 
if (grid[rowR][colR + 6] == 32)
    grid[rowR][colR + 6] = dot; 		 
if (grid[rowR + 1][colR] == 32)
    grid[rowR + 1][colR] = dot;	  
if (grid[rowR + 2][colR] == 32)
    grid[rowR + 2][colR] = dot;
if (grid[rowR + 3][colR] == 32)
    grid[rowR + 3][colR] = dot;    
if (grid[rowR + 4][colR] == 32)
    grid[rowR + 4][colR] = dot;    
if (grid[rowR + 5][colR] == 32)
    grid[rowR + 5][colR] = dot;    
if (grid[rowR + 6][colR] == 32)
    grid[rowR + 6][colR] = dot;    	    
	display(grid);
    
   grid[rowR][colR]=32;

			    


    grid[rowR + 1][colR] = 32;	  

    grid[rowR + 2][colR] = 32;

    grid[rowR + 3][colR] = 32;    

    grid[rowR + 4][colR] = 32;    

    grid[rowR + 5][colR] = 32;    
   	    
    cout << "Now enter row and column number of Rock (8x8 Grid)" << endl;

    while (true) {
        cin >> rowR >> colR;
        if (rowR >= 0 && rowR <= 6 && colR >= 0 && colR <= 6 && rowR - 0 != dot && colR != dot && rowR - 1 != dot && colR + 1 != dot && rowR != dot && colR + 1 != dot && rowR != dot && colR - 1 != dot && rowR + 1 != dot && colR - 1 != dot && rowR + 1 != dot && colR != dot && rowR + 1 != dot && colR + 1 != dot && rowR - 1 != dot && colR - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
   grid[rowR][colR]='R';
   
       display(grid);


}
// staring of the game
void start() {
	 
	int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
    int start;
    int choose;
    cout << "\t\t\tPress 1 to start the game" << endl;
    cin >> start;

    char grid[8][8];
    for (int i = 0; i < 8; i++) 
	{
        for (int j = 0; j < 8; j++) 
		{
			if((i==0 && j==0) || (i==0 && j==7))
			{
			grid[i][j] =82;
			}
			else if((i==7 && j==0)|| (i==7 && j==7))
			grid[i][j] =114;
			else if((i==0 && j==1) || (i==0 && j==6))
			{
			grid[i][j] =72;
			}
			else if((i==7 && j==1)|| (i==7 && j==6))
			grid[i][j] =104;
			else if((i==0 && j==2) || (i==0 && j==5))
			{
			grid[i][j] =66;
			}
			else if( (i==7 && j==2)|| (i==7 && j==5))
			grid[i][j] =98;
			else if((i==0 && j==3))
			{
			grid[i][j] =75;
			setColor(7);
			}
			else if((i==7 && j==4))
			grid[i][j] =107;	
			else if((i==0 && j==4) )
			{
			grid[i][j] =81;
			}
			else if((i==7 && j==3))
			grid[i][j] =113;
			else
            grid[i][j] = ' ';
            
        }
    }
    

    display(grid);

//choosing of options

    while (true) {
        cout << "\n\tPlayer 1 " << endl;
        cout << "\nPlease choose a chess piece:" << endl;
        cout << "1: King" << endl;
        cout << "2: Queen" << endl;
        cout << "3: Bishop" << endl;
        cout << "4: Rock" << endl;
        cout << "5: Knight" << endl;
        cout << "6: Finish" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
           int Kingrow=0, Kingcol=3;
		
			king(grid, &Kingrow, &Kingcol);

            
            cout << "\nPlayer two turn" << endl;
            opponentturn(grid);


        }
         if (choice == 2) {
           int Qrow=0, Qcol=4;
		
			 queen(grid, Qrow, Qcol);

            
            cout << "\nPlayer two turn" << endl;
            opponentturn(grid);


        }
        

        if (choice == 3) {
            int Brow=0, Bcol=2;
            
            bishop(grid, Brow, Bcol);
            
            cout << "\nPlayer two turn" << endl;
            opponentturn(grid);

        }
        if (choice == 4) {
        	
            int rowR=0,colR=0;
            rock(grid,rowR,colR);
            
            cout << "\nPlayer two turn" << endl;
            opponentturn(grid);

        }
        if (choice == 5) {
            int Hrow=0,Hcol=2;
 Knight(grid, Hrow,Hcol);
  cout << "\nPlayer two turn" << endl;
            opponentturn(grid);
        }
        if (choice == 6) {
            cout<<"Game ended"<<endl;
            exit(0);
        }
        else {
            cout << "\nEnter Again";
        }
    }

}

int main() {
    start();
    return 0;
}
//choosing of opponent turn
void opponentturn(char grid[][8]) {

    while (true) {
        cout << "\n\tPlayer two" << endl;
        cout << "\nPlease choose a chess piece:" << endl;
        cout << "1: King" << endl;
        cout << "2: Queen" << endl;
        cout << "3: Bishop" << endl;
        cout << "4: Rook" << endl;
        cout << "5: Knight" << endl;
        cout << "6: Finish" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            int krow=7, kcol=4;
//choosing of opponent king
            opponentking(grid, krow, kcol);
            break;
        }
        if (choice == 2) {
			int qrow=7, qcol=3;
//choosing of opponent queen
            opponentqueen(grid, qrow, qcol);
            break;
        }
        if (choice == 3) {
            int brow=7, bcol=5;
//choosing of opponent bishop
            opponentbishop(grid, brow, bcol);
            break;
        }
          if (choice == 4) {
            int rowr=0, colr=0;
//choosing of opponent rock
            opponentrock(grid, rowr, colr);
            break;
        }
          if (choice == 5) {
            int hrow=7, hcol=6;
//choosing of opponent knight
            opponentknight(grid, hrow, hcol);
            break;
        }
         if (choice == 6) {
            cout<<"Game ended"<<endl;
            exit(0);
        }
    }

}
// opponent king
void opponentking(char grid[][8], int krow, int kcol) {

    cout << "\t\tPlayer two " << endl;

	
	if(grid[krow - 1][kcol]==32 || grid[krow - 1][kcol]==107)
    grid[krow - 1][kcol] = dot;
    if(grid[krow - 1][kcol + 1]==32 || grid[krow - 1][kcol + 1]==107)
    grid[krow - 1][kcol + 1] = dot;
    if(grid[krow][kcol + 1]==32 || grid[krow][kcol + 1]==107)
    grid[krow][kcol + 1] = dot;
    if(grid[krow][kcol + 1]==32 || grid[krow][kcol + 1]==107)
    grid[krow][kcol + 1] = dot;
    if(grid[krow + 1][kcol - 1]==32 || grid[krow + 1][kcol - 1]==107)
    grid[krow + 1][kcol - 1] = dot;
    if(grid[krow + 1][kcol]==32 || grid[krow + 1][kcol]==107)
    grid[krow + 1][kcol] = dot;
    if(grid[krow + 1][kcol + 1]==32 || grid[krow + 1][kcol + 1]==107)
    grid[krow + 1][kcol + 1] = dot;
    if(grid[krow - 1][kcol - 1]==32 || grid[krow - 1][kcol - 1]==107)
    grid[krow - 1][kcol - 1] = dot;
    display(grid);
    grid[krow][kcol]=32;
    cout << "Enter row and column number of king (8x8 Grid)" << endl;
   clearopponentking(grid , krow , kcol);
    while (true)
	 {
		
        cin >> krow >> kcol;
        if (krow >= 1 && krow <= 6 && kcol >= 1 && kcol <= 6 && krow - 1 != dot && kcol != dot &&krow - 1!= dot &&kcol + 1 != dot &&krow!= dot &&kcol + 1 != dot &&krow!= dot &&kcol - 1 != dot &&krow + 1!= dot &&kcol - 1 != dot &&krow + 1!= dot &&kcol != dot &&krow + 1!= dot &&kcol + 1 != dot &&krow - 1!= dot &&kcol - 1 != dot) 
            break;
 
	 
	
        
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }

		 }
    grid[krow][kcol] = 107;
    display(grid);





}
void clearking(char grid[][8], int *Krow,int *Kcol ) {
//	grid[Krow][Kcol] = 75;
    if(grid[*Krow - 1][*Kcol]==dot || grid[*Krow - 1][*Kcol - 1]==75)
    grid[*Krow - 1][*Kcol]=32;
    if(grid[*Krow - 1][*Kcol + 1]==dot|| grid[*Krow - 1][*Kcol - 1]==75)
    grid[*Krow - 1][*Kcol + 1]=32;
    if(grid[*Krow][*Kcol + 1]==dot|| grid[*Krow - 1][*Kcol - 1]==75)    
	grid[*Krow][*Kcol + 1] =32;
	if(grid[*Krow][*Kcol - 1] ==dot|| grid[*Krow - 1][*Kcol - 1]==75)
    grid[*Krow][*Kcol - 1] =32;
    if(grid[*Krow + 1][*Kcol - 1]==dot||grid[*Krow - 1][*Kcol - 1]== 75)
    grid[*Krow + 1][*Kcol - 1] =32;
    if(grid[*Krow + 1][*Kcol]==dot||grid[*Krow - 1][*Kcol - 1]== 75)
    grid[*Krow + 1][*Kcol] =32;
    if(grid[*Krow + 1][*Kcol + 1]==dot|| grid[*Krow - 1][*Kcol - 1]==75)
    grid[*Krow + 1][*Kcol + 1] = 32;
    if(grid[*Krow - 1][*Kcol - 1]== dot||grid[*Krow - 1][*Kcol - 1]== 75)
    grid[*Krow - 1][*Kcol - 1] = 32;

}
void clearopponentking(char grid[][8], int krow, int kcol) {
    if(grid[krow - 1][kcol]==dot || grid[krow - 1][kcol - 1]==107)
    grid[krow - 1][kcol]=32;
    if(grid[krow - 1][kcol + 1]==dot|| grid[krow - 1][kcol - 1]==107)
    grid[krow - 1][kcol + 1]=32;
    if(grid[krow][kcol + 1]==dot|| grid[krow - 1][kcol - 1]==107)    
	grid[krow][kcol + 1] =32;
	if(grid[krow][kcol - 1] ==dot|| grid[krow - 1][kcol - 1]==107)
    grid[krow][kcol - 1] =32;
    if(grid[krow + 1][kcol - 1]==dot||grid[krow - 1][kcol - 1]== 107)
    grid[krow + 1][kcol - 1] =32;
    if(grid[krow + 1][kcol]==dot||grid[krow - 1][kcol - 1]== 107)
    grid[krow + 1][kcol] =32;
    if(grid[krow + 1][kcol + 1]==dot|| grid[krow - 1][kcol - 1]==107)
    grid[krow + 1][kcol + 1] = 32;
    if(grid[krow - 1][kcol - 1]== dot||grid[krow - 1][kcol - 1]== 107)
    grid[krow - 1][kcol - 1] = 32;
}
void opponentbishop(char grid[][8], int brow, int bcol) {

    grid[brow][bcol] = 98;
	int row = brow - 1;
int col = bcol - 1;
while (row >= 0 && col >= 0 && (grid[row][col] == 32 || grid[row][col] == 98)) {
    grid[row][col] = dot;
    row--;
    col--;
}

row = brow - 1;
col = bcol + 1;
while (row >= 0 && col < 8 && (grid[row][col] == 32 || grid[row][col] == 98)) {
    grid[row][col] = dot;
    row--;
    col++;
}

row = brow + 1;
col = bcol - 1;
while (row < 8 && col >= 0 && (grid[row][col] == 32 || grid[row][col] == 98)) {
    grid[row][col] = dot;
    row++;
    col--;
}

row = brow + 1;
col = bcol + 1;
while (row < 8 && col < 8 && (grid[row][col] == 32 || grid[row][col] == 98)) {
    grid[row][col] = dot;
    row++;
    col++;
}
    display(grid);
    cout << "\t\tPlayer two " << endl;
    clearopponentbishop(grid , brow, bcol);
        grid[brow][bcol]=32;

    cout << "Enter row and column number of Bishop(8x8 Grid)" << endl;
    while (true) {

        cin >> brow >> bcol;
        if (brow >= 1 && brow + 3 < grid[7][7] && bcol >= 1 && bcol + 3 < grid[0][7] &&
    (grid[brow - 1][bcol - 1] == 32 || grid[brow - 1][bcol - 1] == 66) &&
    (grid[brow - 2][bcol - 2] == 32 || grid[brow - 2][bcol - 2] == 66) &&
    (grid[brow - 3][bcol - 3] == 32 || grid[brow - 3][bcol - 3] == 66) &&
    (grid[brow + 1][bcol + 1] == 32 || grid[brow + 1][bcol + 1] == 66) &&
    (grid[brow + 2][bcol + 2] == 32 || grid[brow + 2][bcol + 2] == 66) &&
    (grid[brow + 3][bcol + 3] == 32 || grid[brow + 3][bcol + 3] == 66) &&
    (grid[brow - 1][bcol + 2] == 32 || grid[brow - 1][bcol + 2] == 66) &&
    (grid[brow - 2][bcol + 3] == 32 || grid[brow - 2][bcol + 3] == 66) &&
    (grid[brow - 3][bcol + 4] == 32 || grid[brow - 3][bcol + 4] == 66) &&
    (grid[brow + 1][bcol - 1] == 32 || grid[brow + 1][bcol - 1] == 66) &&
    (grid[brow + 2][bcol - 2] == 32 || grid[brow + 2][bcol - 2] == 66) &&
    (grid[brow + 3][bcol - 3] == 32 || grid[brow + 3][bcol - 3] == 66) &&
    (grid[brow + 4][bcol + 4] == 32 || grid[brow + 4][bcol + 4] == 66))
			{
            cout << "Enter input again" << endl;
            continue;
        }
        else {
        	grid[brow][bcol] = 98;
            break;
        }
    }
    display(grid);

}
// clearing bishp after net turn
void clearbishop(char grid[][8], int Brow, int Bcol) {
    grid[Brow][Bcol] = ' ';
    grid[Brow - 1][Bcol - 1] = ' ';
    grid[Brow - 2][Bcol - 2] = ' ';
    grid[Brow + 1][Bcol + 1] = ' ';
    grid[Brow + 2][Bcol + 2] = ' ';
    grid[Brow + 3][Bcol + 3] = ' ';
    grid[Brow - 1][Bcol + 2] = ' ';
    grid[Brow - 2][Bcol + 3] = ' ';
    grid[Brow - 3][Bcol + 4] = ' ';
    grid[Brow + 1][Bcol - 1] = ' ';
    grid[Brow + 2][Bcol - 2] = ' ';
    grid[Brow + 3][Bcol - 3] = ' ';
    grid[Brow + 4][Bcol + 4] = ' ';



}
void clearopponentbishop(char grid[][8], int brow, int bcol) {

  	int row = brow - 1;
int col = bcol - 1;
while (row >= 0 && col >= 0 && (grid[row][col] == dot || grid[row][col] == 98)) {
    grid[row][col] = 32;
    row--;
    col--;
}

row = brow - 1;
col = bcol + 1;
while (row >= 0 && col < 8 && (grid[row][col] == dot || grid[row][col] == 98)) {
    grid[row][col] = 32;
    row--;
    col++;
}

row = brow + 1;
col = bcol - 1;
while (row < 8 && col >= 0 && (grid[row][col] == dot || grid[row][col] == 98)) {
    grid[row][col] = 32;
    row++;
    col--;
}

row = brow + 1;
col = bcol + 1;
while (row < 8 && col < 8 && (grid[row][col] == dot || grid[row][col] == 98)) {
    grid[row][col] = 32;
    row++;
    col++;
}
}

void opponentrock(char grid[][8], int rowr, int colr) {


////

 int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
grid[rowr][colr] = 82,setColor(yellowColorCode);
grid[rowr][colr] = 'r';
   if( grid[rowr][colr - 1]==32)
    grid[rowr][colr - 1] = '.';
      if( grid[rowr][colr - 2]==32)
    grid[rowr][colr - 2] = '.';
      if( grid[rowr][colr - 3]==32)
    grid[rowr][colr - 3] = '.';
      if( grid[rowr][colr - 4]==32)
    grid[rowr][colr - 4] = '.';
      if( grid[rowr + 2][colr]==32)
    grid[rowr + 2][colr] = '.';
      if( grid[rowr][colr - 6]==32)
    grid[rowr][colr - 6] = '.';
     if( grid[rowr] [colr - 5] ==32)
    grid[rowr][colr - 5] = '.';
      if( grid[rowr + 4][colr]==32)
    grid[rowr + 4][colr] = '.';
      if( grid[rowr - 1][colr] ==32)
    grid[rowr - 1][colr] = '.';
      if( grid[rowr - 2][colr] ==32)
    grid[rowr - 2][colr] = '.';
      if( grid[rowr - 3][colr] ==32)
    grid[rowr - 3][colr] = '.';
      if( grid[rowr + 3][colr] ==32)
    grid[rowr + 3][colr] = '.';
      if( grid[rowr - 4][colr] ==32)
    grid[rowr - 4][colr] = '.';
      if( grid[rowr][colr + 1]==32)
    grid[rowr][colr + 1] = '.';
      if( grid[rowr + 1][colr]==32)
    grid[rowr + 1][colr] = '.';
      if( grid[rowr][colr + 2]==32)
    grid[rowr][colr + 2] = '.';
      if( grid[rowr][colr + 3]==32)
    grid[rowr][colr + 3] = '.';
      if( grid[rowr][colr + 4]==32)
    grid[rowr][colr + 4] = '.';     	    
	display(grid);
    
   grid[rowr][colr]=32;

			    


    grid[rowr + 1][colr] = 32;	  

    grid[rowr + 2][colr] = 32;

    grid[rowr + 3][colr] = 32;    

    grid[rowr + 4][colr] = 32;    

    grid[rowr + 5][colr] = 32;    
   	    grid[rowr + 6][colr] = 32; 
    cout << "Now enter row and column number of Rock (8x8 Grid)" << endl;

     while (true) {
        cin >> rowr >> colr;
        if (rowr >= 0 && rowr <= 6 && colr >= 0 && colr <= 6 && rowr - 1 != dot && colr != dot && rowr - 1 != dot && colr + 1 != dot && rowr != dot && colr + 1 != dot && rowr != dot && colr - 1 != dot && rowr + 1 != dot && colr - 1 != dot && rowr + 1 != dot && colr != dot && rowr + 1 != dot && colr + 1 != dot && rowr - 1 != dot && colr - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
   grid[rowr][colr]='r';
   
       display(grid);



}
void clearrock(char grid[][8],int rowR,int colR){

  grid[rowR][colR] = 32;
    grid[rowR][colR - 1] = ' ';
    grid[rowR][colR - 2] = ' ';
    grid[rowR][colR - 3] = ' ';
    grid[rowR][colR - 4] = ' ';
    grid[rowR + 2][colR] = ' ';
    grid[rowR][colR - 6] = ' ';
    grid[rowR][colR - 5] = ' ';
    grid[rowR + 4][colR] = ' ';
    grid[rowR - 1][colR] = ' ';
    grid[rowR - 2][colR] = ' ';
    grid[rowR - 3][colR] = ' ';
    grid[rowR + 3][colR] = ' ';
    grid[rowR - 4][colR] = ' ';
    grid[rowR][colR + 1] = ' ';
    grid[rowR + 1][colR] = ' ';
    grid[rowR][colR + 2] = ' ';
    grid[rowR][colR + 3] = ' ';
    grid[rowR][colR + 4] = ' ';
}

void clearopponentrock(char grid[][8],int rowr,int colr){

  grid[rowr][colr] = '|';
    grid[rowr][colr - 1] = '|';
    grid[rowr][colr - 2] = '|';
    grid[rowr][colr - 3] = '|';
    grid[rowr][colr - 4] = '|';
    grid[rowr + 2][colr] = '|';
    grid[rowr][colr - 6] = '|';
    grid[rowr][colr - 5] = '|';
    grid[rowr + 4][colr] = '|';
    grid[rowr - 1][colr] = '|';
    grid[rowr - 2][colr] = '|';
    grid[rowr - 3][colr] = '|';
    grid[rowr + 3][colr] = '|';
    grid[rowr - 4][colr] = '|';
    grid[rowr][colr + 1] = '|';
    grid[rowr + 1][colr] = '|';
    grid[rowr][colr + 2] = '|';
    grid[rowr][colr + 3] = '|';
    grid[rowr][colr + 4] = '|';

}
void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void queen(char grid[][8], int Qrow, int Qcol){

int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
grid[Qrow][Qcol] = 'Q',setColor(16);
if (grid[Qrow][Qcol - 1] == 32)
    grid[Qrow][Qcol - 1] = dot;
if (grid[Qrow][Qcol - 2] == 32)
    grid[Qrow][Qcol - 2] = dot;
if (grid[Qrow][Qcol - 3] == 32)
    grid[Qrow][Qcol - 3] = dot;
if (grid[Qrow][Qcol - 4] == 32)
    grid[Qrow][Qcol - 4] = dot; 
if (grid[Qrow][Qcol - 6] == 32)
    grid[Qrow][Qcol - 6] = dot;
if (grid[Qrow][Qcol - 5] == 32)
    grid[Qrow][Qcol - 5] = dot;
if (grid[Qrow - 1][Qcol] == 32)
    grid[Qrow - 1][Qcol] = dot;
if (grid[Qrow - 2][Qcol] == 32)
    grid[Qrow - 2][Qcol] = dot;
if (grid[Qrow - 3][Qcol] == 32)
    grid[Qrow - 3][Qcol] = dot;	
if (grid[Qrow - 4][Qcol] == 32)
    grid[Qrow - 4][Qcol] = dot;	
if (grid[Qrow - 5][Qcol] == 32)
    grid[Qrow - 5][Qcol] = dot;
if (grid[Qrow - 6][Qcol] == 32)
    grid[Qrow - 6][Qcol] = dot;				    
if (grid[Qrow][Qcol + 1] == 32)
    grid[Qrow][Qcol + 1] = dot;
if (grid[Qrow][Qcol + 2] == 32)
    grid[Qrow][Qcol + 2] = dot;
if (grid[Qrow][Qcol + 3] == 32)
    grid[Qrow][Qcol + 3] = dot;
if (grid[Qrow][Qcol + 4] == 32)
    grid[Qrow][Qcol + 4] = dot; 
if (grid[Qrow][Qcol + 5] == 32)
    grid[Qrow][Qcol + 5] = dot; 
if (grid[Qrow][Qcol + 6] == 32)
    grid[Qrow][Qcol + 6] = dot; 		 
if (grid[Qrow + 1][Qcol] == 32)
    grid[Qrow + 1][Qcol] = dot;	  
if (grid[Qrow + 2][Qcol] == 32)
    grid[Qrow + 2][Qcol] = dot;
if (grid[Qrow + 3][Qcol] == 32)
    grid[Qrow + 3][Qcol] = dot;    
if (grid[Qrow + 4][Qcol] == 32)
    grid[Qrow + 4][Qcol] = dot;    
if (grid[Qrow + 5][Qcol] == 32)
    grid[Qrow + 5][Qcol] = dot;    
if (grid[Qrow + 6][Qcol] == 32)
    grid[Qrow + 6][Qcol] = dot;  
    if(grid[Qrow - 1][Qcol - 1]==32 || grid[Qrow - 1][Qcol - 1]==66)
    grid[Qrow - 1][Qcol - 1] = dot;
    if(grid[Qrow - 2][Qcol - 2]==32 ||grid[Qrow - 2][Qcol - 2]==66)
    grid[Qrow - 2][Qcol - 2] = dot;
    if(grid[Qrow - 3][Qcol - 3]==32 || grid[Qrow - 3][Qcol - 3]==66)
    grid[Qrow - 3][Qcol - 3] = dot;
    if(grid[Qrow + 1][Qcol + 1]==32 || grid[Qrow + 1][Qcol + 1]==66)
    grid[Qrow + 1][Qcol + 1] = dot;
    if(grid[Qrow + 2][Qcol + 2]==32 || grid[Qrow + 2][Qcol + 2]==66)
    grid[Qrow + 2][Qcol + 2] = dot;
    if(grid[Qrow + 3][Qcol + 3]==32 || grid[Qrow + 3][Qcol + 3]==66)
    grid[Qrow + 3][Qcol + 3] = dot;
    if(grid[Qrow - 1][Qcol + 2]==32 || grid[Qrow - 1][Qcol + 2]==66)
    grid[Qrow - 1][Qcol + 2] = dot;
    if(grid[Qrow - 2][Qcol +3]==32 || grid[Qrow - 2][Qcol + 3]==66)
    grid[Qrow - 2][Qcol + 3] = dot;
    if(grid[Qrow - 3][Qcol + 4]==32 || grid[Qrow - 3][Qcol + 4]==66)
    grid[Qrow - 3][Qcol + 4] = dot;
    if(grid[Qrow + 1][Qcol - 1]==32 || grid[Qrow + 1][Qcol - 1]==66)
    grid[Qrow + 1][Qcol - 1] = dot;
    if(grid[Qrow + 2][Qcol - 2] ==32 || grid[Qrow + 2][Qcol - 2]==66)
    grid[Qrow + 2][Qcol - 2] = dot;
    if(grid[Qrow + 3][Qcol - 3]==32 || grid[Qrow + 3][Qcol - 3]==66)
    grid[Qrow + 3][Qcol - 3] = dot;
    if(grid[Qrow + 4][Qcol + 4]==32 || grid[Qrow + 4][Qcol + 4]==66)
    grid[Qrow + 4][Qcol + 4] = dot;  	    
	display(grid);
    
   grid[Qrow][Qcol]=32;

   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(grid[i][j]==dot){
            grid[i][j]=32;
        }
    }
   }
  
    cout << "Now enter row and column number of Rock (8x8 Grid)" << endl;

    while (true) {
        cin >> Qrow >> Qcol;
        if (Qrow >= 0 && Qrow <= 6 && Qcol >= 0 && Qcol <= 6 && Qrow - 0 != dot && Qcol != dot && Qrow - 1 != dot && Qcol + 1 != dot && Qrow != dot && Qcol + 1 != dot && Qrow != dot && Qcol - 1 != dot && Qrow + 1 != dot && Qcol - 1 != dot && Qrow + 1 != dot && Qcol != dot && Qrow + 1 != dot && Qcol + 1 != dot && Qrow - 1 != dot && Qcol - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
   grid[Qrow][Qcol]='Q';
   
       display(grid);


}
void opponentqueen(char grid[][8], int qrow, int qcol){

int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
grid[qrow][qcol] = 'q',setColor(18);
if (grid[qrow][qcol - 1] == 32)
    grid[qrow][qcol - 1] = dot;
if (grid[qrow][qcol - 2] == 32)
    grid[qrow][qcol - 2] = dot;
if (grid[qrow][qcol - 3] == 32)
    grid[qrow][qcol - 3] = dot;
if (grid[qrow][qcol - 4] == 32)
    grid[qrow][qcol - 4] = dot; 
if (grid[qrow][qcol - 6] == 32)
    grid[qrow][qcol - 6] = dot;
if (grid[qrow][qcol - 5] == 32)
    grid[qrow][qcol - 5] = dot;
if (grid[qrow - 1][qcol] == 32)
    grid[qrow - 1][qcol] = dot;
if (grid[qrow - 2][qcol] == 32)
    grid[qrow - 2][qcol] = dot;
if (grid[qrow - 3][qcol] == 32)
    grid[qrow - 3][qcol] = dot;	
if (grid[qrow - 4][qcol] == 32)
    grid[qrow - 4][qcol] = dot;	
if (grid[qrow - 5][qcol] == 32)
    grid[qrow - 5][qcol] = dot;
if (grid[qrow - 6][qcol] == 32)
    grid[qrow - 6][qcol] = dot;				    
if (grid[qrow][qcol + 1] == 32)
    grid[qrow][qcol + 1] = dot;
if (grid[qrow][qcol + 2] == 32)
    grid[qrow][qcol + 2] = dot;
if (grid[qrow][qcol + 3] == 32)
    grid[qrow][qcol + 3] = dot;
if (grid[qrow][qcol + 4] == 32)
    grid[qrow][qcol + 4] = dot; 
if (grid[qrow][qcol + 5] == 32)
    grid[qrow][qcol + 5] = dot; 
if (grid[qrow][qcol + 6] == 32)
    grid[qrow][qcol + 6] = dot; 		 
if (grid[qrow + 1][qcol] == 32)
    grid[qrow + 1][qcol] = dot;	  
if (grid[qrow + 2][qcol] == 32)
    grid[qrow + 2][qcol] = dot;
if (grid[qrow + 3][qcol] == 32)
    grid[qrow + 3][qcol] = dot;    
if (grid[qrow + 4][qcol] == 32)
    grid[qrow + 4][qcol] = dot;    
if (grid[qrow + 5][qcol] == 32)
    grid[qrow + 5][qcol] = dot;    
if (grid[qrow + 6][qcol] == 32)
    grid[qrow + 6][qcol] = dot;  
    if(grid[qrow - 1][qcol - 1]==32 || grid[qrow - 1][qcol - 1]==66)
    grid[qrow - 1][qcol - 1] = dot;
    if(grid[qrow - 2][qcol - 2]==32 ||grid[qrow - 2][qcol - 2]==66)
    grid[qrow - 2][qcol - 2] = dot;
    if(grid[qrow - 3][qcol - 3]==32 || grid[qrow - 3][qcol - 3]==66)
    grid[qrow - 3][qcol - 3] = dot;
    if(grid[qrow + 1][qcol + 1]==32 || grid[qrow + 1][qcol + 1]==66)
    grid[qrow + 1][qcol + 1] = dot;
    if(grid[qrow + 2][qcol + 2]==32 || grid[qrow + 2][qcol + 2]==66)
    grid[qrow + 2][qcol + 2] = dot;
    if(grid[qrow + 3][qcol + 3]==32 || grid[qrow + 3][qcol + 3]==66)
    grid[qrow + 3][qcol + 3] = dot;
    if(grid[qrow - 1][qcol + 2]==32 || grid[qrow - 1][qcol + 2]==66)
    grid[qrow - 1][qcol + 2] = dot;
    if(grid[qrow - 2][qcol +3]==32 || grid[qrow - 2][qcol + 3]==66)
    grid[qrow - 2][qcol + 3] = dot;
    if(grid[qrow - 3][qcol + 4]==32 || grid[qrow - 3][qcol + 4]==66)
    grid[qrow - 3][qcol + 4] = dot;
    if(grid[qrow + 1][qcol - 1]==32 || grid[qrow + 1][qcol - 1]==66)
    grid[qrow + 1][qcol - 1] = dot;
    if(grid[qrow + 2][qcol - 2] ==32 || grid[qrow + 2][qcol - 2]==66)
    grid[qrow + 2][qcol - 2] = dot;
    if(grid[qrow + 3][qcol - 3]==32 || grid[qrow + 3][qcol - 3]==66)
    grid[qrow + 3][qcol - 3] = dot;
    if(grid[qrow + 4][qcol + 4]==32 || grid[qrow + 4][qcol + 4]==66)
    grid[qrow + 4][qcol + 4] = dot;  	    
	display(grid);
    
   grid[qrow][qcol]=32;

   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(grid[i][j]==dot){
            grid[i][j]=32;
        }
    }
   }
  
    cout << "Now enter row and column number of Rock (8x8 Grid)" << endl;

    while (true) {
        cin >> qrow >> qcol;
        if (qrow >= 0 && qrow <= 6 && qcol >= 0 && qcol <= 6 && qrow - 0 != dot && qcol != dot && qrow - 1 != dot && qcol + 1 != dot && qrow != dot && qcol + 1 != dot && qrow != dot && qcol - 1 != dot && qrow + 1 != dot && qcol - 1 != dot && qrow + 1 != dot && qcol != dot && qrow + 1 != dot && qcol + 1 != dot && qrow - 1 != dot && qcol - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
   grid[qrow][qcol]='q';
   
       display(grid);


}
void Knight(char grid[][8], int Hrow, int Hcol){
    int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
grid[Hrow][Hcol] = 'H';
if(grid[Hrow + 2] [Hcol+ 1]==32)
grid[Hrow + 2] [Hcol+ 1]=dot;
if(grid[Hrow + 2] [Hcol - 1]==32)
grid[Hrow + 2] [Hcol - 1]=dot;
if(grid[Hrow - 2] [Hcol + 1]==32)
grid[Hrow - 2] [Hcol + 1]=dot;
if(grid[Hrow - 2] [Hcol - 1]==32)
grid[Hrow - 2] [Hcol - 1]=dot;
if(grid[Hrow + 1] [Hcol + 2]==32)
grid[Hrow + 1] [Hcol + 2]=dot;
if(grid[Hrow + 1] [Hcol - 2]==32)
grid[Hrow + 1] [Hcol - 2]=dot;
if(grid[Hrow - 1] [Hcol + 2]==32)
grid[Hrow - 1] [Hcol + 2]=dot;
if(grid[Hrow - 1] [Hcol - 2]==32)
grid[Hrow - 1] [Hcol - 2]=dot;

	display(grid);
    
   grid[Hrow][Hcol]=32;





   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(grid[i][j]==dot){
            grid[i][j]=32;
        }
    }
   }
  
    cout << "Now enter row and column number of Rock (8x8 Grid)" << endl;

    while (true) {
        cin >> Hrow >> Hcol;
        if (Hrow >= 0 && Hrow <= 6 && Hcol >= 0 && Hcol <= 6 && Hrow - 0 != dot && Hcol != dot && Hrow - 1 != dot && Hcol + 1 != dot && Hrow != dot && Hcol + 1 != dot && Hrow != dot && Hcol - 1 != dot && Hrow + 1 != dot && Hcol - 1 != dot && Hrow + 1 != dot && Hcol != dot && Hrow + 1 != dot && Hcol + 1 != dot && Hrow - 1 != dot && Hcol - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
   grid[Hrow][Hcol]='H';
   
       display(grid);

}
void opponentknight(char grid[][8], int hrow, int hcol){


  int redColorCode = 12;
    int greenColorCode = 10;
    int blueColorCode = 9;
    int yellowColorCode = 14;
grid[hrow][hcol] = 'h';
grid[hrow + 2] [hcol+ 1]=dot;
if(grid[hrow + 2] [hcol - 1]==32)
grid[hrow + 2] [hcol - 1]=dot;
if(grid[hrow - 2] [hcol + 1]==32)
grid[hrow - 2] [hcol + 1]=dot;
if(grid[hrow - 2] [hcol - 1]==32)
grid[hrow - 2] [hcol - 1]=dot;
if(grid[hrow + 1] [hcol + 2]==32)
grid[hrow + 1] [hcol + 2]=dot;
if(grid[hrow + 1] [hcol - 2]==32)
grid[hrow + 1] [hcol - 2]=dot;
if(grid[hrow - 1] [hcol + 2]==32)
grid[hrow - 1] [hcol + 2]=dot;
if(grid[hrow - 1] [hcol - 2]==32)
grid[hrow - 1] [hcol - 2]=dot;
	display(grid);
    
   grid[hrow][hcol]=32;
   
if(grid[hrow + 2] [hcol+ 1]==32)






   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(grid[i][j]==dot){
            grid[i][j]=32;
        }
    }
   }
  
    cout << "Now enter row and column number of Rock (8x8 Grid)" << endl;

    while (true) {
        cin >> hrow >> hcol;
        if (hrow >= 0 && hrow <= 6 && hcol >= 0 && hcol <= 6 && hrow - 0 != dot && hcol != dot && hrow - 1 != dot && hcol + 1 != dot && hrow != dot && hcol + 1 != dot && hrow != dot && hcol - 1 != dot && hrow + 1 != dot && hcol - 1 != dot && hrow + 1 != dot && hcol != dot && hrow + 1 != dot && hcol + 1 != dot && hrow - 1 != dot && hcol - 1 != dot)
            break;
        else {
            cout << "Invalid row or column number, please re-enter." << endl;
        }
    }
   grid[hrow][hcol]='h';
   
       display(grid);



    
}

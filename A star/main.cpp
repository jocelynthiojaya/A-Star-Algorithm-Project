#include <iostream>
using namespace std;
#include "Header.h"

void printGrid(vector<vector<int>> grid)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == 0) {
                cout << "# ";    //to print walls
            }
            else if (grid[i][j] == 1){
                cout << ". ";    //to print the remaining areas
            }
        }
        cout << "\n";
    }
}


// Driver program to test above function
int main()
{
    int xcoord = 0;
    int ycoord = 0;
    string answ;
    
    Pair src = make_pair(0,0);
    Pair dest = make_pair(10,10);
    
    /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
    while (true) {
    	cout << "Enter number of rows<at least 5>: ";
    	cin >> ROW;
    	if (ROW >= 5) {
    		while (true) {
    			cout << "\nEnter number of columns<at least 5>: ";
    			cin >> COL;
    			if (COL >= 5) {
    				break;
				} else {
					cout << "Please enter the correct number of columns." << endl;
				}
			}
			break;
		} else {
			cout << "Please enter the correct number of rows." << endl;
		}
	}
	
    
    vector<int> rows(COL);
    vector<vector<int>> grid;
    
    fill(rows.begin(), rows.end(), 1);
    for (int i=0; i<ROW; i++) {
        grid.push_back(rows);
    }
    
    printGrid(grid);
    
    while (true)
    {
        cout << "Do you want to block some points?<yes/no>: ";
        cin >> answ;
        if (answ == "yes")
        {
            cout << "Please write the Y coordinate to block: ";
            cin >> ycoord;
            cout << "Please write the X coordinate to block: ";
            cin >> xcoord;
            if ((ycoord >= 0 && ycoord < ROW)&&(xcoord >=0 && xcoord < COL))
            {
              grid[ycoord][xcoord] =0;
                printGrid(grid);
            }
            else{
                cout << "Please input a valid coordinate\n";
            }
        }
        else if (answ == "no")
        {
            break;
        }
        else
        {
            cout << "Please input a valid answer!"<<endl;
        }
    }
    
  //Declare the coordinate for the source and also end point as
  // a global variable so we can access it outside the if condition
    int xsource = 0;
    int ysource = 0;
    int xend = 0;
    int yend = 0;
    while (true){
    // Source is the left-most bottom-most corner
    // create the coordinate for the source
    cout << "Coordinate Y of the source point: ";
    cin >> ysource;
    if (ysource < ROW && ysource >=0)
     {
         break;
     }
    else
    {
        cout << "Y source point is not valid." << endl;
    }
    }
    while (true)
    {
         cout << "Coordinate X of the source point: ";
         cin >> xsource;
        if (xsource < COL && xsource >=0)
        {
            break;
        }
        else
        {
            cout << "X source point is not valid." << endl;
        
        }
    }
    src = make_pair(ysource, xsource);
    

  
    // Create the coordinate for the end point.
    while (true)
    {
    cout << "Coordinate Y of the end point: ";
    cin >> yend;
    if (yend < ROW && yend >=0)
     {
         break;
     }
    else {
            cout << "Y end point is not valid." << endl;
        }
    }
    
    while (true)
    {
         cout << "Coordinate X point of the end: ";
         cin >> xend;
        if (xend < COL && xend >=0)
        {
            break;
        }
        else
        {
            cout << "X end point is not valid." << endl;
        }
     }
     
    dest = make_pair(yend, xend);
    
    aStarSearch(grid, src, dest);
    
    printMap(grid);

    return(0);


    }
    



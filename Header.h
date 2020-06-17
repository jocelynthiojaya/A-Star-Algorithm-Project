//  Header.h

//  Created by christy natalia, aimee putri, jocelyn thiojaya on 04/06/20.

// A C++ Program to implement A* Search Algorithm
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

int ROW;
int COL;
  
// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;
  
// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int>> pPair;
  
// A structure to hold the neccesary parameters
struct cell
{
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};
  
// A Utility Function to check whether given cell (row, col)
// is a valid cell or not.
bool isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
  
// A Utility Function to check whether the given cell is
// blocked or not
bool isUnBlocked(vector<vector<int>> grid, int row, int col)
{
    // Returns true if the cell is not blocked else false
    if (grid[row][col] == 1)
        return (true);
    else
        return (false);
}
  
// A Utility Function to check whether destination cell has
// been reached or not
bool isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
  
// A Utility Function to calculate the 'h' heuristics.
double calculateHValue(int row, int col, Pair dest)
{
    // Return using the distance formula
    return ((double)sqrt ((row-dest.first)*(row-dest.first)
                          + (col-dest.second)*(col-dest.second)));
}

//vectors to store the cell details of the pathway
vector<int> coordinates;
vector<vector<int>> pathway;

// A Utility Function to trace the path from the source
// to destination
void tracePath( vector<vector<cell>> cellDetails, Pair dest)
{
    cout << "\nThe Path is ";
    int row = dest.first;
    int col = dest.second;
  
    stack<Pair> Path;
  
    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col ))
    {
        Path.push (make_pair (row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
  
    Path.push (make_pair (row, col));
    while (!Path.empty())
    {
        pair<int,int> p = Path.top();
        Path.pop();
        cout << "-> (%d,%d)",p.first,p.second;
        
        //pushing the route coordinates to the pathway vector
        coordinates.push_back(p.first);
        coordinates.push_back(p.second);
        pathway.push_back(coordinates);
        coordinates.clear();
    }
    cout << "\n";
  
    return;
}

void printMap(vector<vector<int>> grid)
{
    grid[pathway[0][0]][pathway[0][1]] = 2;
    grid[pathway[pathway.size()-1][0]][pathway[pathway.size()-1][1]] = 3;
    
    for (int i = 1; i < pathway.size()-1; i++)
    {
        grid[pathway[i][0]][pathway[i][1]] = 4;
    }
    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == 0) {
                cout << "# ";    //to print walls
            } else if (grid[i][j] == 1) {
                cout << ". ";    //to print the remaining areas
            } else if (grid[i][j] == 2) {
                cout << "S ";    //to print the Start
            } else if (grid[i][j] == 3) {
                cout << "E ";    //to print the End
            } else {
                cout << "x ";    //to print the pathway
            }
        }
        cout << "\n";
    }
}
  

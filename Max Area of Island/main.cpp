/*BY::CEBASTIAN SANTIAGO
* LEETCODE 695
*/
#include<iostream>
#include<vector>


int dfs(std::vector<std::vector<int>>& grid,int row,int col){
	//outbounds check and if grid equal to 0
	if (row < 0 || row > grid.size() - 1 || col < 0 || col > grid[0].size() - 1 || grid[row][col] == 0) {
		return 0;
	}
	//mark as visited on the grid
	grid[row][col] = 0;
	
	//this call keeps track of the islands(1) since its going to skip the 
	//the if statement and mark the grid as 0 but will return 1 since at this 
	//point we know its an island and thats what the stack is going to return for 
	//up down left right
	return 1 + dfs(grid, row + 1, col) + dfs(grid, row - 1, col) + dfs(grid, row, col + 1) + dfs(grid, row, col - 1);
}



int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
	//variables
	int count = 0; 
	int max = 0;
	//for loop to loop through the grid
	for (int row = 0; row < grid.size(); row++) {
		for (int  col = 0; col < grid[row].size(); col++){
			//only care about counting the islands which are one
			if (grid[row][col] == 1) {
				count = dfs(grid, row, col);
				max = std::max(max, count);
				count = 0;
			}
		}
	}

	return max;
}


int main(int argc, char* argv[]) {
	std::vector<std::vector<int>> grid = { {0,0,1,0,0,0,0,1,0,0,0,0,0},
										   {0,0,0,0,0,0,0,1,1,1,0,0,0},
										   {0,1,1,0,1,0,0,0,0,0,0,0,0},
										   {0,1,0,0,1,1,0,0,1,0,1,0,0},
										   {0,1,0,0,1,1,0,0,1,1,1,0,0},
										   {0,0,0,0,0,0,0,0,0,0,1,0,0},
										   {0,0,0,0,0,0,0,1,1,1,0,0,0},
										   {0,0,0,0,0,0,0,1,1,0,0,0,0} };
	std::cout << maxAreaOfIsland(grid);

	return 0;
}
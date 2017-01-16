#include <iostream>
using namespace std;

class Maze{
	private:
	int **matrix;
	int rows;
	int columns;

	public:
	Maze(int noOfrows, int noOfcolumns){
		matrix = new int*[noOfrows];

		for(int i = 0; i < noOfrows; i++){
			matrix[i] = new int[noOfcolumns];
		}

		this->rows = noOfrows;
		this->columns = noOfcolumns;

		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				matrix[i][j] = 0;
			}
		}
	}

	bool isValidMove(int rowIndex, int columnIndex){
		return (rowIndex < rows && columnIndex < columns && matrix[rowIndex][columnIndex]);
	}

	void addValidBox(int rowIndex, int columnIndex){
		if(rowIndex < rows && columnIndex < columns){
			this->matrix[rowIndex][columnIndex] = 1;	
		}
		
	}

	void removeValidBox(int rowIndex, int columnIndex){
		
		if(rowIndex < rows && columnIndex < columns){
			this->matrix[rowIndex][columnIndex] = 0;	
		}
	}

	int** getMatrix(){
		return this->matrix;
	}

	int rowCount(){
		return this->rows;
	}

	int columnCount(){
		return this->columns;
	}
};

bool findPath(Maze maze, Maze path, int currentX, int currentY){
	
	// base case
	if(currentX == maze.rowCount()-1 && currentY == maze.columnCount()-1){
		return true;
	}

	if(maze.isValidMove(currentX, currentY)){

		path.addValidBox(currentX,currentY);
		//move down

		if(findPath(maze, path, currentX+1, currentY)){
			return true;
		}

		//move right
		if(findPath(maze, path, currentX, currentY+1)){
			return true;
		}
		
		path.removeValidBox(currentX, currentY);
		return false;
	}
	return false;
}


int main(){
	Maze maze(4,4);
	
	maze.addValidBox(0,0);
	maze.addValidBox(1,0);
	maze.addValidBox(1,1);
	maze.addValidBox(1,3);
	maze.addValidBox(2,1);
	maze.addValidBox(2,2);
	maze.addValidBox(3,0);
	maze.addValidBox(3,1);
	maze.addValidBox(3,2);
	maze.addValidBox(3,3);

	Maze path(4,4);
	int x = findPath(maze, path, 0, 0);

	for(int i = 0; i < path.rowCount(); i++){
		for(int j = 0; j < path.columnCount(); j++){
			cout << path.getMatrix()[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
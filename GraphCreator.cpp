//This is a graph creator that allows for addition and removal of vertices and edges
//Author: Kevin Lei
//Date: 5/31/2021


#include <iostream>
#include <cstring>

using namespace std;

//Function prototypes
void ADDVERTEX(int adjacencyMatrix[][20], char labels[], int & vertexCount);
void ADDEDGE(int adjacencyMatrix[][20], char labels[], int vertexCount);
void PRINT(int adjacencyMatrix[][20], char labels[], int vertexCount);
void REMOVEEDGE(int adjacencyMatrix[][20], char labels[], int vertexCount);
void REMOVEVERTEX(int adjacencyMatrix[][20], char labels[], int & vertexCount);

//Main function
int main() {

  int adjacencyMatrix[20][20];
  char labels[20];
  int vertexCount = 0;

  char input[20];

  cout << "Welcome to Graph Creator" << endl;

  while (strcmp(input, "QUIT") != 0) { //While loop will continue to run as long as user doesn't type QUIT
    cout << "Type ADDVERTEX, ADDEDGE, REMOVEVERTEX, REMOVEEDGE, PRINT, or QUIT" << endl;
    cin >> input;
    
    if (strcmp(input, "ADDVERTEX") == 0) { //Adds a vertex
      ADDVERTEX(adjacencyMatrix, labels, vertexCount);
    } else if (strcmp(input, "ADDEDGE") == 0) { //Adds an edge
      ADDEDGE(adjacencyMatrix, labels, vertexCount);
    } else if (strcmp(input, "REMOVEVERTEX") == 0) { //Removes a vertex and corresponding edges
      REMOVEVERTEX(adjacencyMatrix, labels, vertexCount);
    } else if (strcmp(input, "REMOVEEDGE") == 0) { //Removes an edge
      REMOVEEDGE(adjacencyMatrix, labels, vertexCount);
    } else if (strcmp(input, "PRINT") == 0) { //Prints the entire adjacency matrix
      PRINT(adjacencyMatrix, labels, vertexCount);
    } else if (strcmp(input, "QUIT") != 0) { //Invalid command
      cout << "Invalid command" << endl;
    }
  }

  cout << "Goodbye" << endl;
  
  return 0;
}

//Function adds a vertex to the adjacency matrix
void ADDVERTEX(int adjacencyMatrix[][20], char labels[], int & vertexCount) {
  char newLabel;
  cout << "Type the label for the new vertex" << endl;
  cout << "All labels must be a single character" << endl;
  cin >> newLabel;

  //Checking for if the vertex already exists
  for (int i = 0; i <= vertexCount; i++) {
    if (labels[i] == newLabel) {
      cout << "Vertex already exists" << endl;
      return;
    }
  }

  //Adds new vertex
  labels[vertexCount] = newLabel;
  for (int i = 0; i <= vertexCount; i++) {
    adjacencyMatrix[vertexCount][i] = -1;
    adjacencyMatrix[i][vertexCount] = -1;
  }

  vertexCount++;
}

//Function adds an edge to the adjacency matrix
void ADDEDGE(int adjacencyMatrix[][20], char labels[], int vertexCount) {
  char startVertex;
  char endVertex;
  int weight;
  bool vertexExists = false;
  int startVertexIndex;
  int endVertexIndex;

  cout << "Type the vertex where the edge starts" << endl;
  cin >> startVertex;

  //Checks for if the start vertex exists in the adjacency matrix
  for (int i = 0; i <= vertexCount; i++) {
    if (labels[i] == startVertex) {
      vertexExists = true;
      startVertexIndex = i;
    }
  }
  if (vertexExists == false) {
    cout << "Vertex does not exist" << endl;
    return;
  }
  vertexExists = false;
  
  cout << "Type the vertex where the edge ends" << endl;
  cin >> endVertex;

  //Checks for if the end vertex exists in the adjacency matrix
  for (int i = 0; i <= vertexCount; i++) {
    if (labels[i] == endVertex) {
      vertexExists = true;
      endVertexIndex = i;
    }
  }
  if (vertexExists == false) {
    cout << "Vertex does not exist" << endl;
    return;
  }
  vertexExists = false;
  
  cout << "Type the weight of the edge" << endl;
  cin >> weight;

  //Checks for if the weight is positive
  if (weight <= 0) {
    cout << "Only positive weights allowed" << endl;
    return;
  }

  //Adds the edge to the adjacency matrix
  adjacencyMatrix[startVertexIndex][endVertexIndex] = weight;
}

//Function displays the adjacency matrix
void PRINT(int adjacencyMatrix[][20], char labels[], int vertexCount) {
  for (int i = 0; i < vertexCount; i++) {
    cout << '\t' << labels[i];
  }
  cout << endl;
  for (int i = 0; i < vertexCount; i++) {
    cout << labels[i] << '\t';
    for (int j = 0; j < vertexCount; j++) {
      if (adjacencyMatrix[i][j] == -1) {
	cout << "-" << '\t';
      } else {
	cout << adjacencyMatrix[i][j] << '\t';
      }
    }
    cout << endl;
  }
}

//Function removes an edge from the adjacency matrix
void REMOVEEDGE(int adjacencyMatrix[][20], char labels[], int vertexCount) {
  char startVertex;
  char endVertex;
  bool vertexExists = false;
  int startVertexIndex;
  int endVertexIndex;

  cout << "Type the vertex where the edge to be deleted starts" << endl;
  cin >> startVertex;

  //Checks for if the start vertex exists in the adjacency matrix
  for (int i = 0; i <= vertexCount; i++) {
    if (labels[i] == startVertex) {
      vertexExists = true;
      startVertexIndex = i;
    }
  }
  if (vertexExists == false) {
    cout << "Vertex does not exist" << endl;
    return;
  }
  vertexExists = false;
  
  cout << "Type the vertex where the edge to be deleted ends" << endl;
  cin >> endVertex;

  //Checks for if the end vertex exists in the adjacency matrix
  for (int i = 0; i <= vertexCount; i++) {
    if (labels[i] == endVertex) {
      vertexExists = true;
      endVertexIndex = i;
    }
  }
  if (vertexExists == false) {
    cout << "Vertex does not exist" << endl;
    return;
  }
  vertexExists = false;

  //Checks for if the edge exists in the adjacency matrix
  if (adjacencyMatrix[startVertexIndex][endVertexIndex] == -1) {
    cout << "Edge does not exist" << endl;
    return;
  }

  //Removes the edge from the adjacency matrix
  adjacencyMatrix[startVertexIndex][endVertexIndex] = -1;
}

//Function removes a vertex from the adjacency matrix
void REMOVEVERTEX(int adjacencyMatrix[][20], char labels[], int & vertexCount) {
  char toDeleteLabel;
  int toDeleteIndex;
  bool vertexExists = false;
  
  cout << "Type the label of the vertex to be deleted" << endl;
  cin >> toDeleteLabel;

  //Checks for if the vertex exists in the adjacency matrix
  for (int i = 0; i <= vertexCount; i++) {
    if (labels[i] == toDeleteLabel) {
      vertexExists = true;
      toDeleteIndex = i;
    }
  }
  if (vertexExists == false) {
    cout << "Vertex does not exist" << endl;
    return;
  }

  //Removes the vertex label from the array of labels
  for (int i = 0; i < vertexCount; i++) {
    if (i >= toDeleteIndex) {
      labels[i] = labels[i+1];
    }
  }

  //Removes the vertex from the adjacency matrix
  while (toDeleteIndex < vertexCount) {
    //Shifts row left
    for (int i = 0; i < vertexCount; i++) {
      adjacencyMatrix[i][toDeleteIndex] = adjacencyMatrix[i][toDeleteIndex + 1];
    }
    //Shifts columns up
    for (int i = 0; i < vertexCount; i++) {
      adjacencyMatrix[toDeleteIndex][i] = adjacencyMatrix[toDeleteIndex + 1][i];
    }
    toDeleteIndex++;
  }

  //Decreases the count of vertices
  vertexCount--;
}

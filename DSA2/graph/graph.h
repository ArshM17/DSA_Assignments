void createAdjacencyMatrix(int*** matrix_ptr, FILE* file, int vertexCount);

void displayGraph(int** matrix, int vertexCount);

void displayVertexDegrees(int** matrix, int vertexCount);

int isAdjacent(int** matrix, int a, int b);

int countComponents(int** matrix, int vertexCount);

int explore(int*** matrix, int vertex, int vertexCount);

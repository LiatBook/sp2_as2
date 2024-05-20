#include "Graph.hpp"
using std::vector;
using std::string;
using namespace ariel;



    void Graph::loadGraph(const std::vector<std::vector<int>> new_g) {
        if(new_g.empty() ){
        throw std:: invalid_argument("Error in load this grapf");
        }
        for(size_t i = 0 ;i <new_g.size();i++){
            if (new_g.size() != new_g[i].size() ) {
        throw std:: invalid_argument("Error in load this grapf");
    }
        }
    if (new_g.size() != new_g[0].size() || new_g.empty() ) {
        throw std:: invalid_argument("Error in load this grapf");
    }
    size=g.size();
    this->g = new_g; // Assign the provided adjacency matrix to the graph
    this->symmetric=true;
    this->weighted=false;
        for (size_t i = 0; i < g.size(); i++) {
            for (size_t j = 0; j < g[i].size(); j++) {
                if(g[i][i] != 0){
                    throw std:: invalid_argument("The distance from a vertex to itself must be 0");
                }
                if(g[i][j] != g[j][i]){
                    this->symmetric=false;//graph directed
                }
                if(g[i][j]!=0 && g[i][j]!=1){
                    this->weighted=true;
                }
                if(this->weighted==true && this->symmetric==false){
                    return;
                }
            }
        }

    }


void  const Graph::printGraph(){
    int edges=0;
    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g[i].size(); ++j) {
            if(g[i][j] != 0){
                edges++;
            }
        
        }
    }
    if(getSymmetricMat()){
        edges=edges/2;
    }
    std:: cout << "Graph with " << g.size() << " vertices and " << edges << " edges." << std :: endl;
        // printf("Graph with %d vertices and %d edges.",size,edges);
    }

    std:: vector <std:: vector<int>> Graph :: getGraph() const{
        return this -> g;
    }
     bool Graph :: getSymmetricMat() const{
        return this -> symmetric;
     
    }
     bool Graph :: getWeighted() const{
        return this -> weighted;
     
    }

    void Graph::error(const Graph& other){
         // Check if graphs have the same dimensions
      if (g.size() != other.getGraph().size() || g[0].size() != other.getGraph()[0].size()) {
         throw string("The graphs must have the same dimensions.");
      }
        
    }


Graph& Graph::operator+=(const Graph& other)
    {
   // Check if graphs have the same dimensions
      error(other);
      //I ckecked if square matrix in func- loadGraph

    // Change g to result graph    
   for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) {
         g[i][j] = g[i][j] + other.getGraph()[i][j];
      }
   }
    return *this;
    
    }

Graph Graph::operator+(const Graph& other)
    {
   // Check if graphs have the same dimensions
      
      

    // Create a result graph
   Graph result;
   vector<vector<int>> g2(g.size(), vector<int>(g[0].size()));

   // Perform element-wise addition for corresponding elements in the graphs
   for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) {
         g2[i][j] = g[i][j] + other.getGraph()[i][j];
      }
   }

    // Load the result graph with the calculated element-wise addition
   result.loadGraph(g2);
   return result;
   }

Graph& Graph::operator+()
{
 return *this;
}
   
Graph& Graph::operator++( ){
        for (size_t i = 0; i < g.size(); ++i) 
        {
          for (size_t j = 0; j < g[0].size(); ++j) 
          { if(g[i][j]!=0)
            {
              g[i][j] = g[i][j] +1;
            }
          }
        }
         return *this;
    }

Graph Graph::operator*(const Graph& other)
   {
      if (g.size()!= other.getGraph()[0].size()) {
         throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix");
      }

        size_t num_rows = g.size();
        size_t num_cols = other.getGraph()[0].size(); // Assuming consistent number of columns in 'other'
        vector<vector<int>> g2(num_rows, vector<int>(g[0].size()));  
        
    
    for (size_t i = 0; i < num_rows; ++i) {
        for (size_t j = 0; j < num_cols; ++j) {
             g2[i][j]=0; // Set all elements to 0 initially
        }
    }

  // Perform matrix multiplication using nested loops
  for (size_t i = 0; i < num_rows; ++i) {
    for (size_t j = 0; j < num_cols; ++j) {
      for (size_t k = 0; k < num_rows; ++k) { // Iterate through intermediate vertices
            g2[i][j]= g2[i][j] + g[i][k] * other.getGraph()[k][j];
      }
    }
  }

//we want in diagonal have only 0's for legal graph 
for (size_t i = 0; i < num_rows; ++i)
{
  g2[i][i]=0;
}
Graph result;
result.loadGraph(g2);
return result;
}


Graph& Graph::operator*=(const Graph& other)
   {
      if (g.size()!= other.getGraph()[0].size()) {
         throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix");
      }

        size_t num_rows = g.size();
        size_t num_cols = other.getGraph()[0].size(); // Assuming consistent number of columns in 'other'
        vector<vector<int>> g2(num_rows, vector<int>(g[0].size()));  
        
    
    for (size_t i = 0; i < num_rows; ++i) {
        for (size_t j = 0; j < num_cols; ++j) {
             g2[i][j]=0; // Set all elements to 0 initially
        }
    }

  // Perform matrix multiplication using nested loops
  for (size_t i = 0; i < num_rows; ++i) {
    for (size_t j = 0; j < num_cols; ++j) {
      for (size_t k = 0; k < num_rows; ++k) { // Iterate through intermediate vertices
            g2[i][j]= g2[i][j] + g[i][k] * other.getGraph()[k][j];
      }
    }
  }

//we want in diagonal have only 0's for legal graph 
for (size_t i = 0; i < num_rows; ++i){
    for (size_t j = 0; j < num_cols; ++j) {
        g[i][j]=g2[i][j];
        g[i][i]=0;

    }
}
return *this;
}

Graph& Graph::operator*=(const double scalar)
   {
    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g[0].size(); ++j) {
            g[i][j] = scalar*g[i][j];
      }
   }
   return *this;
   }


Graph& Graph::operator/=(const double scalar){
if(scalar==0){
    throw string("must not divide 0");
}
for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) {
         g[i][j] = g[i][j]/scalar;
      }
   }
   return *this;

}

Graph Graph::operator-(const Graph& other)
    {
   // Check if graphs have the same dimensions
     error(other);
    

    // Create a result graph
   Graph result;
   vector<vector<int>> g2(g.size(),vector<int>(g[0].size()));

   // Perform element-wise addition for corresponding elements in the graphs
   for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) 
      {
         g2[i][j] = g[i][j] - other.getGraph()[i][j];
      }
   }
    result.loadGraph(g2);
  return result;
}

Graph& Graph::operator-=(const Graph& other)
{
   // Check if graphs have the same dimensions
      error(other);
 
   // Perform element-wise addition for corresponding elements in the graphs
   for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) {
         g[i][j] = g[i][j] - other.getGraph()[i][j];
      }
   }
    return *this;
}

Graph& Graph::operator-()
{
  return operator*=(-1);
}  

Graph& Graph::operator--(){ 
    for (size_t i = 0; i < g.size(); ++i) 
    {
        for (size_t j = 0; j < g[0].size(); ++j) 
          {
            if(g[i][j]!=0)
            g[i][j] = g[i][j] - 1;
          }
        }
    return *this;
}
Graph Graph::operator++(int){
    Graph copy=*this;
    ++(*this);
    return copy;
}
Graph Graph::operator--(int){
    Graph copy=*this;
    --(*this);
    return copy;
}
    
bool Graph::operator==(const Graph& other) const
{
    if (g.size() != other.getGraph().size() || g[0].size() != other.getGraph()[0].size()) 
    {
            return false;
    }
    if(isSubmatrix(g,other.getGraph()) && isSubmatrix(other.getGraph(),g)){
        return true;
    }
    return false;
}

bool Graph::operator!=(const Graph& other) const
{
  if(*this==other)
  {
    return false;
  }
  return true;
}

size_t Graph::countEdges() const {
        bool sym=true;
        size_t count = 0;
        for (size_t i = 0; i < g.size(); ++i) 
         {
            for (size_t j = 0; j < g[0].size(); ++j) 
             {
                if (g[i][j] != 0) {
                    count++;
                }
                if(g[i][j] != g[j][i]){
                    sym=false;
                }
            }
        }
        if(sym){
            count=count/2;
        }
        return count;
    }

bool Graph::isSubmatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) const{
    size_t n = A.size();
    size_t m = B.size();

    if (n > m) {
        return false; // A cannot be contained in B if A is larger
    }

    // Iterate through each possible position in B to place the top-left corner of A
    for (size_t i = 0; i <= m - n; ++i) {
        for (size_t j = 0; j <= m - n; ++j) {
            bool match = true;
            // Check if A matches B at position (i, j)
            for (size_t x = 0; x < n && match; ++x) {
                for (size_t y = 0; y < n && match; ++y) {
                    if (A[x][y] != B[i + x][j + y] && A[x][y] !=0) {
                        match = false;
                    }
                }
            }
            if (match) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::operator<(const Graph& other) const {
    if(isSubmatrix(this->getGraph(),other.getGraph())){
        return true;
    }
    if(isSubmatrix(other.getGraph(),this->getGraph())){
        return false;
    }
    size_t edgesCountG1 = this->countEdges(); 
    size_t edgesCountG2 = other.countEdges();
    if (edgesCountG1 < edgesCountG2) {
        return true;
        }
    if (edgesCountG2 == edgesCountG1) {
     // Compare the order of magnitude of the representative matrix
        if (this->getGraph().size()<other.getGraph().size()) {
            return true;
        }
    }
    return false;
}
    
bool Graph::operator<=(const Graph& other) const{
 return( *this==other)||(*this<other);
}

bool Graph::operator>(const Graph& other) const{
    return (!(*this<=other));
}

bool Graph::operator>=(const Graph& other) const{
  return (*this==other)||(*this>other);
}





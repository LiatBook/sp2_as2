#include <vector>
#include <iostream>
#pragma once
namespace ariel{
class Graph{

    private:
    std:: vector <std:: vector<int>> g;
    int size;
    bool symmetric;
    bool weighted;


    public:
    void loadGraph(const std:: vector <std:: vector<int>>);//func of object graph
    void const printGraph(); //func of object graph
    // pahad elokim ishmor at oi va'avoi temperatura hazaya hashemesh asta li tov.
    std:: vector <std:: vector<int>> getGraph() const;
    bool getSymmetricMat() const;
    bool getWeighted() const;
    void error(const Graph& other);
    size_t countEdges() const ;
    Graph& operator*=(const double scalar);
    Graph& operator*=(const Graph& other);
    Graph& operator+=(const Graph& other);
   Graph operator+(const Graph& other);
   Graph& operator+();
   Graph operator*(const Graph& other);
   Graph& operator/=(const double scalar);
   Graph operator-(const Graph& other);
   Graph& operator-();
   Graph& operator-=(const Graph& other);
   Graph& operator++();
   Graph& operator--();
   Graph operator++(int);
   Graph operator--(int);
   bool operator==(const Graph& other) const;
   bool operator!=(const Graph& other) const;
   bool isSubmatrix(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) const;
   bool operator<(const Graph& other) const;
   bool operator<=(const Graph& other) const;
   bool operator>(const Graph& other) const;
   bool operator>=(const Graph& other) const;
   friend std::ostream& operator<<(std::ostream& os,const Graph& g1)
   {
        
        for (size_t i = 0; i < g1.getGraph().size(); ++i) 
        {
            os << "[";
            for (size_t j = 0; j < g1.getGraph()[i].size(); ++j)
             {
                os << g1.getGraph()[i][j];
                if (j < g1.getGraph()[i].size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            if (i < g1.getGraph().size() - 1) {
                os << ", ";
            }
        }
        os<<std::endl;
        return os;
    }   

     };
};


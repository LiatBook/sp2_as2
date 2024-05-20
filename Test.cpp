//212736417
//bookliat@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using std::vector;


TEST_CASE("Count edges") {
    ariel:: Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);
    CHECK(g1.countEdges() == 2);

     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);
    CHECK(g2.countEdges() == 3);

    //test loadGraph
      ariel::Graph g3;
    std::vector<std::vector<int>> graph3 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    CHECK_THROWS(g3.loadGraph(graph3));
   
}

TEST_CASE("Scalar multiplication") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);
    g1 *= 2;
    std::vector<std::vector<int>> result = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    CHECK(g1.getGraph() == result);
    g1 *= -1;
    std::vector<std::vector<int>> result2 = {
        {0, -2, 0},
        {-2, 0, -2},
        {0, -2, 0}
    };
    CHECK(g1.getGraph() == result2);
}

TEST_CASE("Graph multiplication") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

     ariel::Graph g3;
    std::vector<std::vector<int>> expectedResult = {
        {0, 0, 3},
        {1, 0, 1},
        {2, 0, 0}
    };
    g3 = g1 * g2;
    CHECK(g3.getGraph() == expectedResult);
}

TEST_CASE("Graph addition") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 5, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, -2, 1},
        {2, 0, 3},
        {1, 3, -0}
    };
    g2.loadGraph(graph2);

     ariel::Graph g3;
    std::vector<std::vector<int>> expectedResult = {
        {0, 3, 1},
        {3, 0, 4},
        {1, 4, 0}
    };
    g3 = g1 + g2;
    CHECK(g3.getGraph() == expectedResult);
}

TEST_CASE("Graph addition assignment") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, -1 , -0},
        {1, 0, -1},
        {-0, -1, -0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, +2, 1},
        {2, 0, -3},
        {1, -3, 0}
    };
    g2.loadGraph(graph2);

    g1 += g2;
    std::vector<std::vector<int>> expectedResult = {
        {0, 1, 1},
        {3, 0, -4},
        {1, -4, 0}
    };
    CHECK(g1.getGraph() == expectedResult);
}

TEST_CASE("Graph subtraction") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

     ariel::Graph g3;
    std::vector<std::vector<int>> expectedResult = {
        {0, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}
    };
    g3 = g1 - g2;
    CHECK(g3.getGraph() == expectedResult);
     ariel::Graph g4;
    std::vector<std::vector<int>> graph4 = {
        {0, -1},
        {-1, 0}
    };
    g4.loadGraph(graph4);
    CHECK_THROWS(g3 - g4);

}

TEST_CASE("Graph subtraction assignment") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

    g1 -= g2;
    std::vector<std::vector<int>> expectedResult = {
        {0, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}
    };
    CHECK(g1.getGraph() == expectedResult);
}

TEST_CASE("Graph increment and decrement") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ++g1;
    std::vector<std::vector<int>> incrementResult = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    CHECK(g1.getGraph() == incrementResult);

    --g1;
    CHECK(g1.getGraph() == graph1);
     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g2.loadGraph(graph2);
    ++g2;
    CHECK(g2.getGraph() == graph2);
    --g2;
    CHECK(g2.getGraph() == graph2);

}

TEST_CASE("Graph division") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    g1 /= 2;
    std::vector<std::vector<int>> divisionResult = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    CHECK(g1.getGraph() == divisionResult);
    CHECK_THROWS(g1 /=0);
}

TEST_CASE("Submatrix check") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    std::vector<std::vector<int>> submatrix = {
        {0, 1},
        {1, 0}
    };
    std::vector<std::vector<int>> submatrix2 = {
        {0, 0},
        {1, 0}
    };
    CHECK(g1.isSubmatrix(graph1, submatrix) == false);
    CHECK(g1.isSubmatrix(submatrix,graph1) == true);
    CHECK(g1.isSubmatrix(submatrix2,submatrix) == true);
}

TEST_CASE("Equality and inequality") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    g2.loadGraph(graph1);
    CHECK(g1 == g2);
    CHECK_FALSE(g1 != g2);

     ariel::Graph g3;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g3.loadGraph(graph2);
    CHECK(g1 != g3);
}

TEST_CASE("Comparison operators") {
     ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);
    
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2},
        {2, 0}
    };
    g3.loadGraph(graph3);
    
  
    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK(g2 > g1);
    CHECK(g2 >= g1);
    CHECK_FALSE(g2 == g1);
    CHECK(g1 > g3);
    CHECK_FALSE(g1 <= g3);
    CHECK(g2 > g3);
    CHECK_FALSE(g3 >= g1);
}
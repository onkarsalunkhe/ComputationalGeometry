
#include <iostream>
#include <vector>
using namespace std;

int main() {

    class Face;
    class Edge
    {
        Face faces_[2];
    };
    class Face
    {
        Edge  edges_[];
    };
    class Body
    {

        Body copy() const
        {

        }
    };

}
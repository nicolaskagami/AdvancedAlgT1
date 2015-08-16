
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

typedef struct FSedge
{
    unsigned target;
    unsigned weight;
}EDGE;
typedef struct FSvert
{
    unsigned index;
    unsigned edgeNum;
}VERT;

class FSgraph
{
    public:
        EDGE * edges;
        VERT * vertices;//indexed by i-1
        unsigned currentEdge;
        unsigned currentVert;
        unsigned numEdges;
        unsigned numVerts;

        FSgraph(unsigned vertNum, unsigned edgeNum);
        FSgraph(std::istream& in);
        void preallocate(unsigned vert, unsigned tgt);
        void indexify();
        ~FSgraph();
        void addEdge(unsigned vert,unsigned tgt,unsigned wht);
        void print();
        
};

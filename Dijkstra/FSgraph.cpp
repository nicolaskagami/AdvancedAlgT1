
#include "FSgraph.h"


FSgraph::FSgraph(unsigned vertNum, unsigned edgeNum)
{
    numEdges = edgeNum;
    numVerts = vertNum;
    currentEdge = 0;
    currentVert = 0;
    edges = (EDGE*) malloc(sizeof(EDGE)*edgeNum);
    vertices = (VERT*) malloc(sizeof(VERT)*vertNum);
}
FSgraph::FSgraph(std::istream& in)
{
    std::string line="", dummy;
    unsigned n,m;

    while (line.substr(0,4) != "p sp")
    {
        getline(in,line);
        //std::cout << line << endl;
    }
    std::stringstream linestr;
    linestr.str(line);
    linestr >> dummy >> dummy >> n >> m;

    //Init
    numVerts = n;
    numEdges = m;
    currentEdge = 0;
    currentVert = 0;
    edges = (EDGE*) malloc(sizeof(EDGE)*numEdges);
    vertices = (VERT*) malloc(sizeof(VERT)*numVerts);

    unsigned i =0;
    while (i<m)
    {
        if(!std::getline(in, line))
        {
            printf("Parsing Error\n");
            exit(1);
        }
        if (line.substr(0,2) == "a ") 
        {
            std::stringstream arc(line);
            unsigned u,v,w;
            char ac;
            arc >> ac >> u >> v >> w;
            addEdge(u,v,w);
            i++;
        }
    }

}
FSgraph::~FSgraph()
{
    free(edges);
    free(vertices);
}
void FSgraph::addEdge(unsigned vert,unsigned tgt,unsigned wht)
{
    //printf("Adding Edge %d %d %d\n",vert, tgt, wht);
    if(vert>numVerts)
    {
        printf("Invalid vertex\n");
        exit(1);
    }
    if(vert==currentVert)
    {
        vertices[vert-1].edgeNum++;
    }
    else
    {
        currentVert = vert;
        vertices[vert-1].index = currentEdge;
        vertices[vert-1].edgeNum = 1;
    }

    edges[currentEdge].target = tgt;    
    edges[currentEdge++].weight = wht;
}
void FSgraph::print()
{
    printf("Forward Star Graph\n");
    printf("Vertices: %d\n",numVerts);
    printf("Edges: %d\n",numEdges);
    for(unsigned i = 0;i<numVerts;i++)
    {
        printf("Vert %d",i+1);
        for(unsigned b = vertices[i].index,j=0;j<vertices[i].edgeNum;j++)
        {
            printf("\t %d %d",edges[b+j].target,edges[b+j].weight);
        }
        printf("\n");
    }
}

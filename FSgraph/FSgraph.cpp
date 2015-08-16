
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
    for(i=0;i<numVerts;i++)
    {
        vertices[i].edgeNum=0;
        vertices[i].index=0;
    }

    std::stringstream buffer;
    buffer << in.rdbuf();
    i=0;
    while (i<m)
    {
        if(!std::getline(buffer, line))
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
            //addEdge(u,v,w);
            //std::cout << u << " " <<  v << " " << w << std::endl;
            preallocate(u,v);
            i++;
        }
         
    }
    indexify();
    buffer.seekg(0);
    i=0;
    while (i<m)
    {
        if(!std::getline(buffer, line))
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
            //std::cout << u << " " <<  v << " " << w << std::endl;
            i++;
        }
    }

}
FSgraph::~FSgraph()
{
    free(edges);
    free(vertices);
}
void FSgraph::preallocate(unsigned vert, unsigned tgt)
{
    if(vert>numVerts)
    {
        printf("Invalid vertex\n");
        exit(1);
    }
    vertices[vert-1].edgeNum++;
}
void FSgraph::indexify()
{
    for(unsigned i = 0; i<(numVerts-1);i++)
    {
        vertices[i+1].index = vertices[i].index + vertices[i].edgeNum;
        vertices[i].edgeNum =0;
    }
    vertices[numVerts-1].edgeNum=0;
}
void FSgraph::addEdge(unsigned vert,unsigned tgt,unsigned wht)
{
    //printf("Adding Edge %d %d %d\n",vert, tgt, wht);
    if(vert>numVerts)
    {
        printf("Invalid vertex\n");
        exit(1);
    }
    unsigned ind = vertices[vert-1].index + vertices[vert-1].edgeNum;
    if(ind>numEdges)
    {
        printf("Invalid Edge\n");
        exit(1);
    }
    edges[ind].target = tgt;    
    edges[ind].weight = wht;
    vertices[vert-1].edgeNum++;
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

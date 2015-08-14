
#include "FSgraph.h"
#include "NHeap.h"
#include<fstream>
#include<sstream>
#include<cassert>

int main(int argc, char ** argv)
{
    assert(argc == 3);
    unsigned src = atoi(argv[1]);
    unsigned tgt = atoi(argv[2]);

    printf("N = %d\n",N);
    FSgraph graph(std::cin);

    bool * visited;
    visited = (bool *) calloc(graph.numVerts,sizeof(bool));
    unsigned * distances;
    distances = (unsigned *) calloc(graph.numVerts,sizeof(unsigned));
    NHeap<unsigned> nh;
    nh.insert(src,0);
    while(nh.occupation>0)
    {
        unsigned p = nh.getMin();
        unsigned value = nh.getMinValue();
        nh.deleteMin();
        //printf("Visiting %d\n",p);
        visited[p-1] = true;
        if(p == tgt) 
        {
            printf("Distance from %d to %d: %d\n",src,tgt,value);exit(0); 
            free(visited);
            free(distances);
        }
        for(unsigned b=graph.vertices[p-1].index,i=0;i<graph.vertices[p-1].edgeNum;i++)
        {
            unsigned neighbor = graph.edges[b+i].target;
            //printf("Neighbor: %d\n",neighbor);
            unsigned wht = graph.edges[b+i].weight;
            if(visited[neighbor-1])
            {
                if((value+wht)<distances[neighbor-1])
                {
                    distances[neighbor-1] = value+wht; 
                    nh.update(neighbor,value+wht);
                }
            }
            else
            {
                distances[neighbor-1] = value+wht; 
                nh.insert(neighbor,value+wht);
            }
        }
    }


    printf("Not found\n");
    free(visited);
    free(distances);
    exit(1);
}

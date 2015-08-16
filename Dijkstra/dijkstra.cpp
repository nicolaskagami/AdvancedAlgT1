
#include "../FSgraph/FSgraph.h"
#include "../NHeap/NHeap.h"
#include<fstream>
#include<sstream>
#include<cassert>
#include<chrono>


// Debug Variables
unsigned inserts = 0;
unsigned updates = 0;
unsigned deletes = 0;

int main(int argc, char ** argv)
{
    assert(argc == 3);
    unsigned src = atoi(argv[1]);
    unsigned tgt = atoi(argv[2]);

    FSgraph graph(std::cin);

    bool * visited;
    visited = (bool *) calloc(graph.numVerts,sizeof(bool));
    unsigned * distances;
    distances = (unsigned *) calloc(graph.numVerts,sizeof(unsigned));
    NHeap<unsigned> nh;

    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
    
    nh.insert(src,0);
    inserts++;
    distances[src-1]= 0;

    
    while(nh.occupation>0)
    {
        unsigned p = nh.getMin();
        unsigned value = nh.getMinValue();
        nh.deleteMin();
        deletes++;
        visited[p-1] = true;
        if(p == tgt) 
        {
            free(visited);
            free(distances);
            std::cerr << inserts << " " << deletes << " " << updates << " ";
            std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << std::endl;
            printf("%u\n",value);exit(0); 
        }
        for(unsigned b=graph.vertices[p-1].index,i=0;i<graph.vertices[p-1].edgeNum;i++)
        {
            unsigned neighbor = graph.edges[b+i].target;
            unsigned wht = graph.edges[b+i].weight;
            if(visited[neighbor-1])
            {
                if((value+wht)<(distances[neighbor-1]))
                {
                    visited[neighbor-1] = true;
                    distances[neighbor-1] = value+wht; 
                    nh.update(neighbor,value+wht);
                    updates++;
                }
            }
            else
            {
                visited[neighbor-1] = true;
                distances[neighbor-1] = value+wht; 
                nh.insert(neighbor,value+wht);
                inserts++;
            }
        }
    }


    std::cerr << inserts << " " << deletes << " " << updates << " ";
    std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << std::endl;
    printf("inf\n");
    free(visited);
    free(distances);
    exit(1);
}

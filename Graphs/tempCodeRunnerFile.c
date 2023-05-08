struct node* create(int vertex,int weight){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=vertex;
    newnode->weight=weight;
    newnode->next=NULL;

    return newnode;
}
struct graph* createGraph(int vertices){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->numvertices=vertices;
    g->adjlist=malloc(vertices* sizeof(struct node));
    for(int i=0;i<vertices;i++){
        g->adjlist[i]=NULL;
    }

    return g;

}
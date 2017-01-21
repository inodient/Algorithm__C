/*
 * AdjacencyListGraph.h
 *
 *  Created on: Jan 18, 2017
 *      Author: changhokang
 */

#ifndef GRAPH_ADJACENCYLISTGRAPH_H_
#define GRAPH_ADJACENCYLISTGRAPH_H_

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

typedef struct tagVertex{
	ElementType Data;
	int Index;
	int Visited;
	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
} Vertex;

typedef struct tagEdge{
	int Weight;
	struct tagVertex* From;
	struct tagVertex* Target;
	struct tagEdge* Next;
} Edge;

typedef struct tagGraph{
	struct tagVertex* Vertices;
	int VertexCount;
} Graph;




Graph* CreateGrpah();
void DestroyGraph( Graph* _G );

Vertex* CreateVertex( ElementType NewData );
void DestroyVertex( Vertex* _V );

Edge* CreateEdge( Vertex* From, Vertex* Target, int Weight );
void DestroyEdge( Edge* _E );

void AddVertex( Graph* G, Vertex* V );
void AddEdge( Vertex* V, Edge* E );

void PrintGraph( Graph* G );

#endif /* GRAPH_ADJACENCYLISTGRAPH_H_ */

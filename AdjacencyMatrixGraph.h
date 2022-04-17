#pragma once
#include "Exception.h"
#include "Graph.h"

template <typename VertexType, typename EdgeType>
class AdjacencyMatrixGraph : public Graph<VertexType, EdgeType>
{
private:
	EdgeType** edge;
	VertexType* vertex;
	EdgeType empty_edge;
	int position(VertexType x) const;
public:
	AdjacencyMatrixGraph(int number_of_vertex, const VertexType origin_vertex_list[], const EdgeType empty_edge_flag);
	~AdjacencyMatrixGraph();
	void insert(VertexType x, VertexType y, EdgeType z);
	void remove(VertexType x, VertexType y);
	bool exist(VertexType x, VertexType y) const;
};

template<typename VertexType, typename EdgeType>
inline int AdjacencyMatrixGraph<VertexType, EdgeType>::position(VertexType x) const
{
	for (int i = 0; i < this->total_vertex; i++)
		if (vertex[i] == x)
			return i;
	return -1;
}

template<typename VertexType, typename EdgeType>
inline AdjacencyMatrixGraph<VertexType, EdgeType>::AdjacencyMatrixGraph(int number_of_vertex, const VertexType origin_vertex_list[], const EdgeType empty_edge_flag)
{
	this->total_vertex = number_of_vertex;
	this->total_edge = 0;
	empty_edge = empty_edge_flag;
	vertex = new VertexType[this->total_vertex];
	for (int i = 0; i < this->total_vertex; i++)
		vertex[i] = origin_vertex_list[i];
	edge = new EdgeType * [this->total_vertex];
	for (int i = 0; i < this->total_vertex; i++)
	{
		edge[i] = new EdgeType[this->total_vertex];
		for (int j = 0; j < this->total_vertex; j++)
			edge[i][j] = empty_edge;
		edge[i][i] = EdgeType(0);
	}
}

template<typename VertexType, typename EdgeType>
inline AdjacencyMatrixGraph<VertexType, EdgeType>::~AdjacencyMatrixGraph()
{
	delete[] vertex;
	for (int i = 0; i < this->total_vertex; i++)
		delete[] edge[i];
	delete edge;
}

template<typename VertexType, typename EdgeType>
inline void AdjacencyMatrixGraph<VertexType, EdgeType>::insert(VertexType x, VertexType y, EdgeType z)
{
	int u = position(x), v = position(y);
	if (u == -1 || v == -1)
		throw InvalidQuery("Error: Edge does not exist");
	edge[u][v] = z;
	this->total_edge++;
}

template<typename VertexType, typename EdgeType>
inline void AdjacencyMatrixGraph<VertexType, EdgeType>::remove(VertexType x, VertexType y)
{
	int u = position(x), v = position(y);
	if (u == -1 || v == -1)
		throw InvalidQuery("Error: Edge does not exist");
	edge[u][v] = empty_edge;
	this->total_edge--;
}

template<typename VertexType, typename EdgeType>
inline bool AdjacencyMatrixGraph<VertexType, EdgeType>::exist(VertexType x, VertexType y) const
{
	int u = position(x), v = position(y);
	if (u == -1 || v == -1)
		throw InvalidQuery("Error: Edge does not exist");
	return edge[u][v] != empty_edge;
}
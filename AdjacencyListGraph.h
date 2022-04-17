#pragma once
#include "Exception.h"
#include "Graph.h"

template <typename VertexType, typename EdgeType>
class AdjacencyListGraph : public Graph<VertexType, EdgeType>
{
private:
	struct EdgeNode
	{
		int target;
		EdgeType weight;
		EdgeNode* next;
		EdgeNode(int _target, EdgeType _weight, EdgeNode* _next = nullptr) :target(_target), weight(_weight), next(_next) {}
	};
	struct VertexNode
	{
		VertexType value;
		EdgeNode* head;
		VertexNode(EdgeNode* _head = nullptr) :head(_head) {}
		VertexNode(VertexType _value, EdgeNode* _head = nullptr) :value(_value), head(_head) {}
	};
	VertexNode* vertex;
	int position(VertexType x) const;
public:
	AdjacencyListGraph(int number_of_vertex, const VertexType origin_vertex_list[]);
	~AdjacencyListGraph();
	void insert(VertexType x, VertexType y, EdgeType z);
	void remove(VertexType x, VertexType y);
	bool exist(VertexType x, VertexType y) const;
};

template<typename VertexType, typename EdgeType>
inline int AdjacencyListGraph<VertexType, EdgeType>::position(VertexType x) const
{
	for (int i = 0; i < this->total_vertex; i++)
		if (vertex[i].value == x)
			return i;
	return -1;
}

template<typename VertexType, typename EdgeType>
inline AdjacencyListGraph<VertexType, EdgeType>::AdjacencyListGraph(int number_of_vertex, const VertexType origin_vertex_list[])
{
	this->total_vertex = number_of_vertex;
	this->total_edge = 0;
	vertex = new VertexNode[this->total_vertex];
	for (int i = 0; i < this->total_vertex; i++)
		vertex[i].value = origin_vertex_list[i];
}

template<typename VertexType, typename EdgeType>
inline AdjacencyListGraph<VertexType, EdgeType>::~AdjacencyListGraph()
{
	EdgeNode* p;
	for (int i = 0; i < this->total_vertex; i++)
		while ((p = vertex[i].head) != nullptr)
		{
			vertex[i].head = p->next;
			delete p;
		}
	delete[] vertex;
}

template<typename VertexType, typename EdgeType>
inline void AdjacencyListGraph<VertexType, EdgeType>::insert(VertexType x, VertexType y, EdgeType z)
{
	int u = position(x), v = position(y);
	vertex[u].head = new EdgeNode(v, z, vertex[u].head);
	this->total_edge++;
}

template<typename VertexType, typename EdgeType>
inline void AdjacencyListGraph<VertexType, EdgeType>::remove(VertexType x, VertexType y)
{
	int u = position(x), v = position(y);
	EdgeNode* p = vertex[u].head;
	if (p == nullptr)
		return;
	if (p->target == v)
	{
		vertex[u].head = p->next;
		delete p;
		this->total_edge--;
		return;
	}
	while (p->next != nullptr && p->next->target != v)
		p = p->next;
	if (p->next != nullptr)
	{
		EdgeNode* q = p->next;
		p->next = q->next;
		delete q;
		this->total_edge--;
	}
}

template<typename VertexType, typename EdgeType>
inline bool AdjacencyListGraph<VertexType, EdgeType>::exist(VertexType x, VertexType y) const
{
	int u = position(x), v = position(y);
	EdgeNode* p = vertex[u].head;
	while (p != nullptr && p->target != v)
		p = p->next;
	return p != nullptr;
}
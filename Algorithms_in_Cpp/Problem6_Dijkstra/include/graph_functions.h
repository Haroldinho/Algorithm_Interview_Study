/*
 * Graph helper functions
 */

#ifndef MY_GRAPH_H
#define MY_GRAPH_H
#include <string>
#include <map>
#include <vector>
#include <utility>

class Vertex{
	private:
		unsigned int _index;
		unsigned long _cost;
		unsigned int _pred_idx;
	public:
		Vertex(unsigned int pred_idx, unsigned int idx, unsigned long cost){
			_pred_idx = pred_idx;
			_index = idx;
			_cost = cost;
		};
		//Copy constructor
		Vertex(const Vertex &v){
			_index = v.get_index();
			_cost = v.get_cost();
			_pred_idx = v.get_predecessor();
		};
		
		unsigned int get_index() const {return _index;};
		unsigned long get_cost() const {return _cost;};
		unsigned int get_predecessor() const {return _pred_idx;};
		void set_index(unsigned int idx){_index=idx;};
		void set_cost(unsigned long cost){_cost = cost;};
		bool operator< (const Vertex& other_node) const
		{
			return (_cost > other_node._cost);
		}
};

class MyVertexComparator
{
public:
	bool operator() (const Vertex& lhs, const Vertex& rhs) const
	{
		return lhs.get_cost() > rhs.get_cost();
	}
};

typedef std::map<int, std::vector<Vertex>> AdjacencyGraph;

AdjacencyGraph read_input_adjacency_list(std::string file_name, int& num_nodes);

void show_graph(AdjacencyGraph graph_adj_list);

#endif

#ifndef QUADTREE_H
#define QUADTREE_H


class QuadTree
{
public:

	QuadTree();

	~QuadTree();

private:

	int const MaxBodies = 4;
	QuadTree* children;
};
#endif // !QUADTREE_H


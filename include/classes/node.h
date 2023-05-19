#ifndef NODE_H
#define NODE_H

#include <vector>

enum NodeType {
    Program,
    Statement,
    Expression
};

class Node {
    public:
        Node(NodeType type);

        void addChild(Node* child);
        NodeType getType() const;
        const std::vector<Node*>& getChildren() const;

    private:
        NodeType m_type;
        std::vector<Node*> m_children;
};

#endif  // NODE_H
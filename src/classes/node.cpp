#include "../../include/classes/node.h"

Node::Node(NodeType type) : m_type(type) {}

void Node::addChild(Node* child) {
    m_children.push_back(child);
}

NodeType Node::getType() const {
    return m_type;
}

const std::vector<Node*>& Node::getChildren() const {
    return m_children;
}
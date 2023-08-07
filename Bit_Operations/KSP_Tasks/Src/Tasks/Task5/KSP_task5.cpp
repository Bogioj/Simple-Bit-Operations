#include "KSP_task5.h"

Tree::Tree(const std::string& name) : name(name) {

}
Tree::~Tree() {
	for (Tree* child : children) {
		delete child;
	}
}

Tree* Tree::AddSub(const std::string& name) {
	Tree* sub = new Tree(name);
	children.push_back(sub);
	return sub;
}

uint32_t Tree::GetSubCount() const {
	return children.size();;
}

uint32_t Tree::GetAllSubCount() const {
	uint32_t count = children.size();
	for (Tree* child : children) {
		count += child->GetAllSubCount();
	}
	return count;
}

bool Tree::Del(uint32_t index) {
	if (index >= children.size()){
		return false;
	}
	delete children[index];
	children.erase(children.begin() + index);
	return true;
}

void Tree::print(uint32_t indent, bool printNumbers, std::string numbering) const {

	std::string indentStr(indent, ' ');	
	std::string prefix = printNumbers ? numbering + " " : "";			
	std::cout << indentStr << prefix << name << std::endl;
	for (int i = 0; i < children.size(); i++) {
		std::string childNumbering = numbering + (printNumbers ? std::to_string(i + 1) + "." : "");
		children[i]->print(indent + 2, printNumbers, childNumbering);
	}
}



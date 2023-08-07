#include "KSP_task4.h"

Tree4::Tree4(const std::string& name) : name(name) {

}
Tree4::~Tree4() {
	for (Tree4* child : children) {
		delete child;
	}
}

Tree4* Tree4::AddSub(const std::string& name) {
	Tree4* sub = new Tree4(name);
	children.push_back(sub);
	return sub;
}

uint32_t Tree4::GetSubCount() const {
	return children.size();;
}

uint32_t Tree4::GetAllSubCount() const {
	uint32_t count = children.size();
	for (Tree4* child : children) {
		count += child->GetAllSubCount();
	}
	return count;
}

bool Tree4::Del(uint32_t index) {
	if (index >= children.size()) {
		return false;
	}
	delete children[index];
	children.erase(children.begin() + index);
	return true;
}

void Tree4::print(uint32_t indent) const {
	std::string indentStr(indent, ' ');
	std::cout << indentStr << name << std::endl;
	for (Tree4* child : children) {
		child->print(indent + 2);
	}
}



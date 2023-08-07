#pragma once
#include <iostream>
#include <vector>
#include <string>

class Tree {

public:
	Tree(const std::string& name);
	~Tree();

	Tree* AddSub(const std::string& name);
	uint32_t GetSubCount() const;
	uint32_t GetAllSubCount() const;
	bool Del(uint32_t index);
	void print(uint32_t indent, bool printNumbers, std::string numbering) const;

private:
	std::string name;
	std::vector<Tree*> children;
};
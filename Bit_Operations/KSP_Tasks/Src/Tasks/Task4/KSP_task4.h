#pragma once
#include <iostream>
#include <vector>
#include <string>

class Tree4 {

public:
	Tree4(const std::string& name);
	~Tree4();

	Tree4* AddSub(const std::string& name);
	uint32_t GetSubCount() const;
	uint32_t GetAllSubCount() const;
	bool Del(uint32_t index);
	void print(uint32_t indent = 0) const;

private:
	std::string name;
	std::vector<Tree4*> children;
};
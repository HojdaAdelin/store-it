#pragma once

class Storing {

public:
	void AutoStore(std::string location);
	void CustomStore(std::string location, std::string file_type);
	void SetDefaultStore();
	void UseDefaultStore(std::string location);
 
};
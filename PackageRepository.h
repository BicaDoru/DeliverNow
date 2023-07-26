#pragma once
#include <vector>
#include "Package.h"
#include <fstream>
#include <sstream>

class PackageRepository
{
private:
	std::vector<Package> packages;
	std::string filename = "packages.txt";
public:
	PackageRepository();
	std::vector<Package> getAllPackages();
	void addPackage(Package p);
	Package parsePackage(std::string line);
	~PackageRepository() = default;
};


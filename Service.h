#pragma once
#include "PackageRepository.h"
#include "CourierRepository.h"

class Service
{
private:
	PackageRepository packageRepository;
	CourierRepository courierRepository;
public:
	Service(PackageRepository& packagerepository, CourierRepository& courierRepository);
	std::vector<Package> getAllPackages();
	std::vector<Courier> getAllCouriers();
	void addPackage(Package p);
	void addCourier(Courier c);
	~Service() = default;
};


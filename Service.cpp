#include "Service.h"

Service::Service(PackageRepository& packagerepository, CourierRepository& courierRepository)
{
    this->packageRepository = packagerepository;
	this->courierRepository = courierRepository;
}

std::vector<Package> Service::getAllPackages()
{
    return this->packageRepository.getAllPackages();
}

std::vector<Courier> Service::getAllCouriers()
{
    return this->courierRepository.getAllCouriers();
}

void Service::addPackage(Package p)
{
    packageRepository.addPackage(p);
}

void Service::addCourier(Courier c)
{
    courierRepository.addCourier(c);
}

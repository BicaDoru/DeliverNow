#include "DeliverNow.h"
#include "Courier.h"
#include "Service.h"
#include "CourierView.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    CourierRepository courierRepository;
    PackageRepository packageRepository;
    Service service{ packageRepository, courierRepository };
    std::vector<Package> packages = service.getAllPackages();
    auto couriers = service.getAllCouriers();

    if (couriers.empty()) {
        // Handle case when there are no couriers available
        return 0;
    }

    CourierView mainView(service, couriers[0], packages);
    mainView.setWindowTitle(QString::fromStdString(couriers[0].getName()));
    mainView.show();

    // Make a copy of the packages vector
    std::vector<Package> packagesCopy = packages;

    for (size_t i = 1; i < couriers.size(); ++i)
    {
        std::vector<Package> courierPackages;
        for (const auto& package : packagesCopy)
        {
            bool isInStreets = std::find(couriers[i].getStreets().begin(), couriers[i].getStreets().end(), package.getAddress()) != couriers[i].getStreets().end();
            bool isInZone = couriers[i].isWithinZone(package.getLocation());

            if (!package.getStatus() && (isInStreets || isInZone))
            {
                courierPackages.push_back(package);
            }
        }

        CourierView courierView(service, couriers[i], courierPackages);
        courierView.setWindowTitle(QString::fromStdString(couriers[i].getName()));
        courierView.show();
    }

    return a.exec();
}

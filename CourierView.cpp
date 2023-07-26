#include "CourierView.h"
#include "Courier.h"

CourierView::CourierView(Service& service, Courier& courier, std::vector<Package>& p, QWidget* parent)
    : QMainWindow(parent), service(service), courier(courier), packages(p), packagesList(nullptr)
{
    ui.setupUi(this);
    packagesList = ui.listWidget;
    setWindowTitle(QString::fromStdString(courier.getName()));

    QString zoneInfo = "Zone: Center(" + QString::number(courier.getZone().center) + "), Radius(" + QString::number(courier.getZone().radius) + ")";
    ui.label->setText(zoneInfo);

    populatePackagesList();
}

CourierView::~CourierView()
{
    // No need to manually delete packagesList since it's owned by the UI
}

void CourierView::populatePackagesList()
{
    packagesList->clear();
    for (const auto& package : packages)
    {
        bool isInStreets = std::find(courier.getStreets().begin(), courier.getStreets().end(), package.getAddress()) != courier.getStreets().end();
        bool isInZone = courier.isWithinZone(package.getLocation());

        if (!package.getStatus() && (isInStreets || isInZone))
        {
            std::string packageInfo = package.getRecipient() + " - " + package.getAddress();
            packagesList->addItem(QString::fromStdString(packageInfo));
        }
    }
}


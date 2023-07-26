#include <QMainWindow>
#include <QListWidget>
#include "ui_CourierView.h"
#include "Service.h"
#include "Courier.h"
#include <vector>

class CourierView : public QMainWindow
{
    Q_OBJECT

public:
    CourierView(Service& service, Courier& courier, std::vector<Package>& p, QWidget* parent = Q_NULLPTR);
    ~CourierView();
    void populatePackagesList();

private:
    Ui::CourierViewClass ui;
    Service& service;
    Courier& courier;
    std::vector<Package>& packages;
    QListWidget* packagesList;

};

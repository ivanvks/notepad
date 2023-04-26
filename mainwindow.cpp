#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr int kColumnsCount = 3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , model_{0, 3}
{
    ui_->setupUi(this);

    selection_model_.setModel(&model_);

    ui_->tableView->setModel(&model_);
    ui_->tableView->setSelectionModel(&selection_model_);
    ui_->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui_->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    model_.setHeaderData(0, Qt::Horizontal, "PC name");
    model_.setHeaderData(1, Qt::Horizontal, "IP address");
    model_.setHeaderData(2, Qt::Horizontal, "MAC address");

    model_.appendRow({new QStandardItem("PC1"), new QStandardItem("192.168.1.100"), new QStandardItem("F0:98:9D:00:00:00")});
    model_.appendRow({new QStandardItem("PC2"), new QStandardItem("192.168.1.101"), new QStandardItem("F0:98:9D:00:00:01")});

    connect(ui_->changeColorButton, &QPushButton::clicked, this, &MainWindow::onChangeColorButton);

    setWindowTitle("Offce PC table");
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::onChangeColorButton()
{
    if (selection_model_.hasSelection()) {
        auto selected_rows = selection_model_.selectedRows();
        for (const auto& index : selected_rows) {
            for (int i = 0; i < kColumnsCount; ++i) {
                auto item = model_.item(index.row(), i);
                item->setData(QColor(Qt::green), Qt::BackgroundRole);
            }
        }
    }
}


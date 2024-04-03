#include "myAppointments.h"
#include "ui_myAppointments.h"

MyAppointments::MyAppointments(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyAppointments)
{
    ui->setupUi(this);


    UsersData usersData;
    QJsonArray usersList = usersData.getArrayUsersData();
    QJsonArray appointments;

    for(int i = 0; i < usersList.size(); i++){
        QJsonObject user = usersList[i].toObject();
        if(user.contains("current")){
            appointments = user.value("appointment").toArray();
        }
    }

    for (int i = 0; i < appointments.size(); ++i) {
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI")});
        font1.setPointSize(15);

        QFrame *appointmentFrame = new QFrame(ui->appointments);
        appointmentFrame->setObjectName("appointment_" + QString::number(i + 1));
        appointmentFrame->setMinimumSize(QSize(465, 80));
        appointmentFrame->setMaximumSize(QSize(465, 80));
        appointmentFrame->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
                                                          "background-color: #626262;\n"
                                                          "padding: 8px 18px;\n"
                                                          ""));
        appointmentFrame->setFrameShape(QFrame::StyledPanel);
        appointmentFrame->setFrameShadow(QFrame::Raised);
        appointmentFrame->setLineWidth(0);

        QWidget *verticalLayoutWidget = new QWidget(appointmentFrame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget_" + QString::number(i + 1));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 441, 81));

        QWidget *horizontalLayoutWidget = new QWidget(appointmentFrame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget_" + QString::number(i + 1));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 441, 81));

        QVBoxLayout *verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout_" + QString::number(i + 1));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        QLabel *doctorLabel = new QLabel(verticalLayoutWidget);
        doctorLabel->setObjectName("doctor_" + QString::number(i + 1));
        doctorLabel->setFont(font1);
        doctorLabel->setMargin(-1);
        doctorLabel->setText("Doctor");

        QPushButton *delete_1 = new QPushButton(horizontalLayoutWidget);
        delete_1->setObjectName("delete_" + QString::number(i + 1));
        delete_1->setGeometry(QRect(170, 0, 25, 30));
        delete_1->setMinimumSize(QSize(25, 30));
        delete_1->setMaximumSize(QSize(25, 30));
        delete_1->setCursor(QCursor(Qt::PointingHandCursor));
        delete_1->setStyleSheet(QString::fromUtf8("background-image: url(:/recources/img/trash.png);\n"
                                                  "background-color: rgb(255, 255, 255, 0);\n"
                                                  "background-repeat: no-repeat;\n"
                                                  "border: none;"));

        QLabel *date_1 = new QLabel(verticalLayoutWidget);
        date_1->setObjectName("date_" + QString::number(i + 1));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(date_1->sizePolicy().hasHeightForWidth());
        date_1->setSizePolicy(sizePolicy);
        date_1->setMaximumSize(QSize(16777215, 30));
        date_1->setFont(font1);
        date_1->setMargin(-4);
        date_1->setText("Date");

        QLabel *time_1 = new QLabel(verticalLayoutWidget);
        time_1->setObjectName("time_" + QString::number(i + 1));
        time_1->setMaximumSize(QSize(16777215, 30));
        time_1->setFont(font1);
        time_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        time_1->setMargin(-4);
        time_1->setText("time");

        verticalLayout->addWidget(doctorLabel);
        verticalLayout->addWidget(date_1);
        verticalLayout->addWidget(time_1);
        verticalLayout->addWidget(delete_1);

        ui->verticalLayout_2->addWidget(appointmentFrame);
    }
}

MyAppointments::~MyAppointments()
{
    delete ui;
}

void MyAppointments::on_delete_1_clicked()
{
    ui->delete_1->destroyed();

    qDebug() << "ASD";
}


// void MyAppointments::on_pushButton_pressed()
// {
//     QFrame *appointmentFrame = ui->appointment_1;
//     appointmentFrame->setVisible(false);
// }

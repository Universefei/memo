#include "dialog.h"
#include "ui_dialog.h"
#include "myitem.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    // anti-aliasing
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //
    // The bounding rectangle of the scene
    // The scene rectangle defines the extent of the scene.
    // It is primarily used by QGraphicsView
    // to determine the view's default scrollable area,
    // and by QGraphicsScene to manage item indexing.
    // void	setSceneRect(qreal x, qreal y, qreal w, qreal h)
    scene->setSceneRect(-200, -200, 300, 300);

    QLineF topLine(scene->sceneRect().topLeft(),
                   scene->sceneRect().topRight());
    QLineF leftLine(scene->sceneRect().topLeft(),
                   scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(),
                   scene->sceneRect().bottomRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(),
                   scene->sceneRect().bottomRight());

    QPen myPen = QPen(Qt::red);

    scene->addLine(topLine, myPen);
    scene->addLine(leftLine, myPen);
    scene->addLine(rightLine, myPen);
    scene->addLine(bottomLine, myPen);

    // adding items to the scene
    int itemCount = 20;
    for(int i = 0; i < itemCount; i++)
    {
        MyItem *item = new MyItem();
        scene->addItem(item);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),scene, SLOT(advance()));
    timer->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}

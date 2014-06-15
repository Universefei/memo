#include "mouse.h"
#include <QtGui>
#include <math.h>

static const int MouseCount = 7;

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	qsrand( QTime(0,0,0).secsTo(QTime::currentTime()) );

	//  create QGraphicsScene
	QGraphicsScene scene;
	//scene.addLine( 0, 0, 300, 300); // draw roads
	scene.setSceneRect(-300, -300, 600, 600);
	scene.setItemIndexMethod( QGraphicsScene::NoIndex );
	//scene.addItem( trafficLight );

	//  add some mouse(cars) to scene
   	for (int i = 0; i < MouseCount; ++i) 
	{
		Mouse *mouse = new Mouse;
		//  set first appear position
		mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
						::cos((i * 6.28) / MouseCount) * 200);
		//  add mouse to scene layout
		scene.addItem( mouse );
	}

	//  create a view to display scene
	QGraphicsView view( &scene );
	view.setRenderHint( QPainter::Antialiasing );
	view.setBackgroundBrush( QPixmap(":/images/cheese.jpg") );
	view.setCacheMode( QGraphicsView::CacheBackground );
	view.setViewportUpdateMode( QGraphicsView::BoundingRectViewportUpdate );
	view.setDragMode( QGraphicsView::ScrollHandDrag );
	view.setWindowTitle( QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice") );

#if defined(Q_WS_S60) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
	view.showMaximized();
#else
	view.resize(400, 300);
	view.show();
#endif

	QTimer timer;
	//  advance is a slot, that process 2 steps, pass param 0 and 1 respectly
	QObject::connect( &timer, SIGNAL(timeout()), &scene, SLOT(advance()) );
	//  send timeout() singnal 33 times per sec.
	timer.start( 1000 / 33 );

	return app.exec();
}

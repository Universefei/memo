#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
 
int main( int argc, char **argv )
{
	QApplication app(argc, argv);
		 
	QGraphicsScene scene;
	// start point, width, height
	scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );
				 
	QGraphicsEllipseItem *item = new QGraphicsEllipseItem( 0, &scene );
	item->setRect( 0.0, 0.0, 100.0, 100.0 );
						 
	QGraphicsView view( &scene );
	view.setRenderHints( QPainter::Antialiasing );
	view.show();
									 
	return app.exec();
}

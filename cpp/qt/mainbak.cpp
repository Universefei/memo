#include <QtGui>
#include <math.h>
#include "car.h"

#include "carGenerator.h"


int main (int argc, char * argv[])
{
	QApplication app( argc, argv );
	
	//  Create QGraphicsScene
	QGraphicsScene scene;
	scene.setSceneRect( -600, -250, 1200, 500 );
	scene.setItemIndexMethod( QGraphicsScene::NoIndex );
	
	//  Draw road
	scene.addLine( -350, -150, -350, -100 );
	scene.addLine( -500, -100, -350, -100 );
	scene.addLine( -500, -50, -350, -50 );
	scene.addLine( -350, 150, -350, -50 );
	scene.addLine( -300, 150, -300, -50 );
	scene.addLine( -300, -150, -300, -100 );

	scene.addLine( -300, -100, 300, -100 );
	scene.addLine( -300, -50, 300, -50 );

	scene.addLine( 350, -150, 350, -100 );
	scene.addLine( 500, -100, 350, -100 );
	scene.addLine( 500, -50, 350, -50 );
	scene.addLine( 350, 150, 350, -50 );
	scene.addLine( 300, 150, 300, -50 );
	scene.addLine( 300, -150, 300, -100 );
	
	scene.addLine( -325, -100, -325, -150 );
	scene.addLine( -325, -50, -325, 150 );
	scene.addLine( 325, -100, 325, -150 );
	scene.addLine( 325, -50, 325, 150 );
	scene.addLine( -475, -75, -350, -75 );
	scene.addLine( -300, -75, 300, -75 );
	scene.addLine( 475, -75, 350, -75 );
	
	//  Road notation
	QGraphicsItem* ptext = scene.addText( "BSN" );
	ptext->setPos( -340, -180 );

	ptext = scene.addText( "BSS" );
	ptext->setPos( -340, 150 );

	ptext = scene.addText( "TBN" );
	ptext->setPos( 310, -180 );
	
	ptext = scene.addText( "TBS" );
	ptext->setPos( 310, 150 );
	
	ptext = scene.addText( "RHW" );
	ptext->setPos( -550, -85 );

	ptext = scene.addText( "RHE" );
	ptext->setPos( 510, -85 );

	//  Draw traffic lights

	//  Add cars to scene
	//Car *car = new Car;
	CarGenerator *pcargen = new CarGenerator( eBSN, -337.5, -150, Qt::blue );
	scene.addItem( pcargen );
	//car->setStartPos();


	//  Create QGraphicsView
	QGraphicsView view( &scene );
	view.setViewportUpdateMode( QGraphicsView::BoundingRectViewportUpdate );
	view.setWindowTitle( QT_TRANSLATE_NOOP(QGraphicsVIew, "Traffic simulation") );

	view.show();


	//  Set Timer
	QTimer timer;
	QObject::connect( &timer, SIGNAL(timeout()), &scene, SLOT(advance()) );
	timer.start( 1000/20 );
	
	return app.exec();
}

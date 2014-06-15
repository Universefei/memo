#include <QtGui>
#include <math.h>
#include "car.h"

#include "carFrom.h"
#include "carGenerator.h"
#include "trafficLight.h"
//#include "userDefines.h"

int main (int argc, char * argv[])
{
	QApplication app( argc, argv );
	qsrand( QTime( 0, 0, 0 ).secsTo( QTime::currentTime() ) );
	
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
	//  BSN
	QGraphicsTextItem bsn("BSN");
	bsn.setDefaultTextColor( pointColor[eBSN] );
	scene.addItem( &bsn );
	bsn.setPos( -340, -230 );
	//  BSS
	QGraphicsTextItem bss("BSS");
	bss.setDefaultTextColor( pointColor[eBSS] );
	scene.addItem( &bss );
	bss.setPos( -340, 200 );
	//  TBN
	QGraphicsTextItem tbn("TBN");
	tbn.setDefaultTextColor( pointColor[eTBN] );
	scene.addItem( &tbn );
	tbn.setPos( 310, -230 );
	//  TBS
	QGraphicsTextItem tbs("TBS");
	tbs.setDefaultTextColor( pointColor[eTBS] );
	scene.addItem( &tbs );
	tbs.setPos( 310, 200 );
	//  RHW
	QGraphicsTextItem rhw("RHW");
	rhw.setDefaultTextColor( pointColor[eRHW] );
	scene.addItem( &rhw );
	rhw.setPos( -580, -85 );
	//  RHE
	QGraphicsTextItem rhe("RHE");
	rhe.setDefaultTextColor( pointColor[eRHE] );
	scene.addItem( &rhe );
	rhe.setPos( 550, -85 );


	//  Draw traffic lights
	//TrafficLight* pLightatCr1 = &lightAtCr1;
	scene.addItem( pLightAtCr1);
	pLightAtCr1->setPos( cr1Center );
	//TrafficLight* pLightatCr2 = &lightAtCr2;
	scene.addItem( pLightAtCr2);
	pLightAtCr2->setPos( cr2Center );


	//  Add car generators to scene
	CarGenerator *pcargen; 
	//  Generator at BSN
	pcargen = new CarGenerator( eBSN, 1 );
	scene.addItem( pcargen );
	//  Generator at BSS
	pcargen = new CarGenerator( eBSS, 1 );
	scene.addItem( pcargen );
	//  Generator at TBN
	pcargen = new CarGenerator( eTBN, 1 );
	scene.addItem( pcargen );
	//  Generator at TBS
	pcargen = new CarGenerator( eTBS, 1 );
	scene.addItem( pcargen );
	//  Generator at RHW
	pcargen = new CarGenerator( eRHW, 2 );
	scene.addItem( pcargen );
	//  Generator at RHE
	pcargen = new CarGenerator( eRHE, 2 );
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
	timer.start( 1000/freq );
	
	return app.exec();
}

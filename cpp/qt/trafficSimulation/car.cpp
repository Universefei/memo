#include "car.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>
//#include "misc.h"


/*---------------------------------------------------------------------------*/
/*                                Constructor                                */
/*---------------------------------------------------------------------------*/
Car::Car() : speed(0.1), genPlace(eBSN), dist(eBSS)
{
	setRotation( 0 );
	setStartPos();

}

Car::Car( EPlace gen, EPlace dis, qreal fast ) :
	genPlace(gen), dist(dis), speed(fast)
{
	setStartPos();

}

Car::~Car() {
}
	
/*---------------------------------------------------------------------------*/
/*                                setStartPos                                */
/*---------------------------------------------------------------------------*/
void Car::setStartPos()
{
	//setPos( -337.5, -150 );
	setPos( startPoint[genPlace] );
	//setPos( -337.5, -87.5 );
}

/*---------------------------------------------------------------------------*/
/*                                 shape                                     */
/*---------------------------------------------------------------------------*/
QPainterPath Car::shape() const
{
	QPainterPath path;
	path.addRect( -2.5, -5, 5, 10 );
	return path;
}

/*---------------------------------------------------------------------------*/
/*                                boundingRect                               */
/*---------------------------------------------------------------------------*/
QRectF Car::boundingRect() const
{
	qreal adjust = 0.5;
	return QRectF( -2.5, -5 - adjust,
			5, 13 + adjust);
}


/*---------------------------------------------------------------------------*/
/*                                 paint                                     */
/*---------------------------------------------------------------------------*/
void Car::paint( QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	//  Car body
	painter->setBrush( pointColor[genPlace] );
	painter->drawRect( -3.5, -6, 7, 12 );

	//  Car front window
	painter->setBrush( pointColor[dist] );
	painter->drawRect( -3, 0.5, 6, 5 );

}

/*---------------------------------------------------------------------------*/
/*                                 ableToForward                             */
/*---------------------------------------------------------------------------*/
bool Car::ableToForward( TrafficLight* light, ELightDirct direct ) const
{
	QColor curColor = light->getLightStatus( direct );

	if ( curColor == trafficLightRed ) {
		return false;
	}
	else if ( curColor == trafficLightGreen ) {
		return true;
	}
}

/*---------------------------------------------------------------------------*/
/*                                 checkLightForward                         */
/*---------------------------------------------------------------------------*/
void Car::checkLightForward( ) 
{

    bool bForward = true;

	QPointF curLoc = mapToScene( 0, 0 );

	if ( curLoc == lightCr1BSN || curLoc == lightCr1BSS ) {
		if ( !ableToForward( pLightAtCr1, eNS ) ) {
		//if ( !pLightAtCr1->ableNS ) {
		//if ( pLightAtCr1->getLightStatus( eNS ) == trafficLightRed ) {
			//setPos( mapToParent( 0, 0.5 ) );
			bForward = false;
		}
		else {
			//setPos( mapToParent( 0, 0.5 ) );
			bForward = true;
		}

	}
	else if ( curLoc == lightCr1RHW || curLoc == lightCr1RHE ) {
		if ( !ableToForward( pLightAtCr1, eWE ) ) {
			//setPos( mapToParent( 0, 0.5 ) );
			bForward = false;
		}
		else {
			//setPos( mapToParent( 0, 0.5 ) );
			bForward = true;
		}
	}
	else if ( curLoc == lightCr2TBN || curLoc == lightCr2TBS ) {
		if ( !ableToForward( pLightAtCr2, eNS ) ) {
			bForward = false;
			//setPos( mapToParent( 0, 0.5 ) );
		}
		else {
			//setPos( mapToParent( 0, 0.5 ) );
			bForward = true;
		}
	}
	else if ( curLoc == lightCr2RHW || curLoc == lightCr2RHE ) {
		if ( !ableToForward( pLightAtCr2, eWE ) ) {
			bForward = false;
			//setPos( mapToParent( 0, 0.5 ) );
		}
		else {
			//setPos( mapToParent( 0, 0.5 ) );
			bForward = true;
		}
	}
	else {
		//setPos( mapToParent( 0, 0.5 ) );
		//*bForward = true;
	//}

		QPointF curLocFront = mapToScene( 0, 15 );
		QGraphicsItem* pfront = scene()->itemAt( curLocFront );
		if (pfront != 0) {
			bForward = false;
		}
		else {
			bForward = true;
		}
	}

    //  Go forward if bForward is ture
    if ( bForward ) {
		setPos( mapToParent( 0, 0.5 ) );
    }

}

/*---------------------------------------------------------------------------*/
/*                               turnDirection                               */
/*---------------------------------------------------------------------------*/
void Car::turnDirection()
{
}

/*---------------------------------------------------------------------------*/
/*                               advance                                     */
/*---------------------------------------------------------------------------*/
void Car::advance( int step )
{
	if(!step)
		return;

    //  How to turn, every derived class need reimplement this function;
    turnDirection();
	//  Check if this advance should go bForward.
	checkLightForward();
}

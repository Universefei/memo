#include "carGenerator.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

/*---------------------------------------------------------------------------*/
/*                               constructor                                 */
/*---------------------------------------------------------------------------*/
CarGenerator::CarGenerator() 
{
//	ticker = 59;
}

/*
CarGenerator::CarGenerator( EPlace place, qreal x, qreal y, QColor color) : 
	genPlace(place), genPoint(QPointF(x,y)), genColor(color), ticker(59)
{

}
*/

CarGenerator::CarGenerator( EPlace place, int heavy ) : 
	genPlace( place ), trafHeavy( heavy ) 
{
	ticker = 600/trafHeavy;
	placeSet();

}

/*---------------------------------------------------------------------------*/
/*                                placeSet                                   */
/*---------------------------------------------------------------------------*/
void CarGenerator::placeSet() 
{
	setPos( endPoint[genPlace] );
}

/*---------------------------------------------------------------------------*/
/*                                boundingRect                               */
/*---------------------------------------------------------------------------*/
QRectF CarGenerator::boundingRect() const
{
	return QRectF( 0, 0, 0, 0 );
}

/*---------------------------------------------------------------------------*/
/*                                paint                                      */
/*---------------------------------------------------------------------------*/
void CarGenerator::paint( QPainter* painter, const QStyleOptionGraphicsItem*, QWidget* )
{
	painter->setBrush( pointColor[genPlace] );
	painter->drawRect( -12.5, -12.5, 25, 25 );

}

/*---------------------------------------------------------------------------*/
/*                                shape                                      */
/*---------------------------------------------------------------------------*/
QPainterPath CarGenerator::shape() const
{
	QPainterPath path;
	//path.addRect( -12.5, -12.5, 25, 25 );
	path.addRect( 0, 0, 0, 0 );
	return path;
}

/*---------------------------------------------------------------------------*/
/*                                advance                                    */
/*---------------------------------------------------------------------------*/
void CarGenerator::advance( int step )
{
	if(!step)
		return;

	//  Counting and producing cars
	if(ticker == 600/trafHeavy) 
	{
		Car* pgotCar;
		if( genPlace == eBSN ) {
			pgotCar = new CarBSN( 0.1 );
		}
		else if ( genPlace == eBSS ) {
			pgotCar = new CarBSS( 0.1 );
		}
		else if ( genPlace == eTBN ) {
			pgotCar = new CarTBN( 0.1 );
		}
		else if ( genPlace == eTBS ) {
			pgotCar = new CarTBS( 0.1 );
		}
		else if ( genPlace == eRHW ) {
			pgotCar = new CarRHW( 0.1 );
		}
		else {
			pgotCar = new CarRHE(0.1 );
		}

		this->scene()->addItem( pgotCar );
		ticker = 1;
	}
	else
	{
		++ticker;
	}

	//  Detecting and clean cars that reach destination
	//QList<QGraphicsItem*> garbage = scene()->collidingItems(this);
	//QGraphicsItem* garbage = scene()->itemAt( mapToParent(0, -30));
	QList<QGraphicsItem*> items = scene()->items();
			//scene()->removeItem( garbage );
	//if (garbage != 0 ) {
		 //free(garbage);
	//}

	foreach (QGraphicsItem* item, items ) 
	{
		if ( item->mapToParent( 0, 0 ) == endPoint[genPlace] ) {
			if ( item != this ) {
				item->setPos( 1000, 1000 );
				//scene()->removeItem( ( Car *)item );
				//delete item;
			}
		}
	}

}


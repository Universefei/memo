#include "trafficLight.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>


/*---------------------------------------------------------------------------*/
/*                                Constructor                                */
/*---------------------------------------------------------------------------*/
TrafficLight::TrafficLight( int tik ) : ticker( tik * freq / speedUp ) 
{
	//if ( ticker >= 0 && ticker <= redTime * freq - 1 ) {
		/*
		colorNS = trafficLightRed;
		colorWE = trafficLightGreen;
		*/
		//ableNS = false;
		//flag = 0;
	//}
	//else {
		/*
		colorWE = trafficLightRed;
		colorNS = trafficLightGreen;
		*/
		//ableNS = true;
		//flag = 1;
	//}
}

/*---------------------------------------------------------------------------*/
/*                                 shape                                     */
/*---------------------------------------------------------------------------*/
//  Used for collision detection
QPainterPath TrafficLight::shape() const
{
	QPainterPath path;
	path.addRect( 0, 0, 0, 0 );
	return path;
}

/*---------------------------------------------------------------------------*/
/*                                boundingRect                               */
/*---------------------------------------------------------------------------*/
QRectF TrafficLight::boundingRect() const
{
	return QRectF( -26, -26 , 52, 52 );
}


/*---------------------------------------------------------------------------*/
/*                                 paint                                     */
/*---------------------------------------------------------------------------*/
void TrafficLight::paint( QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	//  drow north and west direction traffic lights 
	QColor nscolor = getLightStatus( eNS );
	painter->setBrush( nscolor );
	//painter->setBrush( colorNS );
	painter->drawRect( -25, -25, 25, 5 );
	painter->drawRect( 0, 20, 25, 5 );

	//  drow west and east direction traffic lights 
	QColor wecolor = getLightStatus( eWE );
	//painter->setBrush( colorWE );
	painter->setBrush( wecolor );
	painter->drawRect( -25, 0, 5, 25 );
	painter->drawRect( 20, -25, 5, 25 );
}

/*---------------------------------------------------------------------------*/
/*                                 getLightStatus                            */
/*---------------------------------------------------------------------------*/
QColor TrafficLight::getLightStatus( ELightDirct dirc ) volatile 
{
	if ( dirc == eNS ) 
	{
		if ( ticker >= 0 && ticker <= redTime * freq /speedUp - 1 ) {
			return trafficLightRed;
		}
		else {
			return trafficLightGreen;
		}
	}
	else {
		if ( ticker >= 0 && ticker <= redTime * freq / speedUp - 1 )
			return trafficLightGreen;
		else 
			return trafficLightRed;
	}
	/*
	if ( dirc == eNS ) 
	{
			return  colorNS;
	}
	else {
			return  colorWE;
	}
	*/

}

/*---------------------------------------------------------------------------*/
/*                                 advance                                   */
/*---------------------------------------------------------------------------*/
void TrafficLight::advance( int step )
{
	if ( !step )
		return;

	if ( ticker == 140 * freq / speedUp - 1)
	{
		ticker = 0;
		//colorNS = trafficLightRed;
		//colorWE = trafficLightGreen;
		//ableNS = false;
		//flag = 0;
	}
	/*
	else if ( ticker == redTime * freq -1 )
	{
		++ticker;
		//ableNS = true;
		//flag = 1;
		colorWE = trafficLightRed;
		colorNS = trafficLightGreen;
	}
*/
	else 
	{
		++ticker;
	}
}


#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include "misc.h"

//  Using template Design pattern in this class,
//  \ derived classes need reimplement virtual function turnDirection()

class Car: public QGraphicsItem
{
	public:
		Car();
		virtual ~Car();
		//Car( QPointF, QColor, EPlace );
		Car( EPlace, EPlace, qreal );

		QRectF boundingRect() const;
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
				QWidget *widget );

		QPainterPath shape() const;
		void setStartPos();



	protected:
		void advance( int step );

	public:
        virtual void turnDirection();

		bool ableToForward( TrafficLight*, ELightDirct ) const;
		void checkLightForward( ) ;

		EPlace genPlace;
		EPlace dist;
		qreal speed;

		//qreal ticker;

};

#endif // CAR_H

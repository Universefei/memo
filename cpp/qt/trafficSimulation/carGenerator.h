#ifndef CARGENERATOR_H
#define CARGENERATOR_H

#include <QGraphicsItem>
#include "misc.h"
#include "car.h"
#include "carFrom.h"

class CarGenerator : public QGraphicsItem
{
	public:
		CarGenerator();
		//CarGenerator( EPlace, qreal, qreal, QColor );
		CarGenerator( EPlace, int );
		
		QPainterPath shape() const;
		QRectF boundingRect() const;
		void paint( QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget );

		void placeSet();

	protected:
		void advance( int step );

	private:
		EPlace genPlace;
		//QPointF genPoint;
		//QColor genColor;
		int ticker;
		int trafHeavy;  //  traffic condition, car generating speed

};

#endif  // CARGENERATOR_H

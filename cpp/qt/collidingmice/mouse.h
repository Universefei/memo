#ifndef MOUSE_H
#define MOUSE_H

#include <QGraphicsItem>

class Mouse : public QGraphicsItem
{
	public:
	   	Mouse();

		//  Two of QGraphicsItem's pure virtual functions
		QRectF boundingRect() const;
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
												 QWidget *widget );

		QPainterPath shape() const;

	protected:
		void advance(int step);

	private:
		qreal angle;
		qreal speed;
		qreal mouseEyeDirection;
		QColor color;
};

#endif

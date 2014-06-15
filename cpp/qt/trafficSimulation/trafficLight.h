#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QGraphicsItem>
static const qreal speedUp = 1;
static const int freq = 50;
static const int redTime = 50;
//volatile static int flag;

enum ELightDirct {
	eNS = 0,
	eWE
};

static const QColor trafficLightRed = Qt::red;
static const QColor trafficLightGreen = Qt::green;

class TrafficLight : public QGraphicsItem
{
	public:
		//TrafficLight();
		//  param sec is real world second
		TrafficLight( int sec );
		QColor getLightStatus( ELightDirct ) volatile;
		//void setStartPos();

		QRectF boundingRect() const;
		void paint( QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* Widget );
		QPainterPath shape() const;


	protected:
		 void advance( int step );

	private:
		volatile int ticker;

	//public:
		//volatile bool ableNS;
		//QColor colorNS;
		//QColor colorWE;

};

//TrafficLight* pLightAtCr1 = new TrafficLight( 135 );
//TrafficLight* pLightAtCr2 = new TrafficLight( 0 );

#endif  //  TRAFFICLIGHT_H


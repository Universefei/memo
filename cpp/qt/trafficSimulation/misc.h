#ifndef MISC_H
#define MISC_H

#include "trafficLight.h"
//  Simulation speed up
//static const int speedUp = 1;

//  How many frame per secend
//static const int freq = 300;

//  Six road points
enum EPlace {
	eBSN = 0,  //  Baisha North
	eBSS,	   //  Baisha South
	eTBN,      //  Taibai North
	eTBS,      //  Taibai South
	eRHW,      //  Erhuan West
	eRHE       //  Erhuan East
};
	
static const QPointF startPoint[6] = {
	QPointF(-337.5, -150),		//  startPoint[eBSN]
	QPointF(-312.5, 150),		//  startPoint[eBSS]
	QPointF(312.5, -150),		//  startPoint[eTBN]
	QPointF(337.5, 150),		//  startPoint[eTBS]
	QPointF(-500, -62.5),		//  startPoint[eRHW]
	QPointF(500, -87.5)		//  startPoint[eRHE]
};

static const QPointF endPoint[6] = {
	QPointF(-312.5, -180),		//  endPoint[eBSN]
	QPointF(-337.5, 180),		//  endPoint[eBSS]
	QPointF(337.5, -180),		//  endPoint[eTBN]
	QPointF(312.5, 180),		//  endPoint[eTBS]
	QPointF(-530, -87.5),		//  endPoint[eRHW]
	QPointF(530, -62.5)		//  endPoint[eRHE]
};

//  Corner center
static const QPointF cr1Center = QPointF( -325, -75 );
static const QPointF cr2Center = QPointF( 325, -75 );

//  Where to check traffic Light status.
static const QPointF lightCr1BSN = QPointF(-337.5, -100);
static const QPointF lightCr1BSS = QPointF(-312.5, -50);
static const QPointF lightCr1RHW = QPointF(-350, -62.5);
static const QPointF lightCr1RHE = QPointF(-300, -87.5);

static const QPointF lightCr2TBN = QPointF(312.5, -100);
static const QPointF lightCr2TBS = QPointF(337.5, -50);
static const QPointF lightCr2RHW = QPointF(300, -62.5);
static const QPointF lightCr2RHE = QPointF(350, -87.5);

//  Turnning points 
static const QPointF BSN2RHW = QPointF(-337.5, -87.5);
static const QPointF RHE2BSN = QPointF(-312.5, -87.5);
static const QPointF RHW2BSS = QPointF(-337.5, -62.5);
static const QPointF BSS2RHE = QPointF(-312.5, -62.5);

static const QPointF RHDown = QPointF(-500, -87.5);
static const QPointF RHUp = QPointF(500, -62.5);
static const QPointF RHRight = QPointF(-500, -62.5);
static const QPointF RHLeft = QPointF(500, -87.5);

static const QPointF TBN2RHW = QPointF(312.5, -87.5);
static const QPointF RHE2TBN = QPointF(337.5, -87.5);
static const QPointF RHW2TBS = QPointF(312.5, -62.5);
static const QPointF TBS2RHE = QPointF(337.5, -62.5);

//  Color tags of cars from different road point
static const QColor pointColor[6] = {
	Qt::blue,			//  pointColor[eBSN]
	Qt::darkGreen,		//  pointColor[eBSS]
	Qt::cyan,           //  pointColor[eTBN]
	Qt::darkRed,        //  pointColor[eTBS]
	Qt::black,          //  pointColor[eRHW]
	Qt::magenta         //  pointColor[eRHE]
};

//  Traffic light color
//static const QColor trafficLightRed = Qt::red;
//static const QColor trafficLightGreen = Qt::green;

//  Global traffic lights
//volatile static TrafficLight pLightAtCr1( 0 );
//volatile static TrafficLight pLightAtCr2( 125 );
static TrafficLight* pLightAtCr1 = new TrafficLight( 120 );
//static TrafficLight* pLightAtCr1 = &lightAtCr1;
//static TrafficLight* pLightAtCr2 = &lightAtCr2;
static TrafficLight* pLightAtCr2 = new TrafficLight( 0 );

/*
volatile bool ableCr1NS = false;
volatile bool ableCr1WE = false;
volatile bool ableCr2NS = false;
volatile bool ableCr2WE = false;
*/

//static int flag;
#endif //  MISC_H

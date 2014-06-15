#include "carFrom.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>


/*===========================================================================*/
/*                                Constructors                               */
/*===========================================================================*/

/*----- CarBSN --------------------------------------------------------------*/
CarBSN::CarBSN( qreal spd ) : Car( eBSN, eBSN, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
	setRotation( 0 );
}

CarBSN::~CarBSN()
{
}

/*----- CarBSS --------------------------------------------------------------*/
CarBSS::CarBSS( qreal spd ) : Car( eBSS, eBSS, spd ) 
{ 
    //  Init distination 
    dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
	setRotation( 180 );
}

CarBSS::~CarBSS()
{
}
/*----- CarTBN --------------------------------------------------------------*/
CarTBN::CarTBN( qreal spd ) : Car( eTBN, eTBN, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
	setRotation( 0 );
}

CarTBN::~CarTBN()
{
}
/*----- CarTBS --------------------------------------------------------------*/
CarTBS::CarTBS( qreal spd ) : Car( eTBS, eTBS, spd )
{
	//  Init distination
	//dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace) % 5);
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
	setRotation( 180 );
}

CarTBS::~CarTBS()
{
}
/*----- CarRHW --------------------------------------------------------------*/
CarRHW::CarRHW( qreal spd ) : Car( eRHW, eRHW, spd )
{
	//  Init distination
	//dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace) % 5);
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
	setRotation( -90 );
}

CarRHW::~CarRHW()
{
}
/*----- CarRHE --------------------------------------------------------------*/
CarRHE::CarRHE( qreal spd ) : Car( eRHE, eRHE, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
	setRotation( 90 );
}

CarRHE::~CarRHE()
{
}
/*===========================================================================*/
/*                                turnDirection                                    */
/*===========================================================================*/

/*----- CarBSN --------------------------------------------------------------*/
void CarBSN::turnDirection()
{

	QPointF curLocation = this->mapToScene( 0, 0 );

	//  Turnning business logic
	if ( curLocation == BSN2RHW ) {
		if ( dist != eBSS ) {
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHDown ) {
		if ( dist != eRHW )  //  else Head to RHW
		{ 
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )  //  Head to BSS
		{
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )  //  Head to TBS
		{
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHUp ) {
		if ( dist != eRHE )  //  else Head to RHE
		{ 
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHLeft ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 180 );  //  Head to TBN
	}

}

/*----- CarBSS --------------------------------------------------------------*/
void CarBSS::turnDirection()
{
	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSS2RHE ) {
		if ( dist != eBSN ) {
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )  //  Head to TBS
		{
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHUp ) {
		if ( dist != eRHE )  //  else Head to RHE
		{ 
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHLeft ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHE2TBN ) {
		if ( dist == eTBN )  //  Head to TBN
		{
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHE2BSN) {
		if ( dist == eBSN )  //  Head to BSN
		{ 
			setRotation( 180 );
		}
	}
	//  else Head to RHW
}

/*----- CarTBN --------------------------------------------------------------*/
void CarTBN::turnDirection()
{
	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == TBN2RHW ) {
		if ( dist != eTBS ) {
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHE2BSN ) {
		if ( dist == eBSN )  //  Head to BSN
		{
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHDown ) {
		if ( dist != eRHW )  //  else Head to RHW
		{ 
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )  //  Head to BSS
		{
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )  //  Head to TBS
		{
			setRotation( 0 );
		}
	}
	//  else Head to RHE
}

/*----- CarTBS --------------------------------------------------------------*/
void CarTBS::turnDirection()
{
	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == TBS2RHE ) {
		if ( dist != eTBN ) {
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHUp ) {
		if ( dist != eRHE ) {  //  else Head to RHE 
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHLeft ) { // turnning
		setRotation( 90 );
	}
	else if ( curLocation == RHE2TBN ) {
		if ( dist == eTBN ) {  //  Head to TBN
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHE2BSN ) {
		if ( dist == eBSN ) {  //  Head to BSN
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHDown ) {
		if ( dist != eRHW ) {  //  else Head to RHW
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHRight ) { // turnning
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		setRotation( 0 );  //  Head BSS
	}


}

/*----- CarRHW --------------------------------------------------------------*/
void CarRHW::turnDirection()
{
	QPointF curLocation = this->mapToScene( 0, 0 );

	if ( curLocation == RHRight ) {
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS ) {  //  Head to BSS
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS ) {  //  Head to TBS
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHUp ) {
		if ( dist != eRHE ) {  //  esle Head to RHE
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHLeft ) {  //  turnning
		setRotation( 90 );
	}
	else if ( curLocation == RHE2TBN ) {
		if ( dist = eTBN ) {  //  Head to TBN
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHE2BSN ) {
		if ( dist == eBSN ) {  //  Head to BSN
			setRotation( 180 );
		}
	}
	//  else go to the adverse direction 

}
/*----- CarRHE --------------------------------------------------------------*/
void CarRHE::turnDirection()
{
	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == RHLeft ) {
	}
	else if ( curLocation == RHE2TBN ) {
		if ( dist == eTBN ) {  //  Head to TBN
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHE2BSN ) {
		if ( dist == eBSN ) {  //  Head to BSN
			setRotation( 180 );
		}
	}
	else if ( curLocation == RHDown ) {
		if ( dist != eRHW ) {  //  esle Head to RHw
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHRight ) {  //  turnning
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist = eBSS ) {  //  Head to BSS
			setRotation( 0 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS ) {  //  Head to TBS
			setRotation( 0 );
		}
	}
	//  else go to the adverse direction 

}

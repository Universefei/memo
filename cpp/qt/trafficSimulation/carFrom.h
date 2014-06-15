#ifndef CARFROM_H
#define CARFROM_H

#include "car.h"
#include <QGraphicsItem>
//#include "misc.h"

/*---------------------------------------------------------------------------*/
/*                                  CarBSN                                   */
/*---------------------------------------------------------------------------*/
class CarBSN : public Car
{
	public:
		CarBSN( qreal speed );
		virtual ~CarBSN();

	private:
		void turnDirection();
};

/*---------------------------------------------------------------------------*/
/*                                  CarBSS                                   */
/*---------------------------------------------------------------------------*/
class CarBSS : public Car
{
	public:
		CarBSS( qreal speed );
		virtual ~CarBSS();

	private:
		void turnDirection();
};

/*---------------------------------------------------------------------------*/
/*                                  CarTBN                                   */
/*---------------------------------------------------------------------------*/
class CarTBN : public Car
{
	public:
		CarTBN( qreal speed );
		virtual ~CarTBN();

	private:
		void turnDirection();
};

/*---------------------------------------------------------------------------*/
/*                                  CarTBS                                   */
/*---------------------------------------------------------------------------*/
class CarTBS : public Car
{
	public:
		CarTBS( qreal speed );
		virtual ~CarTBS();

	private:
		void turnDirection();
};

/*---------------------------------------------------------------------------*/
/*                                  CarRHW                                   */
/*---------------------------------------------------------------------------*/
class CarRHW : public Car
{
	public:
		CarRHW( qreal speed );
		virtual ~CarRHW();

	private:
		void turnDirection();
};

/*---------------------------------------------------------------------------*/
/*                                  CarRHE                                   */
/*---------------------------------------------------------------------------*/
class CarRHE : public Car
{
	public:
		CarRHE( qreal speed );
		virtual ~CarRHE();

	private:
		void turnDirection();
};

#endif // CARFROM_H

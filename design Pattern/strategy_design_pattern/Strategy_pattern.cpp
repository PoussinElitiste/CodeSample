// 						|-----------|
// 						| Algo1		|
//	|-----------|		|-----------|
//	| AlgoBase	| <---- | Algo2		|
//	|	Go()	|		|-----------|
//	|-----------|		| Algo3		|
//						|-----------|
//						| Algo4		|
//						|-----------|
// 
// |----------------|			|-----------|			|-----------|		
// | Vehicule		|			| StreetCar	|			| Algo1		|
// | |----------|	|			|-----------| SetAlgo()	|-----------|
// | | AlgoBase	|	| <--------	| Formula1	| <------->	| Algo2		|
// | |----------|	|			|-----------|			|-----------|
// |	SetAlgo()	|			| Helicopter|			| Algo3		|
// |	Go()		|			|-----------|			|-----------|
// |----------------|						 			| Algo4		|
//											 			|-----------|

#include "GoAlgorithm.h"

class Vehicule
{
	GoAlgorithm * goAlgorithm_;

public:
	void SetGoAlgorithm(GoAlgorithm * goAlgorithm)
	{
		goAlgorithm_=goAlgorithm;
	}


	void Go()
	{
		goAlgorithm_->Go();
	}
};

class StreetCar
	:public Vehicule
{
public:
	StreetCar()
	{
		SetGoAlgorithm(new GoDrivingAlgorithm());
	}
};

class FormulaOne
	:public Vehicule
{
public:
	FormulaOne()
	{
		SetGoAlgorithm(new GoDrivingAlgorithm());
	}
};

class Helicopter
	:public Vehicule
{
public:
	Helicopter()
	{
		SetGoAlgorithm(new GoFlyingAlgorithm());
	}
};

class Jet
	:public Vehicule
{
public:
	Jet()
	{
		SetGoAlgorithm(new GoFlyingFastAlgorithm());
	}
};

int main()
{
	StreetCar a;
	FormulaOne b;
	Helicopter c;
	Jet d;

	a.Go();
	b.Go();
	c.Go();
	d.Go();
}
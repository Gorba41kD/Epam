#include<iostream>
using namespace std;
// Горбачик % 5 = 3,Task 4
class Vehicle
{
public:
	virtual void moving() = 0;
};
class Car : public Vehicle
{
private:
	float m_dist;
	float m_liter;
public:
	Car( float m_s,float m_l )
	{
		this->m_dist = m_s;
		this->m_liter = m_l;
	}
	float func()
	{
		return m_liter / m_dist;
	}
	virtual void moving() = 0;
};
class Truck : public Car
{
public:
	Truck(float a,float b) : Car(a,b)
	{
		consuption = func();
	}
	void moving() override
	{
		cout << "Truck consumption = ";
		cout << consuption;
	}
private:
	float consuption;
};
class Passenger : public Car
{
public:
	Passenger(float a,float b) : Car(a,b)
	{
		 consuption = func();
	}
	void moving() override
	{
		cout << "Passenger car consumption = ";
		cout << consuption;
	}
private:
	float consuption;
};
class Plane : public Vehicle
{
private:
	float distance;
	float fuel;
public:
	Plane(float a, float b):distance(a),fuel(b)
	{
	}
	virtual void moving() = 0;
	void funcOfPlane()
	{
		cout << distance * fuel;
	}
};
class WarPlane : public Plane
{
public:
	WarPlane(float a, float b):Plane(a,b)
	{

	}
	void moving() override
	{
		cout << "War Plane price = ";
		funcOfPlane();
	}
		
};
class PassengerPlane : public Plane
{
public:
	PassengerPlane(float a,float b) :Plane(a, b)
	{

	}
	void moving() override
	{
		cout << "Passenger price = ";
		funcOfPlane();
	}
};
int main()
{
	cout << "\tEnter the number of kilometers and the corresponding fuel consumption" << endl << endl;
	float km1 = 0;
	do
	{
		cout << "Enter the number of kilometers traveled by the truck(>0) : ";
		cin >> km1;
	} while (km1 <= 0);
	cout << endl;
	float fuel1 = 0;
	do
	{
		cout << "Enter the corresponding fuel consuption for a truck(>0) : ";
		cin >> fuel1;
	} while (fuel1 <= 0);
	cout << endl;
	float km2 = 0;
	do
	{
		cout << "Enter the number of kilometers traveled by the passenger(>0) : ";
		cin >> km2;
	} while (km2 <= 0);
	cout << endl;
	float fuel2 = 0;
	do
	{
		cout << "Enter the corresponding fuel consumption for a passenger(>0) : ";
		cin >> fuel2;
	} while (fuel2 <= 0);
	cout << endl;
	cout << "\tEnter the flight distance of the aircraft and average fuel consuption per 1 kilometr" << endl << endl;
	float pl_km1 = 0;
	do
	{
		cout << "Enter the flight distance for the war-plane(>0) : ";
		cin >> pl_km1;
	} while (pl_km1 <= 0);
	cout << endl;
	float pl_fuel1 = 0;
	do
	{
		cout << "Enter the corresponding fuel consuption for a war-plane(>0) : ";
		cin >> pl_fuel1;
	} while (pl_fuel1 <= 0);
	cout << endl;
	float pl_km2 = 0;
	do
	{
		cout << "Enter the flight distance for the passenger plane(>0) : ";
		cin >> pl_km2;
	} while (pl_km2 <= 0);
	cout << endl;
	float pl_fuel2 = 0;
	do
	{
		cout << "Enter the corresponding fuel consumption for a passenger plane(>0) : ";
		cin >> pl_fuel2;
	} while (pl_fuel2 <= 0);
	cout << endl;
	Truck truck(km1,fuel1);
	Vehicle* vehptr1 = &truck;
	vehptr1->moving();
	cout << endl;
	Passenger pass(km2,fuel2);
	Vehicle* vehptr2 = &pass;
	vehptr2->moving();
	cout << endl;
	WarPlane warPl(pl_km1, pl_fuel1);
	Vehicle* vehptr3 = &warPl;
	vehptr3->moving();
	cout << endl;
	PassengerPlane passPl(pl_km2, pl_fuel2);
	Vehicle* vehptr4 = &passPl;
	vehptr4->moving();
	return 0;
}
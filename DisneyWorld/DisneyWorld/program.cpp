#include "park.h"
#include "facility.h"
#include "guest.h"
#include "operator.h"
#include "person.h"
#include "waterSlide.h"
#include "rollerCoaster.h"
#include "waterRollerCoaster.h"

int main(int argc, const char* argv[])
{
	//init park
	Park disneyWorld("Disney World",10,15,100);
	//init operators
	Operator o1(Person("Keren", 19, 1), 1);
	Operator o2(Person("Daniel", 21, 1), 2);
	Operator o3(Person("Amir", 26, 1), 3);
	Operator o4(Person("Eytan", 28, 1), 4);

	disneyWorld += o1;
	disneyWorld += o2;
	disneyWorld += o3;
	disneyWorld += o4;

	//init facilities
	WaterSlide waterSlide(Facility("KAMIKAZA", 2 ,new bool[]{ true, true, false }, &o1), 800);
	RollerCoaster rollerCoasterA(Facility("BALERINE", 30, new bool[]{true, true, true}, &o2), 4, 0);
	RollerCoaster rollerCoasterB(Facility("ANACONDA", 16, new bool[]{false, true, true}, &o3), 30, 2);

	Facility f("HYDRA", 12, new bool[]{false, true, false}, &o4);
	WaterRollerCoaster waterRollerCoaster(WaterSlide(f,1000), RollerCoaster(f, 40, 7));

	disneyWorld += waterSlide;
	disneyWorld += rollerCoasterA;
	disneyWorld += rollerCoasterB;
	disneyWorld += waterRollerCoaster;

	//create persons to enter park
	Person p1("Adam",13,1.25);
	Person p2("Adir", 21, 1.55);
	Person p3("Adi", 27, 1.68);
	Person p4("Adva", 72, 1.45);

	Guest g1 = disneyWorld.buyTicket(p1, Guest::CHILD, Guest::THRILLED);
	Guest g2 = disneyWorld.buyTicket(p2, Guest::ADULT, Guest::HAPPY, true);
	Guest g3 = disneyWorld.buyTicket(p3, Guest::ADULT, Guest::HAPPY);
	Guest g4 = disneyWorld.buyTicket(p4, Guest::CHILD, Guest::AFRAID);

	//add guest to facility
	waterSlide += g1;
	waterSlide += g2;
	waterSlide.start(); //start() should remove all guests

	waterSlide += g3;
	waterSlide += g4;
	waterSlide.start();

	rollerCoasterA += g1;
	rollerCoasterA += g2;
	rollerCoasterA += g3;
	rollerCoasterA += g4;
	rollerCoasterA.start();

	rollerCoasterB += g1;
	rollerCoasterB += g2;
	rollerCoasterB += g3;
	rollerCoasterB += g4;
	rollerCoasterA.start();

	waterRollerCoaster += g1;
	waterRollerCoaster += g2;
	waterRollerCoaster += g3;
	waterRollerCoaster += g4;
	waterRollerCoaster.start();
}
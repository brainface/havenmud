//*       Created by Severen        *//
//*            room1a.c             *//
//*       Mid November 1998         *//


#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("inside the lower chambers");
    SetLong(
      "This is the southern side of the lower chamber. This room is "
      "not as bloody as the northern ones are. Instead, the walls "
      "are quite spotless in here except for the floor which has traces "
      "of blood upon it. There is a sarcophagus standing upright on "
      "the south wall."
    );

    SetItems(([
	({"side","chamber","room"}) :
	(: GetLong :),
	({"blood","traces"}) :
	"There is not much blood on the floor in this room and none "
	"at all on the walls.",
	({"walls","wall"}) :
	"Square walls made of stone that are clean of any blood or "
	"claw marks.",
	({"marks","mark"}) :
	"There are none.",
	({"south wall"}) :
	"A sarcophagus stands here against the stone wall.",
	({"floor"}) :
	"The floor of the room is made of stone. There are small "
	"traces of blood upon it.",
	({"stone"}) :
	"The material used to build this whole tower. It is grey.",
      ]));

    SetItemAdjectives(([
	"chamber" : ({"southern","lower","spotless"}),
	"blood" : ({"traces","of","small"}),
	"walls" : ({"square","spotless","grey","stone"}),
	"marks" : ({"claw"}),
	"floor" : ({"stone"}),
	"stone" : ({"grey"}),
      ]));

    SetListen("default","Eerie moans are present in the room.");
    SetInventory (([
	TOBJ + "/sarcophagus" : 1,
	TNPC + "/mummy" : 1,
      ]));

    SetExits(([
	"north" : TROOM + "/room1b",
      ]));

}

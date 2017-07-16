// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetDayLight(-20);
  SetTown("Targoviste");
  SetShort("before the outer wall of Targoviste");
  SetLong(
    "Formed of black stone, the outer wall enclosing Targoviste "
    "runs to the north and south. Directly east of here a set "
    "of heavy granite doors allow passage through the outer wall, "
    "while to the west a second massive gate leads to the "
    "Targoviste Road. The Estergrym Mountains loom above on all "
    "sides, blocking out any light that might have penetrated the "
    "darkened sky. North and south runs a path around the exterior "
    "wall of the city."
  );
  SetItems( ([ 
    ({ "gate", "gates" }) : "The entry gates of Targoviste rise to "
    "the west, while to the east lies the gate through the outer "
    "wall of the city.",
    ({ "wall" }) : "This is the outer fortification wall of the "
    "city. It is lined with a battlement and surrounded by cliffs, "
    "intended to help pin down any attacking enemy.",
    ({ "granite" }) : "Black granite forms the western wall of the city.",
    ({ "mountain", "mountains" }) : "The Estergrym Mountains rise "
    "to all sides, their jagged black heights blocking out any light.",
    ({ "cliff", "cliffs" }) : "Cliffs rise steeply to either side, "
    "forming a complete enclosure when both sets of gates are closed.",
    "battlements" : "Battlements line the top of the western wall.",
    ({ "city", "Targoviste" }) : "To the west, through the gate in "
    "the western wall, lies the main part of the city.",
  ]) );
  SetItemAdjectives( ([
    "gate" : ({ "Targoviste", "massive", "granite", "entry", "west" }),
    "wall" : ({ "west", "Targoviste", "city", "granite", "massive",
    "outer" }),
    "granite" : ({ "black" }),
    "mountain" : ({ "Estergrym", "surrounding", "jagged", "black",
    "surrounding", "looming" }),
    "cliff" : ({ "steep", "enclosing", "sharp" }),
  ]) );
  SetListen( ([ 
    "default" : "A faint breeze skirls across the cliff face.",
  ]) );
  SetSmell( ([
    "default" : "Moisture saturates the air.",
  ]) );
  SetExits( ([
    "north" : TARG_ROOM "west_out5",
    "south" : TARG_ROOM "west_out3",
    "east" : TARG_ROOM "west_wall3",
    "west" : TARG_ROOM "gate_west",
  ]) );
}

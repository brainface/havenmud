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
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("north transept of the cathedral of Aberach");
  SetLong(
    "High overhead rises the tower of the north transept, its upper "
    "aspects fading in to the blackness. The transept is a hall which "
    "runs perpendicular to the main aisle. Around the walls of this area "
    "are an array of tables and wooden benches, all sturdy and stained a "
    "uniform black. Parchments are neatly arranged upon most of the table "
    "surfaces. Along the northern wall stands a weapon rack, holding many "
    "different types of swords. Beginning at a level above the weapon rack "
    "and continuing high in to the tower are tall narrow windows with "
    "intricate patterns traced in to their edges."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "No sound disturbs the hallowed silence.",
  ]) );
  SetSmell( ([
    "default" : "The air carries the scent of incense, cut by a tang of sulphur.",
  ]) );
  SetExits( ([ 
    "south": TARG_ROOM "church3",
  ]) );
}

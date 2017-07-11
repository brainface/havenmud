//Alex@Haven
//2006
#include "../area.h"
#include <lib.h>
inherit LIB_ROOM;

static void create(){
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a sleeping area");
  SetLong(
    "The room is smaller, and the multitude of straw mats on the "
    "floor signifies that this is the place where the family sleeps. "
    "The floor is unswept and cluttered with everyday articles. "
    "The only exit from here leads back into the southern "
    "common area."
  );
  SetItems( ([
    ({ "mat", "mats" }) : "The old mat is musty and "
    "smells faintly of sweat and other body odors.",
    ({"articles"}) : "Unwashed clothes, old toys, unpaid bills...",
  ]) );
  SetItemAdjectives( ([
    "mat" : ({"straw"}),
  ]) );
  SetListen( ([
    "default" : "Noise seems to echo off the mud-daubed walls.",
  ]) );
  SetSmell( ([
    "default" : "It absolutely reeks of monkey here.",
  ]) );
  SetInventory( ([
    AREA_NPC + "child" :2,
    AREA_NPC + "abu" :1,
  ]) );
  SetExits( ([
    "south" : AREA_ROOM "common",
  ]) );
}

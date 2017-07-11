//
// at the base of a tower
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at the base of a crumbling tower");
  SetLong(
    "The east-west corridor ends here in a tall crumbling tower,"
    " a huge edifice of stone that has withstood the weight of"
    " centuries. It has forced its way up through the solid rock above"
    " it in an inconceivable feat of strength. A gap in the wall of the"
    " tower allows further progress up the winding stone staircase to"
    " the upper part of the tower.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetExits( ([
    "west" : RNQ_RM + "ecor2.c",
    "up" : RNQ_RM + "rubble3.c",
    ]) );
  SetItems( ([
    "tower" : (:GetLong:),
    ({"stairs","staircase"}) :
      "The stairs at first glance look dangerous, but will probably hold.",
    ({"rock","tower","stone"}) :
      "The tower appears to have forced its way upwards through the rock,"
      " yet the seal between them looks artificially tight.",
    ({"gap","wall","walls"}) :
      "The stones are missing from part of the tower. They may have been"
      " dislodged, or perhaps there used to be a door there.",
  "corridor" : "The corridor leads west back to the market place, and ends here.",
    ]) );
  SetItemAdjectives( ([
    "corridor" : ({"east","west"}),
    "passage" : "south",
    "stairs" : ({"winding","stone"}),
    "tower" : ({"tall","crumbling","upper part of the"}),
    ]) );
  SetListen( ([
    "default" :
      "Silence reigns.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "stalker" : 1
    ]) );
}

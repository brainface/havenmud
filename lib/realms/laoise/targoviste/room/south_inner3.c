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
  SetShort("the inner keep of Targoviste");
  SetLong(
    "A small building stands to the north, its diminutive size "
    "and lack of fortifications suggesting it is a place of business "
    "rather than part of the military defenses of Targoviste. Above "
    "its arched entrance is a sign depicting a piece of parchment with "
    "a feathered quill writing upon it. To the east the inner keep of "
    "stronghold continues, its polished black marble stretching in to "
    "the distance. Northwest of here is an open area, with a marble fountain "
    "sitting in its center."
  );
  SetItems( ([ 
    ({ "office", "building" }) : "This building appears to be the post "
    "office for the city of Targoviste.",
    "sign" : "The sign above the door of the building to the north "
    "shows a feathered quill writing upon a piece of parchment.",

  ]));

  SetItemAdjectives( ([
    "office" : ({ "north", "small", "nearby", "post", "city", "town", 
    "Targoviste" }),

  ]) );
  SetListen( ([ 
    "default" : "Various city noises come from all sides.",
  ]) );
  SetSmell( ([
    "default" : "No sounds are noticeable in this general area.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_inner2",
    "northwest" : TARG_ROOM "west_inner1",
  ]) );
  SetEnters( ([
    "office" : TARG_ROOM "post_office",
  ]) );
}

#include <lib.h>
#include <domains.h>
#include "../gwonish.h"

inherit LIB_ROOM;

static void create() {

  ::create();
  SetClimate("sub-tropical");
  SetAmbientLight(30);
  SetShort("inside a bamboo enclosement");
  SetLong("Bamboo shafts are thrust in the ground and woven "
    "together as they form the encircling enclosement with an "
    "open roof. No trace of the swamp exists in the enclosement, "
    "leaving a clearing save for a fire pit in the center. "
    "The dirt floor surrounding the fire pit is quite dry.");
  SetItems( ([
    ({ "coal", "coals", "bed", "coal" }) : "The coals of the fire glow with "
      "fierceness and heat.",
    ({ "swamp" }) : "The swamp lies outside the enclosement.",
    ({ "muck", "blood", "feces", "mud", "unnamables" }) : 
      "The muck covering the bamboo is a mixture of mud, "
      "blood, feces and other unnamables.",
    ({ "bamboo", "shafts", "shaft" }) : "The bamboo is a light "
      "yellow with a covering of muck.",
    ({ "roof", "opening" }) : "One can see the sky without a roof.",
    ({ "floor", "dirt", "ground" }) : "The floor is nothing more than dirt.",
    ({ "wood", "crack", "bubbles", "liquid", "fuel" }) : 
      "The wood burning in the fire pit has a crack running down "
      "its side, where bubbles of swamp liquid boil out from the heat of the fire.",
    ({ "enclosement" }) : (: GetLong :)
    ]) );
  SetItemAdjectives( ([
    "coals" : ({ "red", "white" }),
    "wood" : ({ "swamp", "wet" }),
    "floor" : ({ "dirt" }),
    "roof" : ({ "open" }),
    "enclosement" : ({ "bamboo", "encircling" }),
    "shaft" : ({ "bamboo", "yellow" }),
    "shafts" : ({ "bamboo", "yellow" }),
    "bamboo" : ({ "weaved", "yellow" }),
    ]) );
  SetInventory( ([
    GWONISH_NPC "controller" : 1,
    GWONISH_OBJ "log" : 1,
    GWONISH_OBJ "firepit" : 1,
    GWONISH_NPC "enclose_train" : 1,
    ]) );
  SetListen( ([
    "default" : "Sounds of the swamp outside echo in the bamboo enclosement.",
    ]) );
  SetSmell( ([
    "default" : "The smell of coal and fire permeates the area.",
    ]) );
  SetExits( ([
    "out" : GWONISH_ROOM "gw09",
    ]) );
  }

void heart_beat() {
  string fire;
  ::heart_beat();
  switch(random(3)) {
    case 0:
      fire = "The fire crackles.";
    break;
    case 1:
      fire = "A long low hiss eminates from still wet swamp wood in the fire.";
    break;
    case 2:
      fire = "The fire crackles.";
    break;
    }
  eventPrint(fire);
  }

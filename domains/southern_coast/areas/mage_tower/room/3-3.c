#include <lib.h>
#include <domains.h>
#include "../mage_tower.h"
inherit LIB_ROOM;
string eventSearchCurtains();

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a private study");
  SetExits( ([
    "south" : "3-2",
    ]) );
  SetSmell( ([
    "default" : "The scent of rosepetals and other spell components "
                "taints the air.",
    ]) );
  SetListen( ([
    "default" : "The study is fairly quiet.",
    ]) );
  SetAmbientLight(40);
  SetLong("This room seems to be some sort of private study. "
          "To the south, the room is protected by a large iron "
          "door. The floor is made of a polished stone, but is "
          "mostly covered by fine rugs of elven make. On the "
          "walls are various curtains which seem to conceal things "
          "best left concealed.");
  SetItems( ([
    ({ "curtain", "curtains" }) : "The curtains are a velvet material "
                                  "which conceals things on the walls.",
    ({ "wall", "walls" }) : "The walls are a smooth and carefully "
                            "crafted stone.",
    ({ "floor", "stone" }) : "The floor is made of a polished stone.",
    ({ "rug", "rugs" }) : "The rugs are of fine elven make.",
    "vortex" : "The vortex is blocked by the curtains.",
    ]) );
  SetItemAdjectives( ([
    "vortex" : "swirling",
    "rug"    : "elven",
    "floor"  : "polished",
    ]) );
  SetSearch("curtain", (: eventSearchCurtains :) );
//  SetEnters( ([
//   "vortex" : (random(2) ? DOMAIN_PLANES "castles/first/entrance"
//                          : DOMAIN_PLANES "virtual/forest/2,2"),
//    ]) );
  SetEnters( ([
      "vortex" : "/domains/planes/virtual/first/0,0.c",
	]) );
  SetInventory( ([
    TOWER_NPC "elf_mage" : 1,
    TOWER_NPC "app_mage" : 2,
    ]) );
  SetDoor("south", TOWER_OBJ "door33");
}

string eventSearchCurtains() {
  object mage = present("elf mage");
  if (mage){
    if (living(mage)) {
    mage->eventForce("speak Please leave my curtains alone.");
    mage->eventForce("emote fixes the disturbed curtain.");
    return "";
      }
   }
  send_messages( ({ "look", "find" }),
    "$agent_name $agent_verb behind a curtain and $agent_verb a "
    "swirling vortex of primordial energy.", this_player(), 0, 
    this_object() );
    return "You have searched the curtains.";
}

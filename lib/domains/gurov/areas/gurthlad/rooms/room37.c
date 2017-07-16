#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("inside a large tent");
  SetLong("A large, hastily erected, cabin style tent. There is a lantern "
          "hung on the ridgpole to provide light. Against the walls of the tent "
          "there are two cots with bedrolls on them. In the middle of the room "
          "there is a collapsable table with maps and papers spread across it.");
  SetObviousExits("out");
  SetExits( ([
          "out" : G_ROOMS + "/room38"]) );
  SetItems( ([
          ({ "bedroll", "bedrolls" }) : "Warm wool bedrolls. They look very heavy.",
          ({ "tent", "cabin style tent" }) : "A large cabin style tent with walls "
          "of worn and patched canvas.",
          "canvas" : "The walls and ceiling are made of worn and patched "
          "canvas.",
          "lantern" : "A large brass oil burning latern. It provides light for the "
          "interior of the tent.",
          "ridgepole" : "A peace of light weight wood that supports the canvas "
          "roof.",
          ({ "cot", "cots" }) : "Two lightweight folding canvas cots with "
          "bedrolls spread out on them",
          "table" : "A lightweight collapsable travel table in the center of the "
          "tent. There are many maps and papers spread out across it.",
          ({ "papers", "maps" }) : "Several maps and many other papers spread out "
          "haphazardly across the camp table. Many of the maps have "
          "recent marks on them that look like troop movements."]) );
  SetClimate("indoors");
  SetSmell( ([
          "default" : "There is a strong smell of wood smoke."]) );
  SetInventory( ([
          G_NPC + "/human_explr" : 4,
          G_NPC + "/human_captain" : 1 ]) );
  }

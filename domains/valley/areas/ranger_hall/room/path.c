// Original text: Davantalus@Haven
// coding Sabrielle 199810
// Updated: Davantalus 20040721

#include <lib.h>
#include "../ranger_hall.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a narrow forest path");
  SetDayLong(
      "A narrow forest path leads from the main road off to the west. "
      "The trees sway with a sentient feeling, branches moving in the "
      "breeze. Clumps of emerald and jade leaves hang from the trees, "
      "obscuring the sun. The forest pulses with natural energy and "
      "light. Tiny motes of light appear and fade like fireflies."
  );
  SetNightLong(
      "The narrow black forest path leads from the main road off to "
      "the west. The trees sway with a sentient feeling, branches "
      "groaning in the breeze. Spidery tree appendages loom above, "
      "their canopy obscuring the sky. To the west, the forest thins. "
      "The path pulses with natural energy."
  );

  SetItems( ([
      ({"appendage", "appendages" })  
                        : "The long slender tree branches look like arms.",
      ({"path","road"}) : "This small path leading away from the main "
                          "road is surrounded by lush greenery.",
      ({"leaves", "greenery" }) 
                        : "The leaves shimmer with natural energy.",
      ({"tree","trees"}): "The trees have almost sentient qualities.",
      ({"forest","woods","surrounding"}) : "The surrounding forest gives "
                          "off an unmistakable feeling of power.",
      ({"moon"})        : "The moon is hidden by the forest canopy.",
      ({"fireflies"})   : "The motes of light look like fireflies.",
      ({"branches" })
                        : "To the west these branches grow thinner.",
      ({"canopy"}) :    "The canopy is deep and rich with beautiful leaves.",
  ]) );
  SetItemAdjectives( ([ 
      "path"     : ({"narrow", "black"}),
      "branches" : ({ "spidery" }),
      "canopy"   : ({ "tree", "forest", "deep", "rich" }),
      "forest"   : ({"surrounding"}),
      "tree"     : ({"life-like", "tall", "large"}),
  ]) );
  SetInventory( ([
      RH_NPC + "hummingbird" : 1+random(4)
  ]) );
  SetListen( ([
      "default" : "The forest crackles with energy!"
  ]) );
  SetSmell( ([
      "default" : "The wind smells of ozone."
  ]) );
  SetExits( ([
      "west" : RH_ROOM + "entrance",
      "east" : "/domains/valley/areas/jidoor_forest/room/path07"
  ]) );
}

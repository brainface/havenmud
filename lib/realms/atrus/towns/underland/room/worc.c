// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is worc.c west outer ring road west side center

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "gate2",
    "east" : "tin1",
    "north" : "worn1",
    "south" : "wors1",
    ]) );
  SetShort("the Outer Ring Road West Hub");
  SetLong("Climbing off to the west is the great bore that runs up to the city "
      "gate and the world beyond. The mouth of the bore is sharply cut at a "
      "tangent to the almost perfectly round road that runs the whole perimeter "
      "of the city. The walls here are perfectly smooth, and the tunnel surrounding "
      "the ring road is as wide as any city avenue. Small doors and "
      "windows are tightly packed along each side of the ring wall as many residents "
      "have carved out a nook for themselves over the eons. To the east lies the "
      "great forge rings and the beating heart of the city. Large cogs line the top "
      "of the tunnels, transferring power all over the city in the form of motion. "
      "To the north and south the ring road continues to curve off into the distance. "
      "Incredible heat pours out of a forge to the northeast."); 
       
  SetItems( ([
    ({ "furnace", "forge", "tin forge", "foundry" }) : 
      "The northeast corner of this residential hub is the entrance to the city's "
      "Tin Forgery. The tall corners of the nook have been ornately carved out of the "
      "heart of the mountain. Small rivulets of lava are being channelled into the "
      "forge along great obsidian troughways. It would seem the forge is never shut down "
      "for any reason.",
    ({ "gate", "bore", "west", "mouth" }) : 
      "The precisely bored tunnel rises sharply to the "
      "west. A soft orange flow spills down the ramp and is lost in the multi-hued "
      "environment of the ring road. Several pipes sink into the walls next to the bore, "
      "seeming to follow the same heading as the bore itself; could be what powers the "
      "city gate.",
    ({ "ground", "floor", "ring road", "ring", "road", "path"}) : "There is a "
      "masterfully pointed marble path here that acts as the road surface. "
      "The grain is dark but radiant and it throws back all light well. "
      "Torches flickering in the kitten's breath of air movements seem to make the "
      "veins of quartz and gold in the marble dance. Not even steel wrapped wagon "
      "wheels would mar such a pristinely polished surface. Eons of foot traffic have "
      "only enhanced the original polish.",
    ({  "window", "windows", "homes", "houses", "doors", "nooks", "cutouts", "home",
        "nook", "cutout", "door", "house" }) : 
      "The Great Outer Ring "
      "road offers the primary residence ring for the many denizens of the city. "
      "It seems there are thousands of homes along both sides, and some even carved "
      "stairs to dig in above their neighbors. The multiple levels and depths of the "
      "cutouts give the otherwise perfectly machine polished tunnel the appearance "
      "the machine simply crossed through the intersecting homes. Each window is "
      "different, with spectacularly colored drapes and wooden shutters. Every home "
      "contained here has been decorated with love and pride not only for their own "
      "property, but to respect the inhabitant across the way.",
    ]) );
  SetListen("The gentle hum of the gears above drone out any distant conversation.");
  SetSmell("Essence of goose grease and naptha waft through the area.");
  SetEnters( ([
    "furnace" : UNDER_ROOM "tinforge",
    ]) );
}

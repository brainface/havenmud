// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is tinforge.c It's a furnace.. for tin.

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : "worc",
    ]) );
  SetShort("a vast furnace for smelting tin");
  SetLong("No place in here is truly safe to stand. There are large pools of standing "
     "liquid tin that threaten to swallow almost any living thing whole without a "
     "drop of regret. Several lines of trough-ways funnel liquid lava from the "
     "heart of the mountain itself to feed the ever hungry blast furnace. "
     "Sizzling heat waves shower the room in a shimmering haze. A large hanging gantry "
     "sways an immense pouring cauldron into pools and moves the liquid tin into a "
     "trough-way of its own flowing steadily from a deposit pool and off to the east."
     );  
  SetItems( ([
  ({ "furnace", "furnaces", "blast", "blast furnace" }) : "A jumbled mass of "
     "pipes and troughs make a steaming network and heat and power. Looking like some "
     "massive mythical beast breathing fire and steam, the great billowing "
     "furnace steadily streams liquid tin into standing pools. The lava powering the "
     "furnace gives it the appearance of having flaming hair above the yawning maw spewing "
     "metal. Steam hisses in escape and is collected in a great hood at the top of the "
     "room. ",
  ({ "pipes", "pipe", "troughs", "trough", "trough-way", "tough-ways", "funnel", 
   "funnels", "line", "lines", "lava" }) :
     "An endlessly jumbled mass of pipes and troughs conglomerate around the furnace, "
     "supplying vast amounts of lava to melt tin, and water to regulate the temperature. "
     "Vents escape steam to the ceiling while leftover lava is dumped down a chute to "
     "what could only be a magma pool below. The troughs give the spidery pipe system an "
     "eerie glow from behind, lending to the face like appearance of the furnaces.",
  ({ "liquid", "tin", "pools", "pool", "liquid tin", "haze", "heat" }) :
     "Shimmering bands of heat radiate off the stagnant pools of liquid tin waiting "
     "for the ladle head to come move it to the production lines. A bright amber glow "
     "bathes the walls and ceiling, a light good enough to read by anywhere you are. "
     "The bubbling and roiling chute sweeping the tin away to the east seems to "
     "belch and burble as it awaits more material.",
   ({ "vent", "vents", "hood", "steam" }) : "Vast amounts of steam is being released "
     "from the incredible thermal reaction taking place within the furnace. Windlasses "
     "and gears drive vents and fans to move the steam away from the work area "
     "into the collecting hood style ceiling above. It must be venting to the "
     "mountainsides above.",
   ({ "crane", "gantry", "cauldron", "ladle" }) : "Overhead there is a large gantry "
     "crane setup with a cauldron that could hold hundres of gallons. The machine "
     "moves at the gentlest input and moves the liquid tin around the room with "
     "ease. It slips slowly under the surface of a pool, relieving it of liquid "
     "death to carry it effortlessly to the east side of the room. The cauldron "
     "bucks and tilts beginning to pour tin into the waiting mouth of the output "
     "trough. Immense weight moves here.",
   ({ "output", "east", "maw", "mouth", "streams", "stream" }) : 
     "Both the great furnace itself and the "
     "output trough for the tin seem to yawn and belch as vast amounts of material "
     "move in and out of the awaiting orifices. Splatter is almost unseen as the "
     "gantry above moves with smooth care while moving the dangerous metal around. ",
  ]) );
  SetSmell("Sharp tangs of metal rest on the back of your tongue and mute all smells.");
  SetListen("A buttery smooth hum punctuated by low hisses sings the furnace's pulse.");
}

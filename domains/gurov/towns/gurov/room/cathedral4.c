#include <lib.h>
#include "../gurov.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetExits( ([
    "east" : GUROV_ROOM "cathedral3",
    ]) );
  SetShort("the Aberach Shrine");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetWarmth(30);
  SetSmell("A faint coppery smell seems to permeate the shrine.");
  SetListen("Faint whispers sometimes echo in the shrine.");
  SetLong(
    "The Shrine of Aberach in the Cathedral of the Three Gods is a "
    "dim place filled with black pillars that seem to obscure the "
    "altar slightly. At the farthest western part of the shrine, "
    "a series of stairs leads up towards a massive obsidian altar "
    "that seems to give off the foul coppery odor that taints the "
    "air. Thin engravings of gold surround all the pillars, causing "
    "the dim torchlight to reflect into thousands of directions and "
    "cast shadows of deepest black onto walls and floors that are "
    "already dark."
    );
  SetItems( ([
    ({ "pillar", "pillars" }) : "The pillars are a deep black "
           "obsidian in color and are engraved with short "
           "lines of gold.",
    ({ "altar" }) : "The altar of the shrine is a massive obsidian "
           "affair that has a faint coppery tint on its surface.",
    ({ "stair", "stairs" }) : "The obsidian stairs climb up near "
           "to the altar.",
    ({ "engraving", "engravings" }) : "The engravings are mostly "
           "formless and shapeless, but do cast flickers of light "
           "that cause deep shadows.",
    ({ "flicker", "light" }) : "The flickers of light cause deep "
           "shadows to fall on the obsidian pillars.",
    ({ "shadow", "shadows" }) : "The shadows fall on the pillars, "
           "giving them an even deeper blackness that seems to "
           "disquiet anyone viewing them.",
    ]) );
  SetItemAdjectives( ([
    "pillar" : ({ "obsidian", "black", }),
    "altar"  : ({ "obsidian", "massive", }),
    "engraving" : ({ "gold", "thin", }),
    "flicker" : ({ "of", "light", "flicker" }),
    "shadow" : ({ "deepest", "black", "deep" }),
    ]) );
  SetInventory( ([
    GUROV_NPC "lydia" : 1,
    ]) );
  SetReligion( ({ "Aberach" }) );
  SetClasses( ({ "cleric" }) );
}

void heart_beat() {
  ::heart_beat();
  foreach(object u in all_inventory(this_object())) {
    if (random(4)) continue;
    switch(random(4)) {
      case 0:
        u->eventPrint("A feeling of terror briefly overwhelms you.");
        u->AddParalyzed(1);
        break;
      case 1:
        u->eventPrint("%^WHITE%^A female voice whispers in your ear, calling you to glory.%^RESET%^");
        break;
      case 2:
        u->eventPrint("A brief flicker of the light causes a shadow.");
        break;
      case 3:
        u->eventPrint("A chill breeze whistles through the shrine.");
        u->eventForce("shiver");
        break;
      }
    }
}

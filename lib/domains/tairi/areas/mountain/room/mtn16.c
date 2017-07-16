//Selket@Haven
//2006

#include <lib.h>
#include "../mtn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at the summit of Shatadru Mountain");
  SetLong(
    "Here, bathed in the wispy clouds of Kailie, is the "
    "peak of Shatadru Mountain. A small structure stands "
    "within the light of Heaven, only a few pieces of wood "
    "hammered together to shut out the rain. Underneath are "
    "a few time-worn blankets used for sitting on the cold "
    "rocky ground. The only way away from here is down the "
    "path leading towards the base of the mountain."
  );
  SetItems( ([
    ({ "mountain", "peak", "summit", "clouds", "light" }) : 
    "Shatadru Mountain's peak is high above Kailie, but "
    "little of the landscape can be discerned from so high "
    "up and through the ever-present clouds and bright light "
    "that swath the summit.",
    ({ "path" }) : 
    "The old path winds around the sides of the mountain, "
    "presumably leading to the base. ",
    ({ "structure", "wood" }) : 
    "The structure has no walls, only a roof and enough "
    "beams to support it, but it seems sturdily built. ",
    ({ "blanket", "blankets", "ground" }) :
    "The blankets seem to be used each day by their owners, "
    "who do not enjoy having their behinds freeze on the "
    "icy ground.",
  ]) );
  SetItemAdjectives( ([
    "clouds" : ({ "wispy", "kailie" }),
    "structure" : ({ "small" }),
    "light" : ({ "bright", "heaven" }),
    "blankets" : ({ "time", "worn" }),
    "ground" : ({ "cold", "rocky" }),
  ]) );
  SetExits( ([
    "down" : MTN_ROOM "/mtn15",
  ]) );
  SetProperty("no teleport", 1);
  SetInventory( ([
   MTN_NPC "/dali" : 1,
   MTN_NPC "/llama" : 1,
  ]) );
  SetListen("The clouds speak softly amongst themselves.");
  SetSmell("The air smells fresh, yet alive.");
}

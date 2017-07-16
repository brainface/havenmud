
// The Rotting Elf
// Laoise
// 2005

#include <lib.h>
#include "../grymxoria.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Rotting Elf");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetLong(
    "Sets of long black benches and tables stretch across the center of the room. "
    "Along the side walls are displays of swords, axes and various other "
    "weaponry. Set forward from the north wall is a bar made of some "
    "dark wood and polished to a high sheen. Although there are gouges "
    "in some of the wood surfaces, generally this bar appears well-tended "
    "and clean. In a place of honor behind the bar on the north wall a spike "
    "juts from the wall. Upon the spike the owner of this bar regularly places "
    "a freshly-harvested elf head."
  );
  SetItems( ([
    ({ "bench", "benches", "table", "tables" }) :
    "Several benches are scattered throughout the rooms, creating places for "
    "patrons of the bar to sit and pass the time.",
    ({ "swords", "sword", "axe", "axes", "weaponry" }) :
    "These weapons appear to be martial trophys from past conflicts. Or "
    "perhaps they are all that is left of patrons who did not pay their tab.",
    ({ "bar" }) :
    "This is the large piece of polished wood from behind which a bartender "
    "normally plies his trade.",
    ({ "spike", "north wall", "elf", "head" }) :
    "A fresh elf head decorates this spike, dripping blood slowly "
    "on to what appears to be a small effigy set beneath it.",
    ({ "effigy" }) :
    "This is a small effigy of Laoise, whom some call the Goddess of Blood.",
   ]) );
   SetItemAdjectives( ([
    "bench" : ({ "long", "black" }),
    "bar" : ({ "north", "dark", "polished" }),
    "spike" : ({ "fresh", "elf", "dripping" }),
    "effigy" : ({ "small", "bloody", "effigy" }),
   ]) );
   SetSmell( ([
    "default" : "A very faint hint of blood trickles through the air.",
  ]) );
   SetListen( ([
    "default" : "A peculiar silence touches the room.",
   ]) );
  SetInventory( ([
    G_NPC + "emat" : 1,
    G_NPC + "chantarn" : 1,
  ]) );
  SetNewsgroups( ({ "player.general" }) );
  SetExits( ([
    "out" : G_ROOM + "road27",
  ]) );
}


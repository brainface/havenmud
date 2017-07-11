#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worm");
  SetShort("a slimy worm");
  SetLong("This is an ugly earthworm. It's body is a dark"
          " brown color and it has a large ring around one"
          " end of it's body.");
  SetAdjectives( ({ "slimy" }) );
  SetId( ({ "worm","slimy worm", "golem_piece", "cata_npc" }) );
  SetMorality(-50);    
  SetRace("worm");
  SetClass("animal");
  SetLevel(random(10) + 3);
  SetGender("male");
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
  }

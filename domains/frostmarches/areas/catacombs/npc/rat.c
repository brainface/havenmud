#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("rat");
  SetShort("a black rat");
  SetLong("This is a black pestilence bearing rat. It's face and body"
          " are marred by scars and pocks that have bee afflicted"
          " from some virus or another.");
  SetId( ({ "rat","giant rat", "golem_piece", "cata_npc" }) );
  SetAdjectives( ({ "black" }) );
  SetMorality(-50);        
  SetRace("rodent");
  SetClass("animal");
  SetLevel(random(10) + 3);
  SetGender("male");
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
  }

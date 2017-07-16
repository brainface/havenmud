// Clown Crab Spider
// Torak@Haven 2014
// FFEAR!

#include <lib.h>
#include <damage_types.h>

inherit LIB_NPC;
inherit LIB_FEAR;

static void create() {
  ::create();
  SetKeyName("spider");
  SetId( ({ "spider" }) );
  SetAdjectives( ({ "clown", "crab" }) );
  SetShort("a clown crab spider");
  SetLong("scariest fucking spider EVAR. JUST LOOK AT IT!");
  SetRace("arachnid");
  SetClass("animal");
  SetLevel(1);
  SetFearType("%^GREEN%^spider fear%^RESET%^");
  SetResistLevel(500);
  SetFearLength(10);
  SetEncounter(100);
  SetResistance(MAGIC, "immune");
  SetResistance(POISON, "immune");
  SetResistance(ACID, "immune");
  SetResistance(DISEASE, "immune");
}


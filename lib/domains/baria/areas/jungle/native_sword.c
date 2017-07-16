/*  A Buff native */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("native");
  SetShort("a large and burly native");
  SetMorality(300);
  SetId( ({ "native" }) );
  SetAdjectives( ({ "burly", "large" }) );
  SetRace("human");
  SetStat("strength", 1, 1);
  SetClass("fighter");
  SetLevel(20 + random(20) );
  SetInventory( ([
      __DIR__ + "obj/ths" : "wield sword",
      "/domains/baria/towns/baria/obj/loincloth" : "wear loincloth",
    ]) );
  SetLong(
     "This large and burly native is one of the many natives "
     "of the jungle. His complextion is very dark, almost an "
     "ebony color. His scalp is bald, with a thick mat of "
     "stubble upon his face. He stands tall and confident, "
     "suggesting he is proficient at his art as a warrior. "
  );
  SetGender("male");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
 }

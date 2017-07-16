/*  A templar in charge of processing foreigners */
#include <lib.h>
#include "../haven.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetShort("Capet Aliana Banewulf, a Templar of Kylin");
  SetId( ({ "aliana", "banewulf", "templar" }) );
  SetAdjectives( ({ "capet", "kylin" }) );
  SetKeyName("Aliana");
  SetRace("elf");
  SetReligion("Kylin");
  SetLocalCurrency("imperials");
  SetTax(100);
  SetTown("Haven");
  SetClass("priest");
  SetSkill("enchantment", GetLevel()*3, 1);
  SetLevel(70);
  SetMorality(1250);
  SetCurrency("imperials",random(1500)+1);
  SetSpellBook( ([
    "smite"         : 100,
    "wall of force" : 100,
    "revive"        : 100,
    "wrath"         : 100,
    ]) );
  SetAction(15, ({
      "!speak Your requests for citizenship may be processed here.",
      "!speak I am responsible for new citizenship requests.",
      "!speak My cousin Annax has been overthrown.",
    }) );
  SetCombatAction(20, ({
     "!cast wall of force",
     "!cast touch of death",
     "!cast smite",
     "!cast wrath",
     "!cast revive",
    }) );
  SetLong("This Templar is in charge of making new citizens out of the "
          "travelling riff-raff that sometimes turn into useful citizens "
          "of Haven Town. By simply asking this templar for citizenship, "
          "even the most vile can be allowed into Duuk's favored "
          "city.");
  SetGender("female");
 }

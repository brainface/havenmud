/*  */
#include <lib.h>
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Taffa");
  SetRace("gelfling");
  SetTown("Arcanith");
  SetBaseLanguage("Koblich");
  SetShort("Taffa, clerk of Arcanith");
  SetId( ({ "taffa", "clerk", "arcanith" }) );
  SetLong(
    "This slender gelfling with simple robes and "
    "inkstained hands seems out of place in the cold "
    "ruins. She seems to have abandoned the wandering "
    "gelfling life to provide scribe duties for the "
    "kobolds that live here."
  );
  SetGender("female");
  SetClass("enchanter");
  SetSpellBook( ([
    "shock"    : 100,
    "fireball" : 100,
    "sphere"   : 100,
    ]) );
  SetLevel(35);
  SetCombatAction(75, ({
    "!cast shock",
    "!cast fireball",
    "!cast sphere",
  }) );
  SetAction(3, ({
    "!say It seems Artzil has found... well, I'm not sure what "
      "exactly, but he's certainly excited about it.",
    "!say The ghost seems disturbed about something of late.",
    "!say The temple at Gurov has promised more aid. It may not "
      "be without cost, of course.",
    "!say Brijhzet reports the new recruits show some potential, but "
      "progress is slow.",
    "!emote scribbles something down on a ledger.",
    "!emote scribbles something down on a ledger.",
  }) );
  SetTaughtLanguages( ({ "Eltherian", "Archaic", "Koblich", "Eetria" }) );
  SetLocalCurrency("senones");
  SetCharge(1500);
  SetReligion("Eclat");
  SetMorality(200);
}


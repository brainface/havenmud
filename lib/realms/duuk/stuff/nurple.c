#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("purple nurple");
  SetMeleeDamageType(MAGIC);
  SetShort("a purple nurple");
  SetId( ({ "nurple" }) );
  SetAdjectives( ({ "small", "purple" }) );
  SetLong("This large beast is a vaguely purple color. "
          "It has several odious habits.");
  SetRace("horse", "nurple");
  RemoveLanguage("Horseish");
  SetLanguage("Nurple", 100, 1);
  SetLevel(1000);
  SetCurrency("imperials", 1);
  SetMorality(750);
  SetGender("male");
  SetAction(10, ({
   "!emote goes, \"%^BOLD%^MAGENTA%^Meep!%^RESET%^\"",
    }) );
  SetClass("animal");
  SetEncounter(1000);
 }

  varargs int eventDie(object killer) {
    object pelt;
  pelt = new("/realms/duuk/stuff/pelt");
  pelt->eventMove(this_object());
  sentient::eventDie(killer);
  }



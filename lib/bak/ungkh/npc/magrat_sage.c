/* Magrat, ogre sage
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Magrat");
  SetRace("ogre");
  SetShort("Magrat the witch");
  SetId( ({ "magrat","witch" }) );
  SetLong(
    "Magrat has unkempt, filthy hair, and small things can"
    " be seen crawling in it. The smell is quite awful,"
    " and the look of ancient cunning which lurks in her"
    " eyes is enough to make anyone shiver.");
  SetGender("female");
  SetClass("enchanter");
  SetSpellBook( ([
     "acid blast" : 100,
     "capsule" : 100,
     "bolt" : 100,
    ]) );
  SetLevel(35);
  RemoveLanguage("Shangtai");
  SetLanguage("Uruk",100,1);
  SetAction(1, ({
    "!say Magrat knows many languages.",
    "!cackle",
    "!emote scratches her head.",
    "!emote glares at you balefully.",
    }) );
  SetCombatAction(15,
      ({ 
        "!cast acid blast",
        "!cast bolt",
        "!cast capsule",
         }) );
  SetTaughtLanguages( ({ "Eltherian", "Uruk", "Sprith" }) );
  SetLocalCurrency("skins");
  SetCharge(4000);
 }

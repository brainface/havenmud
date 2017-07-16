/* Astara Banewulf, Sage v 2.0 compliant */
#include <lib.h>
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("astara Banewulf");
  SetRace("elf");
  SetTown("Haven");
  SetShort("Astara Banewulf, the wife of the mayor");
  SetId( ({ "astara", "astara banewulf", "banewulf" }) );
  SetLong(
    "Astara Banewulf is a regal lady elf that anyone would "
    "know was important. She appears highly intellgent and would "
    "probably be able to teach new things to less knowledgable "
    "individuals."
    );
  SetGender("female");
  SetClass("evoker");
  SetSkill("fire magic",1,2);
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
  SetTaughtLanguages( ({ "Eltherian", "Enlan", "Imperial" }) );
  SetLocalCurrency("imperials");
  SetCharge(1500);
  SetReligion("Kylin");
  SetMorality(450);
 }

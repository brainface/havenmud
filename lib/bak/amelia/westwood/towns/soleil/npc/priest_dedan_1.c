// A priest to help kiee
#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() 
{
  leader::create();
  SetNoJoin(1);
  SetReligion("Eclat","Eclat");
  SetKeyName("Dedan");
  SetShort("Dedan, acolyte priest");
  SetId( ({ "dedan","priest","acolyte" }) );
  SetAdjectives( ({ "dedan","priest","acolyte" }) );
  SetLong("Dedan has milky brown fur covering his entire "
    "body, except a little bit around his eyes and "
    "tiny nose.  He has started learning about "
    "becoming a priest of the Eclats, and his "
    "prodigidous work caused him to be appointed "
    "as Kiee's helper.");
  SetSkill("enchantment",50,1);
  SetClass("cleric");
  SetRace("muezzin");
  SetGender("male");
  SetLevel(25);
  SetSpellBook( ([
    "sanctify" : 100,
    "create flower" : 100,
    "disperse protections" : 100,
    "create rose" : 100,
    "cheerful obstacles" : 100,
    "create golden ball" : 100,
    "create meza" : 100,
    "harm evil" : 100,
    "divine magic" : 100,
    "divine magic fully" : 100,
    "bless" : 100,
    "blessed water" : 100,
    "create sacred candle" : 100,
    "divine mana" : 100,
    "cure blindness" : 100,
    "dispel poison" : 100,
    "mend" : 100,
    "revive" : 100,
  ]) );
  SetAction(8, ({ "!cast cheerful obstacles",
    (: eventCompleteHeal(30) :),
    "!cast sanctify" }) );
  SetCombatAction(20, ({ "!cast sanctify" }) );
}

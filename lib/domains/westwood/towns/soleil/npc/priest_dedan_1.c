// A priest to help kiee
#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() 
{
  leader::create();
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
  SetRace("muezzin");
  SetClass("priest");
  SetSkill("melee combat",1,1);
  SetGender("male");
  SetLevel(25);
  SetSpellBook( ([
    "sanctify" : 100,
    "dispel poison" : 100,
    "mend" : 100,
    "revive" : 100,
  	]) );
  SetAction(8, ({ 
    "!cast sanctify" }) );
  SetCombatAction(20, ({ 
  	"!cast sanctify" 
  	}) );
}

// A priest to help kiee
#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
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
           "as Kiee's helper.  Dedan teaches basic Eclat "
           "spells.");
   SetRace("muezzin");
   SetClass("priest");
   SetSkill("melee combat",1,1);
   
   SetGender("male");
   SetUniqueSkills( ([
      ]) );
   SetLevel(10);
   SetSpellBook( ([
      "mend" : 100,
      "divine magic fully" : 100,
      "cure blindness" : 100,
      "dispel poison" : 100,
      "revive" : 100,
       ]) );
/*
   SetAction(8, ({ "!say I can help less experienced Eclat clerics!  "
                   "I teach the less difficult spells so Kiee "
                   "can do more important things!","!smile",
                   "!emote looks cheerful.","!cast cheerful "
                   "obstacles","!cast cheerful obstacles on "
                   "kiee","!cast create flower","!cast create "
                   "rose", (: eventCompleteHeal(30) :),
                   "!cast bless on kiee",
                   "!cast create meza","!drink first meza" }) );
*/
   SetCombatAction(20, ({ 
   		"!shout Help!  Help!",
   		"!shout The joyful priest are being attacked!",
      }) );
}

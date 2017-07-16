// A priest to help kiee
#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
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
           "as Kiee's helper.  Dedan teaches basic Eclat "
           "spells.");
   SetClass("cleric");
   SetRace("muezzin");
   SetGender("male");
   SetUniqueSkills( ([
                       "healing" : 1,
                       "melee attack" : 1,
                       "enchantment" : 1,
                       "divination" : 2,
                       "blunt defense" : 3,
                       "bargaining" : 2,
                       "slash defense" : 3,
                       "melee defense" : 3,
                       "fishing" : 2,
                       "armour smithing" : 4,
                       "weapon smithing" : 4,
                       "leather working" : 4,
                       "metal working" : 4,
                  ]) );
   SetLevel(10); //
   SetSpellBook( ([
                    "mend heavy" : 100,
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
   SetCombatAction(20, ({ "!shout Help!  Help!","!shout The joyful "
                          "priest are being attacked!",
                          "!cast harm evil" }) );
   SetTaughtSpheres( ({"clerical healing","clerical enchantment",
      "clerical divination","clerical"}) );
}

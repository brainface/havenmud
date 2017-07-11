/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: f_jidoor_bird.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is an inhabitant of Jidoor Forest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_NPC;

static void create() 
{
  npc::create();
  SetKeyName("female jidoor bird");
  SetShort("a female jidoor bird");
  SetId( ({ "bird" }) );
  SetLong("The female jidoor bird is common only in the Jidoor Forest. It "
          "is said that to harm one is to insult the god of magic. She has a "
          "large beak and its feathers are a brilliant red color. She stands "
          "nearly three feet tall and she looks relatively tough.");
  SetRace("bird");
  SetAdjectives( ({ "jidoor","female" }) );
  SetGender("female");
  SetClass("animal");
  SetLevel(5+random(3));
  SetSkill("evokation", 8, 1);
  SetSkill("conjuring", 8, 1);
  SetStat("durability", 25);
  SetStat("intelligence", 20);
  SetSpellBook( ([ "aura" : 100,]) );
  SetAction(6, ({ 
          "A female jidoor bird sings a song to its mate.",
          "A female jidoor bird flutters about quietly.",
          "A female jidoor bird lands on a nearby branch."
               }) );
  SetFriends(({"a male jidoor bird"}) );
  SetCombatAction(15, ({ "!cast aura" }) );
  SetDie("As the female jidoor bird falls to the ground dead, ominous "
         "thunder can be heard from above.");
}

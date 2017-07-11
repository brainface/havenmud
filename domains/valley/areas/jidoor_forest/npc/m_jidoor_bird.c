/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: m_jidoor_bird.c
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
  SetKeyName("a male jidoor bird");
  SetShort("a male jidoor bird");
  SetId( ({ "bird" }) );
  SetLong("The male jidoor bird is common only in the Jidoor Forest. It is "
          "said that to harm one is to insult the god of magic. He has a "
          "large beak and its feathers are a brilliant blue color. He "
          "stands nearly three feet tall and he looks relatively tough.");
  SetRace("bird");
  SetAdjectives( ({ "jidoor","male" }) );
  SetGender("male");
  SetClass("animal");
  SetLevel(5+random(3));
  SetStat("durability", 25);
  SetStat("intelligence", 20);
  SetSkill("evokation", 8, 1);
  SetSkill("conjuring", 8, 1);
  SetSpellBook( ([ 
  	"aura" : 100,
  	]) );
  SetAction(6, ({ 
         "A male jidoor bird sings a song to its mate.",
         "A male jidoor bird flutters about quietly.",
         "A male jidoor bird lands on a nearby branch."
               }) );
  SetFriends(({"a male jidoor bird"}) );
  SetCombatAction(15, ({ 
  	"!cast aura" 
  	}) );
  SetDie("As the male jidoor bird falls to the ground dead, ominous "
         "thunder can be heard from above.");
}

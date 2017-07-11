#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("large furry thing");
  SetMeleeAttackString("feelers");
  SetMeleeDamageType(MAGIC);
  SetFriends("furry thing");
  SetShort("a large, furry thing");
  SetReligion("Kylin");
  SetId( ({ "thing" }) );
  SetAdjectives( ({ "large", "furry" }) );
  SetLong("This is a large furry thing.");
  SetRace("thing",1);
  SetLanguage("Fizgig", 100,1 );
  AddLimb("poofy body", 0, 1, ({ }) );
  AddLimb("right feeler", "poofy body", 4, ({ }) );
  AddLimb("left feeler", "poofy body", 4, ({ }) );
  SetStat("agility",12,3);
  SetStat("durability",8,5);
  SetStat("luck",20,1);
  SetStat("strength", 5, 5);
  SetStat("charisma", 60, 1);
  SetStat("intelligence", 2, 4);
  SetStat("wisdom", 5, 3);
  SetClass("animal");
  SetLevel(60);
  SetMorality(750);
  SetGender("male");
  SetDie("The thing makes a soft noise, like a sigh, as it dies.");
  SetAction(10, ({
     "!smile",
     "!emote purrs nicely.",
     "!emote makes a weird noise.",
     "!emote makes a cooing sound.",
     "!emote looks for someone to snuggle.",
    }) );
 
 }



#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("furry thing");
  SetMeleeAttackString("feelers");
  SetMeleeDamageType(MAGIC);
  SetFriends("furry thing");
  SetShort("a small, furry thing");
  SetId( ({ "thing" }) );
  SetAdjectives( ({ "small", "furry" }) );
  SetLong("This is a small furry thing.  Its pelt looks nice.");
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
  SetLevel(30);
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
  SetClass("animal");
 }

  varargs int eventDie(object killer) {
    object pelt;
  pelt = new("/realms/duuk/stuff/pelt");
  pelt->eventMove(this_object());
  sentient::eventDie(killer);
  }



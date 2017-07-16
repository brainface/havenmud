#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("furry thing");
  SetFriends("furry thing");
  SetShort("%^BLUE%^a small, furry thing%^RESET%^");
  SetId( ({ "furry", "thing", "furry thing" }) );
  SetAdjectives( ({ "small", "furry" }) );
  SetLong("This is a small furry thing.  Its pelt looks nice.");
  SetRace("thing",1);
  AddLimb("poofy body", 0, 1, ({ }) );
  AddLimb("right feeler", "poofy body", 4, ({ }) );
  AddLimb("left feeler", "poofy body", 4, ({ }) );
  SetStat("agility",12,3);
  SetStat("coordination",20,2);
  SetStat("durability",8,5);
  SetStat("luck",20,1);
  SetStat("strength", 5, 5);
  SetStat("charisma", 60, 1);
  SetStat("intelligence", 2, 4);
  SetStat("wisdom", 5, 3);
  SetStat("speed", 20, 2);
  SetLevel(1);
  SetGender("male");
  SetDie("The thing makes a soft noise, like a sigh, as it dies.");
  SetAction(2, ({
     "!smile",
     "!emote purrs nicely.",
     "!emote makes a wierd noise.",
     "!emote makes a cooing sound.",
     "!emote looks for someone to snuggle.",
    }) );
  SetClass("valkyr");
 }

  eventDie(object killer) {
    object pelt;
  pelt = new("/realms/duuktsaryth/stuff/pelt");
  pelt->eventMove(this_object());
  npc::eventDie(killer);
  }


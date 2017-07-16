#include <lib.h>
#include <climb.h> 
inherit LIB_SENTIENT;

int CheckEvil();

static void create() {
   sentient::create();
   SetKeyName("protector");
   SetShort("protector of the forest");
   SetId( ({ "protector" }) );
   SetLong("The protector of the forest is possible the largest "
     "treant to ever walk Kailie.  He easily stands over a hundred "
     "feet tall and has a thick layer of bark covering his body.  "
     "He has branches that are as thick as most of the trees in "
     "area and leaves as tall as a normal man.");
   SetProperty("noleave",1);
   SetLimit(1);
   SetRace("giant","treant");
   SetGender("male");
   SetClass("cavalier");
   SetClass("cleric");
   SetLevel(75);
   SetMorality(1000);
   SetReligion("Eclat");
   SetSpellBook( ([
      "harmony hand" : 100,
      "sanctify" : 100,
      "pious obstructions" : 100,
      "guardian angel" : 100,
      "bloom" : 100,
      "sphere of happiness" : 100,
      "harm evil" : 100,
               ]) );
   SetFriends( ({ "deer","bear","tarantula","wolf","rabbit",
      "blue jay","butterfly","wanderer","muezzin","halfling","raven",
      "gelfling","raven" }) );
   SetAction(2, ({ "!cast sphere of happiness","!cast guardian "
                   "angel" }) );
   SetCombatAction(35, ({ "!cast harm evil","!cast guardian angel" }) );
   SetAction(50, ({ "!go west","!go east","!go north","!go south",
      "!go northeast","!go northwest","!go southeast","!go southwest",
    }) );
   SetEncounter( (: CheckEvil :) );
   SetNoClean(1);
   SetStat("strength",150,1);
   SetStat("durability",150,1);
   SetStat("intelligence",150,1);
   SetStat("wisdom",150,1);
   SetStat("speed",1);
   SetStat("agility",1);
   SetSkill("pierce defense",135,1);
   SetSkill("slash defense",135,1);
   SetSkill("pierce attack",135,1);
   SetSkill("slash attack",135,1);
   SetSkill("faith",135,1);
   SetSkill("melee attack",135,1);
   SetSkill("enchantment",135,1);
   SetSkill("healing",135,1);
}

int CheckEvil() {
  if ((this_player()->GetMorality() < -350) && (this_player()->GetLevel() > 25)) {
      eventForce("speak You are not welcome here!");
      return 1;
    }
  return 0;
 }


void eventDie(object killer) {
  object ob;
  string loc;
  int xline = random(30);
  int yline = random(30);
  loc = xline + "," + yline;
  ob = new("/domains/new_westwood/virtual/npc/protect");
  ob->eventMove("/domains/westwood/virtual/westwood/" + loc);
  ::eventDie(killer);
 }

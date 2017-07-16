#include <lib.h>
#include <armour_types.h>
inherit LIB_NPC;
inherit LIB_SMELL;
#include "../castle.h"

int TalkOut();

static void create() {
   npc::create();
   SetKeyName("Darken Scarzam");
   SetShort("Darken Scarzam, the phantom");
   SetId( ({ "darken","scarzam","phantom","darken scarzam" }) );
   SetAdjectives( ({ }) );
   SetLong("Decay has filled Darken's eyes, and so has sadness.  "
           "His limbs are tired and old, old beyond death as Darken "
           "is already half-dead, wandering the world of the living "
           "in an obscene parody of life.  Anger also hides inside him, "
           "for he cannot seem to escape this world he so wants to leave "
           "behind.");
   
   SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   SetLanguage("Runic",100,1);
   SetProperty("vale_undead", 1);
   SetRace("phantom",1);
   SetGender("male");
   SetClass("fighter");
   SetLevel(27);
   SetUndead(1);
  
   AddLimb("torso",0,1, ({ }) );
   AddLimb("head","torso",1, ({ }) );
   AddLimb("left arm","torso",3,({ }) );
   AddLimb("left leg","torso",2,({ }) );
   AddLimb("right arm","torso",3,({ }) );
   AddLimb("right leg","torso",2,({ }) );
   AddLimb("left hand","left arm",4,({ A_WEAPON }) );
   AddLimb("left foot","left leg",4,({ }) );
   AddLimb("right hand","right arm",4,({ A_WEAPON }) );
   AddLimb("right foot","right leg",4,({ }) );
   SetStat("charisma",1,5);
   SetStat("coordination",20,3);
   SetStat("speed",23,2);
   SetStat("luck",5,5);
   SetStat("wisdom",38,2);
   SetStat("durability",38,2);
   SetStat("intelligence",35,2);
   SetStat("strength",51,1);
   SetStat("agility",19,4);
   SetMorality(-250);
   SetEncounter( (: TalkOut :) );
   SetSmell("The stench of Darken's rotting flesh is putrid and "
            "disguisting.");
   SetInventory( ([
                    VC_OBJ + "/c_jewel" : 1,
                    VC_OBJ + "/c_axe" : "wield axe",
               ]) );
}

int TalkOut() {
 object who = this_player();
  if (!(who->GetProperty("vale_undead"))) {
    SetAttack(who);
    eventForce("say I cannot stand my life, what life is left of it.  "
              "I had a family, a wonderful family, but they died, a "
              "disease struck them and made them wither and fall, "
              "begging for mercy, for my help!  The only comfort that "
              "I can find is to forget those days and every time I "
              "see something alive it makes me remember!  Die, die, for "
              "reminding me!");
    return 1;
  }
 return 0;
}

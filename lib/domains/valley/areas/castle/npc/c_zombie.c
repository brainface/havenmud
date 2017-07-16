#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"
int CheckVale();

static void create() {
   npc::create();
   SetKeyName("decomposing zombie");
   SetShort("a slowly decomposing zombie");
   SetId( ({ "zombie" }) );
   SetAdjectives( ({ "slowly decomposing","decomposing" }) );
   SetLong("Dents have formed in the vaguely human-like face of the "
           "zombie; however, even those a slightly human form is "
           "resembled by the zombie, he looks mostly like a heap "
           "of flesh that is slowly rotting.  Somehow, he stays together "
           "and doesn't fall about at the lightest touches.");
   
   SetClass("rogue");
   SetLevel(19+random(3));
   SetMorality(-80);
   SetUndead(1);
   SetEncounter( (: CheckVale :) );
   SetProperty("vale_undead", 1);
   SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   SetGender("male");
   SetRace("zombie",1);
   AddLimb("torso",0,1,({ }) );
   AddLimb("head","torso",1,({ }) );
   AddLimb("left arm","torso",4,({ }) );
   AddLimb("left leg","torso",3,({ }) );
   AddLimb("left hand","left arm",5,({ }) );
   AddLimb("left foot","left leg",5,({ }) );
   AddLimb("right arm","torso",4,({ }) );
   AddLimb("right leg","torso",3,({ }) );
   AddLimb("right hand","right arm",5,({ }) );
   AddLimb("right foot","right leg",5,({ }) );
   SetStat("charisma",5,5);
   SetStat("coordination",27,3);
   SetStat("speed",29,2);
   SetStat("luck",30,5);
   SetStat("wisdom",10,2);
   SetStat("durability",35,2);
   SetStat("intelligence",10,2);
   SetStat("strength",25,1);
   SetStat("agility",30,4);
   SetInventory( ([
                    VC_OBJ + "/c_gd_chp" : 2+random(4),
               ]) );
}
int CheckVale() {
  object who = this_player();
  if (!(who->GetProperty("vale_undead"))) {
    SetAttack(who);
  return 1;
  }
return 0;
}

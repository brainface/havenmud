/* a llama
*/
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("llama");
  SetShort("a small llama");
  SetId("llama");
  SetAdjectives( ({ "small"}) );
  SetLong("This small llama is quite cute but appears to be a very "
         "strong animal.");
  SetAction(5,({"The llama spits at your feet."}) );
  SetGender("male");
  SetRace("llama",1);
  AddLimb("torso",0,1);
  AddLimb("head","torso",1);
  AddLimb("back right leg","torso",2);
  AddLimb("back left leg","torso",2);
  AddLimb("front left leg","torso",2);
  AddLimb("front right leg","torso",2);
  AddLimb("front right hoof","front right leg",4);
  AddLimb("front left hoof","front left leg",4);
  AddLimb("back left hoof","back left leg",4);
  AddLimb("back right hoof","back right leg",4);
  AddLimb("tail","torso",4);
  
  AddStat("strength", 10, 3);
  AddStat("durability", 10, 3);
  AddStat("agility", 15, 5);
  
  SetClass("animal");
  SetLevel(7);
  
  }

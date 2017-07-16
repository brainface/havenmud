/* a large moose
    kyla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("moose");
  SetShort("a big moose");
  SetLong("This is an exceptionally large moose. His antlers are "
           "absolutely huge.");
  SetId( ({"moose"}) );
  SetAdjectives( ({"large"}) );
  
  SetRace("moose", 1);
  AddLimb("torso", 0,1);
  AddLimb("head","torso",1);
  AddLimb("front right leg", "torso", 2);
  AddLimb("front left leg","torso", 2);
  AddLimb("back left leg","torso", 2);
  AddLimb("back right leg", "torso", 2);
  AddLimb("front right hoof","front right leg",4);
  AddLimb("front left hoof","front left leg",4);
  AddLimb("back left hoof","back left leg",4);
  AddLimb("back right hoof","back right leg",4);
  AddLimb("tail", "torso",4);
  AddLimb("antlers", "head", 3);
  SetClass("animal");
  SetLevel(12);
  SetGender("male");
  SetAction(5, "The moose eyes you over carefully.");
  AddStat("strength", 35, 3);
  AddStat("durability", 15, 5);
  AddStat("agility", 20, 5);
  }

int eventDie(object agent) {
  object antlers;

  antlers = new(MANSION_OBJ + "moose_antlers");
  antlers->eventMove(this_object());
  return(npc::eventDie(agent));
  }


//Illura@Haven
//Nov 2010
#include <lib.h>
#include <daemons.h>
#include "../oil.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("ooze lurker");
  SetId( ({ "lurker" }) );
  SetShort("an ooze lurker");
  SetAdjectives( ({"ooze"}) );
  SetLong(
    "This disgusting ooze creature is made up of oil from its environment "
    "and a decaying, evil spirit from somewhere below. It cascades "
    "in shapeless form from one place to the next, swallowing up "
    "everything in its path. You swear you can almost hear a "
    "burbling, dark laughter coming from within it.");
  SetRace("slime", 1);
  SetClass("horror");
  SetLevel(120);
  SetMorality(0);
  SetNoCorpse(1);
  SetDie("%^RED%^The ooze suddenly dissolves back into the "
         "ground from whence it came.%^RESET%^");
  AddLimb("torso", 0, 1);
  AddLimb("first pseudopod", "torso", 3);
  AddLimb("second pseudopod", "torso", 3);
  AddLimb("third pseudopod", "torso", 3);
  AddLimb("fourth pseudopod", "torso", 3);
  AddLimb("fifth pseudopod", "torso", 3);
  AddLimb("sixth pseudopod", "torso", 3);
  AddLimb("seventh pseudopod", "torso", 3);
  AddLimb("eighth pseudopod", "torso", 3);
  AddLimb("ninth pseudopod", "torso", 3);
  AddLimb("tenth pseudopod", "torso", 3);
  AddLimb("first globule", "first pseudopod", 5);
  AddLimb("second globule", "second pseudopod", 5);
  AddLimb("third globule", "third pseudopod", 5);
  AddLimb("fourth globule", "fourth pseudopod", 5);
  AddLimb("fifth globule", "fifth pseudopod", 5);
  AddLimb("sixth globule", "sixth pseudopod", 5);
  AddLimb("seventh globule", "seventh pseudopod", 5);
  AddLimb("eighth globule", "eighth pseudopod", 5);
  AddLimb("ninth globule", "ninth pseudopod", 5);
  AddLimb("tenth globule", "tenth pseudopod", 5);
  SetEncounter( (: eventCheckPlayer :) );
  SetAction(5, ({
    "!emote bubbles and oozes evilly.",
    "!emote unctuously slides around, subsuming things in its path."
    }) );
  SetCombatAction(3, ({
    "!emote opens what appears to be a gaping maw at you.",
    "!emote extends a pseudopod in an attempt to devour you."
    "!emote lashes itself around in an oily rage."
    }) );
  }

int eventCheckPlayer() {
    object who = this_player();
    if (userp(who)) {
      SetAttack(who);
      return 1;
      }
    else return 0;
  }

varargs int eventDie(object agent) {
  string *stuff_dir;
  object stuff;
  stuff_dir = get_dir(OIL_OBJ);
  stuff = new(OIL_OBJ + stuff_dir[random(sizeof(stuff_dir))]);
  stuff->eventMove(environment(this_object()));
  return ::eventDie(agent);

}

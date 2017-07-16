//Illura@Haven
//Nov 2010
#include <lib.h>
#include <daemons.h>
#include "../oil.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("Snurkh the Muculent");
  SetId( ({ "snurkh" }) );
  SetShort("Snurkh the Muculent");
  SetAdjectives( ({"muculent"}) );
  SetLong(
    "Snurkh is one of the lurking oozes that has consumed so "
    "much in its time that it has grown legendary enough to "
    "be named. It towers over the land and is known for "
    "its ability to shift quickly from one place to the next, "
    "more speedily than the other slime creatures. If fable "
    "is to be believed, Snurkh holds within itself the bodies "
    "of many adventurers it has devoured.");
  SetRace("slime", 1);
  SetClass("horror");
  SetLevel(130);
  SetMorality(0);
  SetNoCorpse(1);
  SetDie("%^RED%^The ooze suddenly dissolves back into the "
         "ground, leaving behind its innards.%^RESET%^");
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
  SetCurrency("crystals", 1000 + random(1000));
  SetAction(5, ({
    "!emote bubbles and oozes evilly.",
    "!emote unctuously slides around, subsuming things in its path.",
    "!emote opens what appears to be a gaping maw at you.",
    "!emote extends a pseudopod in an attempt to devour you."
    }) );
  SetCombatAction(3, ({
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

varargs int eventDir(object agent) {
  string *stuff_dir;
  object stuff;
  
  stuff_dir = get_dir(OIL_OBJ);
  stuff = new(OIL_DIR + stuff_dir[random(sizeof(stuff_dir))]);
  stuff->eventMove(environment());
  stuff->eventMove(environment());
  stuff->eventMove(environment());
  return ::eventDie(agent);

}

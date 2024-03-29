//Illura@Haven
//Nov 2010
#include <lib.h>
#include <daemons.h>
#include "../oil.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("fetid tar creature");
  SetId( ({ "creature" }) );
  SetShort("a fetid tar creature");
  SetAdjectives( ({"fetid", "tar"}) );
  SetLong(
    "This fetid ooze spawned from the slime of the Great Oil Ocean "
    "to become something not quite alive. It attacks without purpose "
    "or will, only to consume whatever falls into its path. It is not "
    "something to be tangled with.");
  SetRace("slime", 1);
  SetClass("horror");
  SetLevel(100);
  SetMorality(0);
  SetNoCorpse(1);
  SetDie("%^RED%^The ooze suddenly dissolves back into the "
         "ground, leaving behind a mess.%^RESET%^");
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
    "!emote bubbles and oozes.",
    "!emote burbles and goops.",
    "!emote unctuously slides around, subsuming things in its path."
    }) );
  SetCombatAction(3, ({
    "!emote opens what appears to be a gaping maw at you.",
    "!emote extends a pseudopod in an attempt to eat you."
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
  return ::eventDie(agent);

}

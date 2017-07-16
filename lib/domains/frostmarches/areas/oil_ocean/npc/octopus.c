//Illura@Haven
//Nov 2010
#include <lib.h>
#include <daemons.h>
#include "../oil.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("black octopus");
  SetId( ({ "octopus" }) );
  SetShort("a black octopus");
  SetAdjectives( ({"black"}) );
  SetLong(
    "This is a giant octopus, so covered in ooze that only his beady red "
    "eyes are visible. He has eight legs and an angry disposition.");
  SetRace("squid");
  SetGender("male");
  SetClass("animal");
  SetLevel(80);
  SetMorality(-200);
  SetEncounter( (: eventCheckPlayer :) );
  SetAction(5, ({
    "!emote spurts ink.",
    "!emote flips his tentacles at you angrily.",
    }) );
  SetCombatAction(3, ({
    "!emote slaps his tentacles furiously."
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

//Illura@Haven
//Nov 2010
#include <lib.h>
#include <daemons.h>
#include "../oil.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("ravening oilhorse");
  SetId( ({ "oilhorse", "horse","seahorse" }) );
  SetShort("a ravening oilhorse");
  SetAdjectives( ({"ravening","sea","oil"}) );
  SetLong(
    "This is a giant black seahorse, her long ebony body covered with "
    "spines and spars that look very sharp. She is hot tempered by "
    "nature and not easy to get along with, much less ride around.");
  SetRace("horse");
  SetGender("female");
  SetClass("animal");
  SetLevel(80);
  SetMorality(-200);
  SetEncounter( (: eventCheckPlayer :) );
  SetAction(5, ({
    "!emote whinnies a terrible death whinny.",
    "!snort",
    "!emote circles and dances."
    }) );
  SetCombatAction(3, ({
    "!emote screams out a shrill neigh of terror."
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



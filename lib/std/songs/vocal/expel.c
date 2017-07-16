/*  A spell to nuke germs */
#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("expulsion");
  SetSongType(SONG_HEALING);
  SetRules("");
  SetMagicCost(30, 30);
  SetMagicCost(10, 10);
  SetSkills( ([
       "vocal music" : 25,
    ]) );
  SetDifficulty(40);
  SetHelp(
    "This song attempts to force a germ to be expelled from "
    "the body of the singer."
  );
  }


int eventSing(object who, int level, mixed u, object *targets) {
  object *germ;
  object sicko = targets[0];

  germ = filter(all_inventory(sicko), (: $1->GetProperty("germ") :) );
  if (!sizeof(germ)) { who->eventPrint("But that person is not diseased!"); return 1; }
  
  if (level + (who->GetStatLevel("luck")) < germ[0]->GetCureChance()) {
      send_messages( ({ "attempt", "fail" }),
      "$agent_name $agent_verb to expell a disease from "
      "$agent_possessive body and $agent_verb.",
         who, sicko, environment(who) );
     return 1;
    }
  send_messages("expel",
    "$agent_name $agent_verb a disease from $agent_possessive "
    "body.",
     who, sicko, environment(who) );
    germ[0]->eventDestruct();
   return 1;
 }

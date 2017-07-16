/*  A trainer to teach combat styles. */
/* Race restriction added by Laoise, 2005 */

#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;
int eventTeachStyle(object who, string command, string style);
int RaceRestricted;

static void create() {
  npc::create();
  AddCommandResponse("teach", (: eventTeachStyle :) );
  }

int SetRaceRestricted(int arg) { return (RaceRestricted = arg); }

int GetRaceRestricted() { return (RaceRestricted); }

int eventTeachStyle(object who, string command, string style) {
  object ob;
  if (!style) {
    eventForce("speak I know " + conjunction(keys(GetCombatStyles())));
    return 1;
    }
  if (!GetCombatStyleLevel(style)) {
    eventForce("speak I don't know that style of fighting, sorry.");
    return 1;
    }
  if(!(ob = STYLES_D->GetStyle(style))) {
    eventForce("emote looks a bit confused.");
    return 1;
    }
  if (GetRaceRestricted() && (who->GetRace() != GetRace()) ) {
    eventForce("speak I do not deal with those of your race.");
    return 1;
    }
  foreach(string skill in ob->GetSkills()) {
    if (who->GetSkillLevel(skill) < ob->GetRequiredSkill(skill)) {
      eventForce("speak You are not prepared to learn that style.");
      return 1;
      }
    }
  if (ob->GetTrainingPointCost() > who->GetDevelopmentPoints()) {
  	eventForce("speak You are not prepared to learn that style.");
  	who->eventPrint("That style requires " + ob->GetTrainingPointCost() + 
  	                " developement points.");
  	return 1;
  }
  send_messages( ({ "show", "explain" }),
    "$agent_name $agent_verb a few techniques of " + style +
    " and $agent_verb the rest to $target_name.", this_object(),
    who, environment() );
  who->AddCombatStyle(style);
  who->AddDevelopmentPoints(-(ob->GetTrainingPointCost()));
  return 1;
}

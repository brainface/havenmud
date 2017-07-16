#include <lib.h>
#include <position.h>
#include <std.h>
#include <daemons.h>
#include "../averath.h"
inherit LIB_STYLE_TRAINER;

int eventTeachStyle(object who, string command, string style);

static void create() {
  ::create();
  SetKeyName("old warrior");
  SetId( ({ "warrior" }) );
  SetAdjectives( ({ "wise-looking", "old", "wise" }) );
  SetShort("a wise-looking old warrior");
  SetLong("This old warrior from the lands of Averath "
          "seems to be sitting, deep in thought. He has a long, grey beard, "
          "extending well below the base of his neck.");
  
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Avera", 100, 1);
  SetClass("priest");
  SetLevel(50);
  SetGender("male");  
  
  SetMorality(0);
  SetInventory( ([     
      STD_CLOTHING + "body/gray_robe" : "wear robe",
    ]) );
  SetAction(5, ({
     "!sit down",     
     }) );
  SetRaceRestricted(1);
  SetCombatStyleLevel("juego del palo", 100);
  SetCombatStyle("juego del palo");
  SetPosition(POSITION_SITTING);
}

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
  if (who->GetReligion() != "Aetarin") {
  	eventForce("speak I only deal with those faithful to Aerelus!");
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

// For players to convert other players to their religion
// do_convert rewritten by Laoise, March 2005

#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("convert");
  SetRules("", "LIV");
  SetHelp(
    "Syntax:       convert \n"
    "              convert LIV \n\n"
    "Using this with no syntax allows you to be converted. "
    "With a syntax allows you to convert someone to your "
    "religion."
  );
}

mixed can_convert() {
  return 1;
}

mixed can_convert_liv() {
  object who = this_player();

  if (who->GetSleeping()) {
    return "You are asleep.";
  }
  if (who->GetParalyzed()) {
    return "You cannot move.";
  }
  return 1;
}

mixed do_convert() {
  object who = this_player();

  if (!who->GetProperty("converting")) {
    who->SetProperty("converting", 1);
    who->eventPrint("You are ready to convert.");
    return 1;
  }
  who->RemoveProperty("converting");
  who->eventPrint("You no longer wish to convert.");
  return 1;
}

mixed do_convert_liv(object target) {
  object who = this_player();
  string skill;
  int x;

  if(target->GetKeyName() == who->GetKeyName()) {
    who->eventPrint("Well that's just silly.");
    return 1;
  }
  if(target->GetUndead()) {
    who->eventPrint("The dead lack free will!");
    return 1;
  }
  if(target->GetReligion() == who->GetReligion()) {
    who->eventPrint(target->GetCapName()+ " is already of your religion.");
    return 1;
  }
  if(target->GetProperty("faithless")) {
    who->eventPrint(target->GetCapName()+ " has shown a lack "
    "of faith in the past and cannot be converted without divine "
    "intervention.");
    return 1;
  }

  if (target->GetReligion() != "agnostic") {
  who->eventPrint(target->GetCapName() + " must renounce their current faith"
               " before you can convert them.");
  return 1;
  }
  if (target->GetReligion() == "agnostic") {
    send_messages("convert",
      "$agent_name $agent_verb $target_name to " + who->GetReligion() +
      ".", who, target, environment(who) );
    CHAT_D->eventSendChannel("Conversion", "prayer",
      capitalize(who->GetKeyName()) + " has converted " +
      capitalize(target->GetKeyName()) + " to " +
    who->GetReligion() + ".");
    target->SetReligion(who->GetReligion());
    target->RemoveProperty("converting");
    return 1;
  }

/*
  if ((target->GetReligion() == "Eclat" && target->GetSkillLevel("natural magic"))
    || (target->GetSkillLevel("faith"))) {
    target->eventPrint("%^YELLOW%^You feel pain at the loss of your Diety.%^RESET%^");
    foreach(skill in target->GetSkills()) {
      x = random(40 - target->GetSkillClass(skill))/2;
      while( x-- )
      target->AddSkillPoints(skill, -target->GetMaxSkillPoints(skill,
      target->GetBaseSkillLevel(skill)));
    }
    foreach(string title in target->GetTitles()) {
      target->RemoveTitle(title);
    }
  }
  if (target->GetReligion() == "Eclat" && target->GetSkillLevel("natural magic")) {
    target->SetSkill("natural magic", 0);
  } else {
    if (target->GetSkillLevel("faith")) {
      target->SetSkill("faith", 0);
    } else {
      target->eventPrint("%^YELLOW%^You feel pain at the loss of your Diety.%^RESET%^");
      foreach(skill in target->GetSkills()) {
        x = random(20 - target->GetSkillClass(skill))/2;
        while( x-- )
        target->AddSkillPoints(skill, -target->GetMaxSkillPoints(skill,
        target->GetBaseSkillLevel(skill)));
      }
    }
  }
  */
  send_messages("convert",
    "$agent_name $agent_verb $target_name to " + who->GetReligion() +
    ".", who, target, environment(who) );
  CHAT_D->eventSendChannel("Conversion", "prayer",
    capitalize(who->GetKeyName()) + " has converted " +
    capitalize(target->GetKeyName()) + " to " +
  who->GetReligion() + ".");
  target->SetReligion(who->GetReligion());
  target->RemoveProperty("converting");
  target->SetPermanentProperty("faithless", 1);
  return 1;
}


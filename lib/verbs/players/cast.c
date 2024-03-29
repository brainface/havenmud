/*    /verbs/players/cast.c
 *    From Dead Souls LPMud
 *    Created by Descartes of Borg 951027
 *    Version: @(#) cast.c 1.4@(#)
 *    Last modified: 96/12/16
 */

#include <lib.h>
#include <daemons.h>
#include <conditions.h>
#include <magic.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("cast");
    SetRules("STR", "STR on OBJ", "STR on STR", "STR on STR of OBJ",
	     "STR against STR");
  SetErrorMessage("Cast what on what?");
    SetHelp("Syntax: <cast SPELL>\n"
	    "        <cast SPELL on LIMB>\n"
	    "        <cast SPELL against STRING>\n"
	    "        <cast SPELL on TARGET>\n"
	    "        <cast SPELL on LIMB of TARGET>\n\n"
	    "Allows you to cast any spell using whatever syntax the "
	    "spell in question requires.  To heal someone, for example, "
            "\"cast heal on descartes\".  \n"
     );
}

mixed can_cast_str(string spell) {
  object tmp = SPELLS_D->GetSpell(spell);
  if (this_player()->GetCombatStyle()) return "You can't cast while using a combat style.";
  if( tmp ) {
    string verb = tmp->GetVerb();
	  if( verb != "cast" ) return "That is not a spell you cast.";
    }
  if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
  if (!environment(this_player())) { return "You have bigger problems."; }
  if(this_player()->GetConditionFlag(CONDITION_PREVENT_MAGIC)) { 
    return "Something prevents you from casting.";
  }
  if(this_player()->GetConditionFlag(CONDITION_PREVENT_TALK)) {
    return "Something prevents you from speaking."; 
  }
  if (tmp && tmp->GetSkills() && member_array("healing",tmp->GetSkills()) != -1 ) {               
    if(this_player()->GetConditionFlag(CONDITION_PREVENT_MAGIC_HEALING)) { 
      return "Your can't concentrate on healing magic.";
    }
  }
  return this_player()->CanCast(tmp);
}                               

mixed can_cast_str_on_obj(string spell) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return can_cast_str(spell);
}

mixed can_cast_str_on_str(string spell) {
    return can_cast_str(spell);
}

mixed can_cast_str_against_str(string spell) {
    return can_cast_str(spell);
}

mixed can_cast_str_on_str_of_str(string spell) {
   return can_cast_str(spell);
}

mixed do_cast_str(string spell) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return this_player()->eventPrepareCast(spell);
}

mixed do_cast_str_on_obj(string spell, object target) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return this_player()->eventPrepareCast(spell, target);
}

mixed do_cast_str_against_str(string spell, object target) {
    return this_player()->eventPrepareCast(spell, target);
}

mixed do_cast_str_on_str(string spell, string limb) {
    return this_player()->eventPrepareCast(spell, limb);
}

mixed do_cast_str_on_str_of_obj(string spell, string limb, object target) {
    return this_player()->eventPrepareCast(spell, limb, target);
}

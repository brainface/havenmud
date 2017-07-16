/*  
 * Metasynthesis
 * converts caster sp to mp
 */


#include <lib.h>
#include <magic.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("metasynthesis");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
     "healing" : 15,
     "natural magic" : 15,
    ]) );
  SetStaminaCost(20, 10);
  SetDifficulty(12);
  SetHelp( 
     "Allows the caster to draw upon either sunlight or moonlight as well as their "
     "own physical energies to gain magical energy."
    );
  }

int CanCast(object who, int level, mixed limb, object *targets) {
   if(who->GetProperty("natures_gift")) {
      message("system","Your link to nature allows you to cast."
              ,who);
      return spell::CanCast(who, level, limb, targets);
   }
   if( (environment(who)->GetClimate() == "indoors") ||
      (environment(who)->GetClimate() == "underground") ){
      message("system","Your spell fizzles and refuses to work "
              "in these types of environmental settings.",who);
      return 0;
   }

   return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed limb, object array tars) {
  int amt, base, rat;

  rat = who->GetSkillLevel("natural magic");
  rat += who->GetLevel();
  switch (rat) {
    case 0..20:
       rat = 5;
       break;
    case 21..40:
       rat = 4;
       break;
    case 41..60:
       rat = 3;
       break;
   default:
       rat = 2;
       break;
    }
  amt = 30 / rat;
  if (who->GetMagicPoints () == who->GetMaxMagicPoints()) {
    send_messages("",
      "$agent_possessive_noun body rebels at having too much magic drawn into it. ",
      who, 0, environment(who) );
    who->eventReceiveDamage(load_object(STD_DUMMY "magicshock"), MAGIC, amt, who->GetTorso(), 1);
    who->eventDisplayStatus();
    return 1;
   }
  if (who->GetStaminaPoints () < 30) {
    send_messages("fail",
      "$agent_name $agent_verb in an attempt to draw magical energies from "
      "$agent_possessive surroundings.",
      who, 0, environment(who) );
     return 1;
   }
  who->AddMagicPoints(amt);
  send_messages("draw", 
    "$agent_name $agent_verb upon the natural energies synthesizing it into "
    "magical energies.",
    who, 0, environment(who) );
  who->eventDisplayStatus();
  return 1;
  }

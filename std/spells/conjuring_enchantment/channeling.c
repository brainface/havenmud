/*  
 * Channeling spell
 * converts caster sp to mp
 */

#include <lib.h>
#include <magic.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("channeling");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
     "enchantment" : 10,
     "conjuring" : 10,
    ]) );
  SetStaminaCost(20, 10);
  SetDifficulty(25);
  SetHelp( 
     "Allows the caster to channel physical energy into magical energy. Casting "
     "this spell while already full on mana will cause serious physical damage."
    );
  }

varargs int eventCast(object who, int level, mixed limb, object array tars) {
  int amt, base, rat;

  rat = who->GetSkillLevel("conjuring");
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
      "$agent_possessive_noun body rebels at having too much magic channeled into it. ",
      who, 0, environment(who) );
    who->eventReceiveDamage(load_object(STD_DUMMY "magicshock"), MAGIC, 20, who->GetTorso());
    who->eventDisplayStatus();
    return 1;
   }
  if (who->GetStaminaPoints () < 30) {
    send_messages("fail",
      "$agent_name $agent_verb in the attempt at channeling energy. ",
      who, 0, environment(who) );
     return 1;
   }
  who->AddMagicPoints(amt);
  send_messages("channel", 
    "$agent_name $agent_verb some energy into magical force. ",
    who, 0, environment(who) );
  who->eventDisplayStatus();
  return 1;
  }


/* Approved by Duuktsaryth on Mon Sep  8 16:10:19 1997. */

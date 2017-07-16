/*  Portia  10-14-98  
    An invisibility spell for my clerics.
    Modified for Haven2 necromancers by Duuk@Haven
    Removed Necromancy to work for Clerics again by Alessandra
*/

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

void eventUnInvis(object who);

static void create() {
  spell::create();
  SetSpell("dim");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
      "enchantment" : 25,
      "faith"       : 25,
        ]) );
  SetReligions("Soirin");
  SetMagicCost(80,60);
  SetDifficulty(30);
  SetHelp( 

       "This spell, if successful, causes the caster to dim from "
       "view for a period of time determined by the caster's spell "
       "level.");
  }

varargs int CanCast(object who, int level, mixed x, object *targets) {
  if (who->GetInvis()) {
    message("system", "You are already dim.", who);
    return 0;
  }

  return spell::CanCast(who, level, x, targets);
 }

varargs int eventCast(object who, int level, mixed x, object *targets) {
  if (random(100) <= level ) who->SetInvis(1);
  send_messages("attempt", 
     "$agent_name $agent_verb to become %^CYAN%^dim%^RESET%^.",
     who, 0, environment(who));
  if (who->GetInvis()) 
     call_out( (: eventUnInvis, who :), level * 5 );
  return 1;
  }

void eventUnInvis(object who) {
  who->SetInvis(0);
  send_messages("are", 
        "$agent_name $agent_verb no longer dim.",
        who, 0, environment(who) );
  return;
 }

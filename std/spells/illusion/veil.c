/*  Portia  10-14-98    
    An invisibility spell for my clerics.
    Modified for Haven2 necromancers by Duuk@Haven
    Removed Necromancy to work for Clerics again by Alessandra
*/                                                            
// copied blatantly by mahkefel, for illusionists.          

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

void eventUnInvis(object who);

static void create() {
  spell::create();    
  SetSpell("veil");    
  SetRules("","LIV");       
  SetSpellType(SPELL_OTHER);
  SetSkills( ([             
    "illusion" : 25,        
        ]) );               
  SetMagicCost(80,60);      
  SetDifficulty(30);        
  SetHelp(                  
    "This spell allows a modest prestiditionist to veil the "
    "target from the sight of mortal eyes.");                  
  }                                                              

varargs int CanCast(object who, int level, mixed x, object *targets) {
  if (who->GetInvis()) {
    message("system", "You are already veiled from sight.", who);
    return 0;
  }
  return spell::CanCast(who, level, x, targets);
 }

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object target = targets[0];
  send_messages( ({"wave","veil"}),
     "$agent_name $agent_verb $agent_possessive hands over $target_name and"
     "%^BOLD%^BLACK%^ $agent_verb%^RESET%^ $target_objective from sight!",
     who, target, environment(who));
  if (random(100) <= level ) {
    target->SetInvis(1);
    call_out( (: eventUnInvis, target :), level * 5 );
  } else {
    send_messages( ({"fumble"}), "$agent_name%^BOLD%^YELLOW%^ $agent_verb "
      "%^RESET%^the trick!", who, target, environment(who) );
  }
  return 1;
}

void eventUnInvis(object who) {
  who->SetInvis(0);
  send_messages("are",
        "$agent_name $agent_verb no longer veiled from mortal eyes!",
        who, 0, environment(who) );
  return;
 }


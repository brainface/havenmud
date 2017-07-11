#include <lib.h>
#include <magic.h>
#include <std.h>
#include <daemons.h>
inherit LIB_SPELL;

void OpenGate();

static void create() {
  spell::create();
  SetSpell("gate");
  SetRules("", "STR");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "faith" : 250,
    "enchantment" : 250,
  ]) );
  SetMagicCost(175, 175);
  SetDifficulty(30);
  SetGlobalSpell(1);
  SetHelp(
                "This spell utilizes the cleric's knowledge of both "
                "the other planes and enchantment to open a temporary "
                "portal to the target. As long as the gate remains anyone "
                "may use it to travel between its two openings.");
}

varargs object *GetTargets(object who, mixed args...) {
  object targets;

  if(sizeof(args) < 1) {
     message("system", "Transport to whom?", who);
     return 0;
     }
     targets = find_living(args[0]);
  if (!targets || targets->GetInvis()) {
     message("system", "Unable to find your target.", who);
    return 0;
     }
  if(!environment(targets)) {
     message("system", "Unable to locate your target.", who);
     return 0;
      }
  return ({ targets });
  }

varargs int CanCast(object who, int level, string limb, object array targets) {
        object target = targets[0];
        object env  = environment(who);
        object envT; 
        int distance;
  
        if( creatorp(target) || target->GetTestChar()) {
                message("fail", "Cast it on whom?", who);
                return 0;
                }
        if( environment(target)->GetProperty("no teleport") ) {
                message("fail", "You can not open a gate to "   + target->GetName()+".", who);
                return 0;
                }
        if( environment(who)->GetProperty("no teleport") ) {
                message("fail", "You can not open a gate from here.", who);
                return 0;
                }
        if( environment(target)->GetProperty("lower plane") ) {
                message("fail", "You can not open a gate to "   + target->GetName()+".", who);
                return 0;
                }
        if( environment(who)->GetProperty("lower plane") ) {
                message("fail", "You can not open a gate from here.", who);
                return 0;
                }
        if( environment(who) == environment(target) ) {
                message("fail", "But " + target->GetName() + " is already here.",       who);
                return 0;
                }
        if( present("gate", environment(who)) ) {
                message("fail", "There is already a gate open from here.",      who);
                return 0;
                }
        if( present("magic_gate", environment(target)) ) {
                message("fail", "There is already a gate present there.",       who);
                return 0;
                }
        if (living(targets[0])) envT = environment(targets[0]);
            else envT = targets[0];
            distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
            SetDifficulty(50 * (1 + distance));
        return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, string limb, object array targets) {
        object target = targets[0];
        object gate;
        
  send_messages(({}), 
    "%^BOLD%^BLUE%^At $agent_possessive_noun bidding a rift in the fabric of "
                "space begins to open.%^RESET%^", who, 0, environment(who));
        message("system", 
          "%^BOLD%^BLUE%^A rift in the fabric of space begins to open before your eyes.%^RESET%^",
                environment(target));
  
  gate = new(STD_SPELLS "obj/gate");
  gate->eventMove(environment(who));
  gate->SetLifeSpan(10 + level + random(30));
  gate->SetGateTarget(file_name(environment(target)));
  
  gate = new(STD_SPELLS "obj/gate");
  gate->eventMove(environment(target));
  gate->SetLifeSpan(10 + level + random(30));
  gate->SetGateTarget(file_name(environment(who)));
  
  return 1;
}

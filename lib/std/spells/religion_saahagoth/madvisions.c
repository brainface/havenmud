// maddening visions
// Thoin
// 12-17-05

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create(){
  spell::create();
  SetSpell("maddening visions");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "faith" : 175,
    "necromancy" : 175,
  ]) );
  SetRequiredMagic(50);
  SetMagicCost(150,150);
  SetReligions("Saahagoth");
  SetDifficulty(165);
  SetHelp(
    "This spell allows the caster to infect the "
    "target with horrible visions which cause them to flee the room "
    "and continue to run until the spell ends."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("uncon_fear")) {
    message("system", "That person has already been affected by "
      "maddening visions.", who);
    return 0;
  }
  if( target->GetParalyzed() ) {
    message("system", "You cannot cast this on someone who is paralyzed.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets){
  object fear;
  object target = targets[0];
  float agentLevel, targetLevel;
  agentLevel = who->GetLevel() * (who->GetSpellLevel("maddening visions") + 10);
  targetLevel = target->GetLevel() * (100 + random(21));

  if( !present(target, environment(who)) )
    return 0;
  if( !(agentLevel >= targetLevel) ) {
    send_messages(({"attempt","avoid",}), "$agent_name "
      "$agent_verb to touch $target_name, but $target_name "
      "$target_verb the touch.", who, target, environment(who));
    if(!userp(target))
      target->AddEnemy(who);
      return 1;
  }
  else {
    send_messages( ({ "grin", "touch" }) , "$agent_name $agent_verb "
      "evilly as $agent_nominative $agent_verb $target_name " 
      "causing $target_objective to look unsettled.", who, target, 
      environment(who));
    who->eventForce("cackle evilly");
    fear = new("/std/spells/obj/mad_visions_ob.c");
    fear->SetCountDown(5 + random(10));
    fear->eventMove(target);
    target->SetProperty("uncon_fear", 1);
    return 1;
    }
}

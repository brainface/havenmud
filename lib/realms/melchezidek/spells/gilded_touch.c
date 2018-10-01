#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("gilded touch");
  SetSkills( ([
     "evokation" : 100,
     "faith" : 100,
  ]) );
  SetRules("OBJ","");
  SetMagicCost(50,80);
  SetStaminaCost(5,5);
  SetReligions("Soirin");
  SetSpellType(SPELL_OTHER);
  SetHelp(
     "This spell allows the caster to enhanced the value of items"
     " by coating it with a false covering of gold. "
  );
}

int CanCast(object who, int level, mixed limb, object *targets)
{
    object thing;
    
    if(sizeof(targets) != 1)
    {
        message("", "Cast guilded touch on what?", who);
        return 0;
    }

    thing = targets[0];
    if (thing->GetProperty("gilded") > 0);
    {
        message("", "That weapon has already been touched!", who);
        return 0;
    }
     
    return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed useless, object *targets) {
  int value;
  int barg;
  int new_value;
  int increase;
  float multiplier = 1.000;
  object target;
  target = targets[0];
  
  value = target->GetValue();
  barg = who->GetSkillLevel("bargaining");
  if (who->GetSkillLevel("bargaining") == 0) barg = 1;
 
  increase = (( barg + who->GetSkillLevel("faith") ) / 25);
  multiplier += increase/100.000;
  new_value = value * multiplier;
  if (who->GetTestChar()) debug("barg: " + barg + " faith: " + who->GetSkillLevel("faith")
                          + " multiplier: " + multiplier + " increase: " + increase);
  target->SetValue(new_value);
  target->SetProperty("gilded", 1);
  if (who->GetTestChar()) debug("old value: " + value + " new value: " + new_value);
  
    send_messages( ({ "summon","wrap" }), "$agent_name $agent_verb a sphere of golden"
     " energy and $agent_verb $target_name in a faux golden finish.",
     who, target, environment(who));
     target->SetShort(target->GetShort() + " (gilded)");
     return 1;
  }
  

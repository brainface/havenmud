#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

object GetVoodooDollTarget(object who, object doll);

static void create() {
  ::create();
  SetSpell("visions");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "natural magic" : 100,
    "necromancy" : 100,
  ]) );
  SetRules("", "", "OBJ");
  SetHelp("A shaman of moderate strength may open the inner mind's eye "
    "of the target, allowing them to see dark visions of the spirit "
    "world and their own demise. The spell may only be directed at a "
    "voodoo doll, allowing the shaman to curse someone at range. "
    "Note : This spell often has undesired effects.");
  SetDifficulty(50);
  SetMorality(-100);
  SetStaminaCost(100, 100);
  SetRequiredStamina(200);
}

int CanCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];

   if(target->GetKeyName() == "voodoo doll") {
     // this probably needs to be done again in eventCast,
     // in case someone logs mid spell
     target = GetVoodooDollTarget(who, target);
     if (!target) {
       who->eventPrint("The spirits can't seem to find "
       "the being you wish to affect.");
       return 0;
     }
   } else if (!living(target)) {
     who->eventPrint("You can't cast visions through that!");
     return 0;
   }

   if((target->GetFear() >= 1)) {
     message("system", "But that person is already scared!", who);
     return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];
  int amt = (who->GetSkillLevel("necromancy") / 33);
  amt *= level / 100;
  if (amt < 2) amt = 2;  
   if(target->GetKeyName() == "voodoo doll") {
     // this probably needs to be done again in eventCast,
     // in case someone logs mid spell
     target = GetVoodooDollTarget(who, target);
     if (!target) {
       message("system", "The spirits can't seem to find "
       "the being you wish to affect.", who);
       return 0;
     }
  }
  if(random(who->GetSkillLevel("necromancy")) > (random(target->GetLevel()*2))) { 
     send_messages(({"stop"}), 
       "%^BOLD%^With a gasp, $target_name $target_verb dead in $target_possessive "
       "tracks, horror written on $target_possessive face, mouth agape and "
       "with eyes as wide as they can be.%^RESET%^",
         who, target, environment(target));
     who->AddParalyzed(1);
     target->AddFear(amt);
     target->AddCaffeine(amt*5);
     target->AddEnemy(who);
     target->eventPrint("%^RED%^You have a sudden urge to kill $agent_name.%^RESET%^");
     who->eventPrint("%^RED%^You do realize, $target_name is mad at you.%^RESET%^");
     return 1;
  } else {
    send_messages( ({ "stop" }),
       "%^BOLD%^With a gasp, $agent_name $agent_verb dead in $agent_possessive "
       "tracks, horror written on $agent_possessive face, mouth agape and "
       "with eyes as wide as they can be.%^RESET%^",
    who, environment(who));
    who->AddFear(amt);
    who->AddCaffeine(amt*5);
  }

object GetVoodooDollTarget(object who, object doll) {
  object target;

  target = find_living(doll->GetVictim()); 
  if (!target) {
    return 0;
  }

  if (environment(target)->GetProperty("no magic")) {
    who->eventPrint("Some magic is warding the spirits away!");
    return 0;
  }

  doll->AddCharges(-2);
  return target;

}

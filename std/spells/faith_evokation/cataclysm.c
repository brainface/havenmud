// Divine cataclysm. Super Powerfull
// avatar level cleric area affect spell,
// coded by: Malak@Haven 6/2/99
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("divine cataclysm");
   SetRules("");
   SetUniqueSpell(1);
   SetSkills( ([ 
     "faith"     : 200,
     "evokation" : 200,
     ]) );
   SetAreaSpell(1);
   SetSpellType(SPELL_COMBAT);
   SetRecoveryTime(10 + random(11));
   SetDifficulty(170);
   SetEnhanceSkills( ({ "fire magic" }) );
   
   SetHelp(
     "This extremely costly spell is used with great care "
     "by those able to cast it, as it is able to cause incredibly "
     "massive carnage to the area surrounding the caster.");
}

int eventCast(object who, int level, string limb, object array targets) {
  int damage = GetDamage(level);
   
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
    who->eventPrint("Your powers fail you.");
    return 0;
  } 

  // echo "hey there's a cataclysm here" to the domain outdoors.
  foreach(object ob in users()) {
    if (!environment(ob)) continue;
    if (environment(ob)->GetDomain() != environment(who)->GetDomain()) continue;
    if (environment(ob)->GetClimate() == "underground") continue;
    if (environment(ob)->GetClimate() == "indoors") continue;
    ob->eventPrint("With a sound of booming anger, huge bolts of "
      "%^RED%^fire%^RESET%^ crash from the heavens.");
  }

  //mahkefel 2015:
  // previously the checks here were "if damage <1", "if damage < damage / 2"
  // and "if damage > damage /2 "
  // Like... clearly that doesn't work? and there is no obvious other check
  // for me to tie success too, so i'm just setting it so description changes 
  // with level.
  if( level < 25 ){
    send_messages(({"scorch"}), "$agent_name mildly%^RED%^ "
      "$agent_verb%^RESET%^ " + conjunction(targets->GetName()) + ".",
    who, targets, environment(who));
  } else if( level < 75 ){
    send_messages(({"summon"}), 
    "$agent_name $agent_verb forth a pilar of %^BLUE%^savage power%^RESET%^, "
    "devastating "+conjunction(targets->GetName())+" with godly fury!",
    who, targets, environment(who));
  } else {
    send_messages(({"unleash"}),
    "$agent_name $agent_verb massive bolts of pure wrath, "
    "%^RED%^obliterating%^RESET%^ "+conjunction(targets->GetName())+" with a "
    "cleansing fire!", who, targets, environment(who));
  }
  targets->eventReceiveDamage(who, HEAT|MAGIC, damage, 0, limb);
      
  return spell::eventCast(who, level, limb, targets);   
}

#include <lib.h>
#include <dirs.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("black circle");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
    "faith" : 350,
    "necromancy" : 350,
    ]) );     
  SetEnhanceSkills( ({ "fire magic" }) );  
  SetMagicCost(150,100);
  SetMaximumMorality(-100);
  SetDifficulty(195);
  SetHelp(
     "This powerful necromatic enchantment spell allows a powerful cleric to create "
     "a circle of destruction with in the room they are in. The circle will "
     "harm all good who attempt to enter the room. Any who remain in the room will "
     "be harmed except for the caster and their group."
     );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  object env = environment(who);

  if(env->GetProperty("great_circle")) {
    message("system", "The area already has a circle field.", who);
    return 0;
      }   

   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets){
  int damage, damageboost;
  object ward;
  object env = environment(who);
  damage = GetDamage(level);
	damageboost = who->GetSkillLevel("fire magic") / (GetSpellLevel() * 2);
	if (damageboost > 3) damageboost = 3;
	damage += damage * damageboost;
	    
  if(!(ward = new(DIR_SPELLS "/obj/bcircle_obj.c"))) return 0;
  
  env->SetProperty("great_circle", 1);
  ward->SetMaster(who->GetKeyName());
  ward->SetCountDown(10 + (who->GetSkillLevel("faith")/10) );
  ward->eventMove(environment(who));
  ward->SetDamageAmount(damage);
  message("ward message","You spread out a circle of black chalk "
          "around the room.",who);
  return 1;
}


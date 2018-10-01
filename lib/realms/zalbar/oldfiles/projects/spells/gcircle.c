#include <lib.h>
#include <dirs.h>
#include <magic.h>

inherit LIB_SPELL;

static void create(){
  spell::create();
  SetSpell("great circle");
  SetSpellType(SPELL_HEALING);
  SetRules("");
  SetSkills( ([
     "faith" : 350,
     "healing" : 350,
  ]) );
  SetMinimumMorality(1000);
  SetDifficulty(195);
  SetHelp(
     "This powerful enchantment spell allows a powerful cleric to create "
     "a circle of protection with in the room he is in. The circle will "
     "protect the good in the room while those who are evil or are undead "
     "will be harmed and caused to flee. ");
  }

int CanCast(object who, int level, mixed limb, object *targets) {
  object env = environment(who);
  
  if(env->GetProperty("great_circle")) {
    message("system", "The area already has a great circle.", who);
    return 0;
      }   

   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets){
        int damage;
        object ward;
        object env = environment(who);
        damage = GetDamage(level);
        
        if(!(ward = new(DIR_SPELLS "/obj/gcircle_ob.c")))
        return 0;
        
        env->SetProperty("great_circle", 1);
        ward->SetMaster(who->GetKeyName());
        ward->SetCountDown(10 + (who->GetSkillLevel("faith")/10) );
        ward->eventMove(environment(who));
        ward->SetDamageAmount(damage);
        message("ward message","You spread out a circle of pure white chalk "
                "around the room.",who);
        
        return 1;
}


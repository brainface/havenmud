#include <lib.h>
#include <dirs.h>
#include <magic.h>

inherit LIB_SPELL;

static void create()
{
        spell::create();
        SetSpell("invisibility purge");
        SetSpellType(SPELL_OTHER);
        SetRules("");
        SetSkills( ([
        "faith" : 225,
        "enchantment" : 225,
                ]) );
        SetMagicCost(150,100);
        SetDifficulty(125);
   SetHelp(
                "This powerful enchantment spell creates a field in the room "
                "that will strip all invisibility magics from any who enter or "
                "stay in the room.");
}

int CanCast(object who, int level, mixed spell, object array targets) {
  object target = targets[0];
  object env = environment(who);

  if(env->GetProperty("invis_field")) {
    message("system", "The area already has an invisibility purging field.", who);
    return 0;
  }   
  return spell::CanCast(who, level, spell, targets);
}

int eventCast(object who, int level, string limb, object array targets)
{
        object ward;
        
        if(!(ward = new(DIR_SPELLS "/obj/invis_purge_ob.c")))
        return 0;
        
        ward->SetMaster(who->GetKeyName());
        ward->SetCountDown(10 + (who->GetLevel() * (random(10) + 10)));
  environment(who)->SetProperty("invis_field", 1);
        ward->eventMove(environment(who));
        message("ward message","You focus your energy to create "
                "an invisibility purging field.",who);
        
        return 1;
}


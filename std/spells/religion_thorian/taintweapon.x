// The 'taint weapon' spell
// Thorian Cleric
// Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("taint weapon");
  SetSkills( ([
     "necromancy" : 10,
     "faith" : 10,
  ]) );
  SetRules("OBJ");
  SetReligions("Thorian");
  SetMagicCost(40,40);
  SetStaminaCost(5,5);
  SetMorality(-10);
  SetSpellType(SPELL_OTHER);
  SetHelp(
     "Using necromantic powers a Thorian cleric can cause a weapon to be covered "
     "in poison."
  );
}

int CanCast(object who, int level, mixed limb, object *targets)
{
    object thing;
    
    if(sizeof(targets) != 1)
    {
        message("", "Cast taint weapon on what?", who);
        return 0;
    }

    thing = targets[0];

    if (thing->GetPoison() > 0)
    {
        message("", "That weapon has already been poisoned!", who);
        return 0;
    }

    if (!(thing->GetVendorType() & VT_WEAPON))
    {
        message("", "You cannot poison that which is not a weapon!", who);
        return 0;
    }
  
    return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) { 

    int yup = (5 + who->GetSkillLevel("necromancy") / 2);
    object thing;

    if(sizeof(targets) != 1)
    {
        message("", "Cast taint weapon on what?", who);
        return 0;
    }

    thing = targets[0];
    thing->AddPoison(yup);
    /*
    if (strsrch(thing->GetShort(), "poisoned") == -1)
    {
        thing->SetShort(thing->GetShort() + " (poisoned)");
    }
    */
    
    send_messages( ({ "cough","beckon" }), "$agent_name $agent_verb up a "
        "%^BOLD%^%^BLACK%^mist of poison%^RESET%^ which covers $target_name "
        "in a thin lair of %^BOLD%^%^BLACK%^poison%^RESET%^.",
        who, thing, environment(who));
    
    return 1;
}


// envenom arrow
// natural magic spell that poisons a ranged weapon
//  basically a copy of Thoin's taint weapon spell
// Mahkefel 2010

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("envenom arrow");
  SetSkills( ([
     "natural magic" : 10,
     "enchantment" : 10,
  ]) );
  SetRules("OBJ");
  SetMagicCost(40,40);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetStaminaCost(5,5);
  SetMorality(-10);
  SetSpellType(SPELL_OTHER);
  SetHelp(
     "Using a basic knowledge of enchantment, the caster can coat arrows "
     "with a powerful natural toxin. This spell may only be used "
     "on a projectile weapon."
  );
}

int CanCast(object who, int level, mixed limb, object *targets)
{
    object thing;

    if(sizeof(targets) != 1)
    {
        message("", "Cast envenom arrow on what?", who);
        return 0;
    }

    thing = targets[0];

    if (thing->GetPoison() > 0)
    {
        message("", "That weapon has already been poisoned!", who);
        return 0;
    }

    if ( !(thing->GetVendorType() & VT_WEAPON) || !( thing->GetWeaponType("projectile") ) )
    {
      message("", "You cannot poison that which is not a projectile weapon!", who);
      return 0;
    }

    return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
    object thing;
    int yup = (5 + who->GetSkillLevel("natural magic") / 4);
    yup += who->GetSkillLevel("poison magic") / 4;

    if(sizeof(targets) != 1)
    {
        message("", "Cast envenom arrow on what?", who);
        return 0;
    }

    thing = targets[0];
    thing->AddPoison(yup);

    send_messages( ({ "apply" }), "$agent_name $agent_verb a "
      "vile-smelling %^BOLD%^BLACK%^toxin%^RESET%^ to $agent_possessive "
      + remove_article(thing->GetShort()) + ".",
      who, thing, environment(who));

    return 1;
}


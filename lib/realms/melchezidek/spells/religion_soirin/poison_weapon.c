// The 'poison weapon' spell
// Artanis@Haven (formerly Zeratul@Haven)
// 11/10/2001
//
// Modified by Zaxan@Haven to work.
// 17-Jul-2004
// Adjusted to fit Soirin Priests
// Melchezidek 8-6-08

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("poison weapon");
  SetSkills( ([
     "necromancy" : 50,
     "faith" : 50,
  ]) );
  SetRules("OBJ","");
  SetMagicCost(60,60);
  SetStaminaCost(5,5);
  SetMorality(-10);
  SetReligions("Soirin");
  SetSpellType(SPELL_OTHER);
  SetHelp(
     "Using necromantic powers, the caster summons a mist of poison that swirls "
     "around the targeted weapon and fuses with it, causing the weapon to be "
      "poisoned. "
  );
}

int CanCast(object who, int level, mixed limb, object *targets)
{
    object thing;
    
    if(sizeof(targets) != 1)
    {
        message("", "Cast poison weapon on what?", who);
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
    int yup = (5 + who->GetLevel() / 5);
    object thing;

    if(sizeof(targets) != 1)
    {
        message("", "Cast poison weapon on what?", who);
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
    
    send_messages( ({ "summon","beckon" }), "$agent_name $agent_verb forth a mist of "
        "%^GREEN%^BOLD%^poison%^RESET%^ and $agent_verb it to fuse with $target_name. ",
        who, thing, environment(who));
    
    return 1;
}

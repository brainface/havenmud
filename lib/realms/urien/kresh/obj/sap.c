/*  A blunt thing */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sap");
  SetDamagePoints(800);
  SetShort("a small sap");
  SetLong("This is a sap, which is a small bag filled with metal shot. "
          "It is highly effective as a surprise tool and quick hitting "
          "weapon.");
  SetClass(12);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetValue(120);
  SetMaterial( ({ "leather" }) );
  SetRepairSkills( ([
      "leather working" : 0,
     ]) );
  SetMass(35);
  SetId( ({ "sap" }) );
  SetAdjectives( ({ "small" }) );
  }

mixed eventUse(object who, string args) {
   object victim;
   object *weapons = who->GetWielded();
   int length, stunlength;
  string what, target_str;
if (who->GetClass() != "valkyr") { return 0; }
if (!sizeof(weapons)) { 
    message("system",
       "You must be wielding it to use it!",
       who);
    return 0;
    }
  foreach(object weapon in weapons) {
    if (weapon->GetKeyName() != "sap") {
    message("system",
       "You must be wielding a sap to use it!",
       who);
       return 0;
      }
    }
  sscanf(args, "%s %s", what, target_str);
   if (!what) { return "Do what with the sap?"; }
  if (!target_str) { return "Do what to whom?"; }
  if (!(victim = present(target_str, environment(who)))) {
    return "That person is not here!";
     }
  if (!(what == "stun")) {
     return "You cannot use the sap for that.";
      }
  length = who->GetSkillLevel("stealth") + who->GetStatLevel("strength") + 
       who->GetStatLevel("coordination");
  length -= (victim->GetLevel());
  if (length > 5) { stunlength = 5; }
  if (length < 1) { 
    send_messages("stumble",
       "$agent_name $agent_verb in an attempt to surprise $target_name.",
       who, victim, environment(who));
     who->AddEnemy(victim);
   victim->AddEnemy(who);
   who->AddSkillPoints("stealth",(random(50)+length));
    return 1;
     }
  message("system",
      "You sneak up behind " + victim->GetCapName() + " and THWAP " +
       objective(victim) + " with the sap.", who);
  message("system",
         "You feel a THUD on your neck.", victim);
   victim->SetParalyzed(stunlength);
    victim->eventCollapse();
  who->AddSkillPoints("stealth",(5+random(5)*(length*who->GetSkillLevel("stealth"))) );
  return 1;
  }


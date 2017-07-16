#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
 
int type = random(3);

static void create() {
  item::create();
  SetKeyName("dart");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 15,
   "weapon smithing" : 10,
     ]) );
  SetShort("a tiny dart");
  SetAdjectives( ({ "tiny" }) );
  SetId( ({ "dart", "tiny dart" }) );
  SetLong("This is a tiny little dart.  It is about "
    "three inches long with sharpened edges and some "
    "etched runes lining the blade.");
  SetClass(12);
  SetDamagePoints(100);
  SetValue(150);
  SetMass(5);
  SetVendorType(VT_WEAPON);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  }
 
mixed eventThrow(object who, object target) 
{
  if(!target) 
  {
    message("dart","Throw the dart at who?",who);
    return 1;
  }
  else
  {
    int amount = random(3);
    switch(amount)
    {
      case 0:
        target->SetParalyzed(65);
        send_messages("throw","$agent_name $agent_verb a small dart "
          "at $target_name.  The dart glows slightly as it hits.",
          who, target, environment(who));
        eventDestruct();
        break;
      case 1..2:
        send_messages("throw","$agent_name $agent_verb a small dart "
          "at $target_name and misses.", who, target, environment(who));
        eventDestruct();
    }
  }
}
    

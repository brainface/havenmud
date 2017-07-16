#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("mithril-hammer");
  SetId( ({ "mithril-hammer","hammer","mithril hammer" }) );
  SetShort("a mithril-hammer");
  SetLong("Forged completely of mithril steel (haft, head and all), the "
          "war hammer looks as deadly as any hammer you have ever seen.");
  SetMaterial( ({"mithril"}) );
  SetRepairSkills( ([
                     "mithril working" : 12,
                     "weapon smithing" : 15
                 ]) );
  SetRepairDifficulty(60);
  SetMass(130);
  SetValue(2500);
  SetDamagePoints(4000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetProperty("magic","The material of the hammer itself glows with power.");
  SetProperty("history","Forged in the legendary forge of Glimmerdin, the "
              "hammer had been in the dwarven church for generations."
              " When the dwarven faiths start to fail, Glimmerdin "
              "underwent many changes.  In the process, this hammer was lost. "
              "Some time later, it was sold to Zurlock by the dwarven metal smith "
              "by the name of Skag.");
}

int eventStrike(object target)
{
  object *combatants;
  
  combatants = (({ previous_object(),target}));
  
  if(random(10)) return item::eventStrike(target);
  message("system","The mithril hammer flashes as it hits your foe.",
          this_player());
  message("system","A flash of light nearly blinds you when " +
          this_player()->GetName() + "'s mithril hammer hits you.",target);
  message("system","A flash of light temporarily blinds all in the "
          "room as " + this_player()->GetName() + "'s mithril hammer hits " +
          target->GetName() + ".",environment(this_player()), combatants);
  return item::eventStrike(target) + random(8) + 5;
}

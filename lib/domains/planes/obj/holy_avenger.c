#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int KylinWield();

static void create() {
  item::create();
  SetKeyName("holy avenger");
  SetRepairSkills( ([
    "metal working" : 4,
    "weapon smith" : 8,
    ]) );
  SetMaterial( ({ "mithril" }) );
  SetShort("a glowing white blade");
  SetId( ({ "blade", "avenger" }) );
  SetAdjectives( ({ "holy", "glowing", "white" }) );
  SetClass(35);
  SetMass(160);
  SetValue(8000);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetLong(
    "This powerful blade is a fearful weapon of divine retribution in the hands of "
    "an Arch-Angel of Kylin. In the hands of a mere mortal it is only a highly effective "
    "weapon."
    );
  SetRadiantLight(10);
  SetDamagePoints(20000);
}

int eventStrike(object ob) {
  if (environment()->GetReligion() == "Kylin" && ob->GetReligion() != "Kylin" && environment()->GetClass() == "paladin") {
      send_messages( ({ "exact" }),
         "%^RED%^BOLD%^The vengence of Duuktsaryth is exacted upon $target_name!%^RESET%^",
         environment(), ob, environment(ob)
       );
     return ::eventStrike(ob) + 50;
     }
  return ::eventStrike(ob);
}

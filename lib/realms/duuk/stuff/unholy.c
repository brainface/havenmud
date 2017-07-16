#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int KylinWield();

static void create() {
  item::create();
  SetKeyName("blade of Kylin");
  SetRepairSkills( ([
    "metal working" : 4,
    "weapon smith" : 8,
    ]) );
  SetMaterial( ({ "mithril" }) );
  SetShort("a sleek mithril blade");
  SetId( ({ "blade" }) );
  SetAdjectives( ({ "sleek", "mithral" }) );
  SetClass(26);
  SetMass(225);
  SetValue(8000);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetLong(
    "This is the famed \"Blade of Kylin\", the weapon of the Prophet of the "
    "Sands and the mark of the most powerful Paladin of the Desert Kylin sect."
    );
  SetRadiantLight(10);
  SetDamagePoints(20000);
  SetWield( (: KylinWield :) );
}

int eventStrike(object ob) {
  if (environment()->GetReligion() == "Kylin" && ob->GetReligion() != "Kylin") {
      send_messages( ({ "exact" }),
         "%^RED%^BOLD%^The vengence of Duuktsaryth is exacted upon $target_name!%^RESET%^",
         environment(), ob, environment(ob)
       );
     return ::eventStrike(ob) + 50;
     }
  return ::eventStrike(ob);
}

int KylinWield() {
  object who = environment();
  if (who->GetReligion() != "Kylin") {
    users()->eventPrint("%^BOLD%^BLUE%^The anger of the heavens can be felt as " +
                        capitalize(who->GetKeyName()) + " commits a great blasphemy.");
    who->eventDie(this_object());
    return 0;
  }
  send_messages( ({ "wield" }),
     "$agent_name $agent_verb " + GetShort() + ".",
     who, 0, environment(who) );
  return 1;
}
                        
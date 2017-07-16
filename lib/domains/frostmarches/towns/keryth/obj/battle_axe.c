//coded by Syra@haven 2/98
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();
    SetShort("a large battle axe");
    SetLong("The great steel head sits upon a long "
           "wooden shaft. Leather strips create hand "
           "grips along the shaft. ");
    SetId( ({"axe","battle axe",}) );
    SetAdjectives( ({ "battle","steel","great"}) );
    SetClass(20);
    SetDamagePoints(2000);
    SetValue(750);
    SetWeaponType("hack");
    SetDamageType(SLASH);
    SetKeyName("battle axe");
    SetMass(350);
    SetVendorType(VT_WEAPON);
    SetAdjectives( ({ "steel" }) );
    SetHands(2);
    SetMaterial( ({
           "metal",
           "wood",
           }) );
    SetRepairDifficulty(15);
    /*SetRepairSkills( ([ "weapon smithing" : 5,
                        "metal working"   : 5,
                        "wood working"    : 2,
                        "leather working" : 1,
          ]) );*/
  SetProperty("history","The battle axe once belonged to Masik, the "
               "bull. He was the leader of the barbarians in Keryth, "
               "and a worthy opponent. ");
}

int WieldMe() {
    if( (int)this_player()->ClassMember("fighter") ) {
        write("The battle axe gives you power as you wield it.");
        say((string)this_player()->GetName() + " wields a battle axe.");
        return 1;
    }
    else {
        write("You are not worthy of this battle axe.");
        return 0;
    }
}

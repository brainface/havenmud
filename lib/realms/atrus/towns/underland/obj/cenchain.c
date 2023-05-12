//Centurion's Armour
//Atrus 2023@HavenMud

#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;


static void create() {
     armour::create();
     SetKeyName("chainmail");
     SetId( ({ "suit" }) );
     SetAdjectives( ({ "sturdy", "suit of" }) );
     SetShort("a suit of mithril chainmail");
     SetLong("This suit of gnomish chainmail is composed of a thick "
        "and extremely durable mithril mesh. The suit appears to fit a gnome "
        "shape perfectly. And would offer supreme protection to the wearer.");
     SetMass(650);
     SetProperty("multiples", 1);
     SetMaterial( ({ "mithril" }) );
     SetRepairDifficulty(40);
     SetValue(4500);
     SetArmourClass(ARMOUR_CHAIN);
     SetDamagePoints(2500);
     SetArmourType(A_BODY_ARMOUR);
     SetSize(SIZE_SMALL);
}

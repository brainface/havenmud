// miney treasure for arcanith
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("shard");
  SetShort("a runed shard of marble");
  SetId( ({ "chunk","shard","marble","arcanith_wall_shard" }) );
  SetAdjectives( ({ "runed","chunk","shard","of","marble" }) );
  SetLong(
    "This chunk of marble is about a hands-width across. One "
    "side is flat and covered with a spider-web like network "
    "of faintly glowing runes. It looks like it was once part "
    "of a larger structure."
  );
  SetMass(20);
  SetValue(600);
  SetDamagePoints(2000);
  SetMaterial( ({ "natural" }) );
  SetRadiantLight(5);
  SetVendorType(VT_GEM);
}


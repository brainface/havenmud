#include <lib.h>
inherit LIB_ITEM;
inherit LIB_FEAR;

static void create() {
  item::create();
  SetKeyName("altar");
  SetProperty("magic",
      "This is an altar of pure evil.");
  SetId( ({ "altar", "altar of stone", "large altar" }) );
  SetShort("a large altar of stone");
  SetPreventGet("It is much too large to move.");
  SetMaterial( ({ "natural", "wood" }) );
  SetLong("The altar is a huge mass of carvings and engravings which "
          "can only be described as horrible.  The evil thing permeates "
          "the very air with its abominable existance.");
  SetFearType("sheer horror of the altar");
  SetResistLevel(20);
  SetFearLength(10);
 }

varargs int CheckResistFear(object who, int level, string type) {
  if (who->GetUndead()) return 0;
  if (who->GetReligion() == "Rath Cult") return 0;
  return ::CheckResistFear(who, level, type);
 }


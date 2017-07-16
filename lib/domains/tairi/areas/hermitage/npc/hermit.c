

#include <lib.h>
#include <domains.h>
#include <vendor_types.h>
#include "../herm.h"

inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("Yoshimitsu the Hermit");
  SetShort("Yoshimitsu the Hermit");
  SetId( ({ "hermit", "yoshimitsu", "yoshi" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Tai");
  SetLong("Years ago Yoshimitsu chose the life of a hermit."
          " His greasy skin hangs from his face and hands"
          " in a manner much like melted wax on a candle."
          " His countenance provides little information"
          " pertaining to his current mood.");
  SetClass("evoker");
  SetLevel(25);
  SetAction(15, ({
          "!emote hrmms.",
          "!emote meditates.",
          "!say Well then, what is it?",
          "!emote nods slightly.",
          "!say Are you interested in buying one of my"
          " ghost slayers?",
     }) );  
  SetMenuItems( ([
    "mace"      : HERM_OBJ "blunt",
    "axe"       : HERM_OBJ "hack",
    "tanto"     : HERM_OBJ "knife",
    "wakizashi" : HERM_OBJ "pierce",
    "bow"       : HERM_OBJ "projectile",
    "katana"    : HERM_OBJ "slash",
    "staff"     : HERM_OBJ "staff",
  ]) );
  SetLocalCurrency("koken");
}


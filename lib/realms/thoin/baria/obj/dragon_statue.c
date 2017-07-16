/*                                                                   */
// Summary: Statue of Rhakz in the Shrine
// Creator: Angel Cazares - Rhakz
// For Baria
// Date: 10/16/98
// Altered for Re-opening July 18, 2004 by Artanis@Haven
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dragon statue");
  SetShort("a dragon statue");
  SetLong("%^YELLOW%^BOLD%^ "
"                               .  .   ~~//====......          __--~ ~~\n"
"                  -.            \\_|//     ||| \\  ~~~~~~::::... /~\n"
"               ___-==_       _-~o~  \\/    |||  \\            _/~~-\n"
"       __---~~~.==~||\\=_    -_--~/_-~|-   | \\   \\        _/~\n"
"   _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \\      /\n"
" .~       .~       |   \\ -_    /  /-   /   ||     \\   /\n"
"/  ____  /         |     \\ ~-_/  /|- _/   .||       \\ /\n"
"|~~    ~~|--~~~~--_\\     ~==-/   | \\~--===~~        .\\\n"
"         '         ~-|      /|    |-~\\~~       __--~~\n"
"                     |-~~-_/ |    |   ~\\_   _-~             /\\\n"
"                          /  \\    \\__   \\/~                  \\__\n"
"                      _--~ _/ | .-~~____--~-/                  ~~==.\n"
"                     ((->/~   '.|||' -_|    ~~-/ ,              . _||\n"
"                                -_     ~\\      ~~---l__i__i__i--~~_/\n"
"                                _-~-__   ~)  \\--______________--~~\n"
"                              //.-~~~-~_--~- |-------~~~~~~~~\n"
"                                     //.-~~~--\\\\\n\n%^RESET%^"
"
                            To our Great Lord, Artanis.\n"
"                 May he bless us all with his infinite wisdom."         );
  SetId( ({ "statue","dragon statue" }) );
  SetAdjectives( ({ "golden", "big" }) );
  SetDamagePoints(1000);
  SetValue(1000);
  SetMass(1000);
  SetVendorType(VT_TREASURE);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(10);
  SetPreventGet(1);
}


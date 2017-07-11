#include <lib.h>
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("Roland");
  SetId( ({ "healer", "roland", "averath_person" }) );
  SetShort("Roland the Healer");
  SetLong(
    "Roland has been trained in the arts of healing and resurrection. He is "
    "a tall man with a vacant stare. Roland would be willing to help anyone "
    "in need, whether they need general healing, rejuvenation, or even "
    "brought back to life. He usually asks for a small donation to the church "
    "for his services."
  );
  
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");
  SetLocalCurrency("ducats");
  
  SetMorality(0);
  SetClass("priest");
  SetLevel(20);
  AddCurrency("ducats", random(50));
  SetTown("Averath");
  SetFees( ([
    "resurrect" : 80,
    "magic" : 8,
    "stamina" : 1,
    "health" : 2,
    "restore" : 30,
    ]) );  
}

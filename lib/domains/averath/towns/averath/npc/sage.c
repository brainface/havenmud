#include <lib.h>
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("michelle cheron");
  SetRace("human");
  SetTown("Averath");
  SetShort("Michelle Cheron, the cunning linguist");
  SetId( ({ "michelle", "cheron", "michelle cheron", "linguist" }) );
  SetLong(
    "Michelle is well travelled young lady. She is well known for her ability "
    "to pick up any language, and has mastered a few. She is fairly short, "
    "with dark brown hair and has a pleasant smile on her face.");    
  SetGender("female");
  SetBaseLanguage("Avera");
  SetClass("fighter");  
  SetSkill("melee combat",1,1);
  SetLevel(35);  
  SetMorality(250);
  SetTaughtLanguages( ({ "Eltherian", "Enlan", "Avera", "Runic" }) );
  SetLocalCurrency("ducats");
  SetCharge(1500);
 }

// changed by Mahkefel 10 2010: decreased fear to negligle time
#include <lib.h>
#include <damage_types.h>

inherit LIB_HEALER;
inherit LIB_FEAR;

static void create() {
  healer::create();
  SetKeyName("nazir");
  SetShort("Nazir the Cursed");
  SetId( ({ "nazir", "healer", }) );
  SetAdjectives( ({ "cursed" }) );
  SetLong("Nazir was once a lovely elven maiden"
          " destined for a life of wealth and privilege"
          " until fate took a turn for the worse. She"
          " started dabbling in the dark arts and was"
          " cursed to walk the world as a wraith. Her"
          " intensive study of magic however yielded"
          " her the ability to heal, an ability she"
          " exercises in the safest place for her kind,"
          " the Ruins of Durgoroth.");
  SetGender("female");
  SetRace("wraith");
  SetClass("priest");
  SetResistance(ALL_PHYSICAL, "immune");
  SetResistance(SHOCK, "immune");
  SetDie("The wraith dispells into a fine mist.");
  SetNoCorpse(1);
  SetLevel(200);
  SetTown("Durgoroth");
  SetMorality(-2000);
  SetBaseLanguage("Gryshnak");
  SetLocalCurrency("crystals");
  SetUndead(1);
  SetResistLevel(150);
  SetFearLength(2);
  SetFearType("undead chill");
  SetFees( ([
        "resurrect" : 50,
        "magic"     : 0,
        "stamina"   : 5,
        "health"    : 3,
        "restore"   : 5,
        ]) );
  SetAction(5, ({ 
    "!speak Your pain is my delight, but for a price"
           " I can heal you.",
    "!muaha",
    "!speak You are better off ending your struggle now,"
           " but if you truely wish to carry on, I can"
           " heal you.",
    }) );
  SetCombatAction(60, ({
    "!cast divine retribution",
    "!cast touch of death",
    "!cast maddening visions",
    "!cast cause bleeding",
    "!cast purify",
    "!cast soul taint",
    "!cast unholy guardian",
    }) );
  SetSpellBook( ([
    "unholy guardian"    : 100,
    "purify"             : 100,
    "unholy power"       : 100,
    "touch of death"     : 100,
    "divine retribution" : 100,
    "maddening visions"  : 100,
    "cause bleeding"     : 100,
    "soul taint"         : 100,
    ]) );
  SetFirstCommands( ({ 
    "cast unholy power",
    "cast unholy guardian",
    "cast unholy guardian",
    "cast unholy guardian",
    }) );
}





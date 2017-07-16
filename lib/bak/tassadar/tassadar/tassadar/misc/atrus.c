#include <lib.h> 
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("atrus");
    SetId( ( "atrus" ) );
    SetAdjectives( ({"huge", "built"}) );
    SetShort("Atrus the Arbitor of Darkness");
    SetLong("From head to toe this huge being is built very well. His arms "
            "ripple with muscles and his chest is huge. His legs are very "
            "large and his wings stand out sharply.");             
    SetLevel(160);
    SetRace("maralith");
    SetClass("rogue");
    SetGender("male");
    SetOwner("tassadar");
    SetCombatStyleLevel("blade dancing", 100); 
    SetCombatStyle("blade dancing");
    SetInventory( ([
      ]) ); 
    SetMorality(400000000);
    SetSkill("knife attack", 500, 1);
    SetSkill("knife defense", 480, 1);
    SetSkill("melee defense", 501, 1);
    SetSkill("mining", 500, 1);
    SetSkill("melee attack", 501, 1);
    SetStat("strength", 400, 1);
    SetStat("durability", 400, 1); 
    SetAction(6, ({ "!look" }));
}

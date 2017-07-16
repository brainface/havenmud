/* miner.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h> 
#include "../mine.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("miner");
    SetId( ( "miner" ) );
    SetAdjectives( ({"sweaty", "built"}) );
    SetShort("a built miner");
    SetLong(
       "From head to toe this miner is well-built. His arms "
       "ripple with muscles and his chest is huge. Sweat stands "
       "out on his brow and he has slicked back hair. His face "
       "is well shaped with a sharp jaw line. His hair is a light "
       "tan, almost blonde with heavy clumps of rock dust caught in "
       "it. He seems strong but not very agile."
       );
    SetLevel(9);
    SetRace("dwarf");
    SetClass("fighter");
    SetGender("male");
    SetInventory( ([
        MINE_OBJ "shirt" : "wear smock",
        MINE_OBJ "pant" : "wear pants",
        MINE_OBJ "pick" : "wield pick",
      ]) ); 
    SetMorality(400);
    SetSkill("mining", 40, 1);
    SetAction(6, ({ "!mine with pick",
            "!emote wipes the sweat from his brow.",
            "!cough",
            "!sneeze",
            "!hum" 
             }) );
}
